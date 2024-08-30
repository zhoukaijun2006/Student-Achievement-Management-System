#include "NumberJudge.h"

double NumberJudge(const std::string &str)
{
	if (str.empty())
	{
		return -1;	// ����Ϊ��
	}

	double score = 0.0;
	bool hasDecimalPoint = false;
	int PointNumber = 0;

	for (char c : str)
	{
		if (c == '.')
		{
			if (hasDecimalPoint == 1)
			{
				return -2;	// ������С���� �������
			}

			hasDecimalPoint = true;
			continue;
		}

		if ((c < '0') || (c > '9'))
		{
			return -2;	// ���ַ����� �������
		}

		if (hasDecimalPoint == 1)
		{
			PointNumber++;
			if (PointNumber > 2)
			{
				return -3;	// ����ɼ�������Ҫ��
			}
		}

		if (hasDecimalPoint == 1 && PointNumber == 0)
		{
			return -2;	// ����С����� û����������
		}
	}

	score = std::stod(str);

	if (score < 0 || score>100)
	{
		return -3;
	}

	return std::stod(str);
}
