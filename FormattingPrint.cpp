
/*
	std::setw �������� <iomanip> ͷ�ļ��� ���ڿ��ƽ���������������С���
	����������ַ�������ָ���Ŀ�� ��������ÿո񣨻���������ַ������ʹ�� std::setfill ָ��������ַ�����䵽ָ���Ŀ��
*/

#include "FormattingPrint.h"

void FormattingPrint(const int& maxlength, const std::string& str)
{
	std::cout << std::setw((maxlength - str.size()) / 2) << "" << std::setw(str.size()) << str << std::setw(maxlength - (maxlength + str.size()) / 2 + 4) << "";
}
