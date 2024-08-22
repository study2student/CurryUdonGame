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
};

