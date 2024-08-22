#pragma once
#include "SceneBase.h"
class GameScene : public SceneBase
{
public:
	//定数
	//スコアマックス
	static constexpr int SCORE_MAX = 120;

	//ゲージマックス
	static constexpr int GAUGE_MAX = 200;

	//ゲージの上がり幅
	static constexpr float GAUGE_INC = 1000.0f;

<<<<<<< Updated upstream
	// Tシャツの汚れ状態
	enum  class DIRT_STATE
	{
		NONE,
		WHITE,
		LOW,
		MIDDLE,
		HIGH,
		MAX
	};
=======
	//何連打でマックスになるか
	static constexpr int RUSHGAUGE_MAX = 30;

	//割合の最大値
	static constexpr float PERCENT_MAX = 1.0f;

	//ゲージの下がり幅
	static constexpr float GAUGE_DECREASE =0.05f;
>>>>>>> Stashed changes

	// コンストラクタ
	GameScene(void);

	// デストラクタ
	~GameScene(void);

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;


private:
	// 連打数
	int rash_;

	//時間
	float time_;

	//ゲージの長さ
	float gaugeLen_;

	//ゲージの割合
	float gaugePercent_;

	//マックスになった時のクールタイム
	bool isCool_;

	//ゲージの更新
	void GaugeUpdate(void);

	//ゲージの描画
	void DrawGauge(void);

<<<<<<< Updated upstream
	//Tシャツの画像
	int Tshirts_;
	int TshirtsWhite_;
	int TshirtsLow_;
	int TshirtsMiddle_;
	int TshirtsHigh_;
	int TshirtsMax_;


	// Tシャツの汚れ状態
	DIRT_STATE dirtState_;

	//Tシャツの画像をロード
	void LoadIMG(void);

	//Tshirts描画
	void DrawTshirts(void);
=======
>>>>>>> Stashed changes
};

