#pragma once
#include "SceneBase.h"

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
	//リザルト絵
	int resultImg_;
	int frame_;
	int goTitle_;
};

