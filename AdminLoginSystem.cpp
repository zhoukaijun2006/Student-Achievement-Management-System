
/*
	AdminLoginSystem.cpp�а�����
	AdminLoginProcedure() Ϊ����Ա��¼��������ܲ˵�ҳ
	AdminLoginSystem::SaveUsersToFile() Ϊ����Ա��ӹ���ʱ���ݿ��е��˺�����
	AdminLoginSystem::LoadUsersFromFile() Ϊ��¼��ȡ���ݿ��е��˺�����
	AdminLoginSystem::ManageUser(const std::string& username, const std::string& password) Ϊ����Ա��ӹ���ʱ�˺�����
	AdminLoginSystem::isLogin(const std::string& username, const std::string& password) Ϊ��¼�жϲ���
*/

#include "AdminLoginSystem.h"

void RevisePassword(const std::string AdminUserName, const std::string AdminPassword);

void AdminLoginProcedure(std::string& AdminUserName, std::string& AdminPassword, int& judgeadmin)
{
	while (1)
	{
		std::cout << "�˵��������Ӧ��ż���ѡ�񣩣�" << std::endl;
		std::cout << "1--������Ϣ����" << std::endl;
		std::cout << "2--��Ա��ݹ���" << std::endl;
		std::cout << "3--ѧ���ɼ�����" << std::endl;
		std::cout << "4--��ѯ��Ϣ����" << std::endl;
		std::cout << "5--�ɼ�ͳ�ƹ���" << std::endl;
		std::cout << "6--��¼�����޸�" << std::endl;
		std::cout << "7--�˳���¼" << std::endl;

		std::string resolution;
		std::getline(std::cin, resolution);

		RefreshScreenBuffer();

		//����Ա�Ի�����Ϣ�Ĺ���
		if (resolution == "1")
		{
			BasicInformationStorage();

			RefreshScreenBuffer();

		}
		//����Ա�Գ�Ա��ݵĹ���
		else if (resolution == "2")
		{
			AdminManage();

			RefreshScreenBuffer();

		}
		//����Ա��ѧ���ɼ��Ĺ���
		else if (resolution == "3")
		{
			StudentScoreManage(AdminUserName, AdminPassword);
		}
		//����Ա�Բ�ѯ��Ϣ�Ĺ���
		else if (resolution == "4")
		{
			QueryMessage();
		}
		//����Ա�Գɼ�ͳ�ƵĹ���
		else if (resolution == "5")
		{
			ScoreStatistics();
		}
		//����Ա�޸ĵ�¼����
		else if (resolution == "6")
		{
			//�޸Ĺ���Ա���� AdminPassword������������

			RevisePassword(AdminUserName, AdminPassword);
			std::cout << "------------------------------------" << std::endl;
		}
		else if (resolution == "7")
		{
			judgeadmin = 0;

			std::cout << "�˳��ɹ�" << std::endl;
			std::cout << "------------------------------------" << std::endl;

			break;
		}
		else
		{
			std::cout << "ѡ�����������ѡ��" << std::endl;
		}
	}
}

AdminLoginSystem::AdminLoginSystem(const char* filepath) : AdminFilePath(filepath) 
{
	LoadUsersFromFile();
};

//����Ա��ӹ���ʱ���ݿ��е��˺�����
void AdminLoginSystem::SaveUsersToFile()
{

	std::ofstream adminfile;

	adminfile.open(AdminFilePath);

	if (adminfile.is_open())
	{
		for (auto user = Users.begin(); user != Users.end(); user++)
		{
			adminfile << user->AdminName << " " << user->AdminPassword << std::endl;
		}
	}
	else
	{
		std::cout << "�洢�û���¼����ʧ��" << std::endl;
		std::cout << "------------------------------------" << std::endl;
	}
}

void RevisePassword(const std::string AdminUserName, const std::string AdminPassword)
{
	while (1)
	{
		std::cout << "�������޸ĺ�Ĺ���Ա���루��" << std::endl;

		std::string adminpassword;

		getline(std::cin, adminpassword);

		RefreshScreenBuffer();

		if (FindSpace(adminpassword) == 1)
		{
			std::cout << "����κŸ�ʽ���� ��֧������ո�" << std::endl;
			continue;
		}

		AdminLoginSystem adminLoginsystem("AdminData.txt");

		for (int i = 0; i < adminLoginsystem.Users.size(); i++)
		{
			if (adminLoginsystem.Users[i].AdminName == AdminUserName && adminLoginsystem.Users[i].AdminPassword == md5(AdminPassword))
			{
				adminLoginsystem.Users[i].AdminPassword = md5(adminpassword);

				std::cout << "�޸ĳɹ�" << std::endl;
				std::cout << "------------------------------------" << std::endl;

				break;
			}
		}

		adminLoginsystem.SaveUsersToFile();

		break;
	}
}

//��¼��ȡ���ݿ��е��˺�����
void AdminLoginSystem::LoadUsersFromFile()
{

	Users.clear();


	std::ifstream AdminFile;

	AdminFile.open(AdminFilePath);

	if (AdminFile.is_open())
	{
		std::string Line;

		while (std::getline(AdminFile, Line))
		{
			/* 
				std::string::npos��һ����̬��Ա���� ��ʾ�ַ����в����ڵ�λ��
				substr�������ڴ��ַ�������ȡ�Ӵ�
				�û����Ǵ��ַ����Ŀ�ʼ���ո�֮ǰ���������ո񣩵��Ӵ���
				�����Ǵӿո�֮�󣨰����ո��ĵ�һ���ַ�������β���Ӵ�
				size_t ��һ���޷����������ͣ����Ǳ�׼���ж����һ�����������ڱ�ʾ��С������
			*/
			size_t pos = Line.find(' ');

			if (pos != std::string::npos) 
			{
				std::string username = Line.substr(0, pos);
				std::string password = Line.substr(pos + 1);
				Users.emplace_back(username, password);
			}
			else
			{
				std::cout << "δ�ɹ���ȡ���ݿ��е�¼���ݵ��˺�����" << std::endl;
			}
		}
		AdminFile.close();

	}
	else
	{
		std::cout << "��ȡ�û���¼����ʧ��" << std::endl;
	}
}

//����Ա��ӹ���ʱ�˺�����
bool AdminLoginSystem::ManageUser(const std::string& username, const std::string& password)
{
	//���ڱ��������е�ÿ��Ԫ�� const����ͨ��user�޸������е�Ԫ�ء�
	for (const auto &user : Users)
	{
		if (user.AdminName == username)
		{
			return false;//�Ѿ��ǹ���Ա
		}
	}

	Users.emplace_back(username, md5(password));

	SaveUsersToFile();

	return true;//��ӳɹ�

	//���õ���������������
	
	//for (std::vector<User>::const_iterator it = users.begin(); it != users.end(); ++it)
	//{
	//	const User& user = *it;
	//	if (user.UserName == username && user)
	//	{
	//		return true;
	//	}
	//}
	//return false;

}

//��¼�ж�
int AdminLoginSystem::isLogin(const std::string& username, const std::string& password)
{
	for (const auto& user : Users)
	{
		if (user.AdminName == username && user.AdminPassword == md5(password))
		{
			return 1;//��¼�ɹ�
		}
		else if (user.AdminName == username && user.AdminPassword != md5(password))
		{
			return 2;//�������
		}
	}
	return 3;//�û���������
}