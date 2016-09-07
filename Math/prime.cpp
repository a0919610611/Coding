#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<bool> notprime(300000000, 0);
const int MAX = 10000;
void build()
{
    for (int i = 2; i * i <= MAX; i++) {
        if (notprime[i])
            continue;
        for (int j = i * i; j <= MAX; j += i) {
            notprime[j] = true;
        }
    }
}
int main()
{
    notprime[1] = true;
    build();
    for (int i = 1; i <= 200; i++) {
        if (!notprime[i])
            cout << i << endl;
    }
    return 0;
}
