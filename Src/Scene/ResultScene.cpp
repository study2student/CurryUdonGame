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
}

void ResultScene::Draw(void)
{
	DrawGraph(0, 0, resultImg_, true);
	DrawFormatString(300, 300, 0xff0000, "rash:%d", rash_.GetScore());
}

void ResultScene::Release(void)
{
}
