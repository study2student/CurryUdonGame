#include "../Application.h"
#include "../Manager/SceneManager.h"
#include "Rash.h"

Rash* Rash::instance_ = nullptr;

void Rash::CreateInstance(void)
{
	if (instance_ == nullptr)
	{
		instance_ = new Rash();
	}
	instance_->Init();
}

Rash& Rash::GetInstance(void)
{
    // TODO: return ステートメントをここに挿入します
	return *instance_;
}

void Rash::Init(void)
{
}

void Rash::AddScore(int rash)
{
	rashNum_ += rash;
}

void Rash::ScoreSet(int rashSet)
{
	rashNum_ = rashSet;
}

const int Rash::GetScore(void) const
{
    return rashNum_;
}

void Rash::ResetScore(void)
{
	rashNum_ = 0;
}
