#include "CourseDisposeMenu.h"

void CourseDisposeMenu()
{
	while (1)
	{
		std::cout << "ȷ���Ƿ�ѡ���޸�/ɾ���γ̻�����Ϣ���ݣ�Yes/No��" << std::endl;
		std::string Coursedetermine;
		std::getline(std::cin, Coursedetermine);

		RefreshScreenBuffer();

		if (Coursedetermine == "yes" || Coursedetermine == "Yes")
		{
			while (1)
			{
				std::cout << "���������޸�/ɾ���Ŀγ̻�����Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << "������γ̱��" << std::endl;

				std::string Coursenumber;
				std::getline(std::cin, Coursenumber);

				RefreshScreenBuffer();

				std::cout << "���������" << std::endl;

				std::string Coursename;
				std::getline(std::cin, Coursename);

				RefreshScreenBuffer();

				std::cout << "�������ον�ʦ" << std::endl;
				
				std::string Courseteacher;
				std::getline(std::cin, Courseteacher);

				RefreshScreenBuffer();

				std::vector<CourseInformation>Courses;

				CourseInformation Courseinformation(Coursenumber, Coursename,Courseteacher);

				Courseinformation.LoadCoursesFromFile(Courses);

				Courseinformation.isIDNameExist(Coursenumber, Coursename, Courseteacher, Courses);

				CourseInformation::SaveToFile(Courses);

				break;
			}
		}
		else if (Coursedetermine == "no" || Coursedetermine == "No")
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