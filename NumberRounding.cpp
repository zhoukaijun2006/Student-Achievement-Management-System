#include "NumberRounding.h"

//�ú���Ϊȡ������ ��double���͵��������������벢ת��Ϊint����

int NumberRounding(double num)
{
    int Num = (int)num;

    if (num - Num >= 0.5)
    {
        Num++;
    }

    return Num;
}
