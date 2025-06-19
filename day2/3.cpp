#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k;
string s;
struct Node
{
  int t;
  int dis;
  int zt;
};
struct Node2
{
  int v;
  int dis;
};

Node2 vis[200010];
bool bfs()
{
  queue<Node> qe;
  Node tp;
  tp.t = 0;
  tp.dis = 0;
  tp.zt = 0;
  qe.push(tp);

  while (!qe.empty())
  {
    Node cur = qe.front();

    qe.pop();
    if (vis[cur.t].v == 1 && vis[cur.t].dis <= cur.dis)
      continue;

    vis[cur.t].v = 1;
    vis[cur.t].dis = cur.dis;
    if (cur.t == n + 1)
      return true;
    if (cur.zt != 1)
    {
      for (int i = 1; i <= m; i++)
      {
        Node nx;
        nx.zt = 0;
        nx.t = cur.t + i;
        if (nx.t > n + 1)
          continue;
        if (s[nx.t - 1] == 'C')
          continue;
        if (s[nx.t - 1] == 'W')
        {
          nx.zt = 1;
          nx.dis = cur.dis + 1;
          if (nx.dis > k)
            continue;
        }
        else
        {
          nx.dis = cur.dis;
        }

        if (vis[nx.t].v == 1 && vis[nx.t].dis <= nx.dis)
          continue;

        qe.push(nx);
      }
    }
    else
    {
      Node nx;
      nx.t = cur.t + 1;
      nx.zt = 0;
      if (nx.t > n + 1)
        continue;
      if (s[nx.t - 1] == 'C')
        continue;
      if (s[nx.t - 1] == 'W')
      {
        nx.zt = 1;
        nx.dis = cur.dis + 1;
        if (nx.dis > k)
          continue;
      }
      else
      {
        nx.dis = cur.dis;
      }

      if (vis[nx.t].v == 1 && vis[nx.t].dis <= nx.dis)
        continue;
      qe.push(nx);
    }
  }

  return false;
}

void slove()
{
  cin >> n >> m >> k;
  cin >> s;
  s += 'P';
  if (bfs())
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    slove();
    for (int i = 0; i <= n + 10; i++)
    {
      vis[i].v = 0;
      vis[i].dis = 1e11;
    }
  }
}