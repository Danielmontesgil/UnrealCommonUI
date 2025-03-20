// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Stealth/StealthGameMode.h"
#include "StealthGameGameMode.generated.h"

/**
 * 
 */
UCLASS()
class STEALTH_API AStealthGameGameMode : public AStealthGameMode
{
	GENERATED_BODY()

	void BeginPlay() override;
};
