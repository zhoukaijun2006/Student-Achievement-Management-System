
/*
	AdminManage() Ϊ����Ա�Գ�Ա��ݵĹ����ʵ�ֺ���
	�˺������Խ��ض��˺���������Ϊ����Ա��¼���˺�����
*/
#include "AdminManage.h"

void AdminManage()
{
	while (1)
	{
		int judge1 = 1;

		AdminLoginSystem  adminloginsystem("AdminData.txt");

		std::cout << "��������Ϊ������˺ţ�����End������һ����" << std::endl;
		std::string username;
		std::getline(std::cin, username);

		RefreshScreenBuffer();


		if (username == "End" || username == "end")
		{
			break;
		}
		else
		{
			while (1)
			{
				std::cout << "��������Ϊ���������" << std::endl;
				std::string password1;
				std::getline(std::cin, password1);

				std::cout << "���ٴ�������Ϊ���������" << std::endl;
				std::string password2;
				std::getline(std::cin, password2);

				RefreshScreenBuffer();

				
				if (password1 == password2)
				{

					if (adminloginsystem.ManageUser(username, password1) == 1)
					{
						std::cout << "���óɹ�" << std::endl;
						std::cout << "------------------------------------" << std::endl;
						break;
					}
					else
					{
						std::cout << "�û��Ѵ��ڣ������ظ�����" << std::endl;
						std::cout << "------------------------------------" << std::endl;
						break;
					}
				}
				else
				{
					std::cout << "�������벻��ͬ��������������������" << std::endl;
					std::cout << "------------------------------------" << std::endl;
				}
			}
		}
	}
}
