#include <bits/stdc++.h>
using namespace std;
const int MAXN = 262144;
typedef complex<double> cc;
const cc I(0, 1);
const double PI = acos(-1.0);
cc omega[MAXN];
void pre_FFT()
{
    for (int i = 0; i <= MAXN; i++)
        omega[i] = exp(i * 2.0 * PI / MAXN * I);
}

void FFT(int n, complex<double> a[], bool inv = false)
{
    int basic = MAXN / n;
    int theta = basic;
    for (int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        for (int i = 0; i < mh; i++) {
            complex<double> w = omega[inv ? MAXN - (i * theta % MAXN) : i * theta % MAXN];
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                complex<double> x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta = (theta * 2) % MAXN;
    }
    int i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1)
            ;
        if (j < i)
            swap(a[i], a[j]);
    }
    if (inv)
        for (i = 0; i < n; i++)
            a[i] /= n;
}

vector<int> PxP(vector<int> A, vector<int> B, int N)
{
    cc a[N], b[N];
    for (int i = 0; i < N; i++) {
        a[i] = cc(A[i], 0);
        b[i] = cc(B[i], 0);
    }
    FFT(N, a);
    FFT(N, b);
    for (int i = 0; i < N; i++)
        a[i] *= b[i];
    FFT(N, a, true);
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        ans.push_back(round(a[i].real()));
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    pre_FFT();
    while (T--) {
        int n;
        cin >> n;
        int m = 1;
        while (m <= (n * 2 - 1))
            m <<= 1;
        vector<int> A(m), B(m);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            A[i] = a;
        }
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            B[i] = b;
        }
        vector<int> ans = PxP(A, B, m);
        for (int i = 0; i < (n * 2 - 1); i++) {
            if (i)
                cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
