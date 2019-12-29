/*
ID: liuzhen25
LANG: C++
TASK: palsquare
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
    ifstream ifs("palsquare.in");
    ofstream ofs("palsquare.out");
    int n;
    ifs>>n;
    for (int m=1;m<301;m++){
        int ms=m*m;
        string ret=trans(ms,n);
        if(pal(ret)){
            ofs<<trans(m,n)<<" "<<ret<<"\n";
        }
    }
    return 0;
}
