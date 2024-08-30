#include "CourseInformation.h"

bool CourseInformation::isCourseExist(const std::string& coursenumber, const std::string& coursename, const std::string& courseteacher, std::vector<CourseInformation>& courses)
{
	std::vector<CourseInformation>::const_iterator it;
	for (it = courses.begin(); it != courses.end(); it++)
	{
		if (it->CourseNumber == coursenumber && it->CourseName == coursename && it->CourseTeacher == courseteacher)
		{
			return true;
		}
	}
	return false;
}

void CourseInformation::LoadCoursesFromFile(std::vector<CourseInformation>& courses)
{
	std::ifstream CourseInformationFile;
	CourseInformationFile.open("Course.txt");
	if (CourseInformationFile.is_open())
	{
		std::string line;
		while (std::getline(CourseInformationFile, line))
		{
			std::string source = line;
			std::stringstream ss(source);
			std::string str;
			getline(ss, str, ' ');
			if (!str.empty())
			{
				std::string coursenumber = str;
				getline(ss, str, ' ');
				std::string coursename = str;
				getline(ss, str);
				std::string courseteacher = str;
				courses.emplace_back(coursenumber, coursename, courseteacher);
			}
		}
		CourseInformationFile.close();
	}
	else
	{
		std::cout << "��ȡ�γ���Ϣ����ʧ��" << std::endl;
		std::cout << "------------------------------------" << std::endl;
	}
}

void CourseInformation::isIDNameExist(const std::string& courseNumber, const std::string& courseName, const std::string& courseTeacher, std::vector<CourseInformation>& courses)
{
	std::vector<CourseInformation>::iterator it;
	for (it = courses.begin(); it != courses.end(); it++)
	{
		if (it->CourseNumber == courseNumber && it->CourseName == courseName && it->CourseTeacher == courseTeacher)
		{
			while (1)
			{
				std::cout << "�����Ӧ��ż���ѡ��:" << std::endl;
				std::cout << "1--�޸ĸÿγ̻�����Ϣ" << std::endl;
				std::cout << "2--ɾ���ÿγ̻�����Ϣ" << std::endl;
				std::cout << "3--������һ���˵�" << std::endl;

				std::string Solution;
				std::getline(std::cin, Solution);

				RefreshScreenBuffer();

				if (Solution == "1")
				{
					while (1)
					{
						std::cout << "��ѡ�����޸Ĵ˿γ̵���Ϣ���ͣ��޸����ݲ�֧������ո�" << std::endl;
						std::cout << "1--�κ�" << std::endl;
						std::cout << "2--����" << std::endl;
						std::cout << "3--�ον�ʦ" << std::endl;
						std::cout << "4--�����޸�" << std::endl;

						std::string Coursenumber;
						std::string Coursename;
						std::string Courseteacher;

						std::string solution;
						std::getline(std::cin, solution);

						RefreshScreenBuffer();

						if (solution == "1")
						{
							//�жϸÿγ��Ƿ��Ѿ�¼��ɼ� ���¼����κŲ��ܱ��޸�
							std::string studentid;
							std::string classid;
							int usualscore = -1;
							int rollscore = -1;
							int score = -1;

							std::vector<ScoreInformation>Scores;

							ScoreInformation scoreinformation(studentid, classid, usualscore, rollscore, score);

							scoreinformation.LoadScoresFromFile(Scores);

							std::vector<ScoreInformation>::iterator It;

							bool ScoreExist = false;

							bool isRevise = true;

							for (It = Scores.begin(); It != Scores.end(); It++)
							{
								if (It->ClassID == courseNumber)
								{
									std::cout << "�ÿγ��Ѿ�¼��ɼ� �����޸Ŀκ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;
									isRevise = false;
									break;
								}
							}

							if (isRevise == 0)
							{
								break;
							}

							//��û��¼��ɼ� �����޸�
							while (1)
							{
								std::cout << "�������޸ĺ�Ŀκ�(����End������һ��)" << std::endl;
								std::getline(std::cin, Coursenumber);

								RefreshScreenBuffer();

								if (Coursenumber == "End" || Coursenumber == "end")
								{
									std::cout << "���سɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;
									break;
								}

								if (Coursenumber[0] != 'P' && Coursenumber[0] != 'S')
								{
									std::cout << "����κŸ�ʽ���󣨿κŵĵ�һλ������ΪS/P �ֱ����רҵ��/���������Σ�" << std::endl;
									std::cout << "------------------------------------------------------------------------" << std::endl;
									continue;
								}

								if (FindSpace(Coursenumber) == 1)
								{
									std::cout << "����κŸ�ʽ���� ��֧������ո�" << std::endl;
									continue;
								}

								while (1)
								{
									std::cout << "���ٴ�ȷ���Ƿ��޸ģ�Yes/No��" << std::endl;
									std::string decision;
									std::getline(std::cin, decision);

									RefreshScreenBuffer();

									if (decision == "Yes" || decision == "yes")
									{
										it->CourseNumber = Coursenumber;
										std::cout << "�޸ĳɹ�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
										break;
									}
									else if (decision == "No" || decision == "no")
									{
										std::cout << "�Ѿ�ȡ���޸�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
										break;
									}
									else
									{
										std::cout << "ȷ�ϴ���������ȷ��" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}
								}
								break;
							}
						}
						else if (solution == "2")
						{
							while (1)
							{
								std::cout << "�������޸ĺ�Ŀ���(����End������һ��)" << std::endl;
								std::getline(std::cin, Coursename);

								RefreshScreenBuffer();

								if (Coursename == "End" || Coursename == "end")
								{
									std::cout << "���سɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;
									break;
								}

								if (FindSpace(Coursenumber) == 1)
								{
									std::cout << "���������ʽ���� ��֧������ո�" << std::endl;
									continue;
								}

								while (1)
								{
									std::cout << "���ٴ�ȷ���Ƿ��޸ģ�Yes/No��" << std::endl;
									std::string decision;
									std::getline(std::cin, decision);

									RefreshScreenBuffer();

									if (decision == "Yes" || decision == "yes")
									{
										it->CourseName = Coursename;
										std::cout << "�޸ĳɹ�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
										break;
									}
									else if (decision == "No" || decision == "no")
									{
										std::cout << "�Ѿ�ȡ���޸�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
										break;
									}
									else
									{
										std::cout << "ȷ�ϴ���������ȷ��" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}
								}
								break;
							}
						}
						else if (solution == "3")
						{
							while (1)
							{
								std::cout << "�������޸ĺ���ον�ʦ(����End������һ��)" << std::endl;
								std::getline(std::cin, Courseteacher);

								RefreshScreenBuffer();

								if (Courseteacher == "End" || Courseteacher == "end")
								{
									std::cout << "���سɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;
									break;
								}

								if (FindSpace(Courseteacher) == 1)
								{
									std::cout << "�����ον�ʦ��ʽ���� ��֧������ո�" << std::endl;
									continue;
								}

								while (1)
								{
									std::cout << "���ٴ�ȷ���Ƿ��޸ģ�Yes/No��" << std::endl;
									std::string decision;
									std::getline(std::cin, decision);

									RefreshScreenBuffer();

									if (decision == "Yes" || decision == "yes")
									{
										it->CourseTeacher = Courseteacher;
										std::cout << "�޸ĳɹ�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
										break;
									}
									else if (decision == "No" || decision == "no")
									{
										std::cout << "�Ѿ�ȡ���޸�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
										break;
									}
									else
									{
										std::cout << "ȷ�ϴ���������ȷ��" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}
								}
								break;
							}
						}
						else if (solution == "4")
						{
							break;
						}
						else
						{
							std::cout << "ѡ�����������ѡ��" << std::endl;
							std::cout << "------------------------------------" << std::endl;
						}
					}
				}
				else if (Solution == "2")
				{
					//�жϸÿγ��Ƿ��Ѿ�¼��ɼ� ���¼�벻�ܱ�ɾ�� 
					std::string studentid;
					std::string classid;
					int usualscore = -1;
					int rollscore = -1;
					int score = -1;

					std::vector<ScoreInformation>Scores;

					ScoreInformation scoreinformation(studentid, classid, usualscore, rollscore, score);

					scoreinformation.LoadScoresFromFile(Scores);

					std::vector<ScoreInformation>::iterator It;

					bool ScoreExist = false;

					bool isDelete = true;

					for (It = Scores.begin(); It != Scores.end(); It++)
					{
						if (It->ClassID == courseNumber)
						{
							std::cout << "�ÿγ��Ѿ�¼��ɼ� ����ɾ��" << std::endl;
							std::cout << "------------------------------------" << std::endl;
							isDelete = false;
							break;
						}
					}

					if (isDelete == 0)
					{
						break;
					}

					std::cout << "*�����ݷǳ���Ҫ �����ѡ���Ƿ�ɾ��" << std::endl;

					while (1)
					{

						std::cout << "��ȷ���Ƿ�ɾ���ÿγ̻�����Ϣ��Yes/No��" << std::endl;
						std::string decision1;
						std::getline(std::cin, decision1);

						RefreshScreenBuffer();

						if (decision1 == "Yes" || decision1 == "yes")
						{
							while (1)
							{

								std::cout << "���ٴ�ȷ���Ƿ�ɾ���ÿγ̻�����Ϣ��Yes/No��" << std::endl;
								std::string decision2;
								std::getline(std::cin, decision2);

								RefreshScreenBuffer();

								if (decision2 == "Yes" || decision2 == "yes")
								{
									courses.erase(it);
									std::cout << "ɾ���ɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;
									break;
								}
								else if (decision2 == "No" || decision2 == "no")
								{
									std::cout << "�Ѿ�ȡ���޸�" << std::endl;
									std::cout << "------------------------------------" << std::endl;
									break;
								}
								else
								{
									std::cout << "ȷ�ϴ���������ȷ��" << std::endl;
									std::cout << "------------------------------------" << std::endl;
								}
							}
						}
						else if (decision1 == "No" || decision1 == "no")
						{
							std::cout << "�Ѿ�ȡ��ɾ��" << std::endl;
							std::cout << "------------------------------------" << std::endl;
							break;
						}
						else
						{
							std::cout << "ȷ�ϴ���������ȷ��" << std::endl;
							std::cout << "------------------------------------" << std::endl;
						}

						break;
					}

				}
				else if (Solution == "3")
				{
					break;
				}
				else
				{
					std::cout << "ѡ�����������ѡ��" << std::endl;
					std::cout << "------------------------------------" << std::endl;
				}

				break;
			}
			return;
		}
	}
	std::cout << "�޴˿γ���Ϣ" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	return;
}

void CourseInformation::SaveToFile(const std::vector<CourseInformation>& courses)
{
	std::ofstream coursesFile;
	coursesFile.open("Course.txt");
	if (coursesFile.is_open())
	{
		for (auto course = courses.begin(); course != courses.end(); course++)
		{
			coursesFile << course->CourseNumber << " " << course->CourseName << " " << course->CourseTeacher << std::endl;
		}
	}
	else
	{
		std::cout << "�ĵ�δ�ɹ���" << std::endl;
		std::cout << "------------------------------------" << std::endl;
	}
	coursesFile.close();
}

void CourseInformation::SearchForFile()
{
	std::ifstream File;
	File.open("Course.txt");
	if (File.is_open())
	{
		//�˹���Ҫʵ�ָ�ʽ�������� �Ƚ���ȡ��ÿһ�����ݷֱ�洢�ڶ�Ӧ������
		std::string Line;

		std::vector<std::string>Coursenumber;
		std::vector<std::string>Coursename;
		std::vector<std::string>Courseteacher;

		Coursenumber.emplace_back("�κ�");
		Coursename.emplace_back("����");
		Courseteacher.emplace_back("�ον�ʦ");

		while (std::getline(File, Line))
		{
			std::string Source = Line;
			std::stringstream ss(Source);
			std::string str;
			getline(ss, str, ' ');
			Coursenumber.emplace_back(str);
			getline(ss, str, ' ');
			Coursename.emplace_back(str);
			getline(ss, str);
			Courseteacher.emplace_back(str);
		}

		std::vector<int>maxlength(3, 0);

		//ͨ�������������ж�ÿ������ַ�����
		for (int i = 0; i < Coursenumber.size(); i++)
		{
			maxlength[0] = std::max(maxlength[0], (int)Coursenumber[i].size());
			maxlength[1] = std::max(maxlength[1], (int)Coursename[i].size());
			maxlength[2] = std::max(maxlength[2], (int)Courseteacher[i].size());
		}

		const int rowsPerpage = 10;

		std::cout << std::endl;

		for (int i = 0; i < std::min(static_cast<int>(Coursenumber.size()), rowsPerpage); i++)
		{
			FormattingPrint(maxlength[0], Coursenumber[i]);
			FormattingPrint(maxlength[1], Coursename[i]);
			FormattingPrint(maxlength[2], Courseteacher[i]);

			std::cout << std::endl;
		}

		std::cout << "--------------�� 1 ҳ--------------" << std::endl;

		int pageNumber;

		std::cout << std::endl << "������ҳ��鿴���ࣨ����0�˳���: " << std::endl;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		while (std::cin >> pageNumber && pageNumber != 0)
		{

			if (pageNumber == 0)
			{
				std::cout << "�˳��ɹ�" << std::endl;
				std::cout << "------------------------------------" << std::endl;
				break;
			}

			RefreshScreenBuffer();

			if (pageNumber < 1)
			{
				std::cout << "ҳ��������0" << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << "����������ҳ��: ";
				continue;
			}

			int startIndex = (pageNumber- 1) * rowsPerpage;

			int endIndex = std::min(static_cast<int>(Coursenumber.size()), startIndex + rowsPerpage);

			if (startIndex >= endIndex)
			{
				std::cout << "ҳ�볬����Χ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << "������ҳ��鿴���ࣨ����0�˳���: ";
				continue;
			}

			for (int i = startIndex; i < endIndex; i++)
			{
				FormattingPrint(maxlength[0], Coursenumber[i]);
				FormattingPrint(maxlength[1], Coursename[i]);
				FormattingPrint(maxlength[2], Courseteacher[i]);

				std::cout << std::endl;
			}

			std::cout << "--------------�� " << pageNumber << " ҳ--------------" << std::endl;

			std::cout << "������ҳ��鿴���ࣨ����0�˳���: ";
		}

		File.close();

		RefreshScreenBuffer();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		std::cout << "�ļ�δ�ɹ���" << std::endl;
		std::cout << "------------------------------------" << std::endl;
	}
}