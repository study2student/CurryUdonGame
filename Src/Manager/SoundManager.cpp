#include"../Application.h"
#include "SoundManager.h"


void SoundManager::LoadBgm(const BGM_TYPE bgm)
{
	bgm_[bgm] = LoadSoundMem((Application::PATH_BGM + bgmPath_[bgm]).c_str());
}

void SoundManager::LoadSe(const SE_TYPE se)
{
	se_[se] = LoadSoundMem((Application::PATH_SE + sePath_[se]).c_str());
}

void SoundManager::BGMInit(void)
{
	bgmPath_[BGM_TYPE::TITLE] = "Title.mp3";
	bgmPath_[BGM_TYPE::GAME] = "Game.mp3";
	bgmPath_[BGM_TYPE::RESULT] = "Result.mp3";
}

void SoundManager::SEInit(void)
{
	sePath_[SE_TYPE::WATER] = "Water.mp3";
	sePath_[SE_TYPE::DRUM] = "Drum.mp3";
	sePath_[SE_TYPE::WHISTLE] = "Whistle.mp3";
	sePath_[SE_TYPE::SLURP] = "slurp_Ramen2Sec.mp3";
	sePath_[SE_TYPE::TITLE2GAME] = "Title2Game.mp3";
	sePath_[SE_TYPE::SIREN] = "Warning-Siren.mp3";
}



void SoundManager::PlayBgm(BGM_TYPE bgm, int type, int volPer,bool isTopPosition)
{
	PlaySoundMem(bgm_[bgm], type,isTopPosition);
	ChangeVolumeSoundMem(255 * volPer / 100, bgm_[bgm]);
}

void SoundManager::PlaySe(SE_TYPE se, int type, int volPer,bool isTopPosition)
{
	PlaySoundMem(se_[se], type, isTopPosition);
	ChangeVolumeSoundMem(255 * volPer / 100,se_[se]);
}

void SoundManager::StopBgm(BGM_TYPE bgm)
{
	StopSoundMem(bgm_[bgm]);
}

void SoundManager::StopSe(SE_TYPE se)
{
	StopSoundMem(se_[se]);
}

void SoundManager::Release(void)
{
	DeleteSoundMem(bgm_[BGM_TYPE::TITLE]);
	DeleteSoundMem(bgm_[BGM_TYPE::GAME]);
	DeleteSoundMem(bgm_[BGM_TYPE::RESULT]);
}
