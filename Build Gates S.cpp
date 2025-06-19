#include <bits/stdc++.h>
using namespace std;
int mp[2021][2021];
int vis[2021][2021];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int flag = 0;
int ans = 0;

struct Node
{
  int x, y;
};
queue<Node> qe;

void bfs(int x, int y)
{
  // mp[x][y] = 2;
  // vis[x][y] = 1;

  qe.push({x, y});

  while (!qe.empty())
  {
    Node cur;
    cur = qe.front();
    qe.pop();

    if (vis[cur.x][cur.y])
      continue;
    vis[cur.x][cur.y] = 1;

    for (int i = 0; i < 4; i++)
    {
      Node nx;
      nx.x = cur.x + dir[i][0];
      nx.y = cur.y + dir[i][1];

      if (nx.x < 1 || nx.x > 2020 || nx.y < 1 || nx.y > 2020)
      {
        flag = 1;
        // cout << f;
        continue;
      }

      if (vis[nx.x][nx.y])
        continue;
      if (mp[nx.x][nx.y] == 1)
        continue;
      if (mp[nx.x][nx.y] != 0)
        continue;

      mp[nx.x][nx.y] = 2;
      qe.push(nx);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  string s;
  cin >> n;
  cin >> s;

  // 源点 1500 1500；
  mp[1010][1010] = 1;
  int x, y;
  x = 1010;
  y = 1010;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'N')
    {
      x--;
      mp[x][y] = 1;
      x--;
      mp[x][y] = 1;
    }
    else if (s[i] == 'S')
    {
      x++;
      mp[x][y] = 1;
      x++;
      mp[x][y] = 1;
    }
    else if (s[i] == 'E')
    {
      y++;
      mp[x][y] = 1;
      y++;
      mp[x][y] = 1;
    }
    else if (s[i] == 'W')
    {
      y--;
      mp[x][y] = 1;
      y--;
      mp[x][y] = 1;
    }
  }

  // for (int i = 1000; i <= 1020; i++)
  // {
  //   for (int j = 1000; j <= 1020; j++)
  //   {
  //     cout << mp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 1; i <= 2020; i++)
  {
    for (int j = 1; j <= 2020; j++)
    {

      if (mp[i][j] == 0)
      {
        // cout << i << " " << j << endl;
        flag = 0;
        bfs(i, j);
        if (!flag == 1)
        {
          ans++;
        }
      }
    }
  }
  cout << ans;
}