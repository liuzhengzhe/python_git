/*
ID: liuzhen25
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string s1,s2;
    fin>>s1;
    fin>>s2;
    int num1=1;
    int num2=1;
    for (int i=0;i<s1.length();i++){
        cout<<s1[i];
        num1=num1*(s1[i]-'A'+1);
    }
    for (int i=0;i<s2.length();i++){
        num2=num2*(s2[i]-'A'+1);
    }
    if (num1%47==num2%47)    fout << "GO"<<endl;
    else    fout << "STAY" << endl;

    return 0;
}
