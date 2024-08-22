#pragma once
class Rash
{
public:
	// �����I�ɃC���X�e���X�𐶐�����
	static void CreateInstance(void);

	// �ÓI�C���X�^���X�̎擾
	static Rash& GetInstance(void);

	void Init(void);

	//�X�R�A���Z
	void AddScore(int score);

	void ScoreSet(int scoreSet);

	const int GetScore(void) const;

	void ResetScore(void);
private:
	// �ÓI�C���X�^���X
	static Rash* instance_;

	//�X�R�A1�l�p
	int rashNum_;
};

