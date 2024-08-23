#include <DxLib.h>
#include "../Application.h"
#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include "../Score/Rash.h"
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
}

void ResultScene::Update(void)
{
	InputManager& ins = InputManager::GetInstance();
	if (ins.IsTrgDown(KEY_INPUT_SPACE) || static_cast<bool>(GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B))
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::TITLE);
	}
}

void ResultScene::Draw(void)
{
	//DrawGraph(0, 0, resultImg_, true);
	DrawExtendGraph(0, 0, Application::SCREEN_SIZE_X, Application::SCREEN_SIZE_Y, resultImg_, true);
	//DrawFormatString(300, 300, 0xff0000, "rash:%d", rash_.GetScore());
	DrawExtendFormatString(200, 100, 12, 12, 0xff0000, "%d", rash_.GetScore());
}

void ResultScene::Release(void)
{
	DeleteGraph(resultImg_);
}
