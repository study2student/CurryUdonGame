#include <DxLib.h>
#include "../Application.h"
#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include "GameScene.h"

GameScene::GameScene(void)
{
}

GameScene::~GameScene(void)
{
}

void GameScene::Init(void)
{
	//�A�Ő�
	rash_ = 0; 
	//����
	time_ = 15.0f;
	//�Q�[�W�̒���
	gaugeLen_ = 0.0f;
<<<<<<< Updated upstream

	LoadIMG();

	dirtState_ = DIRT_STATE::WHITE;
=======
	//�Q�[�W����
	gaugePercent_ = 0.0f;

	//�N�[�����t���O
	isCool_ = false;

>>>>>>> Stashed changes
}

void GameScene::Update(void)
{
<<<<<<< Updated upstream
	InputManager& ins = InputManager::GetInstance();
	if (ins.IsTrgDown(KEY_INPUT_SPACE) || static_cast<bool>(GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B))
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::TITLE);
	}

	//�Q�[�W���}�b�N�X�ɂȂ�����A�łł��Ȃ��悤�ɂ���
	if (gaugeLen_ <= GAUGE_MAX)
	{
		if (ins.IsTrgDown(KEY_INPUT_RETURN))
		{
			rash_++;
			gaugeLen_ ++;
		}
	}

	//�A�Ő��ɂ����T�V���c���ς��悤��
	if (rash_ >= 10)
	{
		dirtState_ = DIRT_STATE::LOW;
	}
	if (rash_ >= 30)
	{
		dirtState_ = DIRT_STATE::MIDDLE;
	}
	if (rash_ >= 50)
	{
		dirtState_ = DIRT_STATE::HIGH;
	}
	if (rash_ >= 70)
	{
		dirtState_ = DIRT_STATE::MAX;
	}

=======
	GaugeUpdate();
	
>>>>>>> Stashed changes
	//���Ԃ����炷
	if (time_ <= 0.0f)
	{
		time_ = 0.0f;
	}
	else
	{
		time_ -= 1 / 60.0f;
	}

}

void GameScene::Draw(void)
{
	DrawFormatString(100, 100, 0xff0000, "Game");
	DrawFormatString(300, 300, 0xff0000, "ENTER:%d", rash_);

	//����
	DrawFormatString(300, 200, 0xff0000, "TIME:%.f", time_);

	//test
	DrawString(50, 50, "test", 0x000000);

	//t�V���c�̕`��
	DrawTshirts();

	// �Q�[�W�`��
	DrawGauge();
}

void GameScene::Release(void)
{
}

void GameScene::GaugeUpdate(void)
{
	InputManager& ins = InputManager::GetInstance();

	//�������v�Z����
	gaugePercent_ = gaugeLen_ / RUSHGAUGE_MAX;
	if (gaugePercent_ >= 0.0f)
	{
		gaugeLen_ -= GAUGE_DECREASE;
	}
	if (ins.IsTrgDown(KEY_INPUT_SPACE) || static_cast<bool>(GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B))
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::TITLE);
	}

	//�Q�[�W���}�b�N�X�ɂȂ�����A�łł��Ȃ��悤�ɂ���
	if (gaugePercent_ < PERCENT_MAX)
	{
		if (ins.IsTrgDown(KEY_INPUT_RETURN) && gaugeLen_ <= GAUGE_MAX)
		{
			rash_++;
			gaugeLen_++;
		}
	}
	else
	{
		isCool_ = true;
	}



}

void GameScene::DrawGauge(void)
{
	// �Q�[�W�̍��W,��
	VECTOR g = { 200,100 };
	VECTOR h = { g.x + 50, g.y + GAUGE_MAX };

	//DrawBox(g.x, h.y, h.x, h.y + (-gaugeLen_ * GAUGE_INC)/ GAUGE_MAX, 0xff0000, true);
	DrawBox(g.x, h.y, h.x, h.y - gaugePercent_*GAUGE_MAX, 0xff0000, true);
	DrawBoxAA(g.x, g.y, h.x, h.y, 0xffffff, false, 5
	);
	
	//DrawBox(sc_x, sc_y, sc_x + (bikes_[playerID]->GetHP() * HP_BAR_WIDTH) / Bike::MAX_HP, HP_BAR_HEIGHT, 0x00aeef, true); // HP�o�[

}

void GameScene::LoadIMG(void)
{
	std::string basePath = Application::PATH_IMAGE;

	TshirtsWhite_ = LoadGraph((basePath + "TShirtsWhite.png").c_str());
	TshirtsLow_ = LoadGraph((basePath + "TShirtsLow.png").c_str());
	TshirtsMiddle_ = LoadGraph((basePath + "TShirtsMiddle.png").c_str());
	TshirtsHigh_ = LoadGraph((basePath + "TShirtsHigh.png").c_str());
	TshirtsMax_ = LoadGraph((basePath + "TShirtsCurry.png").c_str());
}

void GameScene::DrawTshirts(void)
{

	switch (dirtState_)
	{
	case DIRT_STATE::WHITE:
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2, 0.07, 0, TshirtsWhite_, true);
	}
	break;
	case DIRT_STATE::LOW:
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2, 0.07, 0, TshirtsLow_, true);
	}
	break;
	case DIRT_STATE::MIDDLE:
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2, 0.07, 0, TshirtsMiddle_, true);
	}
	break;
	case DIRT_STATE::HIGH:
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2, 0.07, 0, TshirtsHigh_, true);
	}
	break;
	case DIRT_STATE::MAX:
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2, 0.07, 0, TshirtsMax_, true);
	}
	break;
	}
}