#include <DxLib.h>
#include "../Application.h"
#include "../Manager/SceneManager.h"
#include "TshirtsState.h"
#include "../Common/Vector2.h"

TshirtsState* TshirtsState::instance_ = nullptr;

void TshirtsState::CreateInstance(void)
{
	if (instance_ == nullptr)
	{
		instance_ = new TshirtsState();
	}
	instance_->Init();
}

TshirtsState& TshirtsState::GetInstance(void)
{
    // TODO: return ステートメントをここに挿入します
	return *instance_;
}

void TshirtsState::Init(void)
{
}

void TshirtsState::AddScore(int score)
{
}

void TshirtsState::StateSet(DIRT_STATE stateSet)
{
	dirtState_ = stateSet;
}

const int TshirtsState::GetState(void) const
{
	return (int)dirtState_;
}


void TshirtsState::ResetState(void)
{
	dirtState_ = DIRT_STATE::WHITE;
}

void TshirtsState::LoadIMG(void)
{
	std::string basePath = Application::PATH_IMAGE;
	TshirtsWhite_ = LoadGraph((basePath + "TShirtsWhite.png").c_str());
	TshirtsLow_ = LoadGraph((basePath + "TShirtsLow.png").c_str());
	TshirtsMiddle_ = LoadGraph((basePath + "TShirtsMiddle.png").c_str());
	TshirtsHigh_ = LoadGraph((basePath + "TShirtsHigh.png").c_str());
	TshirtsMax_ = LoadGraph((basePath + "TShirtsCurry.png").c_str());
}

void TshirtsState::DrawTshirts(void)
{
	
	if (SceneManager::GetInstance().GetSceneID() == SceneManager::SCENE_ID::GAME)
	{
		Vector2 pos = { Application::SCREEN_SIZE_X - 100, 100 };

		switch (dirtState_)
		{
		case DIRT_STATE::WHITE:
		{
			DrawRotaGraphFast(pos.x, pos.y, UI_REDUCTION, 0, TshirtsWhite_, true);
		}
		break;
		case DIRT_STATE::LOW:
		{
			DrawRotaGraphFast(pos.x, pos.y, UI_REDUCTION, 0, TshirtsLow_, true);
		}
		break;
		case DIRT_STATE::MIDDLE:
		{
			DrawRotaGraphFast(pos.x, pos.y, UI_REDUCTION, 0, TshirtsMiddle_, true);
		}
		break;
		case DIRT_STATE::HIGH:
		{
			DrawRotaGraphFast(pos.x, pos.y, UI_REDUCTION, 0, TshirtsHigh_, true);
		}
		break;
		case DIRT_STATE::MAX:
		{
			DrawRotaGraphFast(pos.x, pos.y, UI_REDUCTION, 0, TshirtsMax_, true);
		}
		break;
		}
	}

	if (SceneManager::GetInstance().GetSceneID() == SceneManager::SCENE_ID::RESULT)
	{
		Vector2 pos = { Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 - 100 };

		float i = 0.12;

		switch (dirtState_)
		{
		case DIRT_STATE::WHITE:
		{
			DrawRotaGraphFast(pos.x, pos.y, i, 0, TshirtsWhite_, true);
		}
		break;
		case DIRT_STATE::LOW:
		{
			DrawRotaGraphFast(pos.x, pos.y, i, 0, TshirtsLow_, true);
		}
		break;
		case DIRT_STATE::MIDDLE:
		{
			DrawRotaGraphFast(pos.x, pos.y, i, 0, TshirtsMiddle_, true);
		}
		break;
		case DIRT_STATE::HIGH:
		{
			DrawRotaGraphFast(pos.x, pos.y, i, 0, TshirtsHigh_, true);
		}
		break;
		case DIRT_STATE::MAX:
		{
			DrawRotaGraphFast(pos.x, pos.y, i, 0, TshirtsMax_, true);
		}
		break;
		}
	}
}
