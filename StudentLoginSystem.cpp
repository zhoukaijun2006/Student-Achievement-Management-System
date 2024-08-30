#include"StudentLoginSystem.h"

void StudentLoginProcedure(std::string& StudentUserName, int& judgestudent)
{
	while (1)
	{
		std::cout << "�˵��������Ӧ��ż���ѡ�񣩣�" << std::endl;
		std::cout << "1--��ѯ������Ϣ" << std::endl;
		std::cout << "2--��ѯ�γ�����" << std::endl;
		std::cout << "3--��ѯ���˳ɼ�" << std::endl;
		std::cout << "4--�˳���¼" << std::endl;

		std::string resolution;
		std::getline(std::cin, resolution);

		RefreshScreenBuffer();

		//��ѯ������Ϣ
		if (resolution == "1")
		{
			std::string studentid;
			std::string studentname;
			std::string studentgender;
			std::string studentage;
			std::string studentsystem;
			std::vector<StudentInformation>Students;

			StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

			Studentinformation.LoadStudentsFromFile(Students);

			std::vector<StudentInformation>::iterator it;

			bool isExist = false;
			for (it = Students.begin(); it != Students.end(); it++)
			{
				if (it->StudentID == StudentUserName)
				{
					isExist = true;

					std::cout << "��ѯ�ɹ�" << std::endl;
					std::cout << "------------------------------------" << std::endl;
					std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
					std::cout << "������" << it->StudentName << std::endl;
					std::cout << "�Ա�" << it->StudentGender << std::endl;
					std::cout << "���䣺" << it->StudentAge << std::endl;
					std::cout << "����ϵ��" << it->StudentSystem << std::endl;
					std::cout << "------------------------------------" << std::endl;

					break;
				}
			}

			if (isExist == 0)
			{
				std::cout << "��Ϣ��δ¼�� ���޸�����Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}

			StudentInformation::SaveToFile(Students);
		}
		else if (resolution == "2")
		{
			CourseStorageSearch();
		}
		else if (resolution == "3")
		{
			std::string Studentid;
			std::string Classid;
			int usualscore = 0;
			int rollscore = 0;
			int score = 0;

			std::vector<ScoreInformation>Scores;

			ScoreInformation Scoreinformation(Studentid, Classid, usualscore, rollscore, score);

			Scoreinformation.LoadScoresFromFile(Scores);

			std::vector<ScoreInformation>::iterator it;

			bool isQuery = false;

			for (it = Scores.begin(); it != Scores.end(); it++)
			{
				if (it->StudentID == StudentUserName)
				{
					if (isQuery == 0)
					{
						std::cout << "��ѯ�ɹ�" << std::endl;
						std::cout << "------------------------------------" << std::endl;
					}

					std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
					//����ѧ����"Student.txt"�в������������

					std::string studentid;
					std::string studentname;
					std::string studentgender;
					std::string studentage;
					std::string studentsystem;
					std::vector<StudentInformation>Students;

					StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

					Studentinformation.LoadStudentsFromFile(Students);

					std::vector<StudentInformation>::iterator It;


					for (It = Students.begin(); It != Students.end(); It++)
					{
						if (It->StudentID == it->StudentID)
						{
							std::cout << "������" << It->StudentName << std::endl;
							break;
						}
					}
					//������������

					std::cout << "�κţ�" << it->ClassID << std::endl;
					//���ÿκ���"Course.txt"�в��ҿ��������

					std::string coursenumber;
					std::string coursename;
					std::string courseteacher;

					std::vector<CourseInformation>Courses;

					CourseInformation courseinformation(coursenumber, coursename, courseteacher);

					courseinformation.LoadCoursesFromFile(Courses);

					std::vector<CourseInformation>::iterator IT;

					for (IT = Courses.begin(); IT != Courses.end(); IT++)
					{
						if (IT->CourseNumber == it->ClassID)
						{
							std::cout << "������" << IT->CourseName << std::endl;
							break;
						}
					}

					std::cout << "�ɼ���" << it->Score << std::endl;
					std::cout << "------------------------------------" << std::endl;

					isQuery = true;
				}
			}

			if (isQuery == 0)
			{
				std::cout << "���޳ɼ�" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}

			ScoreInformation::SaveToFile(Scores);

		}
		else if (resolution == "4")
		{
			judgestudent = 0;
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

StudentLoginSystem::StudentLoginSystem(const char* filepath) :StudentFilePath(filepath) {}

//ע��ʱ���ݿ��е��˺�����
void StudentLoginSystem::SaveUsersToFile()
{
	std::ofstream studentfile;

	studentfile.open(StudentFilePath);

	if (studentfile.is_open())
	{
		for (auto user = users.begin(); user != users.end(); user++)
		{
			studentfile << user->UserName << " " << user->Password << std::endl;
		}
	}
	else
	{
		std::cout << "�洢�û���¼����ʧ��" << std::endl;
	}

	users.clear();

}

//��¼��ȡ���ݿ��е��˺�����
void StudentLoginSystem::LoadUsersFromFile()
{
	std::ifstream File;

	File.open(StudentFilePath);

	if (File.is_open())
	{
		std::string Line;

		while (std::getline(File, Line))
		{
			size_t pos = Line.find(' ');
			if (pos != std::string::npos) //std::string::npos ��һ����̬��Ա��������ʾ�ַ����в����ڵ�λ��
			{
				std::string username = Line.substr(0, pos);//substr �������ڴ��ַ�������ȡ�Ӵ�
				std::string password = Line.substr(pos + 1);
				users.emplace_back(username, password);//�洢��users��vector������

			}
			else
			{
				std::cout << "δ�ɹ���ȡ���ݿ��е�¼���ݵ��˺�����" << std::endl;
			}
		}
		File.close();

	}
	else
	{
		std::cout << "��ȡ�û���¼����ʧ��" << std::endl;
	}
}

//ע���˺�����
bool StudentLoginSystem::RegisterUser(const std::string& username, const std::string& password)
{

	//���ڱ��������е�ÿ��Ԫ�� const����ͨ��user�޸������е�Ԫ�ء�
	for (const auto user : users)
	{
		if (user.UserName == username)
		{
			return false;//�ظ�ע��
		}
	}

	users.emplace_back(username, md5(password));

	SaveUsersToFile();

	return true;//ע��ɹ�
	
}

//��¼�ж�
int StudentLoginSystem::isLogin(const std::string& username, const std::string& password)
{
	for (const auto& user : users)
	{
		if (user.UserName == username && user.Password == md5(password))
		{
			return 1;//��¼�ɹ�
		}
		else if (user.UserName == username && user.Password != md5(password))
		{
			return 2;//�������
		}
	}
	return 3;//�û���������
}
