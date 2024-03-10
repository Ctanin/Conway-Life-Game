#pragma GCC optimize(3)
#include<windows.h>
#include<iostream>
#include<fstream>
#define MAXN 45
using namespace std;
typedef unsigned long long int UL;
typedef long long int LL;
typedef unsigned short US;
typedef double DB;
bool world[MAXN][MAXN]={false};
const LL sleep_time=500;
LL sum=0,cnt=0;
int main()
{
    LL cell_x,cell_y;
    system("chcp 65001");
    while (true)
    {
        cin>>cell_y>>cell_x;
        system("cls");
        if (cell_x==-1||cell_y==-1)
          break;
        world[cell_y][cell_x]=true;
        for (LL y1=0;y1<MAXN;y1++)
        {
            for (LL x1=0;x1<MAXN;x1++)
            {
                if (world[y1][x1]==true)
                  cout<<"□";
                else
                  cout<<"■";
            }
            cout<<endl;
        }
    }
    while (true)
    {
        cout<<"RUNNING   PRESS ENTER TO EXIT"<<endl;
        cout<<"SLEEP TIME:"<<sleep_time<<" MS"<<endl;
        cout<<"TOTAL:"<<cnt++<<endl;
        for (LL y1=0;y1<MAXN;y1++)
        {
            for (LL x1=0;x1<MAXN;x1++)
            {
                if (world[y1][x1]==true)
                {
                    cout<<"□";
                    if (y1-1>=0&&x1-1>=0&&y1+1<MAXN&&x1+1<MAXN)
                    {
                        for (LL y2=y1-1;y2<=y1+1;y2++)
                        {
                            for (LL x2=x1-1;x2<=x1+1;x2++)
                            {
                                if (world[y2][x2]==true)
                                sum++;
                            }
                        }
                        if (sum>=4||sum<=1)
                          world[y1][x1]=false;
                        sum=0;
                    }
                }
                else
                {
                    cout<<"■";
                    if (y1-1>=0&&x1-1>=0&&y1+1<MAXN&&x1+1<MAXN)
                    {
                        for (LL y2=y1-1;y2<=y1+1;y2++)
                        {
                            for (LL x2=x1-1;x2<=x1+1;x2++)
                            {
                                if (world[y2][x2]==true)
                                sum++;
                            }
                        }
                        if (sum==3)
                          world[y1][x1]=true;
                        sum=0;
                    }
                }
            }
            cout<<endl;
        }
        Sleep(sleep_time);
        system("cls");
        if (GetAsyncKeyState(VK_RETURN)&0x8000)
          break;
    }
    system("pause");
    return 0;
}