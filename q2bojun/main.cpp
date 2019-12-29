/*
ID: liuzhen25
LANG: C++
TASK: gift1
*/
//
// Created by White on 6/7/2019.
//
#include<iostream>
#include<fstream>
using namespace std;

int founction(int pnum,string* pnam,ifstream& fin)
{
    string a;
    int b;
    fin>>a;
    for(int i=0;i<pnum;i++)
    {
        if(pnam[i]==a)
        {
            b=i;
        }
    }
    return(b);
}
int main()
{
    int ans;
    ifstream fin("gift1.in");
	ofstream fout("gift1.out");
    int pnum;
    fin>>pnum;
       string pnam[pnum];
    for(int i=0;i<pnum;i++)
    {
        fin>>pnam[i];
    }
    int pmon[pnum];
    for(int i=0;i<pnum;i++)
    {
        pmon[i]=0;
    }
    for(int end=0;end<pnum;end++) {
        ans = founction(pnum, pnam, fin);
        int i;
        int ii;
        fin >> i;
        if(i==0){
            continue;
        }
        fin >> ii;
        int iii;
        iii = (i - (i % ii)) / ii;
        pmon[ans]+=(i%ii);
        pmon[ans]-=i;
        for (int d = 0; d < ii; d++)
        {
            pmon[founction(pnum, pnam, fin)] += iii;
        }
        i=0;
        ii=0;
        iii=0;
    }
    for(int money=0;money<pnum;money++)
    {
        fout<<pnam[money];
        fout<<" ";
        fout<<pmon[money];
        fout<<endl;
    }
    return(0);
}
