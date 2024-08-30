
/*
    printProgressBar����Ϊ"������"��ʾ����
    barwith��ʾ���������
    int pos = barwidth * progress / total ���ݵ�ǰ���Ⱥ��ܽ��ȵı�����������ڽ�������Ӧ����ʾ������ɡ����ֵ�λ�ã�pos��
    ʹ��forѭ�����б���������λ��

    �����ǰλ��i<pos����������ɡ����֣������ӡ�Ⱥţ�=������ʾ�����
    �����ǰλ��i=pos���������ڽ��С���λ�ã������ӡ���ںţ�>������ʾ��ǰ����
    �����ǰλ��i>pos������δ��ɡ����֣������ӡ�ո�����ʾ��δ���

     std::cout.flush() ˢ�������������ȷ��������ʾ
     std::this_thread ��һ�������ռ� ���ṩ��һ�ַ���ķ�ʽ����ѯ�������ǰ����ִ�е��߳� sleep_for �� std::this_thread �����ռ��е�һ������
     ����ʹ��ǰ�߳���ִͣ��ָ����ʱ��Ρ������������һ����ʾʱ��εĲ����������ڸ�ʱ��ν���֮ǰ����ǰ�̲߳������ִ�С�

     std::chrono::milliseconds �� std::chrono �����ռ��е�һ������ʱ�����ͣ�ר�����ڱ�ʾ�Ժ���Ϊ��λ��ʱ��Ρ�

     std::this_thread::sleep_for(std::chrono::milliseconds(100))���д��뱻ִ��ʱ��������ͣ��ǰ�̵߳�ִ�У�ֱ��ָ����ʱ��Σ�100���룩��ȥ��
     ��ͨ������ģ���ʱ����������ִ�����ʻ�򵥵��ӳ�ִ�С�

*/

#include "ProgressBar.h"

void printProgressBar(int progress, int total)
{
    int barwidth = 70;
    int pos = barwidth * progress / total;

    std::cout << "[";

    for (int i = 0; i < barwidth; ++i)
    {
        if (i < pos)
        {
            std::cout << "=";
        }
        else if (i == pos)
        {
            std::cout << ">";
        }
        else
        {
            std::cout << " ";
        }
    }

    std::cout << "] " << int((progress / (float)total) * 100.0) << " %\r";

    std::cout.flush();  

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
