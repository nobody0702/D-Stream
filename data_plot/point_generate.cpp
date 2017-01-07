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
    int cnt = 0;
    int t = 100;
    while(t--){
            LL xx = rand()*(LL)rand()%300000;
            LL yy = rand()*(LL)rand()%300000;
            cout << double(xx)/1000.0 <<" "<<double(yy)/1000.0<< endl;
    }
    while(cnt<5000)
    {
            LL xx = rand()*(LL)rand()%300000;
            LL yy = rand()*(LL)rand()%300000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if((x-50)*(x-50)/(13.0*13)+(y-150)*(y-150)/(130.0*130)<1){
                if(rand()%100<pow((13-fabs(x-50))/13.0,3)*pow((130-fabs(y-150))/130.0,3)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
    }
    cnt = 0;
    while(cnt<2000)
    {
            LL xx = rand()*(LL)rand()%300000;
            LL yy = rand()*(LL)rand()%300000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if((x-90)*(x-90)/(13.0*13)+(y-150)*(y-150)/(50.0*50)<1){
                if(rand()%100<pow((13-fabs(x-90))/13.0,3)*pow((50-abs(y-150))/50.0,3)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
    }
    cnt = 0;
    while(cnt<3000)
    {
            LL xx = rand()*(LL)rand()%300000;
            LL yy = rand()*(LL)rand()%300000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if((x-220)*(x-220)/(23.0*23)+(y-50)*(y-50)/(50.0*50)<1){
                if(rand()%100<pow((23-fabs(x-220))/23.0,2)*pow((50-abs(y-50))/50.0,2)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
    }
    cnt = 0;
    while(cnt<6000)
    {
            LL xx = rand()*(LL)rand()%300000;
            LL yy = rand()*(LL)rand()%300000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if((x-220)*(x-220)/(75.0*75)+y*y/(200.0*200)<1 && (x-220)*(x-220)/(40.0*40)+y*y/(150.0*150)>1){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
    }
    return 0;
}
