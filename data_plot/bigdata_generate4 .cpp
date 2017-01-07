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
            LL xx = rand()*(LL)rand()%10000000;
            LL yy = rand()*(LL)rand()%10000000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if(((LL)rand()*rand())%(LL)1000000<(LL)1)
                cout << x <<" " <<y<<endl;
            if((x-5000)*(x-5000)/(3300.0*3300)+(y-5000)*(y-5000)/(2800.0*2800)<1){
                if(rand()%100<pow((3300-fabs(x-5000))/3300.0,1)*pow((2800-fabs(y-5000))/2800.0,1)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
    }
    cnt = 0;
    while(cnt<50000)
    {
            LL xx = rand()*(LL)rand()%10000000;
            LL yy = rand()*(LL)rand()%10000000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if(((LL)rand()*rand())%(LL)1000000<(LL)1)
                cout << x <<" " <<y<<endl;
            if((x-3000)*(x-3000)/(1300.0*1300)+(y-5000)*(y-5000)/(2000.0*2000)<1){
                if(rand()%100<pow((1300-fabs(x-3000))/1300.0,3)*pow((2000-fabs(y-5000))/2000.0,3)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
            if((x-7000)*(x-7000)/(1300.0*1300)+(y-5000)*(y-5000)/(2000.0*2000)<1){
                if(rand()%100<pow((1300-fabs(x-7000))/1300.0,3)*pow((2000-fabs(y-5000))/2000.0,3)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
    }
    cnt = 0;
    while(cnt<100000)
    {
            LL xx = rand()*(LL)rand()%10000000;
            LL yy = rand()*(LL)rand()%10000000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if(((LL)rand()*rand())%(LL)5000000<(LL)1)
                cout << x <<" " <<y<<endl;
            if(x+y<10000 && 2*x-y<0)
            {
                if(rand()%100<pow(fabs(x-5000)/5000.0,3)*pow((fabs(y-6000))/6000.0,3)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
    }
    cnt = 0;
    while(cnt<100000)
    {
            LL xx = rand()*(LL)rand()%10000000;
            LL yy = rand()*(LL)rand()%10000000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if(((LL)rand()*rand())%(LL)5000000<(LL)1)
                cout << x <<" " <<y<<endl;
            if(6000<x && x<7000)
            {
                if(rand()%100<pow(fabs(x-5000)/5000.0,3)*pow((fabs(y-10000))/10000.0,3)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
    }
    cnt = 0;
    while(cnt<50000)
    {
            LL xx = rand()*(LL)rand()%10000000;
            LL yy = rand()*(LL)rand()%10000000;
            double x = double(xx)/1000.0;
            double y = double(yy)/1000.0;
            if((x-6000)*(x-6000)+(y-6000)*(y-6000)<3000){
                if(rand()%100<pow((3000-fabs(x-6000))/3000.0,1)*pow((3000-fabs(y-6000))/3000.0,1)*100){
                    cout <<x<<" "<<y<<endl;
                    cnt++;
                }
            }
    }
    int T=1000;
    while(T--)
    {
        LL xx = rand()*(LL)rand()%10000000;
        LL yy = rand()*(LL)rand()%10000000;
        double x0 = double(xx)/1000.0;
        double y0 = double(yy)/1000.0;
        cnt = 0;
        while(cnt<10000)
        {
            LL rr = rand()*(LL)rand()%10000000;
            double r = double(rr)/10000.0;
            LL tt = rand()*(LL)rand()%(LL)36000000;
            double t = double(tt)/100000.0;
            double x = r*cos(t)+x0;
            double y = r*sin(t)+y0;
            if(x > 0 && x<10000 && y >0 && y<10000)
            {
                cout << x << " "<<y <<endl;
                cnt++;
            }
        }
    }
    return 0;
}
