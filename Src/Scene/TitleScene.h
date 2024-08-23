#pragma once
#include "SceneBase.h"
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
	//タイトル画像
	int title_;
	//遊び方画像
	int tutorial_;
	//クレジット
	int credit_;

};



