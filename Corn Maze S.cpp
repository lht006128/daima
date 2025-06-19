#include <bits/stdc++.h>
#define int long long
using namespace std;
string s[310];
struct Node
{
  int x, y;
  int l;
  bool operator<(const Node &other) const
  {
    return l > other.l;
  }
};

map<char, int> mp;
map<char, Node> last;

Node ht[310][310];
int vis[310][310];
int dis[310][310];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int sx, sy;
int ex, ey;
int n, m;

priority_queue<Node> qe;
void bfs(int x, int y)
{
  Node tp;
  tp.x = x;
  tp.y = y;
  tp.l = 0;
  dis[x][y] = 0;
  qe.push(tp);

  while (!qe.empty())
  {
    Node cur;
    cur = qe.top();
    qe.pop();
    // cout << cur.l << " " << cur.x << " " << cur.y << endl;

    if (vis[cur.x][cur.y])
      continue;
    vis[cur.x][cur.y] = 1;
    if (cur.x == ex && cur.y == ey)
    {
      dis[cur.x][cur.y] = cur.l;
      return;
    }

    if (s[cur.x][cur.y - 1] >= 'A' && s[cur.x][cur.y - 1] <= 'Z')
    {
      vis[cur.x][cur.y] = 0;
      int tx, ty;
      tx = ht[cur.x][cur.y].x;
      ty = ht[cur.x][cur.y].y;
      cur.x = tx;
      cur.y = ty;
      dis[cur.x][cur.y] = cur.l;
      // cout << cur.l << endl;
    }
    dis[cur.x][cur.y] = cur.l;

    for (int i = 0; i < 4; i++)
    {
      Node nx;
      nx.x = cur.x + dir[i][0];
      nx.y = cur.y + dir[i][1];
      if (nx.x < 1 || nx.y < 1 || nx.x > n || nx.y > m)
        continue;
      if (vis[nx.x][nx.y])
        continue;
      if (s[nx.x][nx.y - 1] == '#')
        continue;
      else
      {
        nx.l = cur.l + 1;
        // cout << nx.l << endl;
        qe.push(nx);
      }
    }
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];
  }

  // 滑梯的读取。
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i][j - 1] >= 'A' && s[i][j - 1] <= 'Z')
      {
        if (mp[s[i][j - 1]] != 0)
        {
          Node tp;
          tp = last[s[i][j - 1]];
          ht[tp.x][tp.y] = {i, j};
          ht[i][j] = tp;
        }
        else
        {
          mp[s[i][j - 1]] = 1;
          last[s[i][j - 1]] = {i, j};
        }
      }
      if (s[i][j - 1] == '@')
      {
        sx = i;
        sy = j;
      }
      if (s[i][j - 1] == '=')
      {
        ex = i;
        ey = j;
      }
    }
  }

  bfs(sx, sy);

  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 1; j <= m; j++)
  //   {
  //     cout << dis[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << dis[ex][ey];
}