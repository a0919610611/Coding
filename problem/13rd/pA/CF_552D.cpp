/*************************************************************************
	> File Name: CF_552D.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/06/01 18:43:43
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
    int operator *(point & a) 
    {
        return x*a.y-y*a.x;
    }
};
int main()
{
    op_io;
    int n;
    cin>>n;
    point p[2000];
    int ans=0;
    for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                point a,b;
                a.x=p[j].x-p[i].x;
                a.y=p[j].y-p[i].y;
                b.x=p[k].x-p[i].x;
                b.y=p[k].y-p[i].y;
                if(abs(a*b))
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
