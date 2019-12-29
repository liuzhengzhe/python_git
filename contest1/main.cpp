#include <iostream>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
    ifstream ifs("gymnastics.in");
    ofstream fout("gymnastics.out");
    int k,n;
    ifs>>k>>n;
    int m[n+1][n+1];
    int l[n];
    for (int i=0;i<n+1;i++){
        for (int j=0;j<n+1;j++){
            m[i][j]=0;
        }
    }
    for (int i=0;i<k;i++){
        for (int j=0;j<n;j++){
            ifs>>l[j];
        }
        for (int j=0;j<n;j++){
            for (int t=j+1;t<n;t++){
                if (m[l[j]][l[t]]==-2 or m[l[t]][l[j]]==-2){
                    continue;
                }
                if (m[l[j]][l[t]]==-1){
                    m[l[j]][l[t]]=-2;
                }
                if (m[l[t]][l[j]]==1){
                    m[l[t]][l[j]]=-2;
                }
                if (m[l[j]][l[t]]==0){
                    m[l[j]][l[t]]=1;
                }
                if (m[l[t]][l[j]]==0){
                    m[l[t]][l[j]]=-1;
                }
            }
        }
    }
    int ret=0;
    for (int j=0;j<n+1;j++){
        for (int t=j+1;t<n+1;t++){
            if (m[j][t]==1 or m[j][t]==-1) ret++;
        }
    }
    fout<<ret<<endl;
    return 0;
}
