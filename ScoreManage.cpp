
/*
	
*/
	
/*  
	����3��ѧ���ɼ�¼�����ۺϳɼ�����
	1��ѧ���ɼ�¼�룺�ɼ���Ϣ������score�ļ���
	ѧ���ɼ�Ӧ�������������¼��ɼ���������Ӧ������¼�룬��ϵͳ�Զ�����ȡ����
	2���ۺϳɼ�����
	¼��ѧ���ɼ���Ϣ��ϣ�Ӧ�����ñ��湦�ܣ����湦������ǰ�ɼ������棬���湦�����к��ۺϳɼ������趨�����Զ����㡣�ۺϳɼ�����������
	���¼��γ�Ϊ�����Σ��� �ۺϳɼ� = ƽʱ�ɼ� * 30 % +����ɼ� * 70 %
	���¼��γ�Ϊרҵ�Σ��� �ۺϳɼ� = ƽʱ�ɼ� * 40 % +����ɼ� * 70 % .

	����6���ɼ��޸ļ�ɾ����Ҫ�����������룩
	1���ɼ��޸�
	���޸ĳɼ�֮ǰ�����ٴ���ȷ������������ܽ���ɼ��޸Ĳ˵����в�����
	ֻ�����޸�ѧ����ƽʱ�ɼ������ɼ����ۺϳɼ��������޸ģ�
	�ۺϳɼ������޸ĺ��ƽʱ�ɼ������ɼ����Զ�������¡�
	2���ɼ�ɾ��
	���Ը���ѧ��ѧ����γ̿κ�ɾ����Ӧ�ɼ���

*/

#include "ScoreManage.h"

void StudentScoreManage(std::string& AdminUserName, std::string& AdminPassword)
{
	while (1)
	{
		std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
		std::cout << "1--ѧ���γ̳ɼ���Ϣ¼��" << std::endl;
		std::cout << "2--�鿴ѧ���γ̳ɼ���Ϣ����" << std::endl;
		std::cout << "3--�޸�/ɾ��ѧ���γ̳ɼ���Ϣ" << std::endl;
		std::cout << "4--�˳��˵�" << std::endl;

		std::string decision;
		std::getline(std::cin, decision);

		RefreshScreenBuffer();

		//����Ա��ѧ���γ̳ɼ���Ϣ��¼��
		if (decision == "1")
		{
			ScoreStorage();
		}
		//����Ա��ѧ���γ̳ɼ���Ϣ�Ĳ鿴
		else if (decision == "2")
		{
			ScoreStorageSearch();
		}
		//����Ա��ѧ���γ̳ɼ���Ϣ���޸�
		else if (decision == "3")
		{
			ScoreDisposeMenu(AdminUserName, AdminPassword);
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

/*ScoreManage�������ã������ܳɼ�
	�κ�S��ͷ��ʾרҵ�Σ�P��ͷ��ʾ���������Ρ�
	���¼��γ�Ϊ�����Σ��� �ۺϳɼ� = ƽʱ�ɼ� * 30 % +����ɼ� * 70 %
	���¼��γ�Ϊרҵ�Σ��� �ۺϳɼ� = ƽʱ�ɼ� * 40 % +����ɼ� * 60 %
*/

int ScoreManage(std::string& classid, int usualscore, int rollscore, int score)
{
	if (classid[0] == 'S')
	{
		score = NumberRounding(usualscore * 0.3 + rollscore * 0.7);
	}
	else if (classid[0] == 'P')
	{
		score = NumberRounding(usualscore * 0.4 + rollscore * 0.6);
	}
	else
	{
		std::cout << "�ÿγ̲�����רҵ�κ͹��������Σ���ʱ�޷������ܳɼ�������0��" << std::endl;
		std::cout << "------------------------------------------------------------------------" << std::endl;
	}
	return score;
}