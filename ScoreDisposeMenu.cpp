#include "ScoreDisposeMenu.h"

void ScoreDisposeMenu(const std::string adminusername, const std::string adminpassword)
{
	while (1)
	{
		std::cout << "ȷ���Ƿ�ѡ���޸�/ɾ���ɼ�������Ϣ���ݣ�Yes/No��" << std::endl;
		std::string Scoredetermine;
		std::getline(std::cin, Scoredetermine);

		RefreshScreenBuffer();

		if (Scoredetermine == "yes" || Scoredetermine == "Yes")
		{
			while (1)
			{
				std::cout << "��Ҫ�ٴ������¼ʱ���˺����� ȷ����������" << std::endl;
				std::cout << "------------------------------------------------" << std::endl;
				std::cout << "���������Ա�˺ţ�����End������һ����" << std::endl;

				std::string username;
				std::getline(std::cin, username);

				RefreshScreenBuffer();

				if (username == "End" || username == "end")
				{
					std::cout << "���سɹ�" << std::endl;
					std::cout << "------------------------------------" << std::endl;
					break;
				}

				RefreshScreenBuffer();

				std::cout << "���������Ա����" << std::endl;

				std::string password;
				std::getline(std::cin, password);

				RefreshScreenBuffer();

				if (username == adminusername && password == adminpassword)
				{
					while (1)
					{
						std::cout << "��֤�ɹ�" << std::endl;

						std::cout << "���������޸�/ɾ����ѧ��������Ϣ" << std::endl;
						std::cout << "------------------------------------" << std::endl;

						std::cout << "������ѧ�����" << std::endl;

						std::string Studentid;
						std::getline(std::cin, Studentid);

						RefreshScreenBuffer();

						if (FindSpace(Studentid) == 1)
						{
							std::cout << "����ѧ�Ÿ�ʽ���� ��֧������ո�" << std::endl;
							continue;
						}

						std::cout << "������γ̱��" << std::endl;

						std::string Classid;
						std::getline(std::cin, Classid);

						RefreshScreenBuffer();

						if (FindSpace(Classid) == 1)
						{
							std::cout << "����κŸ�ʽ���� ��֧������ո�" << std::endl;
							continue;
						}

						std::vector<ScoreInformation>Scores;
						int usualscore = 0;
						int rollscore = 0;
						int score = 0;


						ScoreInformation Scoreinformation(Studentid, Classid, usualscore, rollscore, score);

						Scoreinformation.LoadScoresFromFile(Scores);
						Scoreinformation.isIDNameExist(Studentid, Classid, Scores);
						ScoreInformation::SaveToFile(Scores);

						break;
					}
				}

				else
				{
					std::cout << "��¼���� �����µ�¼" << std::endl;
					std::cout << "------------------------------------" << std::endl;

					continue;
				}

				break;
			}
		}
		else if (Scoredetermine == "no" || Scoredetermine == "No")
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
