#include "ScoreStorage.h"

void ScoreStorage()
{
	std::string studentid;
	std::string classid;

	double UsualScore = 0;
	double RollScore = 0;

	std::string usualscore;
	std::string rollscore;

	int Usualscore = 0;
	int Rollscore = 0;
	int Score = 0;

	std::vector<ScoreInformation> scores;

	ScoreInformation scoreinformation(studentid, classid, Usualscore, Rollscore, Score);

	std::cout << "������ѧ���ɼ��Ļ�����Ϣ" << std::endl;

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
		
		std::string Studentid;
		std::string Studentname;
		std::string studentgender;
		std::string studentage;
		std::string studentsystem;

		std::vector<StudentInformation>Students;

		StudentInformation Studentinformation(Studentid, Studentname, studentgender, studentage, studentsystem);

		Studentinformation.LoadStudentsFromFile(Students);

		std::vector<StudentInformation>::iterator it;

		bool StudentIDExist = false;

		for (it = Students.begin(); it != Students.end(); it++)
		{
			if (it->StudentID == studentid)
			{
				StudentIDExist = true;
				break;
			}
		}

		std::cout << "�κţ�" << std::endl;
		std::getline(std::cin, classid);

		RefreshScreenBuffer();

		if (FindSpace(classid) == 1)
		{
			std::cout << "����κŸ�ʽ���� ��֧������ո�" << std::endl;
			continue;
		}

		std::string Coursenumber;
		std::string Coursename;
		std::string Courseteacher;
		std::vector<CourseInformation>Courses;

		CourseInformation Courseinformation(Coursenumber, Coursename, Courseteacher);

		Courseinformation.LoadCoursesFromFile(Courses);

		std::vector<CourseInformation>::iterator It;

		bool CourseIDExist = false;

		for (It = Courses.begin(); It != Courses.end(); It++)
		{
			if (It->CourseNumber == classid)
			{
				CourseIDExist = true;
				break;
			}
		}

		if (StudentIDExist == 0 && CourseIDExist == 0)
		{
			std::cout << "��ѧ�źͿκž�������" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			break;
		}
		if (StudentIDExist == 1 && CourseIDExist == 0)
		{
			std::cout << "�˿κŲ�����" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			break;
		}

		if (StudentIDExist == 0 && CourseIDExist == 1)
		{
			std::cout << "��ѧ�Ų�����" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			break;
		}

		scoreinformation.LoadScoresFromFile(scores);

		if (ScoreInformation::isScoreExist(studentid, classid, scores) == true)
		{
			std::cout << "���󣺴�ѧ���ĸÿγ̳ɼ��Ѵ��ڣ������ظ�������Ϣ" << std::endl;
			std::cout << "����������ѧ�źͿκ�" << std::endl;
			std::cout << "-----------------------------------------------------" << std::endl;
			continue;
		}

		while (1)
		{

			std::cout << "ƽʱ�ɼ���" << std::endl;
			std::getline(std::cin, usualscore);

			RefreshScreenBuffer();

			if (FindSpace(usualscore) == 1)
			{
				std::cout << "����ƽʱ�ɼ���ʽ���� ��֧������ո�" << std::endl;
				continue;
			}

			if (NumberJudge(usualscore) == -1)
			{
				std::cout << "δ�ɹ����룬����������" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
			else if (NumberJudge(usualscore) == -2)
			{
				std::cout << "����ɼ���ʽ��������������" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
			else if (NumberJudge(usualscore) == -3)
			{
				std::cout << "����ĳɼ���Χ��0--100֮�䣬�Ҳ��ܳ���С�������λ������������" << std::endl;
				std::cout << "------------------------------------------------------------------------" << std::endl;
			}
			else
			{
				UsualScore = NumberJudge(usualscore);
				break;
			}
		}

		while (1)
		{

			std::cout << "����ɼ���" << std::endl;
			std::getline(std::cin, rollscore);

			RefreshScreenBuffer();

			if (FindSpace(rollscore) == 1)
			{
				std::cout << "�������ɼ���ʽ���� ��֧������ո�" << std::endl;
				continue;
			}

			if (NumberJudge(rollscore) == -1)
			{
				std::cout << "δ�ɹ����룬����������" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
			else if (NumberJudge(rollscore) == -2)
			{
				std::cout << "����ɼ���ʽ��������������" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
			else if (NumberJudge(rollscore) == -3)
			{
				std::cout << "����ĳɼ���Χ��0--100֮�䣬�Ҳ��ܳ���С�������λ������������" << std::endl;
				std::cout << "------------------------------------------------------------------------" << std::endl;
			}
			else
			{
				RollScore = NumberJudge(rollscore);
				break;
			}
		}

		/*
			Ҫ��ѧ���ɼ�¼�룺�ɼ���Ϣ������score�ļ���
				  ѧ���ɼ�Ӧ�������������¼��ɼ���������Ӧ������¼�룬��ϵͳ�Զ�����ȡ��
				  ¼��ѧ���ɼ���Ϣ��ϣ�Ӧ�����ñ��湦�ܣ����湦������ǰ�ɼ������棬���湦�����к��ۺϳɼ������趨�����Զ����㡣�ۺϳɼ�����������
		*/

		/*
			NumberRoundingΪȡ������double����ת��Ϊint���� Ҫ����Ȼ˵ϵͳ�Զ�����ȡ�� ���������ϸ�Լ���ڣ���������ԭ��
			���¹��̼�Ϊ����ƽʱ�ɼ��;���ɼ���������ScoreManage�������м����ܳɼ� д��vector<ScoreInformation>��
						  ����ScoreInformation::SaveToFile����������"score.txt"�ļ� 

		*/

		Usualscore = NumberRounding(UsualScore);
		Rollscore = NumberRounding(RollScore);
		scores.emplace_back(studentid, classid, Usualscore, Rollscore, ScoreManage(classid, Usualscore, Rollscore, Score));

		std::cout << "��ѧ���ĸÿγ̳ɼ���������" << std::endl;
		std::cout << "------------------------------------" << std::endl;

		ScoreInformation::SaveToFile(scores);
	}
}

void ScoreStorageSearch()
{

	std::cout << "ȷ�ϳɹ������ڶ�ȡѧ���ɼ�������Ϣ" << std::endl;
	std::cout << "------------------------------------" << std::endl;

	ScoreInformation::SearchForFile();

	std::cout << "------------------------------------" << std::endl;

}