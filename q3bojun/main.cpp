#include <iostream>
#include <fstream>
using namespace std;
int main() {
    //std::cout << "Since 1900" << std::endl;
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int year=1900;
    int after;
    fin>>after;
    int days[after*12];
    int day;
    days[0]=6;
    day=13;
    int RN;
    for(int i=0;i<after;i++) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                RN = 1;
            } else {
                RN = 0;
            }
        } else {
            if (year % 4 == 0) {
                RN = 1;
            } else {
                RN = 0;
            }

        }
        year+=1;
        day+=31;
        days[i*12+1]=day%7;
        if(RN==1)
        {
            day+=29;
        }
        else
        {
            day+=28;
        }
        days[i*12+2]=day%7;
        for(int ii=3;ii<12+1;ii++)
        {
            if(ii==3||ii==5||ii==7||ii==8||ii==10||ii==12)
            {
                day+=31;
                days[i*12+ii]=day%7;
            }
            else
            {
                day+=30;
                days[i*12+ii]=day%7;
            }
        }
    }
    //错误从这开始
    int jud[7];
    for(int i=0;i<7;i++)
    {
        jud[i]=0;
    }
    int a;
    for(int i=0;i<after*12;i++)
    {
        a=days[i];
        jud[a]+=1;
        //fout<<a<<endl;
    }
    for(int i=0;i<6;i++)
    {
        fout<<jud[(i+6)%7]<<endl;
    }
    fout<<jud[5];
    return 0;
}
