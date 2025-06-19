#include <bits/stdc++.h>
#define int long long

using namespace std;
int b[3000100];
int n, m;
struct Node
{
  int t;
  int w;
  int next;

  bool operator<(const Node &other) const
  {
    return w > other.w;
  }
};
Node edge[6000010];
int vis[6000100];
int head[6000010];
int cnt = 0;
priority_queue<Node> dui;

int dij(int x, int t)
{
  Node tp;
  tp.t = x;
  for (int i = 0; i <= b[x]; i++)
  {
    tp.w = i;
    dui.push(tp);
  }

  while (!dui.empty())
  {
    Node cur;
    cur = dui.top();

    dui.pop();
    if (vis[cur.t])
      continue;
    if (cur.t == t)
    {
      return cur.w;
    }

    vis[cur.t] = 1;

    for (int i = head[cur.t]; i != -1; i = edge[i].next)
    {
      Node next;
      next.t = edge[i].t;
      if (cur.w < edge[i].w)
      {
        vis[cur.t] = 0;
        continue;
      }

      for (int i = 0; i <= b[next.t]; i++)
      {
        next.w = cur.w + i;
        dui.push(next);
      }
    }
  }
  return -1;
}

void addedge(int x, int y, int w)
{
  edge[++cnt].t = y;
  edge[cnt].w = w;
  edge[cnt].next = head[x];
  head[x] = cnt;
}

void slove()
{

  cnt = 0;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> b[i];
  }

  for (int i = 1; i <= m; i++)
  {
    int s, t, w;
    cin >> s >> t >> w;
    addedge(s, t, w);
  }

  int ans = dij(1, n);
  cout << ans << endl;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(head, -1, sizeof(head));

  int t;
  cin >> t;
  while (t--)
  {
    slove();
    for (int i = 0; i <= cnt; i++)
    {
      head[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
      vis[i] = 0;
    }
    while (!dui.empty())
    {
      dui.pop();
    }
  }
}