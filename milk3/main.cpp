/*
  ID:liuzhen25
  PROG:milk3
  LANG:C++
*/

#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int state[21][21];

int exist[210];
void dfs(int a,int b,int c,int a0,int b0,int c0){
    if (state[a][b]){
        return;
    }
    state[a][b]=1;
    if (a==0) {
            exist[c]=1;
    }



    if (a>0){
        dfs(a-min(a,b0-b),b+min(a,b0-b),c,a0,b0,c0);
        dfs(a-min(a,c0-c),b,c+min(a,c0-c),a0,b0,c0);
    }
    if (b>0){
        dfs(a+min(a0-a,b),b-min(b,a0-a),c,a0,b0,c0);
        dfs(a,b-min(b,c0-c),c+min(b,c0-c),a0,b0,c0);
    }
    if (c>0){
        dfs(a+min(a0-a,c),b,c-min(a0-a,c),a0,b0,c0);
        dfs(a,b+min(b0-b,c),c-min(b0-b,c),a0,b0,c0);
    }
}

int main()
{
    ifstream ifs("milk3.in");
    ofstream fout("milk3.out");
    int a,b,c;
    ifs>>a>>b>>c;

    for (int i=0;i<21;i++) for (int j=0;j<21;j++)  state[i][j]=0;
    dfs(0,0,c,a,b,c);
    //dfs(min(a,c),0,c-min(a,c),a,b,c);
    //dfs(0,min(b,c),c-min(b,c),a,b,c);
    int start=0;
    for (int i=0;i<210;i++) if(exist[i]) {
            if (start==0) {start=1;fout<<i;}
            else  fout<<" "<<i;
    }
    fout<<endl;
    return 0;
}
