#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
    ifstream ifs("whereami.in");
    ofstream fout("whereami.out");
    int k;
    int ret=0;
    ifs>>k;
    string st;
    ifs>>st;
    if (k==1) fout<<1<<endl;

    for (int l=1;l<=st.length();l++){
        //cout<<"l"<<l<<st.length()-l+1<<endl;
        bool found=0;
        map<string,int> m;
        for (int s=0;s<st.length()-l+1;s++){
            if(m.end() == m.find(st.substr(s,l))){
                m[st.substr(s,l)]=1;
            }
            else{
                m[st.substr(s,l)]+=1;

            }
            //cout<<st.substr(s,l)<<" "<<m[st.substr(s,l)]<<endl;
        }
        for (int s=0;s<st.length()-l+1;s++){
            //cout<<s<<" "<<st.length()-l<<endl;
            if (m[st.substr(s,l)]>1){
                //cout<<s<<"   "<<l<<endl;
                found=1;
                break;
            }
        }
        if (found==0) {
            fout<<l<<endl;
            break;
        }

    }

    return 0;
}
