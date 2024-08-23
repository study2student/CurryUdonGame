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
}

void TitleScene::Release(void)
{
}
