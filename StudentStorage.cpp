#include"StudentStorage.h"

void StudentStorage()
{
	std::string studentid;
	std::string studentname;
	std::string studentgender;
	std::string studentage;
	std::string studentsystem;
	std::vector<StudentInformation>students;

	StudentInformation studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

	std::cout << "������ѧ���Ļ�����Ϣ����֧������ո�" << std::endl;

	while (1)
	{
		std::cout << "ѧ�ţ�������End������һ����" << std::endl;

		std::getline(std::cin, studentid);

		RefreshScreenBuffer();

		if (studentid == "end" || studentid == "End")
		{
			std::cout << "���سɹ�" << std::endl;
			std::cout << "------------------------------------" << std::endl;

			break;
		}

		if (FindSpace(studentid) == 1)
		{
			std::cout << "����ѧ�Ÿ�ʽ���� ��֧������ո�" << std::endl;
			continue;
		}

		studentinformation.LoadStudentsFromFile(students);

		if (StudentInformation::isIDExist(studentid,students) == true)
		{
			std::cout << "����ѧ���Ѵ��ڣ������ظ�������Ϣ" << std::endl;
			std::cout << "����������ѧ���Ļ�����Ϣ" << std::endl;
			std::cout << "------------------------------------" << std::endl;

			continue;
		}

		std::cout << "������" << std::endl;
		std::getline(std::cin, studentname);

		RefreshScreenBuffer();

		if (FindSpace(studentname) == 1)
		{
			std::cout << "����������ʽ���� ��֧������ո�" << std::endl;
			continue;
		}

		std::cout << "�Ա�" << std::endl;
		std::getline(std::cin, studentgender);

		RefreshScreenBuffer();

		if (FindSpace(studentgender) == 1)
		{
			std::cout << "�����Ա��ʽ���� ��֧������ո�" << std::endl;
			continue;
		}

		while (1)
		{
			std::cout << "���䣺" << std::endl;
			std::getline(std::cin, studentage);

			RefreshScreenBuffer();

			if (FindSpace(studentage) == 1)
			{
				std::cout << "���������ʽ���� ��֧������ո�" << std::endl;
				continue;
			}

			/*������ʽ��^ [1 - 9] * $
			  ^��ʾ�ַ����Ŀ�ʼ��
	          [1 - 9] ��ʾƥ���κ�һ����1��9֮������֡�
			  * ��ʾǰ����ַ����������������[1 - 9]�е��κ�һ�����֣����Գ���0�λ��Ρ�
	          $ ��ʾ�ַ����Ľ�����
			*/

			std::regex pattern("^[1-9]*$");

			if (std::regex_match(studentage, pattern) == 0)
			{
				std::cout << "���������ʽ���� ���������루ֻ���������֣�" << std::endl;
				std::cout << "--------------------------------------------------" << std::endl;
			}
			else
			{
				break;
			}
		}

		std::cout << "����ϵ��" << std::endl;
		std::getline(std::cin, studentsystem);

		RefreshScreenBuffer();

		if (FindSpace(studentsystem) == 1)
		{
			std::cout << "��������ϵ��ʽ���� ��֧������ո�" << std::endl;
			continue;
		}

		students.emplace_back(studentid, studentname, studentgender, studentage, studentsystem);

		std::cout << "��ѧ����Ϣ��������" << std::endl;
		std::cout << "------------------------------------" << std::endl;

		StudentInformation::SaveToFile(students);

		students.clear();

	}
}


void StudentStorageSearch()
{

	std::cout << "ȷ�ϳɹ������ڶ�ȡѧ��������Ϣ" << std::endl;
	std::cout << "------------------------------------" << std::endl;

	StudentInformation::SearchForFile();

	std::cout << "------------------------------------" << std::endl;

}