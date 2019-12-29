/*
ID: liuzhen25
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
struct peroid{
  int st;
  int en;
};

bool cmp(peroid x,peroid y){
    if (x.st<y.st) return 1;
    else if (x.st==y.st){
        if (x.en<y.en) return 1;
        else return 0;
    }
    else return 0;
}
int main()
{


    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int n;
    fin>>n;
    if (n==0) fout<<0<<" "<<0;
    peroid p[n];
    for (int i=0;i<n;i++){
        peroid p1;
        fin>>p1.st;
        fin>>p1.en;
        p[i]=p1;
    }
    sort(p,p+n,cmp);
    int pre=p[0].st;
    int last=p[0].en;
    int ret1=0;
    int ret2=0;
    for (int i=0;i<n;i++){
        if (p[i].st>last){
            if (p[i].en-p[i].st>ret1) ret1=p[i].en-p[i].st;
            if (p[i].st-last>ret2) ret2=p[i].st-last;
            pre=p[i].st;
            last=p[i].en;
        }
        else if (p[i].st<=last){
            cout<<p[i].st<< " "<<p[i].en<<endl;
            if (p[i].en-pre>ret1) ret1=p[i].en-pre;
            last=max(last,p[i].en);
        }
    }
    fout<<ret1<<" "<<ret2<<endl;
    return 0;
}

