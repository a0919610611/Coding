//#define txt     //use freopen
//#pragma comment(linker, "/STACK:1024000000,1024000000")  //op
#ifdef LOCAL
#ifdef txt
freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);
#endif
#endif
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define op_io ios_base::sync_with_stdio(0);
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
struct Edge {
  int to;
  int cost;
  bool operator<(const Edge &a) const { return cost > a.cost; }
};
int main() {
  op_io;
  int N;
  int i;
  int cases = 0;
  while (cin >> N) {
    if (cases++)
      cout << endl;
    vector<Edge> E[10000 + 1];
    int ans_1 = 0;
    for (i = 1; i <= N - 1; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      ans_1 += c;
      E[a].push_back((Edge){b, c});
      E[b].push_back((Edge){a, c});
    }
    int K;
    cin >> K;
    for (i = 1; i <= K; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      E[a].push_back((Edge){b, c});
      E[b].push_back((Edge){a, c});
    }
    int M;
    cin >> M;
    for (i = 1; i <= M; i++) {

      int a, b, c;
      cin >> a >> b >> c;
    }

    int d[10000 + 1] = {};
    fill(d + 1, d + 10001, 1e9);
    bool visited[10000 + 1] = {};
    d[1] = 0;
    visited[1] = true;
    priority_queue<Edge> q;
    int point = 1;
    int ans_2 = 0;
    for (i = 0; i < E[1].size(); i++) {
      q.push(E[1][i]);
    }
    while (point < N) {
      Edge a;
      while (1) {
        a = q.top();
        if (!visited[a.to]) {
          ans_2 += a.cost;
          point++;
          // printf("to=%d\n",a.to);
          visited[a.to] = true;
          break;
        } else {
          q.pop();
        }
      }
      // printf("%d\n",point);
      for (i = 0; i < E[a.to].size(); i++) {
        if (!visited[E[a.to][i].to])
          q.push(E[a.to][i]);
      }
    }
    cout << ans_1 << endl;
    cout << ans_2 << endl;
  }

  return 0;
}
