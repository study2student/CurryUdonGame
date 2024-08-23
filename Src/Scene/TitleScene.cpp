#include <DxLib.h>
#include "../Application.h"
#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include "TitleScene.h"

TitleScene::TitleScene(void)
{
}

TitleScene::~TitleScene(void)
{
}

void TitleScene::Init(void)
{
	std::string basePath = Application::PATH_IMAGE;
	title_ = LoadGraph((basePath + "Title.png").c_str());
	tutorial_ = LoadGraph((basePath + "Tutorial.png").c_str());
}

void TitleScene::Update(void)
{
	InputManager& ins = InputManager::GetInstance();
	if (ins.IsTrgDown(KEY_INPUT_RETURN) || static_cast<bool>(GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B))
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::GAME);
	}
}

void TitleScene::Draw(void)
{
	DrawFormatString(100, 100, 0xff0000, "Title");
	DrawExtendGraph(0, 0, Application::SCREEN_SIZE_X, Application::SCREEN_SIZE_Y, title_, true);
	DrawExtendGraph(Application::SCREEN_SIZE_X / 2, 0, Application::SCREEN_SIZE_X, Application::SCREEN_SIZE_Y, tutorial_, true);
}

void TitleScene::Release(void)
{
}
