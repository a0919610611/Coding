#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-6
int dcmp(double x) // compare ex: dcmp(a-b) 0:a=b -1 :a<b 1 : a>b
{
    if(fabs(x)<EPS) return 0;
    else return x<0 ? -1:1; 
}
struct Point
{
    double x,y;
    Point(){x=0,y=0;}
    Point(int _x,int _y){x=_x,y=_y;}
    Point operator +(Point & b)
    {
        return Point(x+b.x,y+b.y);
    }
    Point operator - (Point & b)
    {
        return Point(x-b.x,y-b.y);
    }
    Point operator * (double p)
    {
        return Point(x*p,y*p);
    }
    Point operator / (double p)
    {
        return Point(x/p,y/p);
    }
    Point operator <(const Point & b)
    {
        return a.x<b.x || (a.x==b.x && a.y<b.y);
    }
    bool operator ==(const Point & b) 
    {
        return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
    }
};
typedef Point Vector;
double dot (Vector & v1,Vector & v2)
{
    return v1.x*v2.x+v1.y*v2.y;
}
double cross(Point & o,Point & a, Point &b) //OA X OB
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
double cross(Vector & a,Vector & b)
{
    return a.x*b.y-a.y*b.x;
}
double length(Vector & v)
{
    return sqrt(v.x*v.x+v.y*v.y); //return sqrt(dot(v,v));
}
double angle (const Vector & a,const Vector & b)
{
    return acos(dot(a,b)/length(a)/length(b));
}
double Triarea(const Point & p1,const Point & p2 ,const Point & p3)
{
    return fabs(cross(p2-p1,p3-p1))/2;
}
Vector Rotate(const Vector & a,double rad) //radian 0~2pi //counterclockwise
{
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad)); //旋轉矩陣
}
Vector Normal(const Vector &a) //向量的單位法線
{
    double L=length(a);
    return Vector(-a.y/L,a.x/L);
}
struct Line
{
    Point p1,p2;
};
Point GetLineIntersection (Point p,Vector v,Point q,Vector w) //點斜式交點 p+vt1 q+wt2
{                                                                        
    Vector u=p-q;
    double t=cross(w,u)/cross(v,w); //t1
    return p+v*t; //p+vt1
}
Point GetLineProjection (Point p,Point a,Point b)
{
    Vector v=b-a;
    return a+v*(dot(v,p-a)/dot(v,v));
}
typedef Line Segment;
bool Onsegment(Point p,Point a1,Point a2)//點在線上
{
            //平行                      //端點在兩側
    return dcmp(cross(a1-p,a2-p))==0 && dcmp(dot(a1-p,a2-p))<0;
}
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
    // 規範相交 :交點不能是線段的交點
    double c1=cross(a2-a1,b1-a1) ,c2=cross(a2-a1,b2-a1);
    double c3=cross(b2-b1,a1-b1),c4=cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)* dcmp(c4)<0;
}
bool SegmentProperIntersection(Segment s1, Segment s2)
{
    return SegmentProperIntersection(s1.p1,s1.p2,s2.p1,s2.p2);
}
bool SegmentInterSection(Point a1,Point a2,Point b1,Point b2) //非規範相交
{
    //端點相交
    if(Onsegment(a1,b1,b2)|| Onsegment (a2,b1,b2) || Onsegment (b1,a1,a2) || Onsegment (b2,a1,a2)) return true;
    if(SegmentProperIntersection(a1,a2,b1,b2)) return true; //規範相交
    return false;
}
double distance (Point & a,Point & b)
{
    return sqrt(length(b-a));
}
double distance (Point &p,Point & p1, Point & p2)//Line => p1,p2
{
    Vector v1=p-p1,v2=p2-p1;
    return fabs(cross(v1,v2))/length(v2); //面積/底=高(距離)
}
double distance (Point &p ,Segment & s) //Point to Segment
{
    Vector v=s.p2-s.p1;
    if(dcmp(length(v))==0)  return length(p-s.p1); //線段退化成點
    Vector v1=p-s.p1;
    Vector v2=p-s.p2;
    if(dcmp(dot(v1,v))<0)return length(v1); // 點投影不在線上
    if(dcmp(dot(v2,v))>0) return length(v2);// 點投影不在線上
    return fabs(cross(v,v1))/length(v); 
}
double distance(Segment & s1 , Segment & s2) //線段到線段
{
    if(intersect(s1,s2)) return 0;
    double d =1e9;
    d=min(d,distance(s1.p1,s2)); //點到線段距離取最短
    d=min(d,distance(s1,p2,s2));
    d=min(d,distance(s2.p1,s1));
    d=min(d,distance(s2.p2,s1));
    return d;
}
double distance (Line & l1 ,Line & l2) //線段到線段距離
{
    Vector v1=l1.p2-l1.p1;
    Vector v2=l2.p2-l2.p1;1
    if(cross(v1,v2)!=0) return 0;
    return distance(l1.p1,l2); //點到線段距離
}
bool cmp(Point & a,Point &b)
{
	return a.x<b.x ||
}
int ConvexHull(Point* P, int cnt, Point* res) { //凸包
    sort(P, P + cnt); //先x 後 y 
    cnt = unique(P, P + cnt) - P; //非重複的點數量
    int m = 0;
    for (int i = 0; i < cnt; i++) {
        while (m > 1 && Cross(res[m - 1] - res[m - 2], P[i] - res[m - 2]) <= 0)
        m--;
        res[m++] = P[i];
    }
    int k = m;
    for (int i = cnt - 2; i >= 0; i--) {
        while (m > k && Cross(res[m - 1] - res[m - 2], P[i] - res[m - 2]) <= 0)
        m--;
        res[m++] = P[i];
    }
    if (cnt > 1) //頭尾
    m--;
    return m; //凸包點數
}
double ConvexPolygonArea(Point *p,int n)
{
	double area;
	for(int i=1;i<n-1;++i)
		area+=cross(p[i]-p[0],p[i+1]-p[0]);
	return fabs(area)/2;
}

