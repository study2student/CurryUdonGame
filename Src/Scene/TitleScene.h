#pragma once
#include "SceneBase.h"
#include "../Manager/SoundManager.h"
class SoundManager;
class TitleScene : public SceneBase
{

public:
	// �R���X�g���N�^
	TitleScene(void);

	// �f�X�g���N�^
	~TitleScene(void);

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;


private:
	//�|�C���^
	SoundManager* sound_;
	//�^�C�g���摜
	int title_;
	//�V�ѕ��摜
	int tutorial_;

	//�N���W�b�g
	int credit_;


	//���֌W�̏�����
	void SoundInit(void);

	//�Q�[���X�^�[�g
	int start_;

};



