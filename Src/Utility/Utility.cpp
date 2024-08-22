#include <sstream>
#include "Utility.h"

std::vector<std::string> Utility::Split(std::string& line, char delimiter)
{

    // ���I�z��̕Ԃ�l������
    std::vector<std::string> result;

    // �����񑀍�p�̃N���X�ɒu��������
    std::istringstream stream(line);

    std::string field;

    // stream�����ɓǂݍ��݁A
    // ��R�����Ŏw�肳�ꂽ�����܂ł��Q�����ɕԂ�
    while (getline(stream, field, delimiter)) {
        // ���I�z��ɒǉ�
        result.push_back(field);
    }

    // ��F"aaa,bbb,ccc"
    // �@�@��result[0] = aaa
    // �@�@�@result[1] = bbb
    // �@�@�@result[2] = ccc

    return result;

}

int Utility::Round(float value)
{
    return static_cast<int>(round(value));
}

Vector2 Utility::Round(Vector2F value)
{
    Vector2 ret;
    ret.x = static_cast<int>(round(value.x));
    ret.y = static_cast<int>(round(value.y));
    return ret;
}

Vector2 Utility::Round(float x, float y)
{
    Vector2 ret;
    ret.x = static_cast<int>(round(x));
    ret.y = static_cast<int>(round(y));
    return ret;
}

Vector2F Utility::Normalize(Utility::DIR dir)
{
    Vector2F ret;

    switch (dir)
    {
    case Utility::DIR::UP:
        ret = { 0.0f, -1.0f };
        break;
    case Utility::DIR::RIGHT:
        ret = { 1.0f, 0.0f };
        break;
    case Utility::DIR::DOWN:
        ret = { 0.0f, 1.0f };
        break;
    case Utility::DIR::LEFT:
        ret = { -1.0f, 0.0f };
        break;
    }

    return ret;
}
