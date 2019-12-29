/*
ID: liuzhen25
LANG: C++
TASK: sprime
*/

#include<cstdio>
#include<cstring>
#include<fstream>
#include<cmath>
using namespace std;
int n;
int sushu(int x)
{
    if(x==1)return 0;
    if(x%2==0&&x!=2)return 0;
    for(int i=3;i<=sqrt(x);i+=2)if(x%i==0)return 0;
    return 1;
}
int dfs(int k,int ans,ofstream &fout)
{
    if(k==n)
    {
        fout<<ans<<"\n";
    }
    for(int i=1;i<=9;i++)
    {
        int t=ans*10+i;
        if(sushu(t)==1)dfs(k+1,t,fout);
    }
}
int main()
{
	ifstream ifs("sprime.in");
    ofstream fout("sprime.out");
    ifs>>n;
    dfs(1,2,fout);
    dfs(1,3,fout);
    dfs(1,5,fout);
    dfs(1,7,fout);
    return 0;
}