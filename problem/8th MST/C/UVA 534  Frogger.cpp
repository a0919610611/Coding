#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define op_io
#else
#define op_io                                                                  \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#endif
#define endl "\n"
#define F first
#define S second
#define MAXN 200005
typedef long long LL;
typedef pair<int, int> pii;
struct P {
  int x, y;
};

struct E

{
  int v1, v2;
  double dis;
  E(int v11 = 0, int v22 = 0, double diss = 0.0) {
    v1 = v11;
    v2 = v22;
    dis = diss;
  }
  bool operator<(const E &a) const { return dis < a.dis; }
};

double cdis(P a, P b) {
  double t = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  return sqrt(t);
}

int group[201];
int find_group(int x) {
  return (group[x] == x) ? x : group[x] = find_group(group[x]);
}
int main() {
  int n;
  int times = 1;
  while (cin >> n && n) {
    cout << "Scenario #" << times++ << endl;
    int i;
    P point[201];
    for (i = 1; i <= n; i++) {
      group[i] = i;
    }
    for (i = 1; i <= n; i++) {
      cin >> point[i].x >> point[i].y;
    }
    int j;
    vector<E> edge;
    for (i = 1; i <= n; i++) {
      for (j = i + 1; j <= n; j++) {
        edge.push_back(E(i, j, cdis(point[i], point[j])));
      }
    }

    sort(edge.begin(), edge.end());
    double ans = 0;
    for (i = 0; i < edge.size(); i++) {
      int a = edge[i].v1;
      int b = edge[i].v2;
      if (find_group(a) == find_group(b))
        continue;
      group[find_group(a)] = find_group(b);
      if (find_group(1) == find_group(2)) {
        ans = edge[i].dis;
        break;
      }
    }
    printf("Frog Distance = %.3f\n", ans);
    cout << endl;
  }
  return 0;
}
