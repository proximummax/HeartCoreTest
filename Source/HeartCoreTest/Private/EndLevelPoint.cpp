// Fill out your copyright notice in the Description page of Project Settings.


#include "EndLevelPoint.h"

AEndLevelPoint::AEndLevelPoint()
{
    OnActorBeginOverlap.AddDynamic(this, &AEndLevelPoint::OnOverlapBegin);
}

void AEndLevelPoint::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this))
    {
        GameMode = Cast< AHeartCoreTestGameModeBase>(GetWorld()->GetAuthGameMode());
        GameMode->EndRound(OtherActor);
        
    }
}