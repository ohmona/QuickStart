// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (CameraSwitchTrigger == true) {
        //This code switches the view of the default player between the two cameras every 3 seconds.
        const float TimeBetweenCameraChanges = 2.0f;
        const float SmoothBlendTime = 0.75f;
        TimeToNextCameraChange -= DeltaTime;
        if (TimeToNextCameraChange <= 0.0f)
        {
            TimeToNextCameraChange += TimeBetweenCameraChanges;

            // Find the actors that handle control of the local player.
            APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
            if (OurPlayerController)
            {
                if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
                {
                    // Immediately cut into camera #1.
                    OurPlayerController->SetViewTarget(CameraOne);
                }
                else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
                {
                    // Switch smoothly to camera #2.
                    OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
                }
            }
        }
    }
    else {

    }
}

