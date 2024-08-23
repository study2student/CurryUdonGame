#include <DxLib.h>
#include "../Application.h"
#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include "../Score/Rash.h"
#include "../Score/TshirtsState.h"
#include "ResultScene.h"


ResultScene::ResultScene(void)
{
}

ResultScene::~ResultScene(void)
{
}

void ResultScene::Init(void)
{
	std::string basePath = Application::PATH_IMAGE;
	resultImg_ = LoadGraph((basePath + "rash.png").c_str());

	frame_ = LoadGraph((basePath + "Frame.png").c_str());

	goTitle_ = LoadGraph((basePath + "GoTitle.png").c_str());
}

void ResultScene::Update(void)
{
	InputManager& ins = InputManager::GetInstance();
	if (ins.IsTrgDown(KEY_INPUT_RETURN) || static_cast<bool>(GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B))
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::TITLE);
	}
}

void ResultScene::Draw(void)
{
	DrawExtendGraph(0, Application::SCREEN_SIZE_Y / 2 + (Application::SCREEN_SIZE_Y / 4), Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y, resultImg_, true);
	//DrawFormatString(0, 300, 0xff0000, "rash:%d", rash_.GetScore());
	DrawExtendFormatString(Application::SCREEN_SIZE_X / 3-150, Application::SCREEN_SIZE_Y / 2 + (Application::SCREEN_SIZE_Y / 4) + 30, 3, 3, 0xff0000, "%d", rash_.GetScore());
	tState_.DrawTshirts();
	//äzâè
	DrawRotaGraph(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 - 100, 0.4, 0.0, frame_, true);
	//É^ÉCÉgÉãÇ÷
	DrawExtendGraph(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 + (Application::SCREEN_SIZE_Y / 4), Application::SCREEN_SIZE_X, Application::SCREEN_SIZE_Y,
		goTitle_, true);
}

void ResultScene::Release(void)

{
	DeleteGraph(resultImg_);
}
