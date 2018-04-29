#include <bits/stdc++.h>
using namespace std;
/*
 *  p % i = p - (p/i) * i
 *  p % i =   - (p/i) * i (mod p)
 *  inv[i] = -(p/i) * inv[p%i] (mod p )
 */
void inverse_table(vector<int>& inv, int p)
{
    inv.resize(p + 1);
    inv[1] = 1;
    for (int i = 2; i < p; i++) {
        inv[i] = (p - (p / i) * inv[p % i] % p) % p;
    }
}
