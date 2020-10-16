#include <iostream>
#include <string>
#include <unistd.h>
#include <math.h>
#include <vector>
#include <cmath>

void operation(int job, int machine, int time);
int getMinimum(int job[7]);
int get2ndMinimum(int job[7]);
int getMachine(int job, int machine);

void min_min();
void max_min();
void sufferage();

int job0[7]={13,79,23,71,60,27,2},job1[7]={31,13,14,94,60,61,57},job2[7]={17,1,100,23,36,8,86},job3[7]={19,28,10,4,58,73,40}, job4[7]={94,75,100,58,100,68,46}, job5[7]={8,24,3,32,4,94,89}, job6[7]={10,57,13,1,92,75,29},job7[7]={80,17,38,40,66,25,88};

int main(){
    std::cout << "min-min, max-min, sufferage.\n\n";
    std::cout << "min_min\n";
    min_min();
    std::cout << "max_min\n";
    max_min();
    std::cout << "sufferage\n";
    sufferage();
}

void operation(int job, int machine, int time){
    std::cout << "Job < " << job << " > -running on-> machine < " << machine << " > in < ";
    if(time < 10)
        {
            std::cout << " ";
        }
    std::cout << time << " > ms.\n";
}

void min_min(){
    std::vector<int> jobMinCount;
    jobMinCount.push_back(getMinimum(job0));
    jobMinCount.push_back(getMinimum(job1));
    jobMinCount.push_back(getMinimum(job2));
    jobMinCount.push_back(getMinimum(job3));
    jobMinCount.push_back(getMinimum(job4));
    jobMinCount.push_back(getMinimum(job5));
    jobMinCount.push_back(getMinimum(job6));
    jobMinCount.push_back(getMinimum(job7));

    int j=0;
    while(j<8)
    {
        j++;
        int i=0, min=100, minTime=100;
        while(i < jobMinCount.size())
        {
            
            if(jobMinCount[i] < minTime){
                min = i;
                minTime = jobMinCount[i];
            }
            i++;
        }
        operation(min,getMachine(min, jobMinCount[min]),minTime);
        jobMinCount[min]=100;
    }
}

void max_min(){
    std::vector<int> jobMinCount;

    jobMinCount.push_back(getMinimum(job0));
    jobMinCount.push_back(getMinimum(job1));
    jobMinCount.push_back(getMinimum(job2));
    jobMinCount.push_back(getMinimum(job3));
    jobMinCount.push_back(getMinimum(job4));
    jobMinCount.push_back(getMinimum(job5));
    jobMinCount.push_back(getMinimum(job6));
    jobMinCount.push_back(getMinimum(job7));

    int j=0;
    while(j<8)
    {
        ++j;
        int i=0, max=0, maxTime=0;
        while(i<jobMinCount.size())
        {

            if(jobMinCount[i] > maxTime){
                max = i;
                maxTime = jobMinCount[i];
            }
            ++i;
        }
        operation(max,getMachine(max, jobMinCount[max]),maxTime);
        jobMinCount[max]=0;
    }
}

void sufferage(){
    std::vector<int> jobMinCount, jobSecondMinCount;

    jobMinCount.push_back(getMinimum(job0));
    jobMinCount.push_back(getMinimum(job1));
    jobMinCount.push_back(getMinimum(job2));
    jobMinCount.push_back(getMinimum(job3));
    jobMinCount.push_back(getMinimum(job4));
    jobMinCount.push_back(getMinimum(job5));
    jobMinCount.push_back(getMinimum(job6));
    jobMinCount.push_back(getMinimum(job7));

    jobSecondMinCount.push_back(get2ndMinimum(job0));
    jobSecondMinCount.push_back(get2ndMinimum(job1));
    jobSecondMinCount.push_back(get2ndMinimum(job2));
    jobSecondMinCount.push_back(get2ndMinimum(job3));
    jobSecondMinCount.push_back(get2ndMinimum(job4));
    jobSecondMinCount.push_back(get2ndMinimum(job5));
    jobSecondMinCount.push_back(get2ndMinimum(job6));
    jobSecondMinCount.push_back(get2ndMinimum(job7));    

    int j=0;
    while(j<8)
    {
        ++j;
        int i, max=0, Time=0;
        for(i = 0; i < jobMinCount.size(); ++i){
            if(jobSecondMinCount[i]-jobMinCount[i] > Time && jobSecondMinCount[i] != 100 && jobMinCount[i] != 100){
                max = i;
                Time = jobSecondMinCount[i]-jobMinCount[i];
            }
        }
        operation(max,getMachine(max, jobMinCount[max]),jobMinCount[max]);
        jobMinCount[max]=100;
    }
}


int getMinimum(int job[7]){
    int min = job[0];
      for(int i = 0; i < 7; ++i){
        if(job[i] < min){min = job[i];}
    }

    return min;
}

int getMachine(int job, int time){
    int machine;
    if(job == 0){
        for(int i = 0; i < 7; ++i){
            if(job0[i] == time){machine = i;}
        }
    }
    if(job == 1){
        for(int i = 0; i < 7; ++i){
            if(job1[i] == time){machine = i;}
        }
    }
    if(job == 2){
        for(int i = 0; i < 7; ++i){
            if(job2[i] == time){machine = i;}
        }
    }
    if(job == 3){
        for(int i = 0; i < 7; ++i){
            if(job3[i] == time){machine = i;}
        }
    }
    if(job == 4){
        for(int i = 0; i < 7; ++i){
            if(job4[i] == time){machine = i;}
        }
    }
    if(job == 5){
        for(int i = 0; i < 7; ++i){
            if(job5[i] == time){machine = i;}
        }
    }
    if(job == 6){
        for(int i = 0; i < 7; ++i){
            if(job6[i] == time){machine = i;}
        }
    }
    if(job == 7){
        for(int i = 0; i < 7; ++i){
            if(job7[i] == time){machine = i;}
        }
    }
    return machine;
}

int get2ndMinimum(int job[7]){
    int min = 100;
    int secondMin = 100;

    int i=0;
    while(i<7)
    {
        i++;
        if(job[i] < min)
        {
            min = job[i];
            if(i == 0){secondMin = min;}
        }
        if(job[i] < secondMin && job[i] != min)
        {
            secondMin = job[i];
        }
    }
    return secondMin;
}