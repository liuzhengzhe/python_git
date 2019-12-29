
/*
ID: liuzhen25
PROG: milk
LANG: C++
*/


# include<fstream>
# include<iostream>
# include<algorithm>

using namespace std;



struct node
{
    int x;//��ŵ���
    int y;//�������
};

int cmp ( struct node A,struct node B )
    {
        return A.x<B.x;
    }
int main()
{
    ifstream ifs("milk.in");
    ofstream ofs("milk.out");
    int T;
    int n;
    ifs>>T>>n;
    int ans = 0;//��С����
    int sum = 0;//Ŀǰ�̵���
    node a[n];
    for ( int i = 0;i < n;i++ )
        {
           ifs>>a[i].x>>a[i].y;
        }
    sort(a,a+n,cmp);
    int k = 0;
    int flag = 1;

    for ( int i = 0;i<n;i++ )
        {
            sum+=a[i].y;
            ans+=(a[i].x) * (a[i].y);

            if ( sum == T )
                {
                    break;
                }
                if ( sum > T )
                    {
                        flag = 0;
                        int cha = sum-T;
                        ans-=(a[i].x) * cha;
                        break;
                    }

        }
    ofs<<ans<<endl;
    return 0;
}
