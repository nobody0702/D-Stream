#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("data_out.txt","r",stdin);
    freopen("plot_data.txt","w",stdout);
    int cnt;
    cin >> cnt;
    for(int i=0;i<cnt;i++){
        scanf("%d%d%d",&x,&y,&d);
        printf("%d %d %d\n",x,y,d);
    }

    return 0;
}
