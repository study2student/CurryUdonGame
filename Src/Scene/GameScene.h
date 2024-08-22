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

	//ゲージの描画
	void DrawGauge(void);

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
};

