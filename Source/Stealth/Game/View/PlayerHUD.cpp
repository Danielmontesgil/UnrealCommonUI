// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "PlayerHUD.h"

TOptional<FUIInputConfig> UPlayerHUD::GetDesiredInputConfig() const
{
	return FUIInputConfig(ECommonInputMode::Game, EMouseCaptureMode::CapturePermanently);
}
