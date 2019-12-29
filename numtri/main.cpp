
/*
ID : liuzhen25
LANG: C++11
TASK: numtri
 */
 
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    int n;
    cin >> n;
    int numMax[1050] = {};
    int num[1050] = {};
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j < i + 1; j ++){
            scanf("%d", &num[j]);
        }
        for (int j = i; j > 0; j --){
            numMax[j] = max(numMax[j - 1], numMax[j]) + num[j];
        }
    }
    int ans = 0;
    for (int i = 1; i<= n; i ++){
        ans = max(ans, numMax[i]);
    }
    cout << ans << endl;
    return 0;
}
