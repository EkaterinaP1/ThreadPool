#include <iostream>       // std::cin, std::cout
#include <cstring>
#include <cstdio>
#include "PoolThread.h"
#include "AJob.h"
#include "MyJobs.h"
#include <chrono>
#include <windows.h>
#include "ctype.h"

void menu() {
	int psize = 0;
	int maxQ = 0;
	int com = 0;
	int a, b;
	std::cout << "������� ����������� �������" << endl;
	std::cin >> psize;
	while (psize <= 0) {
		cout << "����������� ������� �� ����� ���� ������������� ��� ��������� ����!!!" << endl;
		cin >> psize;
	}
	while (isdigit(psize)==0) {
		std::cout << "�������� ��������" << endl;
		std::cout << "������� ����������� �������" << endl;
		std::cin >> psize;
	}
	std::cout << "������� ������������ ����������� ����� � �������" << endl;
	std::cin >> maxQ;
	while (maxQ <= 0) {
		cout << "����������� ����� � ������� �� ����� ���� ������������� ��� ��������� ����!!!" << endl;
		cin >> maxQ;
	}
	/*while (!isdigit(maxQ)) {
		std::cout << "�������� ��������" << endl;
		std::cout << "������� ������������ ����������� ����� � �������" << endl;
		std::cin >> maxQ;
	}*/
	PoolThread* PT = new PoolThread(psize);
	PT->Start();
	std::cout << "������� ����� ������ 1)��������, 2)���������, 3)���������, 4)�������";
	std::cin >> com;
	switch (com) {
	case 1:
		Sum * job1;
		int jobid;
		AJob* superjob;
		std::cout << "������� ��� �����" << endl;
		std::cin >> a >> b;
		while ((isdigit(a)) || (isdigit(b))) {
			std::cout << "�������� ��������" << endl;
			std::cout << "������� ��� �����" << endl;
			std::cin >> a >> b;
		}
		for (int i = 0; i < maxQ; i++)
		{
			job1 = new Sum(a, b);
			superjob = job1;
			jobid = PT->ASyncSubmitJob(superjob);
		}
		while (PT->GetJobStatusId(jobid) != 3)
		{
			std::cout << "!----------------------------------!" << std::endl;
			PT->PrintQueue();
			Sleep(1000);
		}
		superjob = PT->GetResJob(jobid);

		delete PT;
		break;
		

	//case 2:
	//		Diff* job2;
	//		int jobid2;
	//		AJob* superjob2;
	//		std::cout << "������� ��� �����" << endl;
	//		std::cin >> a >> b;
	//		/*while (isdigit(a) || isdigit(b)) {
	//			std::cout << "�������� ��������" << endl;
	//			std::cout << "������� ��� �����" << endl;
	//			std::cin >> a >> b;
	//		}*/
	//		for (int i = 0; i < maxQ; i++)
	//		{
	//			job2 = new Diff(a, b);
	//			superjob2 = job2;
	//			jobid2 = PT->ASyncSubmitJob(superjob2);
	//		}
	//		while (PT->GetJobStatusId(jobid2) != 3)
	//		{
	//			std::cout << "!----------------------------------!" << std::endl;
	//			PT->PrintQueue();
	//			Sleep(1000);
	//		}
	//		superjob = PT->GetResJob(jobid2);

	//		delete PT;
	//		break;
	//	
	//	case 3:
	//		/*while (!isdigit(a) || !isdigit(b)) {
	//			std::cout << "�������� ��������" << endl;
	//			std::cout << "������� ��� �����" << endl;
	//			std::cin >> a >> b;
	//		}*/
	//		Mult* job3;
	//		int jobid3;
	//		AJob* superjob3;
	//		std::cout << "������� ��� �����" << endl;
	//		std::cin >> a >> b;
	//		for (int i = 0; i < maxQ; i++)
	//		{
	//			job3 = new Mult(a, b);
	//			superjob3 = job3;
	//			jobid3 = PT->ASyncSubmitJob(superjob3);
	//		}
	//		while (PT->GetJobStatusId(jobid3) != 3)
	//		{
	//			std::cout << "!----------------------------------!" << std::endl;
	//			PT->PrintQueue();
	//			Sleep(1000);
	//		}
	//		superjob3 = PT->GetResJob(jobid3);

	//		delete PT;
	//		break;
	//	
	//	case 4:

	//		Div* job4;
	//		int jobid4;
	//		AJob* superjob4;
	//		std::cout << "������� ��� �����" << endl;
	//		std::cin >> a >> b;
	//		/*while (!isdigit(a) || !isdigit(b)) {
	//			std::cout << "�������� ��������" << endl;
	//			std::cout << "������� ��� �����" << endl;
	//			std::cin >> a >> b;
	//		}*/
	//		for (int i = 0; i < maxQ; i++)
	//		{
	//			job4 = new Div(a, b);
	//			superjob4 = job4;
	//			jobid4 = PT->ASyncSubmitJob(superjob4);
	//		}
	//		while (PT->GetJobStatusId(jobid4) != 3)
	//		{
	//			std::cout << "!----------------------------------!" << std::endl;
	//			PT->PrintQueue();
	//			Sleep(1000);
	//		}
	//		superjob4 = PT->GetResJob(jobid4);

	//		delete PT;
	//		break;
	//	
	default:
	
			std::cout << "������� " << com << " �� ����������" << endl;

		

	}
}




int main()
{
	setlocale(LC_ALL, "Russian");
    PoolThread* PT = new PoolThread(2);
    PT->Start();
    Sum* job1;
    int jobid;
    AJob* superjob;
    for (int i = 0; i < 10; i++)
    {
        job1 = new Sum(3,7);
        superjob = job1;
        jobid = PT->ASyncSubmitJob(superjob);
    }
    //std::this_thread::sleep_for (std::chrono::seconds(15));
    while (PT->GetJobStatusId(jobid) != 3)
    {
        std::cout << "!----------------------------------!" << std::endl;
        PT->PrintQueue();
        Sleep(1000);
    }
    superjob = PT->GetResJob(jobid);

    delete PT;
	///*menu();*/
    return 0;
}
