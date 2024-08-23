#pragma once
#include "SceneBase.h"
class GameScene : public SceneBase
{
public:
	//定数
	//スコアマックス
	static constexpr int SCORE_MAX = 120;

	//ゲージマックス
	static constexpr int GAUGE_MAX = 250;

	//ゲージの上がり幅
	static constexpr float GAUGE_INC = 1000.0f;

	//連打ストップカウントマックス
	static constexpr int PUSH_STOP_MAX = 60;

	//スタートと終了画像の縮小値
	static constexpr float START_END_REDUCTION = 0.1f;

	//UIの縮小値
	static constexpr float UI_REDUCTION = 0.05f;

	//画像サイズ
	static constexpr VECTOR IMAGE_SIZE_ = { 4096,3072 };

	//うどんサイズ
	static constexpr VECTOR UDON_SIZE_ = { 737,552 };


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
	//何連打でマックスになるか
	static constexpr int RUSHGAUGE_MAX = 30;

	//割合の最大値
	static constexpr float PERCENT_MAX = 1.0f;

	//ゲージの下がり幅
	static constexpr float GAUGE_DECREASE =0.5f;

	// コンストラクタ
	GameScene(void);

	// デストラクタ
	~GameScene(void);

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;


private:
	// ゲームスタート時のカウント
	float startCount_;
	// スタートフラグ
	bool isStart_;

	// よーい初めの描画カウント,フラグ
	float imgCount_;
	bool isImg_;


#pragma region 連打ゲージ関連

	// 連打数
	//int rash_;

	//時間
	float time_;

	//ゲージの長さ
	float gaugeLen_;

	//ゲージの割合
	float gaugePercent_;

	//マックスになった時のクールタイム
	bool isCool_;

	//連打が止まったカウント
	int pushStopCnt_;

	//ゲージの更新
	void GaugeUpdate(void);

	//ゲージの下限と上限
	void GaugeLimit(void);

	//連打数処理
	void RashUpdate(void);
	//ゲージの描画
	void DrawGauge(void);

#pragma endregion
#pragma region UI
	//スコアの背景
	int backScore_;

	//残り時間画像
	int timeImg_;

	//スタート画像
	int startImg_;

	//終わり画像
	int endImg_;

	//UI画像のロード
	void LoadUI(void);

	//UI画像の描画
	void DrawUI(void);

	//UI更新処理
	void UIUpdate(void);
#pragma endregion


#pragma region 描画関係

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

	//うどんの皿
	int UdonIMG_;

	//空のうどん
	int UdonNullIMG_;

	//うどんのmenn
	int noodleIMG_;
	//うどんの座標
	VECTOR noodlePos_;

	//うどんの描画
	void DrawUdon(void);
#pragma endregion



	// 箸の絵,座標
	int sticksIMG_;
	VECTOR sticksPos_;
};

