#include "Vector2F.h"
#include "../Utility/Utility.h"
#include "Vector2.h"

// �f�t�H���g�R���X�g���N�^
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

// �R���X�g���N�^
Vector2::Vector2(int vX, int vY)
{
	x = vX;
	y = vY;
}

Vector2::Vector2(Vector2F value)
{
	x = Utility::Round(value.x);
	y = Utility::Round(value.y);
}

Vector2F Vector2::ToVector2F(void)
{
	Vector2F ret;
	ret.x = static_cast<float>(x);
	ret.y = static_cast<float>(y);
	return ret;
}


