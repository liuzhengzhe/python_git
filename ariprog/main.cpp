/*
ID: liuzhen25
LANG: C++
TASK: ariprog
*/




#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#define MAX 125000

using namespace std;

int N,M;
bool flag;
int num[MAX];
int mm[MAX];
bool test(int start,int len);
int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    while( scanf("%d%d",&N,&M) != EOF ){
        int pos = 0;
        flag = false;
        memset(mm,0,sizeof(mm));
        for( int i = 0; i <= M; i++ ){
            for( int j = 0; j <= M; j++ ){
                int tmp = i*i+j*j;
                if( mm[tmp] != 1 ){
                    num[pos] = tmp;
                    mm[tmp] = 1;
                    pos++;
                }
            }
        }
        sort(num,num+pos);
        int up_B = (num[pos-1]-num[0])/(N-1);
        for( int i = 1; i <= up_B; i++ ){
            for( int j = 0; j < pos; j++ ){
                if( test(num[j],i) ){
                    flag = true;
                    printf("%d %d\n",num[j],i);
                }
                if( num[j]+(N-1)*i > num[pos-1] ){
                    break;
                }
            }
        }
        if( flag == false ){
            printf("NONE\n");
        }
    }
    return 0;
}

bool test(int start,int len){
    int tmp = start;
    for( int i = 0; i < N; i++ ){
        if( mm[tmp] != 1 ){
            return false;
        }
        tmp += len;
    }
    return true;
}
