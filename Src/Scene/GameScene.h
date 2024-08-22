#pragma once
#include "SceneBase.h"
class GameScene : public SceneBase
{
public:
	//�萔
	//�X�R�A�}�b�N�X
	static constexpr int SCORE_MAX = 120;

	//�Q�[�W�}�b�N�X
	static constexpr int GAUGE_MAX = 200;

	//�Q�[�W�̏オ�蕝
	static constexpr float GAUGE_INC = 1000.0f;

<<<<<<< Updated upstream
	// T�V���c�̉�����
	enum  class DIRT_STATE
	{
		NONE,
		WHITE,
		LOW,
		MIDDLE,
		HIGH,
		MAX
	};
=======
	//���A�łŃ}�b�N�X�ɂȂ邩
	static constexpr int RUSHGAUGE_MAX = 30;

	//�����̍ő�l
	static constexpr float PERCENT_MAX = 1.0f;

	//�Q�[�W�̉����蕝
	static constexpr float GAUGE_DECREASE =0.05f;
>>>>>>> Stashed changes

	// �R���X�g���N�^
	GameScene(void);

	// �f�X�g���N�^
	~GameScene(void);

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;


private:
	// �A�Ő�
	int rash_;

	//����
	float time_;

	//�Q�[�W�̒���
	float gaugeLen_;

	//�Q�[�W�̊���
	float gaugePercent_;

	//�}�b�N�X�ɂȂ������̃N�[���^�C��
	bool isCool_;

	//�Q�[�W�̍X�V
	void GaugeUpdate(void);

	//�Q�[�W�̕`��
	void DrawGauge(void);

<<<<<<< Updated upstream
	//T�V���c�̉摜
	int Tshirts_;
	int TshirtsWhite_;
	int TshirtsLow_;
	int TshirtsMiddle_;
	int TshirtsHigh_;
	int TshirtsMax_;


	// T�V���c�̉�����
	DIRT_STATE dirtState_;

	//T�V���c�̉摜�����[�h
	void LoadIMG(void);

	//Tshirts�`��
	void DrawTshirts(void);
=======
>>>>>>> Stashed changes
};

