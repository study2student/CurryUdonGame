#pragma once
#include "SceneBase.h"
class GameScene : public SceneBase
{
public:
	//�萔
	//�X�R�A�}�b�N�X
	static constexpr int SCORE_MAX = 120;

	//�Q�[�W�}�b�N�X
	static constexpr int GAUGE_MAX = 250;

	//�Q�[�W�̏オ�蕝
	static constexpr float GAUGE_INC = 1000.0f;

	//�A�ŃX�g�b�v�J�E���g�}�b�N�X
	static constexpr int PUSH_STOP_MAX = 60;

	//�X�^�[�g�ƏI���摜�̏k���l
	static constexpr float START_END_REDUCTION = 0.1f;

	//UI�̏k���l
	static constexpr float UI_REDUCTION = 0.05f;

	//�摜�T�C�Y
	static constexpr VECTOR IMAGE_SIZE_ = { 4096,3072 };

	//���ǂ�T�C�Y
	static constexpr VECTOR UDON_SIZE_ = { 737,552 };


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
	//���A�łŃ}�b�N�X�ɂȂ邩
	static constexpr int RUSHGAUGE_MAX = 30;

	//�����̍ő�l
	static constexpr float PERCENT_MAX = 1.0f;

	//�Q�[�W�̉����蕝
	static constexpr float GAUGE_DECREASE =0.5f;

	// �R���X�g���N�^
	GameScene(void);

	// �f�X�g���N�^
	~GameScene(void);

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;


private:
	// �Q�[���X�^�[�g���̃J�E���g
	float startCount_;
	// �X�^�[�g�t���O
	bool isStart_;

	// ��[�����߂̕`��J�E���g,�t���O
	float imgCount_;
	bool isImg_;


#pragma region �A�ŃQ�[�W�֘A

	// �A�Ő�
	//int rash_;

	//����
	float time_;

	//�Q�[�W�̒���
	float gaugeLen_;

	//�Q�[�W�̊���
	float gaugePercent_;

	//�}�b�N�X�ɂȂ������̃N�[���^�C��
	bool isCool_;

	//�A�ł��~�܂����J�E���g
	int pushStopCnt_;

	//�Q�[�W�̍X�V
	void GaugeUpdate(void);

	//�Q�[�W�̉����Ə��
	void GaugeLimit(void);

	//�A�Ő�����
	void RashUpdate(void);
	//�Q�[�W�̕`��
	void DrawGauge(void);

#pragma endregion
#pragma region UI
	//�X�R�A�̔w�i
	int backScore_;

	//�c�莞�ԉ摜
	int timeImg_;

	//�X�^�[�g�摜
	int startImg_;

	//�I���摜
	int endImg_;

	//UI�摜�̃��[�h
	void LoadUI(void);

	//UI�摜�̕`��
	void DrawUI(void);

	//UI�X�V����
	void UIUpdate(void);
#pragma endregion


#pragma region �`��֌W

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

	//���ǂ�̎M
	int UdonIMG_;

	//��̂��ǂ�
	int UdonNullIMG_;

	//���ǂ��menn
	int noodleIMG_;
	//���ǂ�̍��W
	VECTOR noodlePos_;

	//���ǂ�̕`��
	void DrawUdon(void);
#pragma endregion



	// ���̊G,���W
	int sticksIMG_;
	VECTOR sticksPos_;
};

