#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n;
    ifstream ifs("beads.in");
    ofstream ofs("beads.out");
    ifs>>n;
    string beads;
    ifs>>beads;
    if (n==1 or n==2 or n==0){
        ofs<<n<<"\n";
        return 0;
    }
    char now;
    int mcnt=1;
    for (int i=0;i<n;i++){
        now=beads[(i)%n];
        int cnt=1;
        for (int j=1;j<n;j++){
            cout<<now;
            if (now=='w'){
                now=beads[(i+j)%n];
                cnt+=1;
            }
            else if(now==beads[(i+j)%n]){
                now=beads[(i+j)%n];
                cnt+=1;
            }
            else{
                break;
            }
        }
        cout<<cnt<<endl;
        now=beads[(i-1+n)%n];
        cnt+=1;
        for (int j=2;j<n;j++){
            cout<<now;
            if (now=='w'){
                now=beads[(i-j+n)%n];
                cnt+=1;
            }
            else if(now==beads[(i-j+n)%n]){
                now=beads[(i-j+n)%n];
                cnt+=1;
            }
            else{
                break;
            }
        }
        cout<<cnt<<endl;
        if (cnt>n) cnt=n;
        if (mcnt<cnt){
            mcnt=cnt;
        }
    }
    ofs<<mcnt<<"\n";
    return 0;
}
