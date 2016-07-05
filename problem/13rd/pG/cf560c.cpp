/*************************************************************************
	> File Name: cf560c.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/06/13 23:10:16
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
const long double Eps=1e-6;
const long double PI=3.14159265359;
struct Point
{
   long double x,y;

};

long double carea(Point x,Point y)
{
    return x.x*y.y-x.y*y.x;
}
int main()
{
    op_io;
    long double a[7];
    for(int i=1;i<=6;i++) cin>>a[i];
    Point p[7];
    p[1].x=p[1].y=0;
    p[2].y=p[1].y;
    p[2].x=p[1].x+a[1];
    p[3].x=p[2].x+a[2]*cos(PI/3.0);
    p[3].y=p[2].y+a[2]*sin(PI/3.0);
    p[4].x=p[3].x-a[3]*cos(PI/3.0);
    p[4].y=p[3].y+a[3]*sin(PI/3.0);
    p[5].y=p[4].y;
    p[5].x=p[4].x-a[4];
    p[6].x=p[5].x-a[5]*cos(PI/3.0);
    p[6].y=p[5].y-a[5]*sin(PI/3.0);
    long double area=0;
    for(int i=1;i<6;i++)
    {
        area+=carea(p[i],p[i+1]);
    }
    area+=carea(p[6],p[1]);
    long double tarea=sin(PI/3.0);
     long double ans=area/tarea;
   // printf("%g",round(ans));
    cout<<(int)roundl(ans)<<endl;
    return 0;
}
