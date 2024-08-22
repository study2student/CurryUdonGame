#include <DxLib.h>
#include "../Application.h"
#include "../Score/Rash.h"
#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include "GameScene.h"

std::string basePath = Application::PATH_IMAGE;

GameScene::GameScene(void)
{
}

GameScene::~GameScene(void)
{
}

void GameScene::Init(void)
{

	std::string basePath = Application::PATH_IMAGE;
	std::string fontPath = Application::PATH_FONT;

	//連打数
	//スコアのリセット
	rash_.ResetScore();

	//時間
	time_ = 15.0f;
	//ゲージの長さ
	gaugeLen_ = 0.0f;

	//ゲージ最大になった時のクールタイムフラグ
	isCool_ = false;

	LoadIMG();

	dirtState_ = DIRT_STATE::WHITE;

	//ゲージ割合
	gaugePercent_ = 0.0f;

	//クール中フラグ
	isCool_ = false;

	//うどん絵
	UdonIMG_ = LoadGraph((basePath + "UdonMax.png").c_str());
	UdonNullIMG_ = LoadGraph((basePath + "UdonNull.png").c_str());
	noodleIMG_ = LoadGraph((basePath + "Udon1.png").c_str());
	noodlePos_ = { Application::SCREEN_SIZE_X / 2,Application::SCREEN_SIZE_Y };

	// 箸の絵
	sticksIMG_ = LoadGraph((basePath + "ChopSticks.png").c_str());
	sticksPos_ = { Application::SCREEN_SIZE_X / 2 + 150,Application::SCREEN_SIZE_Y };

	//スコアのリセット
	rash_.ResetScore();
}

void GameScene::Update(void)
{
	InputManager& ins = InputManager::GetInstance();
	if (ins.IsTrgDown(KEY_INPUT_SPACE) || static_cast<bool>(GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B))
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::TITLE);
	}
	//連打数によってTシャツが変わるように
	if (rash_.GetScore() >= 10)
	{
		dirtState_ = DIRT_STATE::LOW;
	}
	if (rash_.GetScore() >= 30)
	{
		dirtState_ = DIRT_STATE::MIDDLE;
	}
	if (rash_.GetScore() >= 50)
	{
		dirtState_ = DIRT_STATE::HIGH;
	}
	if (rash_.GetScore() >= 70)
	{
		dirtState_ = DIRT_STATE::MAX;
	}

	GaugeUpdate();
	

	//時間を減らす
	if (time_ <= 0.0f)
	{
		time_ = 0.0f;
	}
	else
	{
		time_ -= 1 / 60.0f;
	}


	//うどんのmennの座標を可変

	noodlePos_.y -= 20;
	sticksPos_.y -= 20;

	if (noodlePos_.y <= -384)
	{
		noodlePos_.y = Application::SCREEN_SIZE_Y;
		sticksPos_.y = Application::SCREEN_SIZE_Y;
	}
}

void GameScene::Draw(void)
{
	int font = CreateFontToHandle("Gill Sans MT", 30, 8, DX_FONTTYPE_EDGE);
	SetFontSize(40);
	ChangeFont("Paintball_Beta", DX_CHARSET_DEFAULT);
	DrawFormatString(100, 100, 0xff0000, "Game");


	//時間
	DrawFormatString(300, 200, 0xff0000, "TIME:%.f", time_);

	//test
	DrawString(50, 50, "test", 0x000000);


	//tシャツの描画
	DrawTshirts();

	// ゲージ描画
	DrawGauge();

	//うどんの描画
	DrawUdon();


	//時間
	DrawFormatString(10, 10, 0xff0000, "TIME:%.f", time_);

	DrawFormatString(300, 0, 0xff0000, "ENTER:%d", rash_.GetScore());


}

void GameScene::Release(void)
{
	DeleteGraph(noodleIMG_);
}

void GameScene::GaugeUpdate(void)
{
	InputManager& ins = InputManager::GetInstance();
	GaugeLimit();
	//割合を計算する
	gaugePercent_ = gaugeLen_ / RUSHGAUGE_MAX;
	
	if (gaugePercent_ > 0.0f&&pushStopCnt_>= PUSH_STOP_MAX)
	{
		gaugeLen_ -= GAUGE_DECREASE;
	}

	if (ins.IsTrgDown(KEY_INPUT_SPACE) || static_cast<bool>(GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B))
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::RESULT);
	}


	//ゲージがマックスになったら連打できないようにする
	if (gaugePercent_ <= PERCENT_MAX)
	{
		if (ins.IsTrgDown(KEY_INPUT_RETURN))
		{

			RashUpdate();

		}
		else
		{
			pushStopCnt_++;
		}
	}



}

void GameScene::RashUpdate(void)
{
	if (!isCool_)
	{
		rash_.AddScore(1);
		gaugeLen_++;
		pushStopCnt_ = 0;
	}
	
}

void GameScene::DrawGauge(void)
{
	// ゲージの座標,幅
	VECTOR g = { 50,150 };
	VECTOR h = { g.x + 50, g.y + GAUGE_MAX };

	//DrawBox(g.x, h.y, h.x, h.y + (-gaugeLen_ * GAUGE_INC)/ GAUGE_MAX, 0xff0000, true);


	DrawBox(g.x, h.y, h.x, h.y - gaugePercent_ * GAUGE_MAX, 0xff0000, true);


	DrawBoxAA(g.x, g.y, h.x, h.y, 0xffffff, false, 8);





	//DrawBox(sc_x, sc_y, sc_x + (bikes_[playerID]->GetHP() * HP_BAR_WIDTH) / Bike::MAX_HP, HP_BAR_HEIGHT, 0x00aeef, true); // HPバー

}

void GameScene::GaugeLimit(void)
{
	//ゲージ上限
	if (gaugePercent_ > PERCENT_MAX)
	{
		gaugePercent_ = PERCENT_MAX;
		gaugeLen_ = RUSHGAUGE_MAX;
	}
	if (gaugePercent_ >= PERCENT_MAX)
	{
		isCool_ = true;
	}
	//ゲージ下限
	else if (gaugePercent_ < 0.0f)
	{
		gaugePercent_ = 0.0f;
		gaugeLen_ = 0.0f;
	}
	if (gaugePercent_ <= 0.0f)
	{
		isCool_ = false;
	}
}

void GameScene::LoadIMG(void)
{

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
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 - 100, 0.2, 0, TshirtsWhite_, true);
	}
	break;
	case DIRT_STATE::LOW:
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 - 100, 0.2, 0, TshirtsLow_, true);
	}
	break;
	case DIRT_STATE::MIDDLE:
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 - 100, 0.2, 0, TshirtsMiddle_, true);
	}
	break;
	case DIRT_STATE::HIGH:
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 - 100, 0.2, 0, TshirtsHigh_, true);
	}
	break;
	case DIRT_STATE::MAX:
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 - 100, 0.2, 0, TshirtsMax_, true);
	}
	break;
	}
}

void GameScene::DrawUdon(void)
{
	//うどんの描画
	if (rash_.GetScore() <= 70)
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 + 200, 0.4, 0, UdonIMG_, true);
	}
	else
	{
		DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 + 200, 0.4, 0, UdonNullIMG_, true);
	}
	//うどんのmennの描画
	DrawRotaGraphFast(noodlePos_.x, noodlePos_.y, 0.18, 0, noodleIMG_, true);
	//for (int i = 0; i <= 500; i += 10)
	//{
	//	DrawExtendGraph(noodlePos_.x / 2, noodlePos_.y / 2, noodlePos_.x + (noodlePos_.x / 2), noodlePos_.y, noodleIMG_, true);
	//}
	DrawRotaGraphFast(sticksPos_.x, sticksPos_.y, 0.1, 0, sticksIMG_, true);
}
