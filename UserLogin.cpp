#include "UserLogin.h"

void UserLogin::inputUserName()
{

	// ����ѧ���͹���Ա��¼ϵͳ��ʵ�����ֱ����ѧ���͹���Ա����
	StudentLoginSystem studentloginsystem("StudentData.txt"); 
	AdminLoginSystem  adminloginsystem("AdminData.txt");

	int judge1 = 1, judge2 = 1;
	int judgestudent = 0, judgeadmin = 0;
	int Judge = 1;

	std::string AdminUserName;
	std::string AdminPassword;
	std::string StudentUserName;
	std::string StudentPassword;

	RefreshScreenBuffer();

	//��ѭ�������ڴ����û���¼��ע��
	while (1)
	{
		// ��ʾ��¼��ʽѡ�� 
		std::cout << "��ѡ�����ĵ�¼��ʽ������End�˳�����" << std::endl;
		std::cout << "1--ѧ����¼" << std::endl;
		std::cout << "2--����Ա��¼" << std::endl;

		adminloginsystem.LoadUsersFromFile();

		std::string determinenumber;

		std::getline(std::cin, determinenumber);

		RefreshScreenBuffer();

		if (determinenumber == "End" || determinenumber == "end")
		{
			std::cout << "�˳��ɹ�" << std::endl;
			std::cout << "------------------------------------" << std::endl;

			break;
		}
		// ����ѧ����¼
		else if (determinenumber == "1")
		{
			while (1)
			{
				studentloginsystem.LoadUsersFromFile();
				std::cout << "������ѡ��ע����¼������End������һ����" << std::endl;
				std::cout << "1--ע��" << std::endl;
				std::cout << "2--��¼" << std::endl;

				std::string choicenumber;
				std::getline(std::cin, choicenumber);

				RefreshScreenBuffer();

				if (choicenumber == "end" || choicenumber == "End")
				{
					std::cout << "���سɹ�" << std::endl;
					std::cout << "------------------------------------" << std::endl;

					break;
				}

				// �û�ѡ��ע��
				else if (choicenumber == "1")
				{
					std::string username;

					while (1)
					{
						std::cout << "ע��--����������ѧ�ţ���֧������ո�" << std::endl;

						std::getline(std::cin, username);

						RefreshScreenBuffer();

						if (username.find(' ') != std::string::npos)
						{
							std::cout << "�����ʽ���� ��֧������ո�" << std::endl;
							std::cout << "------------------------------------" << std::endl;

							continue;
						}
						break;

					}

					while (1)
					{
						std::cout << "ע��--�������������루��֧������ո�" << std::endl;
						std::string password1;
						std::getline(std::cin, password1);

						if (password1.find(' ') != std::string::npos)
						{
							std::cout << "�����ʽ���� ��֧������ո�" << std::endl;
							continue;
						}

						std::cout << "ע��--���ٴ������Ա�ȷ���������루��֧������ո�" << std::endl;
						std::string password2;
						std::getline(std::cin, password2);

						RefreshScreenBuffer();

						if (password1 == password2)
						{
							if (studentloginsystem.RegisterUser(username, password1) == 1)
							{
								std::cout << "ע��ɹ�" << std::endl;
								std::cout << "------------------------------------" << std::endl;
								judge1 = 0;
								break;
							}
							else
							{
								std::cout << "�û��Ѵ��ڣ������ظ�ע��" << std::endl;
								std::cout << "------------------------------------" << std::endl;
								Judge = 0;
								break;
							}
						}
						else
						{
							std::cout << "�������벻��ͬ��������������������" << std::endl;
							std::cout << "------------------------------------" << std::endl;
						}
					}
					if (judge1 == 0)
					{
						break;
					}
				}
				// �û�ѡ���¼
				else if (choicenumber == "2")
				{

					while (1)
					{
						std::cout << "��¼--����������ѧ�ţ�����End������һ���� " << std::endl;

						std::getline(std::cin, UserName);

						if (UserName == "End" || UserName == "end")
						{
							RefreshScreenBuffer();

							std::cout << "���سɹ�" << std::endl;
							std::cout << "------------------------------------" << std::endl;
							
							break;
						}

						RefreshScreenBuffer();

						std::cout << "��¼--��������������" << std::endl;
						std::getline(std::cin, Password);

						RefreshScreenBuffer();

						/*
							��¼������
						*/

						std::cout << "���ڵ�¼�� ���Ժ�" << std::endl;

						for (int i = 0; i <= 100; i = i + 4)
						{
							printProgressBar(i, 100);
						}

						RefreshScreenBuffer();

						/*
							�������������
						*/

						if (studentloginsystem.isLogin(UserName, Password) == 1)
						{
							std::cout << "��½�ɹ�" << std::endl;
							std::cout << "------------------------------------" << std::endl;
							judge1 = 0;
							judgestudent = 1;
							StudentUserName = UserName;
							StudentPassword = Password;
							break;
						}

						if (studentloginsystem.isLogin(UserName, Password) == 2)
						{
							std::cout << "������� �����µ�¼" << std::endl;
							std::cout << "------------------------------------" << std::endl;
						}

						if (studentloginsystem.isLogin(UserName, Password) == 3)
						{
							std::cout << "���û�����δע�� �����µ�¼" << std::endl;
							std::cout << "------------------------------------" << std::endl;
						}
					}

					if (judge1 == 0)
					{
						break;
					}
				}
				else
				{
					std::cout << "�������" << std::endl;
					std::cout << "------------------------------------" << std::endl;
				}
			}
			if (judge2 == 0)
			{
				break;
			}

		}

		// �������Ա��¼ 
		else if (determinenumber == "2")
		{
			adminloginsystem.LoadUsersFromFile();

			// ����Ա��¼ѭ��  
			while (1)
			{
				std::cout << "��¼--���������Ĺ���Ա�û���������End������һ���� " << std::endl;

				std::getline(std::cin, UserName);

				RefreshScreenBuffer();

				if (UserName == "end" || UserName == "End")
				{

					std::cout << "���سɹ�" << std::endl;
					std::cout << "------------------------------------" << std::endl;
					break;
				}

				std::cout << "��¼--��������������" << std::endl;

				std::getline(std::cin, Password);

				RefreshScreenBuffer();

				/*
					��¼������
				*/

				std::cout << "���ڵ�¼�� ���Ժ�" << std::endl;

				for (int i = 0; i <= 100; i = i + 4)
				{
					printProgressBar(i, 100);
				}

				RefreshScreenBuffer();

				/*
					�������������
				*/

				if (adminloginsystem.isLogin(UserName, Password) == 1)
				{
					std::cout << "��½�ɹ�" << std::endl;
					std::cout << "------------------------------------" << std::endl;
					judge2 = 0;
					judgeadmin = 1;
					AdminUserName = UserName;
					AdminPassword = Password;
					break;
				}

				if (adminloginsystem.isLogin(UserName, Password) == 2)
				{
					std::cout << "������� �����µ�¼" << std::endl;				
					std::cout << "------------------------------------" << std::endl;
				}

				if (adminloginsystem.isLogin(UserName, Password) == 3)
				{
					std::cout << "���û�����δע�� �����µ�¼" << std::endl;
					std::cout << "------------------------------------" << std::endl;
				}
			}
		}
		else
		{
			std::cout << "ѡ�����������ѡ�����ĵ�¼��ʽ" << std::endl;
			std::cout << "------------------------------------" << std::endl;
		}

	//����Ϊ�ɹ���¼��Ĳ˵��ͳ���

	    //ѧ����¼ϵͳ��
		if (judgestudent == 1)
		{
			StudentLoginProcedure(StudentUserName, judgestudent);
		}

		//����Ա��¼ϵͳ��
		if (judgeadmin == 1)
		{
			AdminLoginProcedure(AdminUserName, AdminPassword, judgeadmin);
		}

	}
}