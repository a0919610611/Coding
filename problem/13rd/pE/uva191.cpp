/*************************************************************************
	> File Name: uva191.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/06/10 18:47:54
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
const double Eps=1e-6;
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x=_x;
        y=_y;
    }
    Point operator - (const Point b) 
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^ (const Point b)
    {
        return x*b.y-y*b.x;
    }
};
typedef Point Vector;
struct Line
{
    Point p1,p2;
    Line (){}
    Line (double x1,double y1,double x2,double y2)
    {
        p1.x=x1,p1.y=y1;
        p2.x=x2,p2.y=y2;
    }
    Line (Point _p1,Point _p2)
    {
        p1=_p1;
        p2=_p2;
    }

};
bool intersect1D(int a1,int a2,int b1,int b2)
{
    if(a1>a2) swap(a1,a2);
    if(b1>b2)swap (b1,b2);
    return max(a1,b1)<=min(a2,b2);
}
bool intersection(Line l1 , Line l2)
{
    int x1=l1.p1.x,y1=l1.p1.y;
    int x2=l1.p2.x,y2=l1.p2.y;
    int x3=l2.p1.x,x4=l2.p2.x;
    int y3=l2.p1.y,y4=l2.p2.y;
    Point p1=l1.p1,p2=l1.p2,p3=l2.p1,p4=l2.p2;
    Vector v1,v2,v3,v4;
    v1=p3-p1;v2=p4-p1;
    v3=p1-p3;v4=p2-p3;
    Vector L1,L2;
    L1=p2-p1,L2=p4-p3;
    return intersect1D(x1,x2,x3,x4) && intersect1D(y1,y2,y3,y4)
        && ((L1^v1)*(L1^v2)<=0) &&((L2^v3)*(L2^v4)<=0);


}
int main()
{
    op_io;
    int T;
    cin>>T;
    while(T--)
    {
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        Line line(x1,y1,x2,y2);
        Point plt,pld,prt,prd;
        plt.x=pld.x=min(x3,x4);
        prt.x=prd.x=max(x3,x4);
        plt.y=prt.y=max(y3,y4);
        pld.y=prd.y=min(y3,y4); 
        Line l1(pld,plt),l2(plt,prt),l3(prt,prd),l4(prd,pld);
        if(min(x1,x2)>=plt.x && max(x1,x2)<=prt.x && min(y1,y2)>=pld.y && max(y1,y2)<=plt.y) {cout<<"T"<<endl; continue;}
        if(intersection(line,l1)||intersection(line,l2) || intersection(line,l3)||intersection(line,l4)) cout<<"T"<<endl;else cout<<"F"<<endl;
    }

    return 0;
}
