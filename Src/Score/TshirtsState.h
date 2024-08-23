#pragma once
class TshirtsState
{
public:
	// �����I�ɃC���X�e���X�𐶐�����
	static void CreateInstance(void);

	// �ÓI�C���X�^���X�̎擾
	static TshirtsState& GetInstance(void);

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


	//UI�̏k���l
	static constexpr float UI_REDUCTION = 0.05f;

	void Init(void);

	//�X�R�A���Z
	void AddScore(int score);

	void StateSet(DIRT_STATE stateSet);

	const int GetState(void) const;

	void ResetState(void);

	//T�V���c�̉摜�����[�h
	void LoadIMG(void);

	//Tshirts�`��
	void DrawTshirts(void);
private:
	// �ÓI�C���X�^���X
	static TshirtsState* instance_;

	//T�V���c�̉摜
	int Tshirts_;
	int TshirtsWhite_;
	int TshirtsLow_;
	int TshirtsMiddle_;
	int TshirtsHigh_;
	int TshirtsMax_;


	// T�V���c�̉�����
	DIRT_STATE dirtState_;

};

