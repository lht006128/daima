#include <bits/stdc++.h>
using namespace std;
struct zb
{
  int x, y;
};

map<int, zb> mp;

struct Node
{
  int t;
  int next;
  double l;

  bool operator<(const Node &ohter) const
  {
    return l > ohter.l;
  }
};

Node edge[6000];
int head[6000];
int vis[6000];
double dis[6000];

int cnt = 0;
void addedge(int x, int y)
{
  edge[++cnt].t = y;
  edge[cnt].next = head[x];
  head[x] = cnt;
}

priority_queue<Node> qe;
double dij(int s, int t)
{
  Node tp;
  tp.t = s;
  tp.l = 0;
  qe.push(tp);
  dis[tp.t] = 0;
  while (!qe.empty())
  {
    Node cur;
    cur = qe.top();
    qe.pop();
    if (vis[cur.t])
      continue;
    ;
    vis[cur.t] = 1;
    if (cur.t == t)
      return cur.l;
    for (int i = head[cur.t]; i != -1; i = edge[i].next)
    {
      Node nx;
      nx.t = edge[i].t;
      if (vis[nx.t])
      {
        continue;
      }

      nx.l = sqrt((mp[cur.t].x - mp[nx.t].x) * (mp[cur.t].x - mp[nx.t].x) + (mp[cur.t].y - mp[nx.t].y) * (mp[cur.t].y - mp[nx.t].y)) + cur.l;
      qe.push(nx);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(head, -1, sizeof(head));
  // memset(dis, 1000000.0, sizeof(dis));
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int x, y;
    cin >> x >> y;
    mp[i] = {x, y};
  }

  int m;
  cin >> m;

  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;

    addedge(u, v);
    addedge(v, u);
  }

  int s, t;
  cin >> s >> t;
  double ans;
  ans = dij(s, t);
  printf("%.2lf", ans);

  // cout << dis[t];
}