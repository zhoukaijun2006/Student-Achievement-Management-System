#include "QueryMessageFunction.h"

void QueryStudentFunction()
{
	while (1)
	{
		std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
		std::cout << "1--��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
		std::cout << "2--��������ѯѧ����Ϣ" << std::endl;
		std::cout << "3--���Ա��ѯѧ����Ϣ" << std::endl;
		std::cout << "4--�������ѯѧ����Ϣ" << std::endl;
		std::cout << "5--������ϵ��ѯѧУ��Ϣ" << std::endl;
		std::cout << "6--�˳��˵�" << std::endl;

		std::string decision;
		std::getline(std::cin, decision);

		RefreshScreenBuffer();

		if (decision == "1")
		{
			std::string id;
			std::cout << "������ѧ��" << std::endl;
			std::getline(std::cin, id);

			RefreshScreenBuffer();

			std::string studentid;
			std::string studentname;
			std::string studentgender;
			std::string studentage;
			std::string studentsystem;
			std::vector<StudentInformation>Students;

			StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

			Studentinformation.LoadStudentsFromFile(Students);

			std::vector<StudentInformation>::iterator it;

			bool isQuery = false;

			for (it = Students.begin(); it != Students.end(); it++)
			{
				if (it->StudentID == id)
				{
					std::cout << "��ѯ�ɹ�" << std::endl;
					std::cout << "------------------------------------" << std::endl;
					std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
					std::cout << "������" << it->StudentName << std::endl;
					std::cout << "�Ա�" << it->StudentGender << std::endl;
					std::cout << "���䣺" << it->StudentAge << std::endl;
					std::cout << "����ϵ��" << it->StudentSystem << std::endl;
					std::cout << "------------------------------------" << std::endl;

					isQuery = true;

					break;
				}
			}

			if (isQuery == 0)
			{
				std::cout << "���޴�ѧ�ŵ�ѧ����Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}

		}
		else if (decision == "2")
		{
			std::string name;
			std::cout << "����������" << std::endl;
			std::getline(std::cin, name);

			RefreshScreenBuffer();

			std::string studentid;
			std::string studentname;
			std::string studentgender;
			std::string studentage;
			std::string studentsystem;
			std::vector<StudentInformation>Students;

			StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

			Studentinformation.LoadStudentsFromFile(Students);

			std::vector<StudentInformation>::iterator it;

			bool isQuery = false;

			for (it = Students.begin(); it != Students.end(); it++)
			{
				if (it->StudentName == name)
				{
					std::cout << "��ѯ�ɹ�" << std::endl;
					std::cout << "------------------------------------" << std::endl;
					std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
					std::cout << "������" << it->StudentName << std::endl;
					std::cout << "�Ա�" << it->StudentGender << std::endl;
					std::cout << "���䣺" << it->StudentAge << std::endl;
					std::cout << "����ϵ��" << it->StudentSystem << std::endl;
					std::cout << "------------------------------------" << std::endl;
					isQuery = true;

					break;
				}
			}

			if (isQuery == 0)
			{
				std::cout << "���޴�������ѧ����Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
		}



		else if (decision == "3")
		{
			std::string gender;
			std::cout << "�������Ա�" << std::endl;
			std::getline(std::cin, gender);

			RefreshScreenBuffer();

			while (1)
			{
				std::string isconfirm;
				std::cout << "�Ƿ���������ѯҪ��Yes/No��" << std::endl;
				std::getline(std::cin, isconfirm);

				RefreshScreenBuffer();

				if (isconfirm == "Yes" || isconfirm == "yes")
				{
					while (1)
					{
						std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
						std::cout << "1--��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
						std::cout << "2--��������ѯѧ����Ϣ" << std::endl;
						std::cout << "3--�������ѯѧ����Ϣ" << std::endl;
						std::cout << "4--������ϵ��ѯѧ����Ϣ" << std::endl;
						std::string Decision;

						std::getline(std::cin, Decision);

						RefreshScreenBuffer();

						if (Decision == "1")
						{
							std::string id;
							std::cout << "������ѧ��" << std::endl;
							std::getline(std::cin, id);

							RefreshScreenBuffer();

							std::string studentid;
							std::string studentname;
							std::string studentgender;
							std::string studentage;
							std::string studentsystem;
							std::vector<StudentInformation>Students;

							StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

							Studentinformation.LoadStudentsFromFile(Students);

							std::vector<StudentInformation>::iterator it;

							bool isQuery = false;
							for (it = Students.begin(); it != Students.end(); it++)
							{
								if (it->StudentGender == gender && it->StudentID == id)
								{
									if (isQuery == 0)
									{
										std::cout << "��ѯ�ɹ�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
									std::cout << "������" << it->StudentName << std::endl;
									std::cout << "�Ա�" << it->StudentGender << std::endl;
									std::cout << "���䣺" << it->StudentAge << std::endl;
									std::cout << "����ϵ��" << it->StudentSystem << std::endl;
									std::cout << "------------------------------------" << std::endl;

									isQuery = true;
								}
							}

							if (isQuery == 0)
							{
								std::cout << "���޸��Ա��ѧ�ŵ�ѧ����Ϣ" << std::endl;
								std::cout << "------------------------------------" << std::endl;
							}

							break;

						}
						else if (Decision == "2")
						{
							std::string name;
							std::cout << "����������" << std::endl;
							std::getline(std::cin, name);

							RefreshScreenBuffer();

							std::string studentid;
							std::string studentname;
							std::string studentgender;
							std::string studentage;
							std::string studentsystem;
							std::vector<StudentInformation>Students;

							StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

							Studentinformation.LoadStudentsFromFile(Students);

							std::vector<StudentInformation>::iterator it;

							bool isQuery = false;

							for (it = Students.begin(); it != Students.end(); it++)
							{
								if (it->StudentGender == gender && it->StudentName == name)
								{
									if (isQuery == 0)
									{
										std::cout << "��ѯ�ɹ�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
									std::cout << "������" << it->StudentName << std::endl;
									std::cout << "�Ա�" << it->StudentGender << std::endl;
									std::cout << "���䣺" << it->StudentAge << std::endl;
									std::cout << "����ϵ��" << it->StudentSystem << std::endl;
									std::cout << "------------------------------------" << std::endl;

									isQuery = true;
								}
							}

							if (isQuery == 0)
							{
								std::cout << "���޸��Ա��������ѧ����Ϣ" << std::endl;
								std::cout << "------------------------------------" << std::endl;
							}

							break;

						}
						else if (Decision == "3")
						{
							std::string age;
							std::cout << "����������" << std::endl;
							std::getline(std::cin, age);

							RefreshScreenBuffer();

							while (1)
							{
								std::string Isconfirm;
								std::cout << "�Ƿ���������ѯҪ��Yes/No��" << std::endl;
								std::getline(std::cin, Isconfirm);

								RefreshScreenBuffer();

								if (Isconfirm == "Yes" || Isconfirm == "yes")
								{
									while (1)
									{
										std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
										std::cout << "1--��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
										std::cout << "2--��������ѯѧ����Ϣ" << std::endl;
										std::cout << "3--������ϵ��ѯѧ����Ϣ" << std::endl;

										std::string Resolution;

										std::getline(std::cin, Resolution);

										RefreshScreenBuffer();

										if (Resolution == "1")
										{
											std::string id;
											std::cout << "������ѧ��" << std::endl;
											std::getline(std::cin, id);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentAge == age && it->StudentGender == gender && it->StudentID == id)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸�ѧ��������Ա��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "2")
										{
											std::string name;
											std::cout << "����������" << std::endl;
											std::getline(std::cin, name);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentAge == age && it->StudentGender == gender && it->StudentName == name)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸�����������Ա��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "3")
										{
											std::string system;
											std::cout << "����������ϵ" << std::endl;
											std::getline(std::cin, system);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentAge == age && it->StudentGender == gender && it->StudentSystem == system)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸������Ա������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else
										{
											std::cout << "ѡ�����������ѡ��" << std::endl;
											std::cout << "------------------------------------" << std::endl;
										}
									}

									break;
								}
								else if (Isconfirm == "No" || Isconfirm == "no")
								{
									std::string studentid;
									std::string studentname;
									std::string studentgender;
									std::string studentage;
									std::string studentsystem;
									std::vector<StudentInformation>Students;

									StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

									Studentinformation.LoadStudentsFromFile(Students);

									std::vector<StudentInformation>::iterator it;

									bool isQuery = false;
									for (it = Students.begin(); it != Students.end(); it++)
									{
										if (it->StudentAge == age && it->StudentGender == gender)
										{
											if (isQuery == 0)
											{
												std::cout << "��ѯ�ɹ�" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
											std::cout << "������" << it->StudentName << std::endl;
											std::cout << "�Ա�" << it->StudentGender << std::endl;
											std::cout << "���䣺" << it->StudentAge << std::endl;
											std::cout << "����ϵ��" << it->StudentSystem << std::endl;
											std::cout << "------------------------------------" << std::endl;

											isQuery = true;
										}
									}

									if (isQuery == 0)
									{
										std::cout << "���޸�������Ա��ѧ����Ϣ" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									break;

								}
								else
								{
									std::cout << "ѡ�����������ѡ��" << std::endl;
									std::cout << "------------------------------------" << std::endl;
								}
							}
							break;
						}
						else if (Decision == "4")
						{
							std::string system;
							std::cout << "����������ϵ" << std::endl;
							std::getline(std::cin, system);

							RefreshScreenBuffer();

							while (1)
							{
								std::string Isconfirm;
								std::cout << "�Ƿ���������ѯҪ��Yes/No��" << std::endl;
								std::getline(std::cin, Isconfirm);

								RefreshScreenBuffer();

								if (Isconfirm == "Yes" || Isconfirm == "yes")
								{
									while (1)
									{
										std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
										std::cout << "1--��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
										std::cout << "2--��������ѯѧ����Ϣ" << std::endl;
										std::cout << "3--�������ѯѧ����Ϣ" << std::endl;
										std::string Resolution;

										std::getline(std::cin, Resolution);

										RefreshScreenBuffer();

										if (Resolution == "1")
										{
											std::string id;
											std::cout << "������ѧ��" << std::endl;
											std::getline(std::cin, id);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentGender == gender && it->StudentID == id)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸�ѧ���Ա������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "2")
										{
											std::string name;
											std::cout << "����������" << std::endl;
											std::getline(std::cin, name);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentGender == gender && it->StudentName == name)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸������Ա������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "3")
										{
											std::string age;
											std::cout << "����������" << std::endl;
											std::getline(std::cin, age);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentGender == gender && it->StudentAge == age)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸������Ա������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else
										{
											std::cout << "ѡ�����������ѡ��" << std::endl;
											std::cout << "------------------------------------" << std::endl;
										}
									}

									break;
								}
								else if (Isconfirm == "No" || Isconfirm == "no")
								{
									std::string studentid;
									std::string studentname;
									std::string studentgender;
									std::string studentage;
									std::string studentsystem;
									std::vector<StudentInformation>Students;

									StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

									Studentinformation.LoadStudentsFromFile(Students);

									std::vector<StudentInformation>::iterator it;

									bool isQuery = false;
									for (it = Students.begin(); it != Students.end(); it++)
									{
										if (it->StudentSystem == system && it->StudentGender == gender)
										{
											if (isQuery == 0)
											{
												std::cout << "��ѯ�ɹ�" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
											std::cout << "������" << it->StudentName << std::endl;
											std::cout << "�Ա�" << it->StudentGender << std::endl;
											std::cout << "���䣺" << it->StudentAge << std::endl;
											std::cout << "����ϵ��" << it->StudentSystem << std::endl;
											std::cout << "------------------------------------" << std::endl;

											isQuery = true;
										}
									}

									if (isQuery == 0)
									{
										std::cout << "���޸��Ա������ϵ��ѧ����Ϣ" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									break;

								}
								else
								{
									std::cout << "ѡ�����������ѡ��" << std::endl;
									std::cout << "------------------------------------" << std::endl;
								}
							}
							break;
						}
						else
						{
							std::cout << "ѡ�����������ѡ��" << std::endl;
							std::cout << "------------------------------------" << std::endl;
						}
					}
					break;
				}
				else if (isconfirm == "No" || isconfirm == "no")
				{
					std::string studentid;
					std::string studentname;
					std::string studentgender;
					std::string studentage;
					std::string studentsystem;
					std::vector<StudentInformation>Students;

					StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

					Studentinformation.LoadStudentsFromFile(Students);

					std::vector<StudentInformation>::iterator it;

					bool isQuery = false;
					for (it = Students.begin(); it != Students.end(); it++)
					{
						if (it->StudentGender == gender)
						{
							if (isQuery == 0)
							{
								std::cout << "��ѯ�ɹ�" << std::endl;
								std::cout << "------------------------------------" << std::endl;
							}

							std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
							std::cout << "������" << it->StudentName << std::endl;
							std::cout << "�Ա�" << it->StudentGender << std::endl;
							std::cout << "���䣺" << it->StudentAge << std::endl;
							std::cout << "����ϵ��" << it->StudentSystem << std::endl;
							std::cout << "------------------------------------" << std::endl;

							isQuery = true;
						}
					}

					if (isQuery == 0)
					{
						std::cout << "���޸��Ա��ѧ����Ϣ" << std::endl;
						std::cout << "------------------------------------" << std::endl;
					}

					break;
				}
				else
				{
					std::cout << "ѡ�����������ѡ��" << std::endl;
					std::cout << "------------------------------------" << std::endl;
				}
			}
		}

		else if (decision == "4")
		{
			std::string age;
			std::cout << "����������" << std::endl;
			std::getline(std::cin, age);

			RefreshScreenBuffer();

			while (1)
			{
				std::string isconfirm;
				std::cout << "�Ƿ���������ѯҪ��Yes/No��" << std::endl;
				std::getline(std::cin, isconfirm);

				RefreshScreenBuffer();

				if (isconfirm == "Yes" || isconfirm == "yes")
				{
					while (1)
					{
						std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
						std::cout << "1--��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
						std::cout << "2--��������ѯѧ����Ϣ" << std::endl;
						std::cout << "3--���Ա��ѯѧ����Ϣ" << std::endl;
						std::cout << "4--������ϵ��ѯѧ����Ϣ" << std::endl;

						std::string Decision;

						std::getline(std::cin, Decision);

						RefreshScreenBuffer();

						if (Decision == "1")
						{
							std::string id;
							std::cout << "������ѧ��" << std::endl;
							std::getline(std::cin, id);

							RefreshScreenBuffer();

							std::string studentid;
							std::string studentname;
							std::string studentgender;
							std::string studentage;
							std::string studentsystem;
							std::vector<StudentInformation>Students;

							StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

							Studentinformation.LoadStudentsFromFile(Students);

							std::vector<StudentInformation>::iterator it;

							bool isQuery = false;
							for (it = Students.begin(); it != Students.end(); it++)
							{
								if (it->StudentAge == age && it->StudentID == id)
								{
									if (isQuery == 0)
									{
										std::cout << "��ѯ�ɹ�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
									std::cout << "������" << it->StudentName << std::endl;
									std::cout << "�Ա�" << it->StudentGender << std::endl;
									std::cout << "���䣺" << it->StudentAge << std::endl;
									std::cout << "����ϵ��" << it->StudentSystem << std::endl;
									std::cout << "------------------------------------" << std::endl;

									isQuery = true;
								}
							}

							if (isQuery == 0)
							{
								std::cout << "���޸������ѧ�ŵ�ѧ����Ϣ" << std::endl;
								std::cout << "------------------------------------" << std::endl;
							}

							break;

						}
						else if (Decision == "2")
						{
							std::string name;
							std::cout << "����������" << std::endl;
							std::getline(std::cin, name);

							RefreshScreenBuffer();

							std::string studentid;
							std::string studentname;
							std::string studentgender;
							std::string studentage;
							std::string studentsystem;
							std::vector<StudentInformation>Students;

							StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

							Studentinformation.LoadStudentsFromFile(Students);

							std::vector<StudentInformation>::iterator it;

							bool isQuery = false;

							for (it = Students.begin(); it != Students.end(); it++)
							{
								if (it->StudentAge == age && it->StudentName == name)
								{
									if (isQuery == 0)
									{
										std::cout << "��ѯ�ɹ�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
									std::cout << "������" << it->StudentName << std::endl;
									std::cout << "�Ա�" << it->StudentGender << std::endl;
									std::cout << "���䣺" << it->StudentAge << std::endl;
									std::cout << "����ϵ��" << it->StudentSystem << std::endl;
									std::cout << "------------------------------------" << std::endl;

									isQuery = true;
								}
							}

							if (isQuery == 0)
							{
								std::cout << "���޸������������ѧ����Ϣ" << std::endl;
								std::cout << "------------------------------------" << std::endl;
							}

							break;

						}
						else if (Decision == "3")
						{
							std::string gender;
							std::cout << "�������Ա�" << std::endl;
							std::getline(std::cin, gender);

							RefreshScreenBuffer();

							while (1)
							{
								std::string Isconfirm;
								std::cout << "�Ƿ���������ѯҪ��Yes/No��" << std::endl;
								std::getline(std::cin, Isconfirm);

								RefreshScreenBuffer();

								if (Isconfirm == "Yes" || Isconfirm == "yes")
								{
									while (1)
									{
										std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
										std::cout << "1--��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
										std::cout << "2--��������ѯѧ����Ϣ" << std::endl;
										std::cout << "3--������ϵ��ѯѧ����Ϣ" << std::endl;

										std::string Resolution;

										std::getline(std::cin, Resolution);

										RefreshScreenBuffer();

										if (Resolution == "1")
										{
											std::string id;
											std::cout << "������ѧ��" << std::endl;
											std::getline(std::cin, id);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentAge == age && it->StudentGender == gender && it->StudentID == id)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸�ѧ��������Ա��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "2")
										{
											std::string name;
											std::cout << "����������" << std::endl;
											std::getline(std::cin, name);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentAge == age && it->StudentGender == gender && it->StudentName == name)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸�����������Ա��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "3")
										{
											std::string system;
											std::cout << "����������ϵ" << std::endl;
											std::getline(std::cin, system);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentAge == age && it->StudentGender == gender && it->StudentSystem == system)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸������Ա������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else
										{
											std::cout << "ѡ�����������ѡ��" << std::endl;
											std::cout << "------------------------------------" << std::endl;
										}
									}

									break;
								}
								else if (Isconfirm == "No" || Isconfirm == "no")
								{
									std::string studentid;
									std::string studentname;
									std::string studentgender;
									std::string studentage;
									std::string studentsystem;
									std::vector<StudentInformation>Students;

									StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

									Studentinformation.LoadStudentsFromFile(Students);

									std::vector<StudentInformation>::iterator it;

									bool isQuery = false;
									for (it = Students.begin(); it != Students.end(); it++)
									{
										if (it->StudentAge == age && it->StudentGender == gender)
										{
											if (isQuery == 0)
											{
												std::cout << "��ѯ�ɹ�" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
											std::cout << "������" << it->StudentName << std::endl;
											std::cout << "�Ա�" << it->StudentGender << std::endl;
											std::cout << "���䣺" << it->StudentAge << std::endl;
											std::cout << "����ϵ��" << it->StudentSystem << std::endl;
											std::cout << "------------------------------------" << std::endl;

											isQuery = true;
										}
									}

									if (isQuery == 0)
									{
										std::cout << "���޸�������Ա��ѧ����Ϣ" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									break;

								}
								else
								{
									std::cout << "ѡ�����������ѡ��" << std::endl;
									std::cout << "------------------------------------" << std::endl;
								}
							}
							break;
						}
						else if (Decision == "4")
						{
							std::string system;
							std::cout << "����������ϵ" << std::endl;
							std::getline(std::cin, system);

							RefreshScreenBuffer();

							while (1)
							{
								std::string Isconfirm;
								std::cout << "�Ƿ���������ѯҪ��Yes/No��" << std::endl;
								std::getline(std::cin, Isconfirm);

								RefreshScreenBuffer();

								if (Isconfirm == "Yes" || Isconfirm == "yes")
								{
									while (1)
									{
										std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
										std::cout << "1--��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
										std::cout << "2--��������ѯѧ����Ϣ" << std::endl;
										std::cout << "3--���Ա��ѯѧ����Ϣ" << std::endl;
										std::string Resolution;

										std::getline(std::cin, Resolution);

										RefreshScreenBuffer();

										if (Resolution == "1")
										{
											std::string id;
											std::cout << "������ѧ��" << std::endl;
											std::getline(std::cin, id);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentAge == age && it->StudentID == id)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸�ѧ�����������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "2")
										{
											std::string name;
											std::cout << "����������" << std::endl;
											std::getline(std::cin, name);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentAge == age && it->StudentName == name)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸��������������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "3")
										{
											std::string gender;
											std::cout << "�������Ա�" << std::endl;
											std::getline(std::cin, gender);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentAge == age && it->StudentGender == gender)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸������Ա������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else
										{
											std::cout << "ѡ�����������ѡ��" << std::endl;
											std::cout << "------------------------------------" << std::endl;
										}
									}

									break;
								}
								else if (Isconfirm == "No" || Isconfirm == "no")
								{
									std::string studentid;
									std::string studentname;
									std::string studentgender;
									std::string studentage;
									std::string studentsystem;
									std::vector<StudentInformation>Students;

									StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

									Studentinformation.LoadStudentsFromFile(Students);

									std::vector<StudentInformation>::iterator it;

									bool isQuery = false;
									for (it = Students.begin(); it != Students.end(); it++)
									{
										if (it->StudentSystem == system && it->StudentAge == age)
										{
											if (isQuery == 0)
											{
												std::cout << "��ѯ�ɹ�" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
											std::cout << "������" << it->StudentName << std::endl;
											std::cout << "�Ա�" << it->StudentGender << std::endl;
											std::cout << "���䣺" << it->StudentAge << std::endl;
											std::cout << "����ϵ��" << it->StudentSystem << std::endl;
											std::cout << "------------------------------------" << std::endl;

											isQuery = true;
										}
									}

									if (isQuery == 0)
									{
										std::cout << "���޸����������ϵ��ѧ����Ϣ" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									break;

								}
								else
								{
									std::cout << "ѡ�����������ѡ��" << std::endl;
									std::cout << "------------------------------------" << std::endl;
								}
							}
							break;
						}
						else
						{
							std::cout << "ѡ�����������ѡ��" << std::endl;
							std::cout << "------------------------------------" << std::endl;
						}
					}
					break;
				}
				else if (isconfirm == "No" || isconfirm == "no")
				{
					std::string studentid;
					std::string studentname;
					std::string studentgender;
					std::string studentage;
					std::string studentsystem;
					std::vector<StudentInformation>Students;

					StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

					Studentinformation.LoadStudentsFromFile(Students);

					std::vector<StudentInformation>::iterator it;

					bool isQuery = false;
					for (it = Students.begin(); it != Students.end(); it++)
					{
						if (it->StudentAge == age)
						{
							if (isQuery == 0)
							{
								std::cout << "��ѯ�ɹ�" << std::endl;
								std::cout << "------------------------------------" << std::endl;
							}

							std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
							std::cout << "������" << it->StudentName << std::endl;
							std::cout << "�Ա�" << it->StudentGender << std::endl;
							std::cout << "���䣺" << it->StudentAge << std::endl;
							std::cout << "����ϵ��" << it->StudentSystem << std::endl;
							std::cout << "------------------------------------" << std::endl;

							isQuery = true;
						}
					}

					if (isQuery == 0)
					{
						std::cout << "���޸������ѧ����Ϣ" << std::endl;
						std::cout << "------------------------------------" << std::endl;
					}

					break;
				}
				else
				{
					std::cout << "ѡ�����������ѡ��" << std::endl;
					std::cout << "------------------------------------" << std::endl;
				}
			}
		}

		else if (decision == "5")
		{
			std::string system;
			std::cout << "����������ϵ" << std::endl;
			std::getline(std::cin, system);

			RefreshScreenBuffer();
			
			while (1)
			{
				std::string isconfirm;
				std::cout << "�Ƿ���������ѯҪ��Yes/No��" << std::endl;
				std::getline(std::cin, isconfirm);

				RefreshScreenBuffer();

				if (isconfirm == "Yes" || isconfirm == "yes")
				{
					while (1)
					{
						std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
						std::cout << "1--��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
						std::cout << "2--��������ѯѧ����Ϣ" << std::endl;
						std::cout << "3--���Ա��ѯѧ����Ϣ" << std::endl;
						std::cout << "4--�������ѯѧ����Ϣ" << std::endl;

						std::string Decision;

						std::getline(std::cin, Decision);

						RefreshScreenBuffer();

						if (Decision == "1")
						{
							std::string id;
							std::cout << "������ѧ��" << std::endl;
							std::getline(std::cin, id);

							RefreshScreenBuffer();

							std::string studentid;
							std::string studentname;
							std::string studentgender;
							std::string studentage;
							std::string studentsystem;
							std::vector<StudentInformation>Students;

							StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

							Studentinformation.LoadStudentsFromFile(Students);

							std::vector<StudentInformation>::iterator it;

							bool isQuery = false;
							for (it = Students.begin(); it != Students.end(); it++)
							{
								if (it->StudentSystem == system && it->StudentID == id)
								{
									if (isQuery == 0)
									{
										std::cout << "��ѯ�ɹ�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
									std::cout << "������" << it->StudentName << std::endl;
									std::cout << "�Ա�" << it->StudentGender << std::endl;
									std::cout << "���䣺" << it->StudentAge << std::endl;
									std::cout << "����ϵ��" << it->StudentSystem << std::endl;
									std::cout << "------------------------------------" << std::endl;

									isQuery = true;
								}
							}

							if (isQuery == 0)
							{
								std::cout << "���޸�ѧ�Ŵ�����ϵ��ѧ����Ϣ" << std::endl;
								std::cout << "------------------------------------" << std::endl;
							}

							break;

						}
						else if (Decision == "2")
						{
							std::string name;
							std::cout << "����������" << std::endl;
							std::getline(std::cin, name);

							RefreshScreenBuffer();

							std::string studentid;
							std::string studentname;
							std::string studentgender;
							std::string studentage;
							std::string studentsystem;
							std::vector<StudentInformation>Students;

							StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

							Studentinformation.LoadStudentsFromFile(Students);

							std::vector<StudentInformation>::iterator it;

							bool isQuery = false;

							for (it = Students.begin(); it != Students.end(); it++)
							{
								if (it->StudentSystem == system && it->StudentName == name)
								{
									if (isQuery == 0)
									{
										std::cout << "��ѯ�ɹ�" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
									std::cout << "������" << it->StudentName << std::endl;
									std::cout << "�Ա�" << it->StudentGender << std::endl;
									std::cout << "���䣺" << it->StudentAge << std::endl;
									std::cout << "����ϵ��" << it->StudentSystem << std::endl;
									std::cout << "------------------------------------" << std::endl;

									isQuery = true;
								}
							}

							if (isQuery == 0)
							{
								std::cout << "���޸�����������ϵ��ѧ����Ϣ" << std::endl;
								std::cout << "------------------------------------" << std::endl;
							}

							break;

						}
						else if (Decision == "3")
						{
							std::string gender;
							std::cout << "�������Ա�" << std::endl;
							std::getline(std::cin, gender);

							RefreshScreenBuffer();

							while (1)
							{
								std::string Isconfirm;
								std::cout << "�Ƿ���������ѯҪ��Yes/No��" << std::endl;
								std::getline(std::cin, Isconfirm);

								RefreshScreenBuffer();

								if (Isconfirm == "Yes" || Isconfirm == "yes")
								{
									while (1)
									{
										std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
										std::cout << "1--��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
										std::cout << "2--��������ѯѧ����Ϣ" << std::endl;
										std::cout << "3--�������ѯѧ����Ϣ" << std::endl;
										std::string Resolution;

										std::getline(std::cin, Resolution);

										RefreshScreenBuffer();

										if (Resolution == "1")
										{
											std::string id;
											std::cout << "������ѧ��" << std::endl;
											std::getline(std::cin, id);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentGender == gender && it->StudentID == id)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸�ѧ���Ա������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "2")
										{
											std::string name;
											std::cout << "����������" << std::endl;
											std::getline(std::cin, name);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentGender == gender && it->StudentName == name)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸������Ա������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "3")
										{
											std::string age;
											std::cout << "����������" << std::endl;
											std::getline(std::cin, age);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentGender == gender && it->StudentAge == age)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸��Ա����������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else
										{
											std::cout << "ѡ�����������ѡ��" << std::endl;
											std::cout << "------------------------------------" << std::endl;
										}
									}

									break;
								}
								else if (Isconfirm == "No" || Isconfirm == "no")
								{
									std::string studentid;
									std::string studentname;
									std::string studentgender;
									std::string studentage;
									std::string studentsystem;
									std::vector<StudentInformation>Students;

									StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

									Studentinformation.LoadStudentsFromFile(Students);

									std::vector<StudentInformation>::iterator it;

									bool isQuery = false;
									for (it = Students.begin(); it != Students.end(); it++)
									{
										if (it->StudentSystem == system && it->StudentGender == gender)
										{
											if (isQuery == 0)
											{
												std::cout << "��ѯ�ɹ�" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
											std::cout << "������" << it->StudentName << std::endl;
											std::cout << "�Ա�" << it->StudentGender << std::endl;
											std::cout << "���䣺" << it->StudentAge << std::endl;
											std::cout << "����ϵ��" << it->StudentSystem << std::endl;
											std::cout << "------------------------------------" << std::endl;

											isQuery = true;
										}
									}

									if (isQuery == 0)
									{
										std::cout << "���޸��Ա������ϵ��ѧ����Ϣ" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									break;

								}
								else
								{
									std::cout << "ѡ�����������ѡ��" << std::endl;
									std::cout << "------------------------------------" << std::endl;
								}
							}
							break;
						}

						else if (Decision == "4")
						{
							std::string age;
							std::cout << "����������" << std::endl;
							std::getline(std::cin, age);

							RefreshScreenBuffer();

							while (1)
							{
								std::string Isconfirm;
								std::cout << "�Ƿ���������ѯҪ��Yes/No��" << std::endl;
								std::getline(std::cin, Isconfirm);

								RefreshScreenBuffer();

								if (Isconfirm == "Yes" || Isconfirm == "yes")
								{
									while (1)
									{
										std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
										std::cout << "1--��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
										std::cout << "2--��������ѯѧ����Ϣ" << std::endl;
										std::cout << "3--���Ա��ѯѧ����Ϣ" << std::endl;

										std::string Resolution;

										std::getline(std::cin, Resolution);

										RefreshScreenBuffer();

										if (Resolution == "1")
										{
											std::string id;
											std::cout << "������ѧ��" << std::endl;
											std::getline(std::cin, id);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentAge == age && it->StudentID == id)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸�ѧ�����������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "2")
										{
											std::string name;
											std::cout << "����������" << std::endl;
											std::getline(std::cin, name);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentAge == age && it->StudentName == name)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸��������������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else if (Resolution == "3")
										{
											std::string gender;
											std::cout << "�������Ա�" << std::endl;
											std::getline(std::cin, gender);

											RefreshScreenBuffer();

											std::string studentid;
											std::string studentname;
											std::string studentgender;
											std::string studentage;
											std::string studentsystem;
											std::vector<StudentInformation>Students;

											StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

											Studentinformation.LoadStudentsFromFile(Students);

											std::vector<StudentInformation>::iterator it;

											bool isQuery = false;
											for (it = Students.begin(); it != Students.end(); it++)
											{
												if (it->StudentSystem == system && it->StudentAge == age && it->StudentGender == gender)
												{
													if (isQuery == 0)
													{
														std::cout << "��ѯ�ɹ�" << std::endl;
														std::cout << "------------------------------------" << std::endl;
													}

													std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
													std::cout << "������" << it->StudentName << std::endl;
													std::cout << "�Ա�" << it->StudentGender << std::endl;
													std::cout << "���䣺" << it->StudentAge << std::endl;
													std::cout << "����ϵ��" << it->StudentSystem << std::endl;
													std::cout << "------------------------------------" << std::endl;

													isQuery = true;
												}
											}

											if (isQuery == 0)
											{
												std::cout << "���޸������Ա������ϵ��ѧ����Ϣ" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											break;
										}
										else
										{
											std::cout << "ѡ�����������ѡ��" << std::endl;
											std::cout << "------------------------------------" << std::endl;
										}
									}

									break;
								}
								else if (Isconfirm == "No" || Isconfirm == "no")
								{
									std::string studentid;
									std::string studentname;
									std::string studentgender;
									std::string studentage;
									std::string studentsystem;
									std::vector<StudentInformation>Students;

									StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

									Studentinformation.LoadStudentsFromFile(Students);

									std::vector<StudentInformation>::iterator it;

									bool isQuery = false;
									for (it = Students.begin(); it != Students.end(); it++)
									{
										if (it->StudentSystem == system && it->StudentAge == age)
										{
											if (isQuery == 0)
											{
												std::cout << "��ѯ�ɹ�" << std::endl;
												std::cout << "------------------------------------" << std::endl;
											}

											std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
											std::cout << "������" << it->StudentName << std::endl;
											std::cout << "�Ա�" << it->StudentGender << std::endl;
											std::cout << "���䣺" << it->StudentAge << std::endl;
											std::cout << "����ϵ��" << it->StudentSystem << std::endl;
											std::cout << "------------------------------------" << std::endl;

											isQuery = true;
										}
									}

									if (isQuery == 0)
									{
										std::cout << "���޸ø����������ϵ��ѧ����Ϣ" << std::endl;
										std::cout << "------------------------------------" << std::endl;
									}

									break;

								}
								else
								{
									std::cout << "ѡ�����������ѡ��" << std::endl;
									std::cout << "------------------------------------" << std::endl;
								}
							}
							break;
						}
						else
						{
							std::cout << "ѡ�����������ѡ��" << std::endl;
							std::cout << "------------------------------------" << std::endl;
						}
					}
					break;
				}
				else if (isconfirm == "No" || isconfirm == "no")
				{
					std::string studentid;
					std::string studentname;
					std::string studentgender;
					std::string studentage;
					std::string studentsystem;
					std::vector<StudentInformation>Students;

					StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

					Studentinformation.LoadStudentsFromFile(Students);

					std::vector<StudentInformation>::iterator it;

					bool isQuery = false;
					for (it = Students.begin(); it != Students.end(); it++)
					{
						if (it->StudentSystem == system)
						{
							if (isQuery == 0)
							{
								std::cout << "��ѯ�ɹ�" << std::endl;
								std::cout << "------------------------------------" << std::endl;
							}

							std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
							std::cout << "������" << it->StudentName << std::endl;
							std::cout << "�Ա�" << it->StudentGender << std::endl;
							std::cout << "���䣺" << it->StudentAge << std::endl;
							std::cout << "����ϵ��" << it->StudentSystem << std::endl;
							std::cout << "------------------------------------" << std::endl;

							isQuery = true;
						}
					}

					if (isQuery == 0)
					{
						std::cout << "���޴�����ϵ��ѧ����Ϣ" << std::endl;
						std::cout << "------------------------------------" << std::endl;
					}

					break;
				}
				else
				{
					std::cout << "ѡ�����������ѡ��" << std::endl;
					std::cout << "------------------------------------" << std::endl;
				}
			}
		}

		else if (decision == "6")
		{
			std::cout << "�˳��˵��ɹ�" << std::endl;
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

void QueryCourseFunction()
{
	while (1)
	{
		std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
		std::cout << "1--���κŲ�ѯ�γ���Ϣ" << std::endl;
		std::cout << "2--��������ѯ�γ���Ϣ" << std::endl;
		std::cout << "3--���ον�ʦ��ѯ�γ���Ϣ" << std::endl;
		std::cout << "4--�˳��˵�" << std::endl;

		std::string decision;
		std::getline(std::cin, decision);

		RefreshScreenBuffer();

		if (decision == "1")
		{
			std::string id;
			std::cout << "������κ�" << std::endl;
			std::getline(std::cin, id);

			RefreshScreenBuffer();

			std::string	coursenumber;
			std::string coursename;
			std::string courseteacher;
			std::vector<CourseInformation>courses;


			CourseInformation courseinformation(coursenumber, coursename, courseteacher);

			courseinformation.LoadCoursesFromFile(courses);

			std::vector<CourseInformation>::iterator it;

			bool isQuery = false;
			for (it = courses.begin(); it != courses.end(); it++)
			{
				if (it->CourseNumber == id)
				{
					if (isQuery == 0)
					{
						std::cout << "���ҳɹ�" << std::endl;
						std::cout << "------------------------------------" << std::endl;
					}

					std::cout << "�κţ�" << it->CourseNumber << std::endl;
					std::cout << "������" << it->CourseName << std::endl;
					std::cout << "�ον�ʦ��" << it->CourseTeacher << std::endl;
					std::cout << "------------------------------------" << std::endl;

					isQuery = true;

				}

			}

			if (isQuery == 0)
			{
				std::cout << "���޴˿κŵĿγ���Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}

		}
		else if (decision == "2")
		{
			std::string name;
			std::cout << "���������" << std::endl;
			std::getline(std::cin, name);

			RefreshScreenBuffer();

			std::string	coursenumber;
			std::string coursename;
			std::string courseteacher;
			std::vector<CourseInformation>courses;


			CourseInformation courseinformation(coursenumber, coursename, courseteacher);

			courseinformation.LoadCoursesFromFile(courses);

			std::vector<CourseInformation>::iterator it;

			bool isQuery = false;
			for (it = courses.begin(); it != courses.end(); it++)
			{
				if (it->CourseName == name)
				{
					if (isQuery == 0)
					{
						std::cout << "���ҳɹ�" << std::endl;
						std::cout << "------------------------------------" << std::endl;
					}
					std::cout << "�κţ�" << it->CourseNumber << std::endl;
					std::cout << "������" << it->CourseName << std::endl;
					std::cout << "�ον�ʦ��" << it->CourseTeacher << std::endl;
					std::cout << "------------------------------------" << std::endl;

					isQuery = true;
				}

			}

			if (isQuery == 0)
			{
				std::cout << "���޴˿����Ŀγ���Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}

		}
		else if (decision == "3")
		{
			std::string teacher;
			std::cout << "�������ον�ʦ" << std::endl;
			std::getline(std::cin, teacher);

			RefreshScreenBuffer();

			std::string	coursenumber;
			std::string coursename;
			std::string courseteacher;
			std::vector<CourseInformation>courses;


			CourseInformation courseinformation(coursenumber, coursename, courseteacher);

			courseinformation.LoadCoursesFromFile(courses);

			std::vector<CourseInformation>::iterator it;

			bool isQuery = false;
			for (it = courses.begin(); it != courses.end(); it++)
			{

				if (it->CourseTeacher == teacher)
				{
					if (isQuery == 0)
					{
						std::cout << "���ҳɹ�" << std::endl;
						std::cout << "------------------------------------" << std::endl;
					}

					std::cout << "�κţ�" << it->CourseNumber << std::endl;
					std::cout << "������" << it->CourseName << std::endl;
					std::cout << "�ον�ʦ��" << it->CourseTeacher << std::endl;
					std::cout << "------------------------------------" << std::endl;

					isQuery = true;

				}

			}

			if (isQuery == 0)
			{
				std::cout << "���޴��ο���ʦ�Ŀγ���Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}

		}
		else if (decision == "4")
		{
			std::cout << "�˳��˵��ɹ�" << std::endl;
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

void QueryScoreFunction()
{
	while (1)
	{
		std::cout << "�˵���������ż���ѡ�񣩣�" << std::endl;
		std::cout << "1--��ѧ�Ų�ѯѧ���ɼ�" << std::endl;
		std::cout << "2--��������ѯѧ���ɼ�" << std::endl;
		std::cout << "3--���κŲ�ѯѧ���ɼ�" << std::endl;
		std::cout << "4--��������ѯѧ���ɼ�" << std::endl;
		std::cout << "5--�˳��˵�" << std::endl;

		std::string decision;
		std::getline(std::cin, decision);

		RefreshScreenBuffer();

		if (decision == "1")
		{
			std::string id;
			std::cout << "������ѧ��" << std::endl;
			std::getline(std::cin, id);

			RefreshScreenBuffer();

			std::string Studentid;
			std::string Classid;
			int usualscore = -1;
			int rollscore = -1;
			int score = -1;
			std::vector<ScoreInformation>Scores;

			ScoreInformation scoreinformation(Studentid, Classid, usualscore, rollscore, score);

			scoreinformation.LoadScoresFromFile(Scores);


			std::vector<ScoreInformation>::iterator it;

			bool isQuery = false;

			for (it = Scores.begin(); it != Scores.end(); it++)
			{
				if (it->StudentID == id)
				{
					if (isQuery == 0)
					{
						std::cout << "��ѯ�ɹ�" << std::endl;
						std::cout << "------------------------------------" << std::endl;
					}

					std::cout << "ѧ�ţ�" << it->StudentID << std::endl;

					//����ѧ����"Student.txt"�в������������
					std::string studentid;
					std::string studentname;
					std::string studentgender;
					std::string studentage;
					std::string studentsystem;
					std::vector<StudentInformation>Students;

					StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

					Studentinformation.LoadStudentsFromFile(Students);

					std::vector<StudentInformation>::iterator It;

					for (It = Students.begin(); It != Students.end(); It++)
					{
						if (It->StudentID == it->StudentID)
						{
							std::cout << "������" << It->StudentName << std::endl;
							break;
						}
					}
					//������������

					std::cout << "�κţ�" << it->ClassID << std::endl;

					//���ÿκ���"Course.txt"�в��ҿ��������

					std::string coursenumber;
					std::string coursename;
					std::string courseteacher;

					std::vector<CourseInformation>Courses;

					CourseInformation courseinformation(coursenumber, coursename, courseteacher);

					courseinformation.LoadCoursesFromFile(Courses);

					std::vector<CourseInformation>::iterator IT;

					for (IT = Courses.begin(); IT != Courses.end(); IT++)
					{
						if (IT->CourseNumber == it->ClassID)
						{
							std::cout << "������" << IT->CourseName << std::endl;
							break;
						}
					}

					//���ҿκŽ���

					std::cout << "ƽʱ�ɼ���" << it->UsualScore << std::endl;
					std::cout << "����ɼ���" << it->RollScore << std::endl;
					std::cout << "�ܳɼ���" << it->Score << std::endl;
					std::cout << "------------------------------------" << std::endl;

					isQuery = true;
				}
			}

			if (isQuery == 0)
			{
				std::cout << "���޴�ѧ�ŵĳɼ���Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
		}
		else if (decision == "2")
		{
			std::string name;
			std::cout << "����������" << std::endl;
			std::getline(std::cin, name);

			RefreshScreenBuffer();

			std::string StudentId;

			//����������"Student.txt"�в���ѧ�Ų����
			std::string studentid;
			std::string studentname;
			std::string studentgender;
			std::string studentage;
			std::string studentsystem;
			std::vector<StudentInformation>Students;

			StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

			Studentinformation.LoadStudentsFromFile(Students);

			std::vector<StudentInformation>::iterator It;

			bool isnameexist = false;
			for (It = Students.begin(); It != Students.end(); It++)
			{
				if (It->StudentName == name)
				{
					StudentId = It->StudentID;
					isnameexist = true;
					break;
				}
			}
			//����ѧ�Ž���

			if (isnameexist == 0)
			{
				std::cout << "���޴�������ѧ����Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
			else
			{
				std::string Studentid;
				std::string Classid;
				int usualscore = -1;
				int rollscore = -1;
				int score = -1;
				std::vector<ScoreInformation>Scores;

				ScoreInformation scoreinformation(Studentid, Classid, usualscore, rollscore, score);

				scoreinformation.LoadScoresFromFile(Scores);

				std::vector<ScoreInformation>::iterator it;

				bool isQuery = false;

				for (it = Scores.begin(); it != Scores.end(); it++)
				{
					if (it->StudentID == StudentId)
					{
						if (isQuery == 0)
						{
							std::cout << "��ѯ�ɹ�" << std::endl;
							std::cout << "------------------------------------" << std::endl;
						}

						std::cout << "ѧ�ţ�" << it->StudentID << std::endl;
						std::cout << "������" << name << std::endl;
						std::cout << "�κţ�" << it->ClassID << std::endl;

						//���ÿκ���"Course.txt"�в��ҿ��������

						std::string coursenumber;
						std::string coursename;
						std::string courseteacher;

						std::vector<CourseInformation>Courses;

						CourseInformation courseinformation(coursenumber, coursename, courseteacher);

						courseinformation.LoadCoursesFromFile(Courses);

						std::vector<CourseInformation>::iterator IT;

						for (IT = Courses.begin(); IT != Courses.end(); IT++)
						{
							if (IT->CourseNumber == it->ClassID)
							{
								std::cout << "������" << IT->CourseName << std::endl;
								break;
							}
						}

						//���ҿκŽ���

						std::cout << "ƽʱ�ɼ���" << it->UsualScore << std::endl;
						std::cout << "����ɼ���" << it->RollScore << std::endl;
						std::cout << "�ܳɼ���" << it->Score << std::endl;
						std::cout << "------------------------------------" << std::endl;

						isQuery = true;

					}

				}

				if (isQuery == 0)
				{
					std::cout << "���޴�ѧ�ŵĳɼ���Ϣ" << std::endl;
					std::cout << "------------------------------------" << std::endl;
				}
			}
		}
		else if (decision == "3")
		{
			std::string id;
			std::cout << "������κ�" << std::endl;
			std::getline(std::cin, id);

			RefreshScreenBuffer();

			std::string Studentid;
			std::string Classid;
			int usualscore = -1;
			int rollscore = -1;
			int score = -1;
			std::vector<ScoreInformation>Scores;

			ScoreInformation scoreinformation(Studentid, Classid, usualscore, rollscore, score);

			scoreinformation.LoadScoresFromFile(Scores);


			std::vector<ScoreInformation>::iterator it;

			bool isQuery = false;

			for (it = Scores.begin(); it != Scores.end(); it++)
			{
				if (it->ClassID == id)
				{
					if (isQuery == 0)
					{
						std::cout << "��ѯ�ɹ�" << std::endl;
						std::cout << "------------------------------------" << std::endl;
					}

					std::cout << "ѧ�ţ�" << it->StudentID << std::endl;

					//����ѧ����"Student.txt"�в������������
					std::string studentid;
					std::string studentname;
					std::string studentgender;
					std::string studentage;
					std::string studentsystem;
					std::vector<StudentInformation>Students;

					StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

					Studentinformation.LoadStudentsFromFile(Students);

					std::vector<StudentInformation>::iterator It;

					for (It = Students.begin(); It != Students.end(); It++)
					{
						if (It->StudentID == it->StudentID)
						{
							std::cout << "������" << It->StudentName << std::endl;
							break;
						}
					}
					//������������

					std::cout << "�κţ�" << it->ClassID << std::endl;

					//���ÿκ���"Course.txt"�в��ҿ��������

					std::string coursenumber;
					std::string coursename;
					std::string courseteacher;

					std::vector<CourseInformation>Courses;

					CourseInformation courseinformation(coursenumber, coursename, courseteacher);

					courseinformation.LoadCoursesFromFile(Courses);

					std::vector<CourseInformation>::iterator IT;

					for (IT = Courses.begin(); IT != Courses.end(); IT++)
					{
						if (IT->CourseNumber == it->ClassID)
						{
							std::cout << "������" << IT->CourseName << std::endl;
							break;
						}
					}

					//���ҿκŽ���

					std::cout << "ƽʱ�ɼ���" << it->UsualScore << std::endl;
					std::cout << "����ɼ���" << it->RollScore << std::endl;
					std::cout << "�ܳɼ���" << it->Score << std::endl;
					std::cout << "------------------------------------" << std::endl;

					isQuery = true;
				}
			}

			if (isQuery == 0)
			{
				std::cout << "���޴�ѧ�ŵĳɼ���Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
		}
		else if (decision == "4")
		{
			std::string name;
			std::cout << "���������" << std::endl;
			std::getline(std::cin, name);

			RefreshScreenBuffer();

			std::string ClassId;

			//���ÿ�����"Course.txt"�в��ҿκŲ����
			std::string coursenumber;
			std::string coursename;
			std::string courseteacher;
			std::vector<CourseInformation>Courses;

			CourseInformation courseinformation(coursenumber, coursename, courseteacher);

			courseinformation.LoadCoursesFromFile(Courses);

			std::vector<CourseInformation>::iterator IT;

			bool isnameexist = false;

			for (IT = Courses.begin(); IT != Courses.end(); IT++)
			{
				if (IT->CourseName == name)
				{
					ClassId = IT->CourseNumber;
					isnameexist = true;
					break;
				}
			}
			//���ҿκŽ���

			if (isnameexist == 0)
			{
				std::cout << "���޴˿����Ŀγ���Ϣ" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
			else
			{
				std::string Studentid;
				std::string Classid;
				int usualscore = -1;
				int rollscore = -1;
				int score = -1;
				std::vector<ScoreInformation>Scores;

				ScoreInformation scoreinformation(Studentid, Classid, usualscore, rollscore, score);

				scoreinformation.LoadScoresFromFile(Scores);

				std::vector<ScoreInformation>::iterator it;

				bool isQuery = false;

				for (it = Scores.begin(); it != Scores.end(); it++)
				{
					if (it->ClassID == ClassId)
					{
						if (isQuery == 0)
						{
							std::cout << "��ѯ�ɹ�" << std::endl;
							std::cout << "------------------------------------" << std::endl;
						}

						std::cout << "ѧ�ţ�" << it->StudentID << std::endl;

						//����ѧ����"Student.txt"�в������������
						std::string studentid;
						std::string studentname;
						std::string studentgender;
						std::string studentage;
						std::string studentsystem;
						std::vector<StudentInformation>Students;

						StudentInformation Studentinformation(studentid, studentname, studentgender, studentage, studentsystem);

						Studentinformation.LoadStudentsFromFile(Students);

						std::vector<StudentInformation>::iterator It;

						for (It = Students.begin(); It != Students.end(); It++)
						{
							if (It->StudentID == it->StudentID)
							{
								std::cout << "������" << It->StudentName << std::endl;
								break;
							}
						}

						//������������

						std::cout << "�κţ�" << it->ClassID << std::endl;
						std::cout << "������" << name << std::endl;
						std::cout << "ƽʱ�ɼ���" << it->UsualScore << std::endl;
						std::cout << "����ɼ���" << it->RollScore << std::endl;
						std::cout << "------------------------------------" << std::endl;

						isQuery = true;

					}

				}
				if (isQuery == 0)
				{
					std::cout << "���޴˿κŵĳɼ���Ϣ" << std::endl;
					std::cout << "------------------------------------" << std::endl;
				}
			}
		}
		else if (decision == "5")
		{
			std::cout << "�˳��˵��ɹ�" << std::endl;
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