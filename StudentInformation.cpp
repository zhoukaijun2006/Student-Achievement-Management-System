#include "StudentInformation.h"
#include <regex>

bool StudentInformation::isIDExist(const std::string& studentID, std::vector<StudentInformation>& students)
{
	std::vector<StudentInformation>::const_iterator it;
	for (it = students.begin(); it != students.end(); it++)
	{
		if (it->StudentID == studentID)
		{
			return true;
		}
	}
	return false;
}

void StudentInformation::isIDNameExist(const std::string& StudentId, const std::string& Studentname, std::vector<StudentInformation>& students)
{
	std::vector<StudentInformation>::iterator it;
	for (it = students.begin(); it != students.end(); it++)
	{
		if (it->StudentID == StudentId && it->StudentName == Studentname)
		{
			while (1)
			{
				std::cout << "�����Ӧ��ż���ѡ��:" << std::endl;
				std::cout << "1--�޸ĸ�ѧ��������Ϣ" << std::endl;
				std::cout << "2--ɾ����ѧ��������Ϣ" << std::endl;
				std::cout << "3--������һ���˵�" << std::endl;

				std::string Solution;
				std::getline(std::cin, Solution);

				RefreshScreenBuffer();

				if (Solution == "1")
				{
					while (1)
					{
						std::cout << "��ѡ�����޸Ĵ�ѧ������Ϣ���ͣ��޸����ݲ�֧������ո�" << std::endl;
						std::cout << "1--ѧ��" << std::endl;
						std::cout << "2--����" << std::endl;
						std::cout << "3--�Ա�" << std::endl;
						std::cout << "4--����" << std::endl;
						std::cout << "5--����ϵ" << std::endl;
						std::cout << "6--�����޸�" << std::endl;

						std::string Studentid;
						std::string Studentname;
						std::string Studentgender;
						std::string Studentage;
						std::string Studentsystem;

						std::string solution;
						std::getline(std::cin, solution);

						RefreshScreenBuffer();

						if (solution == "1")
						{
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
								if (It->StudentID == StudentId)
								{
									std::cout << "��ѧ���Ѿ�¼��ɼ� �����޸�" << std::endl;
									std::cout << "------------------------------------" << std::endl;

									isRevise = false;
									break;
								}
							}

							if (isRevise == 0)
							{
								break;
							}

							while (1)
							{
								std::cout << "�������޸ĺ��ѧ��(����End������һ��)" << std::endl;

								std::getline(std::cin, Studentid);

								RefreshScreenBuffer();

								if (Studentid == "End" || Studentid == "end")
								{
									std::cout << "���سɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;

									break;
								}

								if (FindSpace(Studentid) == 1)
								{
									std::cout << "����ѧ�Ÿ�ʽ���� ��֧������ո�" << std::endl;
									continue;
								}

								RefreshScreenBuffer();

								while (1)
								{
									std::cout << "���ٴ�ȷ���Ƿ��޸ģ�Yes/No��" << std::endl;
									std::string decision;
									std::getline(std::cin, decision);

									RefreshScreenBuffer();

									if (decision == "Yes" || decision == "yes")
									{
										it->StudentID = Studentid;

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
							}


						}
						else if (solution == "2")
						{
							while (1)
							{
								std::cout << "�������޸ĺ������(����End������һ��)" << std::endl;

								std::getline(std::cin, Studentname);

								RefreshScreenBuffer();

								if (Studentname == "End" || Studentname == "end")
								{
									std::cout << "���سɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;

									break;
								}

								if (FindSpace(Studentname) == 1)
								{
									std::cout << "����������ʽ���� ��֧������ո�" << std::endl;
									continue;
								}

								RefreshScreenBuffer();

								while (1)
								{
									std::cout << "���ٴ�ȷ���Ƿ��޸ģ�Yes/No��" << std::endl;
									std::string decision;
									std::getline(std::cin, decision);

									RefreshScreenBuffer();

									if (decision == "Yes" || decision == "yes")
									{
										it->StudentName = Studentname;

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
								std::cout << "�������޸ĺ���Ա�(����End������һ��)" << std::endl;

								std::getline(std::cin, Studentgender);

								RefreshScreenBuffer();

								if (Studentgender == "End" || Studentgender == "end")
								{
									std::cout << "���سɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;

									break;
								}

								if (FindSpace(Studentgender) == 1)
								{
									std::cout << "�����Ա��ʽ���� ��֧������ո�" << std::endl;
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
										it->StudentGender = Studentgender;

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
							while (1)
							{
								std::cout << "�������޸ĺ������(����End������һ��)" << std::endl;

								std::getline(std::cin, Studentage);

								RefreshScreenBuffer();

								if (Studentage == "End" || Studentage == "end")
								{
									std::cout << "���سɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;

									break;
								}

								if (FindSpace(Studentage) == 1)
								{
									std::cout << "���������ʽ���� ��֧������ո�" << std::endl;
									continue;
								}


								while (1)
								{
									std::cout << "���ٴ�ȷ���Ƿ��޸ģ�Yes/No��" << std::endl;
									std::cout << "------------------------------------" << std::endl;

									std::string decision;
									std::getline(std::cin, decision);

									RefreshScreenBuffer();

									if (decision == "Yes" || decision == "yes")
									{
										it->StudentAge = Studentage;

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
						else if (solution == "5")
						{
							while (1)
							{
								std::cout << "�������޸ĺ������ϵ(����End������һ��)" << std::endl;

								std::getline(std::cin, Studentsystem);

								RefreshScreenBuffer();

								if (FindSpace(Studentsystem) == 1)
								{
									std::cout << "������������ϵ���� ��֧������ո�" << std::endl;
									continue;
								}

								if (Studentsystem == "End" || Studentsystem == "end")
								{
									std::cout << "���سɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;

									break;
								}

								while (1)
								{
									std::cout << "���ٴ�ȷ���Ƿ��޸ģ�Yes/No��" << std::endl;

									std::string decision;
									std::getline(std::cin, decision);

									RefreshScreenBuffer();

									if (decision == "Yes" || decision == "yes")
									{
										it->StudentSystem = Studentsystem;

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
						else if (solution == "6")
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

				else if (Solution == "2")
				{

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
						if (It->StudentID == StudentId)
						{
							std::cout << "��ѧ���Ѿ�¼��ɼ� ����ɾ��" << std::endl;
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

						std::cout << "��ȷ���Ƿ�ɾ����ѧ��������Ϣ��Yes/No��" << std::endl;
						std::string decision1;
						std::getline(std::cin, decision1);

						RefreshScreenBuffer();

						if (decision1 == "Yes" || decision1 == "yes")
						{
							while (1)
							{

								std::cout << "���ٴ�ȷ���Ƿ�ɾ����ѧ��������Ϣ��Yes/No��" << std::endl;
								std::string decision2;
								std::getline(std::cin, decision2);

								RefreshScreenBuffer();

								if (decision2 == "Yes" || decision2 == "yes")
								{
									students.erase(it);
									std::cout << "ɾ���ɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;
									break;
								}
								else if (decision2 == "No" || decision2 == "no")
								{
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
			}
			return;
		}
	}
	std::cout << "�޴�ѧ����Ϣ" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	return;
}

void StudentInformation::LoadStudentsFromFile(std::vector<StudentInformation> &students)
{
	std::ifstream StudentInformationFile;

	StudentInformationFile.open("Student.txt");

	if (StudentInformationFile.is_open())
	{

		std::string line;

		while (std::getline(StudentInformationFile, line))
		{
			std::string source = line;
			std::stringstream ss(source);
			std::string str;

			getline(ss, str, ' ');

			if (!str.empty())
			{

				std::string studentid = str;
				getline(ss, str, ' ');
				std::string studentname = str;
				getline(ss, str, ' ');
				std::string studentgender = str;
				getline(ss, str, ' ');
				std::string studentage = str;
				getline(ss, str);
				std::string studentsystem = str;

				students.emplace_back(studentid, studentname, studentgender, studentage, studentsystem);
			}

		}
		StudentInformationFile.close();
	}
	else
	{
		std::cout << "��ȡѧ����Ϣ����ʧ��" << std::endl;
		std::cout << "------------------------------------" << std::endl;
	}
}

void StudentInformation::SaveToFile(const std::vector<StudentInformation>& students)
{
	std::ofstream studentsFile;

	studentsFile.open("Student.txt");

	if (studentsFile.is_open())
	{
		for (auto student = students.begin(); student != students.end(); student++)
		{
			studentsFile << student->StudentID << " " << student->StudentName << " " << student->StudentGender << " " << student->StudentAge << " " << student->StudentSystem << std::endl;
		}
	}
	else
	{
		std::cout << "�ĵ�δ�ɹ���" << std::endl;
		std::cout << "------------------------------------" << std::endl;
	}
	studentsFile.close();
}

void StudentInformation::SearchForFile()
{
	std::ifstream File;
	File.open("Student.txt");
	if (File.is_open())
	{
		//�˹���Ҫʵ�ָ�ʽ�������� �Ƚ���ȡ��ÿһ�����ݷֱ�洢�ڶ�Ӧ������
		std::string Line;

		std::vector<std::string>Studentid;
		std::vector<std::string>Studentname;
		std::vector<std::string>Studentgender;
		std::vector<std::string>Studentage;
		std::vector<std::string>Studentsystem;

		Studentid.emplace_back("ѧ��");
		Studentname.emplace_back("����");
		Studentgender.emplace_back("�Ա�");
		Studentage.emplace_back("����");
		Studentsystem.emplace_back("����ϵ");

		while (std::getline(File, Line))
		{
			std::string Source = Line;
			std::stringstream ss(Source);
			std::string str;
			getline(ss, str, ' ');
			Studentid.emplace_back(str);
			getline(ss, str, ' ');
			Studentname.emplace_back(str);
			getline(ss, str, ' ');
			Studentgender.emplace_back(str);
			getline(ss, str, ' ');
			Studentage.emplace_back(str);
			getline(ss, str, ' ');
			Studentsystem.emplace_back(str);
		}

		std::vector<int>maxlength(5, 0);

		//ͨ�������������ж�ÿ������ַ�����
		for (int i = 0; i < Studentid.size(); i++)
		{
			maxlength[0] = std::max(maxlength[0], (int)Studentid[i].size());
			maxlength[1] = std::max(maxlength[1], (int)Studentname[i].size());
			maxlength[2] = std::max(maxlength[2], (int)Studentgender[i].size());
			maxlength[3] = std::max(maxlength[3], (int)Studentage[i].size());
			maxlength[4] = std::max(maxlength[4], (int)Studentsystem[i].size());
		}

		const int rowsPerpage = 10;

		//static_cast<int>�� C++ �е�һ������ת��������

		std::cout << std::endl;

		for (int i = 0; i < std::min(static_cast<int>(Studentid.size()), rowsPerpage); ++i)
		{
			FormattingPrint(maxlength[0], Studentid[i]);
			FormattingPrint(maxlength[1], Studentname[i]);
			FormattingPrint(maxlength[2], Studentgender[i]);
			FormattingPrint(maxlength[3], Studentage[i]);
			FormattingPrint(maxlength[4], Studentsystem[i]);
			std::cout << std::endl;
		}

		std::cout << "-------------------�� 1 ҳ-------------------" << std::endl;

		int pageNumber;
		std::cout << std::endl << "������ҳ��鿴���ࣨ����0�˳���: " << std::endl;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		while (std::cin >> pageNumber && pageNumber != 0)
		{

			RefreshScreenBuffer();
			if (pageNumber < 1)
			{
				std::cout << "ҳ��������0" << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << "����������ҳ��: ";
				continue;
			}

			int startIndex = (pageNumber - 1) * rowsPerpage;
			int endIndex = std::min(static_cast<int>(Studentid.size()), startIndex + rowsPerpage);

			if (startIndex >= endIndex)
			{
				std::cout << "ҳ�볬����Χ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << "������ҳ��鿴���ࣨ����0�˳���: ";
				continue;
			}

			for (int i = startIndex; i < endIndex; ++i) 
			{
				FormattingPrint(maxlength[0], Studentid[i]);
				FormattingPrint(maxlength[1], Studentname[i]);
				FormattingPrint(maxlength[2], Studentgender[i]);
				FormattingPrint(maxlength[3], Studentage[i]);
				FormattingPrint(maxlength[4], Studentsystem[i]);
				std::cout << std::endl;
			}

			std::cout << "-------------------�� " << pageNumber << " ҳ-------------------" << std::endl;

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