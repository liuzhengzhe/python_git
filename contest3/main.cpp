#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
bool good;
string names[8];
void dfs(string* a,int *used,int n,string** s,int k){
    if (good) return;
    if(n==8) {good=1;return};

    if(n==0){
        for (int i=0;i<8;i++){
            a[n]=names[i];
            used[i]=1;
            dfs(a,used,1,s,k);
            used[i]=0;
        }
    }
    else if(n==1){
        string prev=a[n-1];
        bool align=0;
        for(int j=0;j<k;j++){
            if (s[j][0]==prev){
                align=1;
                a[n]=s[j][1];
                used[i]=1;
                dfs(a,used,n+1,s,k);
                used[i]=0;
            }
            if (s[j][1]==prev){
                align=1;
                a[n]=s[j][0];
                used[i]=1;
                dfs(a,used,n+1,s,k);
                used[i]=0;
            }
        }
        if (align==0){
            for (int i=0;i<8;i++){
                if (used[i]==1) continue;
                a[n]=names[i];
                used[i]=1;
                dfs(a,used,n+1,s,k);
                used[i]=0;
            }
        }
    }
    else{
        string prev=a[n-1];
        string prev2=a[n-2];
        bool align=0;
        for(int j=0;j<k;j++){
            if (s[j][0]==prev){
                if (prev2==s[j][1]){

                }
                else{
                    align=1;
                    a[n]=s[j][1];
                    used[i]=1;
                    dfs(a,used,n+1,s,k);
                    used[i]=0;
                }
            }
            if (s[j][1]==prev){
                if (prev2==s[j][0]){

                }
                else{
                    align=1;
                    a[n]=s[j][0];
                    used[i]=1;
                    dfs(a,used,n+1,s,k);
                    used[i]=0;
                }
            }
        }
        if (align==0){
            for (int i=0;i<8;i++){
                if (used[i]==1) continue;
                a[n]=names[i];
                used[i]=1;
                dfs(a,used,n+1,s,k);
                used[i]=0;
            }
        }

    }

}
int main()
{
    good=False;
    names[8]={"Beatrice"£¬"Belinda"£¬"Bella"£¬"Bessie"£¬"Betsy"£¬"Blue"£¬"Buttercup"£¬"Sue"};
    ifstream ifs("lineup.in");
    ofstream fout("lineup.out");
    int k;
    ifs>>k;
    map<string,int> n2n;
    for (int i=0;i<8;i++){
        n2n[names[i]]=i;
    }
    string s[k][2];
    string nouse;
    for (int i=0;i<k;i++){
        ifs>>s[i][0];
        ifs>>nouse;
        ifs>>nouse;
        ifs>>nouse;
        ifs>>nouse;
        ifs>>s[i][1];
    }
    string a[8];
    int used[8];
    for (int i=0;i<8;i++){
        used[i]=0;
    }
    dfs(a,used,0,s,k);
    for (int i=0;i<8;i++){
        cout<<a[i];
    }
    return 0;
}
