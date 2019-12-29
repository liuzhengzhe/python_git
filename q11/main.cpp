
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
    if(m>=c) ofs<<c<<endl;//提供的木块比牛多
    else{
        for(int i=0;i<c;i++) ifs>>cow[i];
        sort(cow,cow+c);
        for(int i=0;i<c-1;i++){
            ans[i]=cow[i+1]-cow[i]-1;//每头牛之间的间隔
        }
        sort(ans,ans+c-1,cmp);
        int tot=cow[c-1]-cow[0]+1;//头尾两头牛之间的间隔
        for(int i=0;i<m-1;i++){//m块木块久减去间隔最大的m-1个
            tot-=ans[i];
        }
        ofs<<tot<<endl;
    }
    return 0;
}
