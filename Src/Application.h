#pragma once
#include <string>

class Application
{

public:

	// スクリーンサイズ
	static constexpr int SCREEN_SIZE_X = 1024;
	static constexpr int SCREEN_SIZE_Y = 640;

	//設定フレームレート
	static constexpr float FRAME_RATE = (1000 / 60);


	// データパス関連
	//-------------------------------------------
	static const std::string PATH_IMAGE;
	static const std::string PATH_FONT;
	static const std::string PATH_MODEL;
	static const std::string PATH_BGM;
	static const std::string PATH_SE;
	static const std::string PATH_EFFECT;
	//-------------------------------------------

	// 明示的にインステンスを生成する
	static void CreateInstance(void);

	// 静的インスタンスの取得
	static Application& GetInstance(void);

	// 初期化
	void Init(void);

	// ゲームループの開始
	void Run(void);

	// 解放処理
	bool Release(void);

	// リソースの破棄
	void Destroy(void);

	// 初期化成功／失敗の判定
	bool IsInitFail(void) const;

	// 解放成功／失敗の判定
	bool IsReleaseFail(void) const;

private:

	// 静的インスタンス
	static Application* instance_;

	// 初期化失敗
	bool isInitFail_;

	// 解放失敗
	bool isReleaseFail_;

	// デフォルトコンストラクタをprivateにして、
	// 外部から生成できない様にする
	Application(void);
	Application(const Application& manager) = default;
	~Application(void) = default;

	// Effekseerの初期化
	void InitEffekseer(void);


	int currentTime = 0;			//現在の時間
	int lastFrameTime = 0;			//前回のフレーム実行時の時間

	int frameCnt = 0;				//フレームカウント用
	int updateFrameRateTime = 0;	//フレームレートを更新した時間

	float frameRate = 0.f;			//フレームレート(表示用)

	//フレームレート計算
	void CalcFrameRate();

	// フレームレート表示用(デバッグ)
	void DrawFrameRate();
};
