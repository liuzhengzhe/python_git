/*
ID: liuzhen25
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int func(ifstream& fi){
}
int main()
{
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int n;
    fin>>n;
    string names[n];
    map <string,int> m;
    for(int i=0;i<n;i++){

        fin>>names[i];
        cout<<names.len();
        m[names[i]]=0;
    }
    for(int i=0;i<n;i++){
        string name;
        fin>>name;
        int total,num;
        fin>>total;
        fin>>num;
        if (num==0){
            continue;
        }
        int each=total/num;
        m[name]-=total;
        int left=total-num*each;
        m[name]+=left;
        for (int j=0;j<num;j++){
            string acc;
            fin>>acc;
            m[acc]+=each;
        }
    }
    for(int i=0;i<n;i++){
        fout<<names[i]<<" "<<m[names[i]]<<"\n";
    }
    return 0;
}
