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
    while(cnt<5000)
    {
            LL xx = rand()*(LL)rand()%1000000;
            LL yy = rand()*(LL)rand()%1000000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if(rand()%100000<8)
                cout << x <<" " <<y<<endl;
            if((x-500)*(x-500)/(330.0*330)+(y-500)*(y-500)/(280.0*280)<1){
                if(rand()%100<pow((330-fabs(x-500))/330.0,1)*pow((280-fabs(y-500))/280.0,1)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
    }
    cnt = 0;
    while(cnt<50000)
    {
            LL xx = rand()*(LL)rand()%1000000;
            LL yy = rand()*(LL)rand()%1000000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if(rand()%100000<8)
                cout << x <<" " <<y<<endl;
            if((x-300)*(x-300)/(130.0*130)+(y-500)*(y-500)/(200.0*200)<1){
                if(rand()%100<pow((130-fabs(x-300))/130.0,3)*pow((200-fabs(y-500))/200.0,3)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
            if((x-700)*(x-700)/(130.0*130)+(y-500)*(y-500)/(200.0*200)<1){
                if(rand()%100<pow((130-fabs(x-700))/130.0,3)*pow((200-fabs(y-500))/200.0,3)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
    }
    return 0;
}
