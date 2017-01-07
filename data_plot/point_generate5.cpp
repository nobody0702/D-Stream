#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;

int main()
{
    freopen("data.txt","w",stdout);
    int cnt;
    cnt = 0;
    while(cnt<50000)
    {
            LL xx = rand()*(LL)rand()%1000000;
            LL yy = rand()*(LL)rand()%1000000;
            LL zz = rand()*(LL)rand()%1000000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            double z = double(zz)/1000.0;
            if((LL)rand()*rand()%100000000<1)
            {
                cout <<x<<" "<<y<<" "<<z<<endl;continue;
            }
            if((x-500)*(x-500)+(y-500)*(y-500)+(z-500)*(z-500)<40000){
                if(rand()%100<pow((200-fabs(x-500))/200.0,3)*pow((200-fabs(y-500))/200.0,3)*pow((200-fabs(z-500))/200.0,3)*100){
                    cout <<x<<" "<<y<<" "<<z<<endl;
                    cnt++;
                }
            }
    }
    return 0;
}
