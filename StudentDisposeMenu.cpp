#include "StudentDisposeMenu.h"

void StudentDisposeMenu()
{
	while (1)
	{
		std::cout << "ȷ���Ƿ�ѡ���޸�/ɾ��ѧ��������Ϣ���ݣ�Yes/No��" << std::endl;
		std::string Studentdetermine;
		std::getline(std::cin, Studentdetermine);

		RefreshScreenBuffer();

		if (Studentdetermine == "yes" || Studentdetermine == "Yes")
		{
			while (1)
			{
				std::cout << "���������޸�/ɾ���Ŀγ̻�����Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << "������ѧ��" << std::endl;

				std::string Studentid;
				std::getline(std::cin, Studentid);

				RefreshScreenBuffer();

				std::cout << "����������" << std::endl;

				std::string Studentname;
				std::getline(std::cin, Studentname);

				RefreshScreenBuffer();

				std::string Studentgender;
				std::string Studentage;
				std::string Studentsystem;

				std::vector<StudentInformation>Students;

				StudentInformation Studentinformation(Studentid, Studentname, Studentgender, Studentage, Studentsystem);

				Studentinformation.LoadStudentsFromFile(Students);

				Studentinformation.isIDNameExist(Studentid, Studentname, Students);

				StudentInformation::SaveToFile(Students);

				break;
			}
		}
		else if (Studentdetermine == "no" || Studentdetermine == "No")
		{
			std::cout << "ȷ�ϳɹ����ѷ��ز˵�" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			break;
		}
		else
		{
			std::cout << "ȷ��ʧ�ܣ�������ȷ��" << std::endl;
			std::cout << "------------------------------------" << std::endl;
		}
	}
}
