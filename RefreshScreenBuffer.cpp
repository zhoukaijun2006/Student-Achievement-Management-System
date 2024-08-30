#define _CRT_SECURE_NO_WARNINGS

#include "RefreshScreenBuffer.h"

void printtime()
{

    /* ��ȡ��ǰʱ���
       std::chrono::system_clock::now()��ȡ��ǰʱ���
       std::chrono::system_clock��<chrono>ͷ�ļ��ж����һ��ʱ������
       now()��һ����̬���������ر�ʾ��ǰʱ����std::chrono::system_clock::time_point���͵�ֵ��time_point��һ��ʱ���
    */
    auto now = std::chrono::system_clock::now();
    /* ת��Ϊtime_t����
       to_time_t ��һ����̬��Ա���������� std::chrono::system_clock::time_point ת��Ϊ std::time_t ���͵�ֵ
       std::time_t ��һ���� <ctime> ͷ�ļ��ж������������
    */
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    /* ת��Ϊ����ʱ��
       std::localtime ��һ���� <ctime> ͷ�ļ��ж���ĺ�����������һ��ָ�� std::time_t�����ָ�룬������һ��ָ�� std::tm �ṹ��ָ��
       std::tm ��һ���ṹ�壬�����˷ֽ��ʱ����Ϣ�����ꡢ�¡��ա�Сʱ�����ӡ���ȣ�

       localtime��������Ϊ�ǲ���ȫ�ģ���Ϊ��������������������Ȱ�ȫ���� 
    */
    std::tm* now_c = std::localtime(&in_time_t);

    /* ʹ��put_time����ʽ������ʾʱ��
       std::put_time ��һ���� <iomanip> ͷ�ļ��ж����I/O���ݷ���������һ��ָ�� std::tm �����ָ���һ����ʽ�ַ�����������ʽ����ʱ���������֮���������С�
       ��ʽ�ַ��� "%Y-%m-%d %H:%M:%S" ָ��������ĸ�ʽ������ %Y��%m��%d �ֱ������λ������ݡ��·ݡ����ڣ�%H��%M��%S �ֱ����Сʱ�����ӡ��롣
    */

    std::cout << "+------------------------------------------+" << std::endl;
    std::cout << "|" << "      ��ǰʱ��: " << std::put_time(now_c, "%Y-%m-%d %H:%M:%S") << "       " << "|" << std::endl;
    std::cout << "+------------------------------------------+" << std::endl << std::endl;
}


/*
    #ifdef _WIN32   ��һ��Ԥ����ָ����ڼ�� _WIN32 ���Ƿ��Ѷ��塣_WIN32 ���� Windows ϵͳ���ɱ������Զ����塣
    ��� _WIN32 �Ѷ��壬������������std::system("cls") �� Windows �ϣ����д������ std::system ����ִ�� cls ���������������������д��ڵ���Ļ��
     
    #elif __linux__ ��� _WIN32 δ���壬��Ԥ���������� __linux__ ���Ƿ��Ѷ��塣__linux__ ���� Linux ϵͳ���ɱ������Զ����塣
    ��� _WIN32 δ������ __linux__ �Ѷ��壬���������std::system("clear") �� Linux �ϣ����д������ std::system ����ִ�� clear �����������������ն˵���Ļ��
*/
void cls()
{

#ifdef _WIN32
    std::system("cls");
#elif  __linux__ 
    std::system("clear");
#endif

}

void RefreshScreenBuffer()
{
	cls();
    printtime();
}