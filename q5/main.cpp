/*
 ID: liuzhen25
 LANG: C++
 TASK: milk2
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
struct strct{
    int start;
    int end;
};
bool cmp(strct x,strct y){
    if (x.start<y.start) {
        return 1;
    }
    else {
        if (x.start == y.start) {
            if (x.end<y.end){
                return 1;
            }
            else {
                return 0;
            }
        }
        return 0;
    }
}
int main() {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int rounds;
    fin>>rounds;
    strct m[rounds];
    for(int i=1;i<=rounds;i++){
        fin>>m[i-1].start;
        fin>>m[i-1].end;
    }
    sort(m,m+rounds,cmp);
    int maxd=abs(m[0].start-m[0].end);
    int maxr=0;
    int start=m[0].start;
    int end=m[0].end;
    //int js=1;

    if(rounds!=1) {
        for (int i = -1; i < rounds - 1; i++) {
            //if (m[i].end > end) {
            //    end = m[i].end;
            //}

            if (end >= m[i + 1].start) {
                maxd = max(abs(start - m[i + 1].end), maxd);

                end=max(end,m[i+1].end);
            } else {

                maxr = max(abs(end - m[i + 1].start), maxr);
                maxd = max(maxd, abs(m[i + 1].start - m[i + 1].end));
                start=min(start,m[i + 1].start);
                end=max(end,m[i+1].end);
            }
            cout<<maxr<<endl<<maxd<<endl;
        }
    }
    else{
        maxd=abs(m[0].start-m[0].end);
        maxr=0;
    }
    fout<<maxd<<" "<<maxr<<endl;
    return 0;
}
