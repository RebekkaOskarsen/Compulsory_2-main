// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameController.generated.h"

class AAlienShip;

UCLASS()
class COMPULSORY_2_API AGameController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
        UStaticMeshComponent* StaticMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
        TArray<int> WaveDifficulty;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
        TArray<int> WaveSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
        TArray<int> WaveSpawnFrequency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
        float MinX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
        float MaxX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
        float MinY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
        float MaxY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
        int CurrentWave;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
        TSubclassOf<AAlienShip> BP_AlienShip;

private:
    int LeftToSpawn;
    float Clock;
    bool GameWon;

    void ChangeWave(int wave);
};
