#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node
{
  int t;
  int time;
  int next;

  bool operator<(const Node &other) const
  {
    return time > other.time; // 小根堆， 时间短的先
  }
};
Node edge[2000000];

int cnt = 0;
int head[2000000]; // 链式前向星 建图
int arr[2000000];
int unlock[2000000]; // 记录解锁状态
int dis[2000000];    // 记录所需要的时间.

void addedge(int x, int y, int w)
{
  edge[++cnt].t = y;
  edge[cnt].time = w; // 记录花费的时间 边
  edge[cnt].next = head[x];
  head[x] = cnt;
}

priority_queue<Node> dui;

void bfs()
{

  while (!dui.empty())
  {
    Node cur = dui.top(); // 读入一个能量或者刷新器。
    dui.pop();
    if (cur.next == -1)
    {
      // 这个是被刷新了 -1 是刷新qi
      arr[cur.t] = 0;
    }
    else
    {
      // 这个是接受一个能量，相当于减去1 的限制
      arr[cur.t] -= 1;
    }
    // 如果还没解锁，记录当前的时间。
    if (unlock[cur.t] == 0)
    {
      dis[cur.t] = max(dis[cur.t], cur.time);
    }
    // 这是 可以解锁了 ，解锁之后可以传递一个新的能量
    if (unlock[cur.t] != 1 && arr[cur.t] <= 0)
    {

      unlock[cur.t] = 1;
      // 解锁成功 ，发送能量
      for (int i = head[cur.t]; i != -1; i = edge[i].next)
      {
        Node nex;

        nex.t = edge[i].t;
        if (unlock[nex.t] == 1)
          continue;
        nex.time = edge[i].time + cur.time;
        nex.next = 0;
        dui.push(nex);
      }
    }
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  // 初始化
  memset(head, -1, sizeof(head));
  memset(dis, -1, sizeof(dis));

  int n, m, k;
  cin >> n >> m >> k;

  // 因为有可能不同刷新器对同一个点刷新，所以取一个最小值。
  map<int, int> mp;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    if (arr[i] == 0)
    {
      dui.push({i, 0, 0});
    }
  }

  for (int i = 1; i <= k; i++)
  {
    int tpt, tpsc;
    cin >> tpt >> tpsc;
    for (int j = 1; j <= tpsc; j++)
    {
      int id;
      cin >> id;

      if (mp[id] == 0)
      {
        mp[id] = tpt + 1;
      }
      else
      {
        mp[id] = min(mp[id], tpt + 1); // 加一是因为 时间会有0的情况 又因为我要判断
      }
    }
  }

  vector<Node> qe; // 存放每个点刷新为0 的时间 ，当然是值有被刷新qi刷新到的

  for (auto [x, y] : mp)
  {
    // qe.push_back({x, y, -1});
    dui.push({x, y - 1, -1});
  }

  for (int i = 1; i <= m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;

    addedge(u, v, w);
  }

  bfs();

  for (int i = 1; i <= n; i++)
  {
    if (unlock[i] == 1)
    {
      cout << dis[i] << " ";
    }
    else
    {
      cout << -1 << " ";
    }
  }
}