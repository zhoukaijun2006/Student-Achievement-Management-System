
/*
	ScoreStatistics����Ϊ����Ա�Գɼ�ͳ�ƹ���
	���а����γ̳ɼ����� �γ̳ɼ�ͳ�� ѧ���ɼ�ͳ�Ƶ�ʵ��
	���пγ̳ɼ�ͳ�ƺ�ѧ���ɼ�ͳ�Ʋ���������ʽ���
*/

/*
	����8���ɼ�ͳ��
	��ʾÿ�ſγ̵ľ���ɼ����ۺϳɼ�����߷���ƽ���֣�
	��ʾÿ�ſγ̾�������У����������ε�����ͳ�ƣ�����6��������100�֡�90 - 99�֡�80 - 89�֡�70 - 79�֡�60 - 69�֡�60�����µȣ�
	��ʾÿ�ſγ��ۺϷ����У����������ε�����ͳ�ƣ�����6��������100�֡�90 - 99�֡�80 - 89�֡�70 - 79�֡�60 - 69�֡�60�����µȡ�

	����9�����ܱ���
	��ʾÿ�ſγ̵Ŀκš���������������������������������ٷֱȣ�
	��ʾÿ��ѧ����ѧ�š��������ܿ�����������γ�����
*/

#include "ScoreStatistics.h"

void ScoreStatistics()
{
	while (1)
	{
		std::cout << "�˵��������Ӧ��ż���ѡ�񣩣�" << std::endl;
		std::cout << "1--�γ̳ɼ�����" << std::endl;
		std::cout << "2--�γ̳ɼ�ͳ��" << std::endl;
		std::cout << "3--ѧ���ɼ�ͳ��" << std::endl;
		std::cout << "4--�˳���¼" << std::endl;

		std::string decision;
		std::getline(std::cin, decision);

		RefreshScreenBuffer();

		//����Ա�Կγ̳ɼ��ķ���
		if (decision == "1")
		{
			std::string classId;
			std::string className;
			std::string classTeacher;

			std::vector<CourseInformation>Courses;

			CourseInformation Courseinformation(classId, className, classTeacher);

			Courseinformation.LoadCoursesFromFile(Courses);

			std::vector<CourseInformation>::iterator It;

			std::vector<CourseInformation>courses;

			std::vector<CourseInformation>::iterator IT;

			for (It = Courses.begin(); It != Courses.end(); It++)
			{
				bool isExist = false;

				for (IT = courses.begin(); IT != courses.end(); IT++)
				{
					if (It->CourseNumber == IT->CourseNumber)
					{
						isExist = true;
						break;
					}
				}

				if (isExist == 0)
				{
					courses.emplace_back(It->CourseNumber, It->CourseName, It->CourseTeacher);
				}

			}

			for (It = courses.begin(); It != courses.end(); It++)
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

				int maxusualscore = 0;
				int minusualscore = 100;
				double averageusualscore = 0;

				int maxrollscore = 0;
				int minrollscore = 100;
				double averagerollscore = 0;

				int maxscore = 0;
				int minscore = 100;
				double averagescore = 0;

				int count = 0;

				int UsualPoint[6] = { 0 };
				int RollPoint[6] = { 0 };
				int ScorePoint[6] = { 0 };

				for (it = Scores.begin(); it != Scores.end(); it++)
				{

					if (It->CourseNumber == it->ClassID)
					{
						count++;

						maxusualscore = std::max(maxusualscore, it->UsualScore);
						minusualscore = std::min(minusualscore, it->UsualScore);
						averageusualscore += it->UsualScore;

						ScoreRank(it->UsualScore, UsualPoint);

						maxrollscore = std::max(maxrollscore, it->RollScore);
						minrollscore = std::min(minrollscore, it->RollScore);
						averagerollscore += it->RollScore;

						ScoreRank(it->RollScore, RollPoint);

						maxscore = std::max(maxscore, it->Score);
						minscore = std::min(minscore, it->Score);
						averagescore += it->Score;

						ScoreRank(it->Score, ScorePoint);

					}
				}

				std::cout << "������" << It->CourseName << "    " << "�κţ�" << It->CourseNumber << std::endl;
				std::cout << "ƽʱ�ɼ���" << std::endl;
				std::cout << "��߷֣�" << maxusualscore << "    " << "��ͷ֣�" << minusualscore << "    " << "ƽ���֣�" << std::setprecision(2) << std::fixed << averageusualscore / count << std::endl;
				std::cout << "100��������" << UsualPoint[0] << "    90-99��������" << UsualPoint[1] << "    80-89��������" << UsualPoint[2] << "    70-79��������" << UsualPoint[3] << "    60-69��������" << UsualPoint[4] << "    60������������" << UsualPoint[5] << std::endl << std::endl;

				std::cout << "����ɼ�" << std::endl;
				std::cout << "��߷֣�" << maxrollscore << "    " << "��ͷ֣�" << minrollscore << "    " << "ƽ���֣�" << std::setprecision(2) << std::fixed << averagerollscore / count << std::endl;
				std::cout << "100��������" << RollPoint[0] << "    90-99��������" << RollPoint[1] << "    80-89��������" << RollPoint[2] << "    70-79��������" << RollPoint[3] << "    60-69��������" << RollPoint[4] << "    60������������" << RollPoint[5] << std::endl << std::endl;

				std::cout << "�ۺϳɼ�" << std::endl;
				std::cout << "��߷֣�" << maxscore << "    " << "��ͷ֣�" << minscore << "    " << "ƽ���֣�" << std::setprecision(2) << std::fixed << averagescore / count << std::endl;
				std::cout << "100��������" << ScorePoint[0] << "    90-99��������" << ScorePoint[1] << "    80-89��������" << ScorePoint[2] << "    70-79��������" << ScorePoint[3] << "    60-69��������" << ScorePoint[4] << "    60������������" << ScorePoint[5] << std::endl << std::endl;

				std::cout << "------------------------------------------------------------------------" << std::endl;
			}
		}
		//����Ա�Կγ̳ɼ���ͳ��
		else if (decision == "2")
		{
			std::unordered_set<std::string> nameSet;

			std::ifstream File;
			File.open("Course.txt");

			if (File.is_open())
			{
				std::vector<int> heights;

				std::vector<int> totalperson;

				std::vector<std::string>coursenumber;

				List<CourseInformation>* head1 = new List <CourseInformation>;
				List<CourseInformation>* cur1 = head1;

				std::string Line;

				while (std::getline(File, Line))
				{
					cur1->next = new List<CourseInformation>;
					cur1 = cur1->next;

					std::string Source = Line;
					std::stringstream ss1(Source);

					getline(ss1, cur1->val.CourseNumber, ' ');
					getline(ss1, cur1->val.CourseName, ' ');
					getline(ss1, cur1->val.CourseTeacher);

				}

				cur1 = head1->next;

				List<CourseInformation>* head2 = new List <CourseInformation>;

				while (cur1 != nullptr)
				{

					bool flg = false;

					List<CourseInformation>* cur2 = head2;

					if (!nameSet.count(cur1->val.CourseName))
					{
						cur2->next = new List<CourseInformation>;
						cur2 = cur2->next;

						cur2->val.CourseNumber = cur1->val.CourseNumber;
						cur2->val.CourseName = cur1->val.CourseName;
						cur2->val.CourseTeacher = cur1->val.CourseTeacher;

						flg = true;

						nameSet.insert(cur1->val.CourseName);
					}

					std::ifstream file;
					file.open("Score.txt");
					if (file.is_open())
					{
						List<ScoreInformation>* head3 = new List<ScoreInformation>;
						List<ScoreInformation>* cur3 = head3;

						std::string line;

						while (std::getline(file, line))
						{
							cur3->next = new List<ScoreInformation>;
							cur3 = cur3->next;

							std::string source = line;
							std::stringstream ss2(source);

							getline(ss2, cur3->val.StudentID, ' ');
							getline(ss2, cur3->val.ClassID, ' ');

							std::string str;

							getline(ss2, str, ' ');
							cur3->val.UsualScore = stoi(str);
							getline(ss2, str, ' ');
							cur3->val.RollScore = stoi(str);
							getline(ss2, str);
							cur3->val.Score = stoi(str);
						}

						cur3 = head3->next;

						double totalcount = 0;
						double failcount = 0;
						double percentage = 0;

						while (cur3 != nullptr)
						{
							if (cur2->val.CourseNumber == cur3->val.ClassID)
							{
								totalcount++;
								if (cur3->val.Score < 60)
								{
									failcount++;
								}
							}

							cur3 = cur3->next;
						}

						percentage = failcount / totalcount * 100;

						if (flg)
						{
							std::cout << "������" << cur2->val.CourseName << "    �κţ�" << cur2->val.CourseNumber << std::endl;
							std::cout << "��������" << (int)totalcount << "    ������������" << (int)failcount << "    ������ٷֱ�" << std::fixed << std::setprecision(1) << percentage << "%" << std::endl;
							std::cout << "------------------------------------------------------" << std::endl;

							heights.emplace_back((int)totalcount - (int)failcount);

							totalperson.emplace_back((int)totalcount);

							coursenumber.emplace_back(cur2->val.CourseNumber);

						}

						deleteList(head3);

						file.close();
					}
					else
					{
						std::cout << "��Score.txt���ļ�δ�ɹ���" << std::endl;
						std::cout << "------------------------------------------------------" << std::endl;
					}

					cur1 = cur1->next;
				}

				deleteList(head1);

				File.close();

				/*
					���ƿκŶ�Ӧ����������ֱ��ͼ
				*/

				std::cout << std::endl << "��״ֱ��ͼ��������Ϊ�κţ�������Ϊ�����������" << std::endl << std::endl;

				int max_value = *max_element(totalperson.begin(), totalperson.end());

				for (int i = max_value; i >= 0; i--)
				{
					std::cout << std::setw(2) << i << "|";

					for (int j = 0; j < heights.size(); j++)
					{
						if (heights[j] >= i)
						{
							std::cout << "   *  ";
						}
						else
						{
							std::cout << "      ";
						}
					}

					std::cout << std::endl;
				}

				std::cout << "   --------------------------------------------------------" << std::endl;
				std::cout << "     ";

				for (int i = 0; i < heights.size(); i++)
				{
					std::cout << coursenumber[i] << "   ";
				}

				std::cout << std::endl << std::endl;
				std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;


			}
			else
			{
				std::cout << "��Course.txt���ļ�δ�ɹ���" << std::endl;
				std::cout << "------------------------------------------------------" << std::endl;
			}

		}
		//����Ա��ѧ���ɼ���ͳ��
		else if (decision == "3")
		{
			std::ifstream File;
			File.open("Student.txt");
			if (File.is_open())
			{
				std::vector<int> heights;

				std::vector<int> totalcourse;

				std::vector<std::string>studentid;

				List<StudentInformation>* head1 = new List <StudentInformation>;
				List<StudentInformation>* cur1 = head1;

				std::string Line;

				while (std::getline(File, Line))
				{

					cur1->next = new List<StudentInformation>;
					cur1 = cur1->next;

					std::string Source = Line;
					std::stringstream ss1(Source);

					getline(ss1, cur1->val.StudentID, ' ');
					getline(ss1, cur1->val.StudentName, ' ');
					getline(ss1, cur1->val.StudentGender, ' ');
					getline(ss1, cur1->val.StudentAge, ' ');
					getline(ss1, cur1->val.StudentSystem);
				}

				cur1 = head1->next;

				while (cur1 != nullptr)
				{
					std::ifstream file;
					file.open("Score.txt");
					if (file.is_open())
					{
						List<ScoreInformation>* head2 = new List<ScoreInformation>;
						List<ScoreInformation>* cur2 = head2;

						std::string line;

						while (std::getline(file, line))
						{
							cur2->next = new List<ScoreInformation>;
							cur2 = cur2->next;

							std::string source = line;
							std::stringstream ss2(source);

							getline(ss2, cur2->val.StudentID, ' ');
							getline(ss2, cur2->val.ClassID, ' ');

							std::string str;

							getline(ss2, str, ' ');
							cur2->val.UsualScore = stoi(str);
							getline(ss2, str, ' ');
							cur2->val.RollScore = stoi(str);
							getline(ss2, str);
							cur2->val.Score = stoi(str);
						}

						cur2 = head2->next;

						int totalcount = 0;
						int failcount = 0;

						while (cur2 != nullptr)
						{
							if (cur2->val.StudentID == cur1->val.StudentID)
							{

								totalcount++;
								if (cur2->val.Score < 60)
								{
									failcount++;
								}
							}

							cur2 = cur2->next;
						}

						std::cout << "������" << cur1->val.StudentName << "    ѧ�ţ�" << cur1->val.StudentID << std::endl;
						std::cout << "�ܿ�����" << totalcount << "    �����������" << failcount << std::endl;
						std::cout << "------------------------------------------------------" << std::endl;

						heights.emplace_back(totalcount - failcount);

						totalcourse.emplace_back(totalcount);

						studentid.emplace_back(cur1->val.StudentID);


						deleteList(head2);

						file.close();
					}
					else
					{
						std::cout << "��Score.txt���ļ�δ�ɹ���" << std::endl;
						std::cout << "------------------------------------------------------" << std::endl;
					}

					cur1 = cur1->next;
				}

				deleteList(head1);

				File.close();

				/*
					����ѧ�Ŷ�Ӧ����γ�����ֱ��ͼ
				*/

				std::cout << std::endl << "��״ֱ��ͼ��������Ϊѧ�ţ�������Ϊ����Ŀγ�����" << std::endl << std::endl;

				/*
					max_element ��������ָ����Χ�ڲ��Ҿ������ֵ��Ԫ�� 
					�������ģ�嶨���� <algorithm> ͷ�ļ��У�������һ����������ָ��Χ�ڵ����ֵԪ�� �����Χ�ڵ�����Ԫ�ض���ȣ��򷵻�ָ��÷�Χ�ڵ�һ��Ԫ�صĵ�����
					�������������洢Ԫ�ص�ֵ����ֻ��ָ�������е�һ��Ԫ�� ��'*'�����ú�洢
				*/

				int max_value = *max_element(totalcourse.begin(), totalcourse.end());

				for (int i = max_value; i >= 0; i--)
				{
					std::cout << std::setw(2) << i << "|";

					for (int j = 0; j < heights.size(); j++)
					{
						if (heights[j] >= i)
						{
							std::cout << "  *  ";
						}
						else
						{
							std::cout << "     ";
						}
					}

					std::cout << std::endl;
				}

				std::cout << "   --------------------------------------------------------" << std::endl;
				std::cout << "     ";

				for (int i = 0; i < heights.size(); i++)
				{
					std::cout << studentid[i] << "   ";
				}

				std::cout << std::endl << std::endl;
				std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;


			}
			else
			{
				std::cout << "��Student.txt���ļ�δ�ɹ���" << std::endl;
				std::cout << "------------------------------------------------------" << std::endl;
			}
		}
		else if (decision == "4")
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