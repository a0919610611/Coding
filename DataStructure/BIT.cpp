#include <bits/stdc++.h>
using namespace std;

struct BIT {
    // 1-indexed
    vector<int> value;
    BIT(vector<int> _v = {})
    {
        value.resize(_v.size());
        for (int i = 1; i < _v.size(); i++) {
            update(i, _v[i]);
        }
    };
    int lowbit(int x)
    {
        // return x&(~x+1);
        return x & (-x);
    }
    // value[k] += value;
    void update(int k, int val)
    {
        for (int i = k; i <= value.size(); i += lowbit(i)) {
            value[i] += val;
        }
    }
    int getSum(int x)
    {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) {
            ans += value[i];
        }
        return ans;
    }
    // x <= y
    int query(int x, int y)
    {
        return getSum(y) - getSum(x - 1);
    }
};

int main()
{
    vector<int> value;
    for (int i = 0; i <= 100; i++) {
        value.push_back(i);
    }
    BIT tree(value);
    assert(tree.query(1, 1) == 1);
    assert(tree.query(2, 2) == 2);
    assert(tree.query(2, 3) == 5);
    assert(tree.query(5, 7) == 18);
}
