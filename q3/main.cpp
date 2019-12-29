/*
ID: liuzhen25
LANG: C++
TASK: friday
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs("friday.in");
    ofstream ofs("friday.out");
    ofstream ofs2("day.out");
    int n;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    ifs>>n;
    int ret[7];
    for (int i=0;i<7;i++) ret[i]=0;
    int number=0;
    for (int i=1900;i<1900+n;i++){
        for (int j=0;j<12;j++){
            ofs2<<(number+6)%7<<endl;
            cout<<number<<endl;
            ret[number]+=1;
            if ((j==1) and ((i%4==0 and i%100!=0) or (i%400==0))){
                number=(number+29)%7;
            }
            else{
                number=(number+month[j])%7;
            }
        }
    }
    ofs<<ret[0];
    for (int i=1;i<7;i++){
        ofs<<" "<<ret[i];
    }
    ofs<<"\n";
    return 0;
}
