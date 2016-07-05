/*************************************************************************
	> File Name: uva_10112.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/06/01 18:57:06
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
struct Point 
{
    int x,y;
    Point (int _x=0,int _y=0) {x=_x,y=_y;}
    Point operator - (Point a)
    {
        return Point(x-a.x,y-a.y);
    }
    int operator * (Point a)
    {
        return (x*a.y)-(y*a.x);
    }
};
int main()
{
    op_io;
    int n;
    while(cin>>n && n)
    {
        Point p[20];
        int ans[3]={};
        for(int i=0;i<n;i++)
        {
            cin.ignore();
            char c;
            cin>>c>>p[i].x>>p[i].y;
        }
        int max_area=INT_MIN;
        for (int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    Point v1=p[j]-p[i];
                    Point v2=p[k]-p[i];
                    Point v3=p[k]-p[j];
                    int area=abs(v1*v2);
                
                    if(area>max_area)
                    {
                        bool ok=true;
                        for(int q=0;q<n;q++)
                        {
                            if(q==i || q==j || q==k) continue;
                            Point qi=p[q]-p[i];
                            Point qj=p[q]-p[j];
                            Point qk=p[q]-p[k];
                            int area1=abs(qi*v1);
                            int area2=abs(qi*v2);
                            int area3=abs(v3*qk);
                            if(area1+area2+area3<=area)
                            {
                                ok=false;
                            }
                        }
                        if(ok)
                        {
                            max_area=area;
                            ans[0]=i,ans[1]=j,ans[2]=k;
                        }
                    }
                }
            }
        }
        cout<<char('A'+ans[0])<<char('A'+ans[1])<<char('A'+ans[2])<<endl;
    }
    return 0;
}
