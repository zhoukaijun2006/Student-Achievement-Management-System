#include"CourseStorage.h"

void CourseStorage()
{
	std::string coursenumber;
	std::string coursename;
	std::string courseteacher;

	std::vector<CourseInformation>courses;

	CourseInformation courseinformation(coursenumber, coursename, courseteacher);

	std::cout << "������γ̵Ļ�����Ϣ����֧������ո�" << std::endl;

	while (1)
	{
		std::cout << "�κţ�������End������һ����" << std::endl;

		std::getline(std::cin, coursenumber);

		RefreshScreenBuffer();

		if (coursenumber == "end" || coursenumber == "End")
		{
			std::cout << "���سɹ�" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			break;
		}

		if (coursenumber[0] != 'P' && coursenumber[0] != 'S')
		{
			std::cout << "����κŸ�ʽ���󣨿κŵĵ�һλ������ΪS/P �ֱ����רҵ��/���������Σ�" << std::endl;
			std::cout << "------------------------------------------------------------------------" << std::endl;
			continue;
		}

		if (FindSpace(coursenumber) == 1)
		{
			std::cout << "����κŸ�ʽ���� ��֧������ո�" << std::endl;
			continue;
		}

		courseinformation.LoadCoursesFromFile(courses);

		std::cout << "������" << std::endl;
		std::getline(std::cin, coursename);

		RefreshScreenBuffer();

		if (FindSpace(coursenumber) == 1)
		{
			std::cout << "���������ʽ���� ��֧������ո�" << std::endl;
			continue;
		}

		std::cout << "�ον�ʦ��" << std::endl;
		std::getline(std::cin, courseteacher);

		RefreshScreenBuffer();

		if (FindSpace(courseteacher) == 1)
		{
			std::cout << "�����ον�ʦ��ʽ���� ��֧������ո�" << std::endl;
			continue;
		}

		if (CourseInformation::isCourseExist(coursenumber, coursename, courseteacher, courses) == true)
		{
			std::cout << "���󣺸��ο���ʦ�Ĵ˿γ��Ѵ��ڣ������ظ�������Ϣ" << std::endl;
			std::cout << "����������" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			continue;
		}

		courses.emplace_back(coursenumber, coursename, courseteacher);

		std::cout << "�ÿγ���Ϣ��������" << std::endl;

		CourseInformation::SaveToFile(courses);

		courses.clear();
	}
}

void CourseStorageSearch()
{

			std::cout << "ȷ�ϳɹ������ڶ�ȡ�γ̻�����Ϣ" << std::endl;
			std::cout << "------------------------------------" << std::endl;

			CourseInformation::SearchForFile();

			std::cout << "------------------------------------" << std::endl;

}