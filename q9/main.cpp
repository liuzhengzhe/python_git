/*
ID: liuzhen25
LANG: C++
TASK: dualpal
*/
#include <iostream>
#include <fstream>
using namespace std;
string int2str="0123456789ABCDEFGHIJK";

string trans(int m,int b){
    string ret="";
    while(m>0){
        ret=int2str[m%b]+ret;
        m=m/b;
    }
    return ret;
}

bool pal(string ret){
    int len=ret.length();
    for(int i=0;i<len;i++){
        if(ret[i]!=ret[len-i-1]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    ifstream ifs("dualpal.in");
    ofstream ofs("dualpal.out");
    int n,s;
    ifs>>n>>s;
    int cnt=0;
    int tmp=s+1;
    while(cnt<n){

        int ispal=0;
        for (int b=2;b<11;b++){
            if(pal(trans(tmp,b))){
                ispal+=1;
            }
            if (ispal>=2){

                ofs<<tmp<<endl;
                cnt+=1;
                break;
            }
        }
        tmp+=1;
    }
    return 0;
}
