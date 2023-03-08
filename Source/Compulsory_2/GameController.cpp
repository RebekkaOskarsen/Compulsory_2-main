// Fill out your copyright notice in the Description page of Project Settings.


#include "GameController.h"
#include "AlienShip.h"

// Sets default values
AGameController::AGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(GetRootComponent());
    StaticMesh->SetRelativeScale3D(FVector(0.1f, 1.f, 1.f));
    StaticMesh->SetRelativeLocation(FVector(0.f, 0.f, -50.f));

    WaveSize.Add(10);
    WaveSize.Add(15);
    WaveSize.Add(20);

    WaveDifficulty.Add(0.5);
    WaveDifficulty.Add(1);
    WaveDifficulty.Add(2);

    WaveSpawnFrequency.Add(2);
    WaveSpawnFrequency.Add(1);
    WaveSpawnFrequency.Add(0.5f);

    MinX = 2000;
    MaxX = 2200;

    MinY = -400;
    MaxY = 400;
    GameWon = false;

}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
	Super::BeginPlay();

    CurrentWave = 1;
    LeftToSpawn = WaveSize[CurrentWave - 1];
}

// Called every frame
void AGameController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Clock += DeltaTime;

    if (Clock > WaveSpawnFrequency[CurrentWave - 1] && !GameWon)
    {
        Clock = 0.f;
        FVector location = FVector(FMath::RandRange(MinX, MaxX), FMath::RandRange(MinY, MaxY), 80);

        //Spawning
        AActor* Actor = GetWorld()->SpawnActor<AActor>(BP_AlienShip, location, FRotator::ZeroRotator);
        AAlienShip* AlienShip = Cast<AAlienShip>(Actor);
        AlienShip->MovementSpeed += WaveDifficulty[CurrentWave - 1];
        LeftToSpawn--;
        if (LeftToSpawn <= 0)
        {
            ChangeWave(CurrentWave + 1);
        }
    }
}

void AGameController::ChangeWave(int wave)
{
    if (WaveSize.Num() < wave)
    {
        //game won
        GameWon = true;
        return;
    }
    CurrentWave++;
    LeftToSpawn = WaveSize[CurrentWave - 1];
}