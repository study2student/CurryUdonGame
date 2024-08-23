#pragma once
#include"../Manager/SoundManager.h"
#include "SceneBase.h"
class SoundManager;
class ResultScene :  public SceneBase
{
public:
	//コンストラクタ
	ResultScene(void);
	//デストラクタ
	~ResultScene(void);

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;
private:
	SoundManager* sound_;
	//リザルト絵
	int resultImg_;
<<<<<<< Updated upstream
	int frame_;
	int goTitle_;
=======

	//サウンド初期化
	void SoundInit(void);
>>>>>>> Stashed changes
};

