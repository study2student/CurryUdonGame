#pragma once
#include"../Manager/SoundManager.h"
#include "SceneBase.h"
class SoundManager;
class ResultScene :  public SceneBase
{
public:
	//�R���X�g���N�^
	ResultScene(void);
	//�f�X�g���N�^
	~ResultScene(void);

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;
private:
	SoundManager* sound_;
	//���U���g�G
	int resultImg_;
<<<<<<< Updated upstream
	int frame_;
	int goTitle_;
=======

	//�T�E���h������
	void SoundInit(void);
>>>>>>> Stashed changes
};

