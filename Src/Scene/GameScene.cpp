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
}

void GameScene::Update(void)
{
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


	// �Q�[�W�`��
	DrawGauge();
}

void GameScene::Release(void)
{
}

void GameScene::DrawGauge(void)
{
	// �Q�[�W�̍��W,��
	VECTOR g = { 200,100 };
	VECTOR h = { g.x + 50, g.y + GAUGE_MAX };

	DrawBox(g.x, h.y, h.x, h.y + (-gaugeLen_ * GAUGE_INC)/ GAUGE_MAX, 0xff0000, true);
	DrawBoxAA(g.x, g.y, h.x, h.y, 0xffffff, false,10);
	//DrawBox(sc_x, sc_y, sc_x + (bikes_[playerID]->GetHP() * HP_BAR_WIDTH) / Bike::MAX_HP, HP_BAR_HEIGHT, 0x00aeef, true); // HP�o�[

}
