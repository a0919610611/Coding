#include <bits/stdc++.h>
using namespace std;

struct BIT_2D {
    // 1-indexed
    vector<vector<int> > value;
    int x_len, y_len;
    BIT_2D(vector<vector<int> > _v = { {} })
    {
        x_len = _v.size();
        y_len = _v[0].size();
    };
    int lowbit(int x)
    {
        // return x&(~x+1);
        return x & (-x);
    }
    // value[k] += value;
    void update(int x, int y, int val)
    {
        for (int i = x; i <= x_len; i += lowbit(i)) {
            for (int j = y; j <= y_len; j += lowbit(j)) {
                value[i][j] += val;
            }
        }
    }
    int getSum(int x, int y)
    {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) {
            for (int j = y; j; j -= lowbit(j)) {
                ans += value[x][y];
            }
        }
    }
    // x <= y
    int query(int x1, int y1,int x2,int y2)
    {
        return getSum(x2,y2) - getSum(x1-1,y2)-getSum(x2,y1-1)+getSum(x1-1,y1-1);
    }
};

int main()
{
}
