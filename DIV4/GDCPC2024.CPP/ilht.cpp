#include <bits/stdc++.h>

using namespace std;

map<int, map<int, int>> mp;
vector<int> arr(300010, 1);
int js[300010];
int cnt[300010];

struct Node
{
  /* data */
  int g, a, b;
};

vector<Node> que;

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  int t = m;
  while (t--)
  {
    int g, a, b;
    cin >> g >> a >> b;

    if (mp[g][a] == 1 || mp[g][b] == 1)
    {
      cout << -1;
      return 0;
    }

    mp[a][g] = 1;
    mp[b][g] = 1;
    js[g]++;

    que.push_back({g, a, b});
  }

  int f = 1;

  f = 1;
  for (int i = 0; i < m; i++)
  {
    if (js[que[i].a] <= 0 && js[que[i].b] <= 0)
    {
      arr[que[i].g] = max(arr[que[i].g], arr[que[i].a] + arr[que[i].b]);
      // cout << arr[que[i].g] << endl;
      js[que[i].g]--;
    }
    else
    {
      f = 0;
    }
  }

  int sum = 0;
  for (int i = 1; i <= n; i++)
  {
    sum += arr[i];
    // cout << arr[i] << " " << i << endl;
  }
  cout << sum;
}
