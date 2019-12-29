#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
bool good;
string names[8];
string retnames[8];
map<string,int> n2n;
string s[7][2];
int k;
void dfs(string a[],int *used,int n){
    if (good) {return;}
    if(n==8) {
        int correct[k];
        for (int i=0;i<k;i++){
            correct[i]=0;
        }
        for (int i=0;i<7;i++){
            string n=a[i];
            string n2=a[i+1];
            for(int j=0;j<k;j++){
                if ( (n==s[j][1] && n2==s[j][0]) || (n2==s[j][1] && n==s[j][0]) ){
                    correct[j]=1;
                }
            }
        }
        int allcorrect=1;
        for (int i=0;i<k;i++){
            if (correct[i]==0){
                allcorrect=0;
            }
        }
        if (allcorrect){
            for (int i=0;i<8;i++){
                retnames[i]=a[i];
            }
            good=1;
        }
        return;
    }

    if(n==0){

        for (int i=0;i<8;i++){
            //cout<<0<<" "<<names[i]<<endl;
            a[n]=names[i];
            used[i]=1;
            dfs(a,used,1);
            used[i]=0;
        }
    }
    else if(n==1){
        string prev=a[n-1];
        bool align=0;
        for(int j=0;j<k;j++){
            if (s[j][0]==prev){
                align+=1;
                a[n]=s[j][1];
                int i=n2n[a[n]];
                if (used[i]==1) continue;
                used[i]=1;
                dfs(a,used,n+1);
                used[i]=0;
            }
            if (s[j][1]==prev){
                align+=1;
                a[n]=s[j][0];
                int i=n2n[a[n]];
                if (used[i]==1) continue;
                used[i]=1;
                dfs(a,used,n+1);
                used[i]=0;
            }
        }
        if (align==0){
            for (int i=0;i<8;i++){
                //cout<<1<<" "<<names[i]<<endl;
                if (used[i]==1) continue;
                a[n]=names[i];
                used[i]=1;
                dfs(a,used,n+1);
                used[i]=0;
            }
        }
    }
    else{
        //cout<<n<<endl;
        string prev=a[n-1];
        string prev2=a[n-2];
        bool align=0;
        for(int j=0;j<k;j++){
            if (s[j][0]==prev){
                if (prev2==s[j][1]){

                }
                else{
                    align+=1;
                    a[n]=s[j][1];
                    int i=n2n[a[n]];
                    if (used[i]==1) continue;
                    used[i]=1;
                    dfs(a,used,n+1);
                    used[i]=0;
                }
            }
            if (s[j][1]==prev){
                if (prev2==s[j][0]){

                }
                else{
                    align+=1;
                    a[n]=s[j][0];
                    int i=n2n[a[n]];
                    if (used[i]==1) continue;
                    used[i]=1;
                    dfs(a,used,n+1);
                    used[i]=0;
                }
            }
        }
        if (align==0){
            for (int i=0;i<8;i++){
                if (used[i]==1) continue;
                a[n]=names[i];
                used[i]=1;
                dfs(a,used,n+1);
                used[i]=0;
            }
        }

    }

}
int main()
{
    good=0;
    names[0]="Beatrice";
    names[1]="Belinda";
    names[2]="Bella";
    names[3]="Bessie";
    names[4]="Betsy";
    names[5]="Blue";
    names[6]="Buttercup";
    names[7]="Sue";
    ifstream ifs("lineup.in");
    ofstream fout("lineup.out");

    ifs>>k;

    for (int i=0;i<8;i++){
        n2n[names[i]]=i;
    }

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
    dfs(a,used,0);
    for (int i=0;i<8;i++){
        fout<<retnames[i]<<endl;
    }
    return 0;
}
