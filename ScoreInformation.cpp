#include"ScoreInformation.h"

bool ScoreInformation::isScoreExist(const std::string& studentID, const std::string& classID,  std::vector<ScoreInformation>& scores)
{
	std::vector<ScoreInformation>::const_iterator it; //����������

	for (it = scores.begin(); it != scores.end(); it++)
	{
		if (it->StudentID == studentID && it->ClassID == classID)
		{
			return true;
		}
	}

	return false;
}

void ScoreInformation::LoadScoresFromFile(std::vector<ScoreInformation>& scores)
{
	scores.clear();

	std::ifstream ScoreInformationFile;

	ScoreInformationFile.open("Score.txt");

	if (ScoreInformationFile.is_open())
	{

		std::string line;

		while (std::getline(ScoreInformationFile, line))
		{
			std::string source = line;
			std::stringstream ss(source);
			std::string str;

			getline(ss, str, ' ');

			if (!str.empty())
			{
				std::string studentid = str;
				getline(ss, str, ' ');
				std::string classid = str;
				getline(ss, str, ' ');
				std::string usualscore = str;
				getline(ss, str, ' ');
				std::string rollscore = str;
				getline(ss, str);
				std::string score = str;
				scores.emplace_back(studentid, classid, stoi(usualscore), stoi(rollscore), stoi(score));
			}
		
		}

		ScoreInformationFile.close();
	}
	else
	{
		std::cout << "��ȡ�γ���Ϣ����ʧ��" << std::endl;
		std::cout << "------------------------------------" << std::endl;
	}
}

void ScoreInformation::isIDNameExist(const std::string& Studentid, const std::string& ClassID, std::vector<ScoreInformation>& scores)
{
	std::vector<ScoreInformation>::iterator it;

	for (it = scores.begin(); it != scores.end(); it++)
	{
		if (it->StudentID == Studentid && it->ClassID == ClassID)
		{
			while (1)
			{
				std::cout << "�����Ӧ��ż���ѡ��:" << std::endl;
				std::cout << "1--�޸ĸóɼ�������Ϣ" << std::endl;
				std::cout << "2--ɾ���óɼ�������Ϣ" << std::endl;
				std::cout << "3--������һ���˵�" << std::endl;

				std::string Solution;
				std::getline(std::cin, Solution);

				RefreshScreenBuffer();

				if (Solution == "1")
				{
					while (1)
					{
						std::cout << "��ѡ�����޸Ĵ�ѧ������Ϣ����" << std::endl;
						std::cout << "1--ƽʱ�ɼ�" << std::endl;
						std::cout << "2--����ɼ�" << std::endl;
						std::cout << "3--�����޸�" << std::endl;

						std::string Usualscore;
						std::string Rollscore;

						std::string solution;
						std::getline(std::cin, solution);

						RefreshScreenBuffer();

						if (solution == "1")
						{
							while (1)
							{
								std::cout << "�������޸ĺ��ƽʱ�ɼ�(����End������һ��)" << std::endl;
								std::getline(std::cin, Usualscore);


								RefreshScreenBuffer();

								if (Usualscore == "End" || Usualscore == "end")
								{
									std::cout << "���سɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;
									break;
								}

								if (FindSpace(Usualscore) == 1)
								{
									std::cout << "����ƽʱ�ɼ���ʽ���� ��֧������ո�" << std::endl;
									continue;
								}

								if (NumberJudge(Usualscore) == -1)
								{
									std::cout << "δ�ɹ����룬����������" << std::endl;
									std::cout << "---------------------------------" << std::endl;
								}
								else if (NumberJudge(Usualscore) == -2)
								{
									std::cout << "����ɼ���ʽ��������������" << std::endl;
									std::cout << "----------------------------------" << std::endl;
								}
								else if (NumberJudge(Usualscore) == -3)
								{
									std::cout << "����ĳɼ���Χ��0--100֮�䣬�Ҳ��ܳ���С�������λ������������" << std::endl;
									std::cout << "--------------------------------------------------------------------------" << std::endl;
								}
								else
								{
									while (1)
									{
										std::cout << "���ٴ�ȷ���Ƿ��޸ģ�Yes/No��" << std::endl;
										std::string decision;
										std::getline(std::cin, decision);

										RefreshScreenBuffer();

										if (decision == "Yes" || decision == "yes")
										{
											it->UsualScore = NumberRounding(NumberJudge(Usualscore));
											std::cout << "�޸ĳɹ�" << std::endl;
											std::cout << "----------------------------------" << std::endl;
											break;
										}
										else if (decision == "No" || decision == "no")
										{
											std::cout << "�Ѿ�ȡ���޸�" << std::endl;
											std::cout << "----------------------------------" << std::endl;
											break;
										}
										else
										{
											std::cout << "ȷ�ϴ���������ȷ��" << std::endl;
											std::cout << "----------------------------------" << std::endl;
										}
									}
									break;
								}
							}
						}
						else if (solution == "2")
						{
							while (1)
							{
								std::cout << "�������޸ĺ��ƽʱ�ɼ�(����End������һ��)" << std::endl;
								std::getline(std::cin, Rollscore);

								RefreshScreenBuffer();

								if (Rollscore == "End" || Rollscore == "end")
								{
									std::cout << "���سɹ�" << std::endl;
									std::cout << "------------------------------------" << std::endl;
									break;
								}

								if (FindSpace(Rollscore) == 1)
								{
									std::cout << "�������ɼ���ʽ���� ��֧������ո�" << std::endl;
									continue;
								}

								if (NumberJudge(Rollscore) == -1)
								{
									std::cout << "δ�ɹ����룬����������" << std::endl;
									std::cout << "----------------------------------" << std::endl;
								}
								else if (NumberJudge(Rollscore) == -2)
								{
									std::cout << "����ɼ���ʽ��������������" << std::endl;
									std::cout << "----------------------------------" << std::endl;
								}
								else if (NumberJudge(Rollscore) == -3)
								{
									std::cout << "����ĳɼ���Χ��0--100֮�䣬�Ҳ��ܳ���С�������λ������������" << std::endl;
									std::cout << "--------------------------------------------------------------------------" << std::endl;
								}
								else
								{
									while (1)
									{
										std::cout << "���ٴ�ȷ���Ƿ��޸ģ�Yes/No��" << std::endl;
										std::string decision;
										std::getline(std::cin, decision);

										RefreshScreenBuffer();

										if (decision == "Yes" || decision == "yes")
										{
											it->RollScore = NumberRounding(NumberJudge(Rollscore));
											std::cout << "�޸ĳɹ�" << std::endl;
											std::cout << "----------------------------------" << std::endl;
											break;
										}
										else if (decision == "No" || decision == "no")
										{
											std::cout << "�Ѿ�ȡ���޸�" << std::endl;
											std::cout << "----------------------------------" << std::endl;
											break;
										}
										else
										{
											std::cout << "ȷ�ϴ���������ȷ��" << std::endl;
											std::cout << "----------------------------------" << std::endl;
										}
									}
									break;
								}
							}
						}
						else if (solution == "3")
						{
							std::cout << "�����ɹ�" << std::endl;
							std::cout << "----------------------------------" << std::endl;
							break;
						}
						else
						{
							std::cout << "ѡ�����������ѡ��" << std::endl;
							std::cout << "----------------------------------" << std::endl;
						}
					}
				}
				else if (Solution == "2")
				{
					std::cout << "*�����ݷǳ���Ҫ �����ѡ���Ƿ�ɾ��" << std::endl;
					std::cout << "------------------------------------------" << std::endl;

					while (1)
					{

						std::cout << "��ȷ���Ƿ�ɾ���óɼ�������Ϣ��Yes/No��" << std::endl;
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
									scores.erase(it);
									std::cout << "ɾ���ɹ�" << std::endl;
									std::cout << "----------------------------------" << std::endl;
									break;
								}
								else if (decision2 == "No" || decision2 == "no")
								{
									break;
								}
								else
								{
									std::cout << "ȷ�ϴ���������ȷ��" << std::endl;
									std::cout << "----------------------------------" << std::endl;
								}
							}
							break;
						}
						else if (decision1 == "No" || decision1 == "no")
						{
							std::cout << "�Ѿ�ȡ��ɾ��" << std::endl;
							std::cout << "----------------------------------" << std::endl;
							break;
						}
						else
						{
							std::cout << "ȷ�ϴ���������ȷ��" << std::endl;
							std::cout << "----------------------------------" << std::endl;
						}
					}

				}
				else if (Solution == "3")
				{
					std::cout << "���سɹ�" << std::endl;
					std::cout << "----------------------------------" << std::endl;
					break;
				}
				else
				{
					std::cout << "ѡ�����������ѡ��" << std::endl;
					std::cout << "----------------------------------" << std::endl;
				}
			}
			return;
		}
	}
	std::cout << "��ѧ���ÿγ����޳ɼ�" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return;
}

void ScoreInformation::SaveToFile(const std::vector<ScoreInformation>& scores)
{
	std::ofstream scoresFile;
	scoresFile.open("Score.txt");
	if (scoresFile.is_open())
	{
		for (auto score = scores.begin(); score != scores.end(); score++)
		{
			scoresFile << score->StudentID << " " << score->ClassID << " " << score->UsualScore << " " << score->RollScore << " " << score->Score << std::endl;
		}
	}
	else
	{
		std::cout << "�ĵ�δ�ɹ���" << std::endl;
	}
	scoresFile.close();
}

void ScoreInformation::SearchForFile()
{
	std::ifstream File;
	File.open("Score.txt");
	if (File.is_open())
	{
		//�˹���Ҫʵ�ָ�ʽ�������� �Ƚ���ȡ��ÿһ�����ݷֱ�洢�ڶ�Ӧ������
		std::string Line;

		std::vector<std::string>Studentid;
		std::vector<std::string>Classid;
		std::vector<std::string>Usualscore;
		std::vector<std::string>Rollscore;
		std::vector<std::string>Score;

		Studentid.emplace_back("ѧ��");
		Classid.emplace_back("�κ�");
		Usualscore.emplace_back("ƽʱ�ɼ�");
		Rollscore.emplace_back("����ɼ�");
		Score.emplace_back("�ܳɼ�");

		while (std::getline(File, Line))
		{
			std::string Source = Line;
			std::stringstream ss(Source);
			std::string str;
			getline(ss, str, ' ');
			Studentid.emplace_back(str);
			getline(ss, str, ' ');
			Classid.emplace_back(str);
			getline(ss, str, ' ');
			Usualscore.emplace_back(str);
			getline(ss, str, ' ');
			Rollscore.emplace_back(str);
			getline(ss, str, ' ');
			Score.emplace_back(str);
		}

		std::vector<int>maxlength(5, 0);

		//ͨ�������������ж�ÿ������ַ�����
		for (int i = 0; i < Studentid.size(); i++)
		{
			maxlength[0] = std::max(maxlength[0], (int)Studentid[i].size());
			maxlength[1] = std::max(maxlength[1], (int)Classid[i].size());
			maxlength[2] = std::max(maxlength[2], (int)Usualscore[i].size());
			maxlength[3] = std::max(maxlength[3], (int)Rollscore[i].size());
			maxlength[4] = std::max(maxlength[4], (int)Score[i].size());
		}
		//�������
		for (int i = 0; i < Studentid.size(); i++)
		{
			//����FormattingPrint�������о��ж������

			FormattingPrint(maxlength[0], Studentid[i]);
			FormattingPrint(maxlength[1], Classid[i]);
			FormattingPrint(maxlength[2], Usualscore[i]);
			FormattingPrint(maxlength[3], Rollscore[i]);
			FormattingPrint(maxlength[4], Score[i]);

			std::cout << std::endl;
		}

		File.close();
	}
	else
	{
		std::cout << "�ļ�δ�ɹ���" << std::endl;
	}
}