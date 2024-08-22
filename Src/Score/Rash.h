#pragma once
class Rash
{
public:
	// 明示的にインステンスを生成する
	static void CreateInstance(void);

	// 静的インスタンスの取得
	static Rash& GetInstance(void);

	void Init(void);

	//スコア加算
	void AddScore(int score);

	void ScoreSet(int scoreSet);

	const int GetScore(void) const;

	void ResetScore(void);
private:
	// 静的インスタンス
	static Rash* instance_;

	//スコア1人用
	int rashNum_;
};

