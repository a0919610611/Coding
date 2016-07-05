/*************************************************************************
	> File Name: uva_11310.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 廿十六年五月三日 (週二) 十六時39分十二秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    op_io;
    LL n;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        LL dp[41][5]={}; // 1 :both 2:top 3:bot 4:empty;
        dp[0][1]=1;
        dp[1][4]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i][1]=dp[i-1][2]+dp[i-1][3]+dp[i-1][1]+2*dp[i-1][4];
            dp[i][2]=dp[i-1][1]+dp[i-1][4];
            dp[i][3]=dp[i-1][1]+dp[i-1][4];
           // if(i>=2)
            dp[i][4]=dp[i-1][1];
            //dp[i][4]=dp[i-1][4];
        }
        cout<<dp[n][1]<<endl;

    }
    return 0;
}
