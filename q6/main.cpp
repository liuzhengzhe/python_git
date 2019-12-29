
/*
ID: liuzhen25
PROG: transform
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctype.h>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <deque>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
 
using namespace std;
 
#define mst(a,b) memset(a,b,sizeof(a))
#define eps  10e-8
 
typedef long long ll;
const int N = 100010;
const ll MOD = 1000000007;
const int INF = 0x7fffffff;
 
char original [11][11];
char target   [11][11];
char reflect  [11][11];
 
int n, i, j;
bool match( char array1[][11], char array2[][11]){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(array1[i][j] != array2[i][j])
                return false;
        }
    }
    return true;
}
 
void rotate90(){
    // first mirror by cross line
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n - i; j++)
            swap(original[i][j], original[n+1-j][n+1-i]);
    // reflect by horizontal line
    for(int i = 1; i <= n/2; i++)
        for(int j = 1; j <= n; j++)
            swap(original[i][j], original[n+1-i][j]);
}
 
int main()
{
    string line;
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    fin >> n;
    int ans = 7;
    for(i = 1; i <= n; i++){
        fin >> line;
        for(j = 1; j <= n; j++){
            original[i][j] = line[j-1];
        }
    }
    for(i = 1; i <= n; i++){
        fin >> line;
        for(j = 1; j <= n; j++){
            target[i][j] = line[j-1];
        }
    }
    // case 6
    if(match(target, original)){
        ans = min(ans,6);
    }
    // get the reflection of original
    for(i = 1; i <= n; i++){
        for(j = 1; j < n+1; j++){
            reflect[i][j] = target[i][n+1-j];
        }
    }
 
    if(match(reflect, original)){
        ans = min(ans,4);
    }
 
    for(int t = 1; t <= 3; t++){
        rotate90();
 
        if(match(target, original)){
            ans = min(ans, t);
        }
        if(match(reflect, original)){
            ans = min(ans, 5);
        }
    }
 
    fout << ans << endl;
    fin.close();
    fout.close();
    return 0;
}
