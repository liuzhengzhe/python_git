
/*
ID: liuzhen25
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    ifstream ifs("barn1.in");
    ofstream ofs("barn1.out");
    int m,s,c;
    ifs>>m>>s>>c;
    int cow[222],ans[222];
    if(m>=c) ofs<<c<<endl;//�ṩ��ľ���ţ��
    else{
        for(int i=0;i<c;i++) ifs>>cow[i];
        sort(cow,cow+c);
        for(int i=0;i<c-1;i++){
            ans[i]=cow[i+1]-cow[i]-1;//ÿͷţ֮��ļ��
        }
        sort(ans,ans+c-1,cmp);
        int tot=cow[c-1]-cow[0]+1;//ͷβ��ͷţ֮��ļ��
        for(int i=0;i<m-1;i++){//m��ľ��ü�ȥ�������m-1��
            tot-=ans[i];
        }
        ofs<<tot<<endl;
    }
    return 0;
}
