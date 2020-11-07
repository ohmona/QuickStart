// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

UCLASS()
class QUICKSTART_API ACameraDirector : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACameraDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
	Note : The UPROPERTY macro makes this variable visible to Unreal Engine.
	In this way, the value set for this variable will not be reset if
	you run the game or reload the level or project during future work.
	And the EditAnywhere keyword will allow you to configure
	CameraOne and CameraTwo in Unreal Editor.
	*/
	UPROPERTY(EditAnywhere)
		AActor* CameraOne;

	UPROPERTY(EditAnywhere)
		AActor* CameraTwo;

	float TimeToNextCameraChange;

	bool CameraSwitchTrigger = true;
};