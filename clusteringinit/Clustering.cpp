#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
//end header

typedef long long LL;
#define DIMENSION 2//维度
#define LAMBDA 0.9997//衰减因子
#define CITA ((2*Cm*Cm)/(DIMENSION*N*N*(1-LAMBDA)*(1-LAMBDA)))//判断强链接的阈值
//end define
/*
结构体：格子
该聚类的基本单位是格子。格子中存储着一系列信息，聚类过程中将所有具有聚类潜力的格子放到Grid_list。
*/
typedef struct Grid
{
    LL tg;//tg is the last time when g is updated;
    LL tm;//tm is the last time when g is removed from grid list as a sporadic grid (if ever);
    long double D;// D is the grid density at the last update;
    vector <long double> C;//Center of Mass;
    vector <int> father;//father is the class label of the grid;
}Grid;
//end Grid;

map <vector <int>,Grid>Grid_list;//格子表，是一个红黑树
LL tc;//当前时间
long double record_x[DIMENSION+10];//记录点record_x
long double GRID_LEN[DIMENSION+10];//格子长度
long double UPPERBOUND[DIMENSION+10];//上界
LL p[DIMENSION+10];//每一维
long double N;//空间中格子总数
long double Cm,Cl;//判断稀疏、过度、稠密的阈值
LL gap;//下一次更新时间段
LL tgap;//下一次更新时间点
//end parameter

/*两个向量的重载加号*/
vector <long double> operator +(const vector <long double>v1,const vector <long double>v2)
{
    vector <long double>ret_v;ret_v.clear();
    for(int i=0;i<DIMENSION;i++)
        ret_v.push_back(v1[i]+v2[i]);
    return ret_v;
}
/*向量的重载乘号*/
vector <long double> operator *(const vector <long double>v0,const long double c0)
{
    vector <long double>ret_v;ret_v.clear();
    for(int i=0;i<DIMENSION;i++)
        ret_v.push_back(v0[i]*c0);
    return ret_v;
}
/*向量的重载除号*/
vector <long double> operator /(const vector <long double>v0,const long double c0)
{
    vector <long double>ret_v;ret_v.clear();
    for(int i=0;i<DIMENSION;i++)
        ret_v.push_back(v0[i]/c0);
    return ret_v;
}

bool read_record(long double *a);
void init_parameters_and_data_structures();
void insert_temgrid_to_gridlist(vector <int> tem_v);
void update_characteristic_vector(map<vector <int>, Grid>::iterator iter);
int density_atrribute(Grid tem_grid);
void remove_sporadic_grids();
void output_matlab_gridlist();
long double update_all_grid_cal_v();
void learn_new_parameters(long double);
void generate_clustering();
//end define function

int main()
{
    freopen("data5.txt","r",stdin);
    //freopen("output5.txt","w",stdout);
    init_parameters_and_data_structures();
    int count_out =0;//对gap数进行计数的值。
    while(read_record(record_x)){
        tc++;
        vector <int> tem_v;
        tem_v.clear();
        for(int i=0;i<DIMENSION;i++)
            tem_v.push_back(floor(record_x[i]/GRID_LEN[i]));//tem_v存储的是该数据点对应格子的编号
        map<vector <int>, Grid>::iterator iter = Grid_list.find(tem_v);
        if(iter == Grid_list.end())//如果当前格子不在Grid_list中
            insert_temgrid_to_gridlist(tem_v);//将tem_v插入到Grid_list中
        else//如果当前格子在Grid_list中
            update_characteristic_vector(iter);//更新该格子对应的Grid_list。
        if(tc==tgap)//如果到下一次更新时间点
        {
            count_out++;
            long double s = update_all_grid_cal_v();//将所有的Grids的更新，
            remove_sporadic_grids();//将稀疏的格子从Gridlist中移去
            generate_clustering();//生成聚类
            if(count_out == 10)
            {
                output_matlab_gridlist();//将聚类结果用输出供matlab处理
                break;
            }
            tgap+=gap;
        }
    }
    return 0;
}

/*输出格子的编号tmp_v*/
void output_grid_v(vector <int> tmp_v)
{
    for(int i=0;i<DIMENSION;i++)
        cout << tmp_v[i];
}

/*找到格子编号x_v的所属于的聚类格子编号*/
vector <int> find_clustering(vector <int> x_v)
{
    if(x_v != Grid_list[x_v].father)Grid_list[x_v].father=find_clustering(Grid_list[x_v].father);
    return Grid_list[x_v].father;
}

/*合并编号a_v和编号b_v所在的聚类*/
void Merge_A_B(vector <int> a_v,vector <int> b_v)
{
    if((a_v = find_clustering(a_v)) == (b_v = find_clustering(b_v)))return;
    Grid_list[a_v].father = b_v;
}

/*计算g1和g2的吸引力*/
long double attraction(Grid g1,Grid g2)
{
    long double r2 = 0;
    for(int i=0;i<DIMENSION;i++)
        r2+=(g1.C[i]-g2.C[i])*(g1.C[i]-g2.C[i]);
    return (g1.D*g2.D)/(r2);
}

bool attraction2(Grid g1, Grid g2){
    for(int i = 0; i < DIMENSION; i++){
        if(abs(g1.C[i] - g2.C[i]) > 0.60*2*GRID_LEN[i])
            return false;
    }
    return true;
}
/*合并聚类*/
void generate_clustering()
{
    for(map <vector <int>,Grid>::iterator it=Grid_list.begin();it!=Grid_list.end();++it){
        (it->second).father = it->first;
    }//将每个格子归为一个聚类。
    for(map <vector <int>,Grid>::iterator itg=Grid_list.begin();itg!=Grid_list.end();++itg){
        vector <int>g_v = itg->first;
        vector <int>h_v;
        for(LL enmu = 1LL;enmu<(1LL<<DIMENSION);enmu++){//对每个邻居
            h_v.clear();
            int flag = 0;
            for(int i=0;i<DIMENSION;i++){
                if((enmu>>i) & 1LL){
                    if(g_v[i]+1>=p[i]){flag = 1;break;}
                    h_v.push_back(g_v[i]+1);
                }
                else{
                    h_v.push_back(g_v[i]);//h_v是g_v;
                }
            }
            if(flag)break;
            map<vector <int>, Grid>::iterator iter = Grid_list.find(h_v);
            if(iter == Grid_list.end())break;// 如果h_v不在Grid_list中；
            if(attraction2(Grid_list[g_v],Grid_list[h_v])){//attraction(Grid_list[g_v],Grid_list[h_v])>CITA
                Merge_A_B(g_v,h_v);//合并g_v,h_v;
            }
        }
    }
}

/*更新所有格子的参数，并计算一个平均值s*/
long double update_all_grid_cal_v()
{
    double ret = 0;
    int cnt = 0;
    for(map <vector <int>,Grid>::iterator it=Grid_list.begin();it!=Grid_list.end();++it){
         (it->second).D = pow(LAMBDA,tc-((it->second).tg))*(it->second).D;
         if((it->second).D>((long double)1.0/(N*(1-LAMBDA)))){ret += (it->second).D;cnt++;}
    }
    return ret/cnt;
}
/*移除稀疏格子*/
void remove_sporadic_grids()
{
    for(map <vector <int>,Grid>::iterator it=Grid_list.begin();it!=Grid_list.end();){
         if(density_atrribute(it->second) == 0)
         {
             map <vector <int>,Grid>::iterator erase_it = it;
             it++;
             Grid_list.erase(erase_it);
         }
         else it++;
    }
}
/*输出聚类的数据 提供给matlab*/
void output_matlab_gridlist()
{
    for(map <vector <int>,Grid>::iterator it=Grid_list.begin();it!=Grid_list.end();++it){
        //if(density_atrribute(it->second) == 0)continue;
        vector <int>tem_v0 = it->first;
        vector <long double>tem_x = (it->second).C;
        for(int i=0;i<DIMENSION;i++)
                cout << tem_x[i] << " ";
        output_grid_v(find_clustering(tem_v0));
        cout << endl;
    }
}
/*初始化参数*/
void init_parameters_and_data_structures()
{
    tc = 0;
    Grid_list.clear();
    for(int i=0;i<DIMENSION;i++)
        UPPERBOUND[i] = 200;
    for(int i=0;i<DIMENSION;i++)
        GRID_LEN[i] = 2;//格子的长度
    for(int i=0;i<DIMENSION;i++)
        p[i] = ceil(UPPERBOUND[i]/GRID_LEN[i]);
    for(int i=0;i<DIMENSION;i++)
        UPPERBOUND[i] = GRID_LEN[i]*p[i];//重新设定UPPERBOUND;
    N = 1.0;
    for(int i=0;i<DIMENSION;i++)
        N *= (long double)p[i];//计算格子总数;
    Cl = (long double)2.0/3.0*1.0/(N*(1-LAMBDA));
    Cm = (long double)3.0/(N*(1-LAMBDA));
    gap = (LL)floor(log(Cl/Cm)/log(LAMBDA));
    gap = min((LL)floor(log(N-Cm/N-Cl)/log(LAMBDA)),gap);
    gap = max(gap,1LL);
    tgap+=gap;//设定Cm，Cl和gap;
}
/*读取数据*/
bool read_record(long double *a){
    for(int i=0;i<DIMENSION-1;i++)
        cin >> a[i];
    return cin >> a[DIMENSION-1];
}
/*将临时的格子插入Gridlist*/
void insert_temgrid_to_gridlist(vector <int> tem_v)
{
    Grid tem_grid;
    tem_grid.tg = tc;
    tem_grid.tm = 0;
    tem_grid.D = 1;
    tem_grid.father = tem_v;
    tem_grid.C.clear();
    for(int i=0;i<DIMENSION;i++)
        tem_grid.C.push_back(record_x[i]);
    Grid_list.insert(pair<vector <int> ,Grid>(tem_v,tem_grid));
}
/*更新特征向量*/
void update_characteristic_vector(map<vector <int>, Grid>::iterator iter)
{
    int tem_tg = (iter->second).tg;
    (iter->second).tg = tc;
    double tem_D = (iter->second).D;
    double pow_coeff = pow(LAMBDA,tc-tem_tg);/*衰减数*/
    tem_D = pow_coeff*tem_D+1.0;
    vector <long double> tem_v;tem_v.clear();
    for(int i=0;i<DIMENSION;i++)
        tem_v.push_back(record_x[i]);
    (iter->second).C = (((iter->second).C)*(iter->second).D*pow_coeff+tem_v)/tem_D;/*更新引力值*/
    (iter->second).D = tem_D;/*更新密度值*/
}
/*根据密度分类*/
int density_atrribute(Grid tem_grid)
{
     if(tem_grid.D > Cl&&tem_grid.D < Cm)return 1;
     else if(tem_grid.D <= Cl)return 0;
     else return 2;
}
