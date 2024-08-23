#pragma once
class TshirtsState
{
public:
	// 明示的にインステンスを生成する
	static void CreateInstance(void);

	// 静的インスタンスの取得
	static TshirtsState& GetInstance(void);

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


	//UIの縮小値
	static constexpr float UI_REDUCTION = 0.05f;

	void Init(void);

	//スコア加算
	void AddScore(int score);

	void StateSet(DIRT_STATE stateSet);

	const int GetState(void) const;

	void ResetState(void);

	//Tシャツの画像をロード
	void LoadIMG(void);

	//Tshirts描画
	void DrawTshirts(void);
private:
	// 静的インスタンス
	static TshirtsState* instance_;

	//Tシャツの画像
	int Tshirts_;
	int TshirtsWhite_;
	int TshirtsLow_;
	int TshirtsMiddle_;
	int TshirtsHigh_;
	int TshirtsMax_;


	// Tシャツの汚れ状態
	DIRT_STATE dirtState_;

};

