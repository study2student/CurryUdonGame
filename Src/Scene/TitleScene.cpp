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
	credit_ = LoadGraph((basePath + "Credit1.jpeg").c_str());

	SoundInit();

	//ゲームスタート
	start_ = LoadGraph((basePath + "GameStart.png").c_str());

}

void TitleScene::Update(void)
{
	InputManager& ins = InputManager::GetInstance();
	if (ins.IsTrgDown(KEY_INPUT_RETURN) || static_cast<bool>(GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B))
	{
		sound_->PlaySe(SoundManager::SE_TYPE::TITLE2GAME, DX_PLAYTYPE_BACK/*, SoundManager::SE_VOL*/);
		sound_->Release();
		delete sound_;
		sound_ = nullptr;
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::GAME);
	}
}

void TitleScene::Draw(void)
{
	DrawFormatString(100, 100, 0xff0000, "Title");
	DrawExtendGraph(0, 0, Application::SCREEN_SIZE_X, Application::SCREEN_SIZE_Y, title_, true);
	DrawExtendGraph(Application::SCREEN_SIZE_X / 2, 0, Application::SCREEN_SIZE_X, Application::SCREEN_SIZE_Y, tutorial_, true);

	//クレジット
	DrawExtendGraph(10, Application::SCREEN_SIZE_Y / 2 + Application::SCREEN_SIZE_Y / 8, Application::SCREEN_SIZE_X / 2 - 10, Application::SCREEN_SIZE_Y - 10,
		credit_, true);

	//ゲームスタート
	DrawExtendGraph(10, Application::SCREEN_SIZE_Y / 2 - 50, 
		Application::SCREEN_SIZE_X / 2 - 10, Application::SCREEN_SIZE_Y / 2 + Application::SCREEN_SIZE_Y / 8,
		start_, true);
	
}

void TitleScene::Release(void)
{
	DeleteGraph(title_);
	DeleteGraph(tutorial_);

}

void TitleScene::SoundInit(void)
{
	sound_ = new SoundManager();
	sound_->BGMInit();
	sound_->SEInit();
	sound_->LoadBgm(SoundManager::BGM_TYPE::TITLE);
	sound_->LoadSe(SoundManager::SE_TYPE::TITLE2GAME);
	sound_->PlayBgm(SoundManager::BGM_TYPE::TITLE, DX_PLAYTYPE_LOOP, 40);
}
