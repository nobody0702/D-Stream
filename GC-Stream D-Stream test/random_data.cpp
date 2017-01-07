#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;
#define DIMENSION 20

int main()
{
    freopen("data.txt","w",stdout);
    int T = 7200;
    while(T--){
        for(int i=0;i<DIMENSION;i++){

            LL xx = rand()*(LL)rand()%200000;
            cout << double(xx)/1000.0 << " ";
        }
        cout << endl;
    }
}
