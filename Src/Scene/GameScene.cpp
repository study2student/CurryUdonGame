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

	LoadUI();

	LoadIMG();

	dirtState_ = DIRT_STATE::WHITE;

	//ゲージ割合
	gaugePercent_ = 0.0f;

	//クール中フラグ
	isCool_ = false;

	//うどん絵
	UdonIMG_ = LoadGraph((basePath + "UdonMax.png").c_str());
	UdonNullIMG_ = LoadGraph((basePath + "UdonNull.png").c_str());
	noodleIMG_ = LoadGraph((basePath + "UdonAlpha1.png").c_str());
	noodlePos_ = { Application::SCREEN_SIZE_X / 2,Application::SCREEN_SIZE_Y };

	// 箸の絵
	sticksIMG_ = LoadGraph((basePath + "ChopSticks.png").c_str());
	sticksPos_ = { Application::SCREEN_SIZE_X / 2 + 150,Application::SCREEN_SIZE_Y };

	// ゲームスタート時のカウント
	startCount_ = 3.0f;
	isStart_ = false;
	imgCount_ = 1.0f;
	isImg_ = false;

	//スコアのリセット
	rash_.ResetScore();
}

void GameScene::Update(void)
{
	InputManager& ins = InputManager::GetInstance();
	if (ins.IsTrgDown(KEY_INPUT_SPACE) || static_cast<bool>(GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)
		|| time_ == 0)
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::RESULT);
	}


	// スタート時のカウントダウンを減らす
	if (startCount_ >= 0.0f)
	{
		startCount_ -= SceneManager::GetInstance().GetDeltaTime();
	}

	if (isImg_ == true)
	{
		if (imgCount_ >= 0.0f)
		{
			imgCount_ -= SceneManager::GetInstance().GetDeltaTime();
		}
	}


	if (imgCount_ <= 0.0f)
	{
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

		//if (noodlePos_.y <= -384)
		//{
		//	noodlePos_.y = Application::SCREEN_SIZE_Y;
		//	sticksPos_.y = Application::SCREEN_SIZE_Y;

		if (noodlePos_.y <= -40)
		{
			noodlePos_.y = Application::SCREEN_SIZE_Y;
			sticksPos_.y = Application::SCREEN_SIZE_Y;

			//うどんのmennの座標を可変

			//noodlePos_.y -= 20;
			//sticksPos_.y -= 20;

			//if (noodlePos_.y <= -384)
			//{
			//	noodlePos_.y = Application::SCREEN_SIZE_Y;
			//	sticksPos_.y = Application::SCREEN_SIZE_Y;
			//}
		}
	}
}


void GameScene::Draw(void)
{
	int font = CreateFontToHandle("Gill Sans MT", 30, 8, DX_FONTTYPE_EDGE);
	SetFontSize(40);
	ChangeFont("Paintball_Beta", DX_CHARSET_DEFAULT);
	
	DrawUI();

	//tシャツの描画
	DrawTshirts();

	// ゲージ描画
	DrawGauge();

	//うどんの描画
	DrawUdon();

	// スタート時のカウントを減らす
	if (startCount_ > 0.0f)
	{
		DrawExtendFormatString(Application::SCREEN_SIZE_X / 2 - 50 - GetDrawFormatStringWidth("%.f"), Application::SCREEN_SIZE_Y / 2 - 95, 5, 5, 0xff0000, "%.f", startCount_);
	}
	if (startCount_ <= 0.0f)
	{
		isImg_ = true;
	}

	if (isImg_)
	{
		if (imgCount_ > 0.0f)
		{
			DrawRotaGraph(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2, START_END_REDUCTION, 0.0f, startImg_, true);
		}
	}

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
	VECTOR g = { 50,200 };
	VECTOR h = { g.x + 50, g.y + GAUGE_MAX };

	//DrawBox(g.x, h.y, h.x, h.y + (-gaugeLen_ * GAUGE_INC)/ GAUGE_MAX, 0xff0000, true);


	DrawBox(g.x, h.y, h.x, h.y - gaugePercent_ * GAUGE_MAX, 0xff0000, true);


	DrawBoxAA(g.x, g.y, h.x, h.y, 0xffffff, false, 8);





	//DrawBox(sc_x, sc_y, sc_x + (bikes_[playerID]->GetHP() * HP_BAR_WIDTH) / Bike::MAX_HP, HP_BAR_HEIGHT, 0x00aeef, true); // HPバー

}

void GameScene::LoadUI(void)
{
	//スコア背景
	backScore_ = LoadGraph((basePath + "ヨゴレド.png").c_str());

	//時間画像
	timeImg_ = LoadGraph((basePath + "Time.png").c_str());

	//スタート画像
	startImg_ = LoadGraph((basePath + "Count.png").c_str());

	//終わり画像
	endImg_ = LoadGraph((basePath + "End.png").c_str());
}

void GameScene::DrawUI(void)
{
	//スコア描画
	DrawRotaGraphFast(Application::SCREEN_SIZE_X / 2, Application::SCREEN_SIZE_Y / 2 - 100, 0.15, 0.0f, backScore_, true);
	if (!(rash_.GetScore() == 0))
	{
		DrawExtendFormatString(Application::SCREEN_SIZE_X / 2 - GetDrawFormatStringWidth("%d") / 2 - 80, Application::SCREEN_SIZE_Y / 2 - GetDrawFormatStringWidth("%d") / 2, 5, 5, 0xff0000, "%d", rash_.GetScore());
	}

	//残り時間
	DrawExtendGraph(20, 0, 250, 360, timeImg_, true);
	DrawExtendFormatString(5,80, 2.2, 2.2, 0xff0000, "%.1f", time_);


}

void GameScene::UIUpdate(void)
{
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
	DrawRectGraph(
		Application::SCREEN_SIZE_X / 2 - UDON_SIZE_.x/2
		, Application::SCREEN_SIZE_Y /2 - UDON_SIZE_.y / 2+50
		,noodlePos_.x-500, -noodlePos_.y+200
		,UDON_SIZE_.x
		,UDON_SIZE_.y
		, noodleIMG_, true
		,false
		,false);
	//DrawGraph(0, 0, noodleIMG_, true);
	//for (int i = 0; i <= 500; i += 10)
	//{
	//	DrawExtendGraph(noodlePos_.x / 2, noodlePos_.y / 2, noodlePos_.x + (noodlePos_.x / 2), noodlePos_.y, noodleIMG_, true);
	//}
	DrawRotaGraphFast(sticksPos_.x-30, sticksPos_.y, 0.1, 0, sticksIMG_, true);
}
