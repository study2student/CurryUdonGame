#pragma once
#include "SceneBase.h"
#include "../Manager/SoundManager.h"
class SoundManager;
class TitleScene : public SceneBase
{

public:
	// コンストラクタ
	TitleScene(void);

	// デストラクタ
	~TitleScene(void);

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;


private:
	//ポインタ
	SoundManager* sound_;
	//タイトル画像
	int title_;
	//遊び方画像
	int tutorial_;

	//クレジット
	int credit_;


	//音関係の初期化
	void SoundInit(void);

	//ゲームスタート
	int start_;

};



