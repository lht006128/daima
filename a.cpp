#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
map<int, int> vis;
int n, s;
int maxnum = 0;
struct Node
{
  int t;
  int cnt;
};

int bfs(int x)
{
  queue<Node> qe;
  Node tp;
  tp.cnt = 0;
  tp.t = x;
  qe.push(tp);
  while (!qe.empty())
  {
    Node cur = qe.front();
    qe.pop();
    if (vis[cur.t] == 1)
      continue;
    vis[cur.t] = 1;
    if (cur.t == s)
    {
      return cur.cnt;
    }

    Node nx;
    if (vis[cur.t - 1] != 1 && cur.t > 1)
    {
      nx.t = cur.t - 1;
      nx.cnt = cur.cnt + 1;
      qe.push(nx);
    }

    if (vis[cur.t + 1] != 1 && cur.t < n)
    {
      nx.t = cur.t + 1;
      nx.cnt = cur.cnt + 1;
      qe.push(nx);
    }
    if (vis[n / cur.t] != 1)
    {
      nx.t = n / cur.t;
      nx.cnt = cur.cnt + 1;
      qe.push(nx);
    }
  }
  return -1;
}

void slove()
{
  vis.clear();

  cin >> n >> s;
  maxnum = s - 1;
  int ans = bfs(1);
  cout << ans << " " << s << " " << (n - s) / 2 << endl;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }
}