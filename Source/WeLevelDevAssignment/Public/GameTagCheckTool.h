#pragma once
#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GameTagCheckTool.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinished);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpdated);

UCLASS()
class WELEVELDEVASSIGNMENT_API UGameTagCheckTool : public UBlueprintAsyncActionBase, public FTickableGameObject
{
public:
    virtual void Tick(float DeltaTime) override;
    virtual TStatId GetStatId() const override;
    virtual bool IsTickable() const override;
private:

    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FOnFinished OnFinished;

    UPROPERTY(BlueprintAssignable)
    FOnUpdated OnUpdated;


    UPROPERTY()
        AActor* ActorToCheckTag = nullptr;

    UPROPERTY()
        int32 NumOfTags=0;



    virtual void Activate() override;

  
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "Flow Control")
        static UGameTagCheckTool* GameTagCheckTool(AActor* ActorToCheck);


private:
    bool bShouldTick = false;

};


