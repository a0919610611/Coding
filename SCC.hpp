#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
vector<int> e[10000]; //Edge
int visit[10000], low[10000];
bool instack[10000];
int belong[10000]; //屬於哪個點
stack<int> s;
int t; //Time stamp;
int num; //number of SCC
void DFS(int u)
{
    visit[u] = low[u] = ++t;
    s.push(u);
    instack[u] = true;
    for (int i = 0; i < e[i].size(); i++) {
        int v = e[u][i];
        if (!visit[v]) {
            DFS(v);
            if (!instack[v]) {
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (visit[u] == low[u]) //SCC
    {
        num++;
        int v = s.top();
        s.pop();
        instack[v] = false;
        belong[v] = num;
        while (v != u) {
            v = s.top();
            s.pop();
            belong[v] = num;
            instack[v] = false;
        }
    }
}
int Tarjan(int n) //n:number of vertex 0-based
{
    t = 0, num = 0;
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; i++)
        e[i].clear();
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            DFS(i);
        }
    }
}
