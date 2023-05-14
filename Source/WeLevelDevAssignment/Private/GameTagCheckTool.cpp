// Fill out your copyright notice in the Description page of Project Settings.


#include "GameTagCheckTool.h"



UGameTagCheckTool* UGameTagCheckTool::GameTagCheckTool(AActor* ActorToCheck)
{
    UGameTagCheckTool* TagCheckObj = NewObject<UGameTagCheckTool>();
    TagCheckObj->ActorToCheckTag = ActorToCheck;
    return TagCheckObj;
}

TStatId UGameTagCheckTool::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(FTest, STATGROUP_Tickables);
}

bool UGameTagCheckTool::IsTickable() const
{
    return bShouldTick;
}

void UGameTagCheckTool::Activate()
{
    bShouldTick = true;

    //setting up initial tag numbers
    if (ActorToCheckTag) {
        NumOfTags = ActorToCheckTag->Tags.Num();
    }
}

void UGameTagCheckTool::Tick(float DeltaTime)
{
     OnUpdated.Broadcast();

     //checking if we have recieved any tag that has increased count - if yes, then destroy listener
    if (NumOfTags < ActorToCheckTag->Tags.Num())
    {
        bShouldTick = false;
        OnFinished.Broadcast();
        SetReadyToDestroy();
    }

    //adjusting num of tag , incase target actor deletes tag
    if (ActorToCheckTag && NumOfTags > ActorToCheckTag->Tags.Num()) {
        NumOfTags = ActorToCheckTag->Tags.Num();
    }
}
