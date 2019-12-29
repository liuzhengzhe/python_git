/*
ID: liuzhen25
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;

int main()
{
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    ifstream nin("dict.txt");
    int m[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

    string name;
    string n;
    bool exist=0;
    fin>>name;
    while (nin>>n){
        if (n.length()!=name.length()) continue;
        bool cannot=0;
        for (int i=0;i<n.length();i++){
            if (m[n[i]-'A']!=int(name[i]-'0')){

                cannot=1;
                break;
            }

        }
        if (cannot==0){
            exist=1;
            cout<<n<<endl;
        }
    }
    if (exist==0){
        cout<<"NONE"<<endl;
    }

    return 0;
}
