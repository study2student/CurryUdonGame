#include"../Score/Rash.h"
#include"../Score/TshirtsState.h"
#include "SceneBase.h"

SceneBase::SceneBase(void) : rash_(Rash::GetInstance()), tState_(TshirtsState::GetInstance())
{
}

SceneBase::~SceneBase()
{
}

void SceneBase::Init(void)
{
}

void SceneBase::Update(void)
{
}

void SceneBase::Draw(void)
{
}

void SceneBase::Release(void)
{
}