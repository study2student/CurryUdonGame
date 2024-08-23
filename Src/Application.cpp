#include <DxLib.h>
#include <EffekseerForDXLib.h>
#include "Manager/InputManager.h"
#include "Manager/SceneManager.h"
#include "Score/Rash.h"
#include "Score/TshirtsState.h"
#include "Application.h"

Application* Application::instance_ = nullptr;

const std::string Application::PATH_IMAGE = "Data/IMG/";
const std::string Application::PATH_FONT = "Data/Font/";
const std::string Application::PATH_MODEL = "Data/Model/";
const std::string Application::PATH_BGM = "Data/BGM/";
const std::string Application::PATH_SE = "Data/SE/";
const std::string Application::PATH_EFFECT = "Data/Effect/";

void Application::CreateInstance(void)
{
	if (instance_ == nullptr)
	{
		instance_ = new Application();
	}
	instance_->Init();
}

Application& Application::GetInstance(void)
{
	return *instance_;
}

void Application::Init(void)
{

	// �A�v���P�[�V�����̏����ݒ�
	SetWindowText("ContestBaseProject");

	// �E�B���h�E�T�C�Y
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);
	ChangeWindowMode(true);

	// DxLib�̏�����
	SetUseDirect3DVersion(DX_DIRECT3D_11);
	isInitFail_ = false;
	if (DxLib_Init() == -1)
	{
		isInitFail_ = true;
		return;
	}

	// Effekseer�̏�����
	InitEffekseer();

	// �L�[���䏉����
	SetUseDirectInputFlag(true);

	// �X�R�A�̏�����
	Rash::CreateInstance();

	TshirtsState::CreateInstance();

	// �V�[���Ǘ�������
	SceneManager::CreateInstance();
}

void Application::Run(void)
{
	auto& inputManager = InputManager::GetInstance();
	auto& sceneManager = SceneManager::GetInstance();

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		Sleep(1);		//�V�X�e���ɏ�����Ԃ�

		currentTime = GetNowCount();

		// ���݂̎������A�O��̃t���[�������
		// 1/60�b�o�߂��Ă����珈�������s����
		if (currentTime - lastFrameTime >= FRAME_RATE)
		{
			// �t���[�����s���Ԃ��X�V
			lastFrameTime = currentTime;

			// �t���[�������J�E���g
			frameCnt++;

			inputManager.Update();
			sceneManager.Update();

			sceneManager.Draw();

			// �t���[�����[�g�v�Z
			CalcFrameRate();

			// �t���[�����[�g�\��
			//DrawFrameRate();

			ScreenFlip();
		}
	}

}

bool Application::Release(void)
{
	// �Ǘ��}�l�[�W���[�̉������
	// �V�[���Ǘ��p
	SceneManager::GetInstance().Release();

	// �V���O���g����
	// ------------------------
	Destroy();

	// �V�X�e���I������
	// ----------------------
	DxLib_End();			// DX���C�u�����̏I������


	return true;			// �Q�[���̏I��
}

void Application::Destroy(void)
{

	InputManager::GetInstance().Destroy();
	SceneManager::GetInstance().Destroy();

	// Effekseer���I������B
	Effkseer_End();

	// DxLib�I��
	if (DxLib_End() == -1)
	{
		isReleaseFail_ = true;
	}

	delete instance_;

}

bool Application::IsInitFail(void) const
{
	return isInitFail_;
}

bool Application::IsReleaseFail(void) const
{
	return isReleaseFail_;
}

Application::Application(void)
{
	isInitFail_ = false;
	isReleaseFail_ = false;
}

void Application::InitEffekseer(void)
{
	if (Effekseer_Init(8000) == -1)
	{
		DxLib_End();
	}

	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	Effekseer_SetGraphicsDeviceLostCallbackFunctions();
}

void Application::CalcFrameRate()
{
	// �O��̃t���[�����[�g�X�V����̌o�ߎ��Ԃ����߂�
	int nDirTime = currentTime - updateFrameRateTime;

	// �O��̃t���[�����[�g���X�V����
	// 1�b�ȏ�o�߂��Ă�����t���[�����[�g���X�V����
	if (nDirTime > 1000)
	{
		// �t���[���񐔂��~���b�ɍ��킹��
		//�����܂ŏo�����̂�float�ɃL���X�g
		float fFrameCnt = (float)(frameCnt * 1000);

		// �t���[�����[�g�����߂�
		// ���z�ʂ�Ȃ�60000 / 1000 �� 60�ƂȂ�
		frameRate = fFrameCnt / nDirTime;

		// �t���[���J�E���g���N���A
		frameCnt = 0;

		// �t���[�����[�g�X�V���Ԃ��X�V
		updateFrameRateTime = currentTime;
	}
}

void Application::DrawFrameRate()
{
	DrawFormatString(SCREEN_SIZE_X - 90, 0, GetColor(255, 30, 30), "FPS[%.2f]", frameRate);
}
