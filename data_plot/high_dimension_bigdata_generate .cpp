#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;
LL dd[41];
double d[41];
double p[41];
int main()
{
    freopen("data.txt","w",stdout);
    int cnt;
    int T=3000;
    while(T--)
    {
        for(int i=0;i<20;i++){
            dd[i] = (LL)rand()*(LL)rand()%10000000;
            d[i] = (double)dd[i]/1000.0;
            if(d[i]<100||d[i]>9900)i--;
        }
        cnt = 0;
        while(cnt<3000)
        {
            for(int i=0;i<20;i++){
                LL t = (LL)rand()*(LL)rand()%200000;
                p[i] = (double)t/1000.0+d[i]-100;
            }

            for(int i=0;i<20;i++)
                cout << p[i] <<" ";
            cout <<endl;
            cnt++;

        }
    }
    return 0;
}
