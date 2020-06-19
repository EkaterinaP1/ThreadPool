#include <iostream>       // std::cin, std::cout
#include <cstring>
#include <cstdio>
#include "PoolThread.h"
#include "AJob.h"
#include "MyJobs.h"
#include <chrono>
#include <windows.h>
//#include "ctype.h"


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
	
    return 0;
}
