/*
	
*/

#include "QueryMessage.h"

void QueryMessage()
{
	while (1)
	{
		std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
		std::cout << "1--��ѯѧ����Ϣ" << std::endl;
		std::cout << "2--��ѯ�γ���Ϣ" << std::endl;
		std::cout << "3--��ѯ�ɼ���Ϣ" << std::endl;
		std::cout << "4--�˳���¼" << std::endl;

		std::string Resolution;
		std::getline(std::cin, Resolution);

		RefreshScreenBuffer();

		//����Ա��ѧ����Ϣ�Ĳ�ѯ
		if (Resolution == "1")
		{
			QueryStudentFunction();
		}
		//����Ա�Կγ���Ϣ�Ĳ�ѯ
		else if (Resolution == "2")
		{
			QueryCourseFunction();
		}
		//����Ա�Գɼ���Ϣ�Ĳ�ѯ
		else if (Resolution == "3")
		{
			QueryScoreFunction();
		}
		else if (Resolution == "4")
		{
			std::cout << "�˳��ɹ�" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			break;
		}
		else
		{
			std::cout << "ѡ�����������ѡ��" << std::endl;
			std::cout << "------------------------------------" << std::endl;
		}
	}
}
