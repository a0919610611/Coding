#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main(){
        int a[10]={0,1,2,2,3,4,5,9,10,10};
        vector<int> v(a,a+10);
        vector<int>::iterator low
        =lower_bound(v.begin(),v.end(),5);
        cout<<*(low)<<endl;
    return 0;
}
