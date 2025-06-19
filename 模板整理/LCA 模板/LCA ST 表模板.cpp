#include <bits/stdc++.h>
using namespace std;

vector<int> shu[500010];

int arr[1000010];
int num = 0;
int idx = 0;
int pos[500010];
int dp[64][1000100];

map<int, int> mp;
void dfs(int x, int fa)
{
  int tmp = ++num;
  arr[++idx] = tmp;
  mp[num] = x;
  pos[x] = idx;

  for (int i = 0; i < shu[x].size(); i++)
  {
    int j = shu[x][i];
    if (j == fa)
    {
      continue;
    }
    dfs(j, x);
    arr[++idx] = tmp;
  }
}
// 测试代码
void init(int n)
{

  for (int i = 1; i <= n; i++)
  {
    dp[0][i] = arr[i];
  }

  int len = log2(n);

  for (int i = 1; i <= len; i++)
  { // 遍历所有可能的幂次
    for (int j = 1; j <= n - (1 << i) + 1; j++)
    { // 遍历所有可能的起始位置
      dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
    }
  }
}

int queryST(int l, int r)
{
  if (l > r)
  {
    swap(l, r);
  }
  int t = log2(r - l + 1);
  return min(dp[t][l], dp[t][r - (1 << t) + 1]);
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m, s;
  cin >> n >> m >> s;

  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    shu[x].push_back(y);
    shu[y].push_back(x);
  }

  dfs(s, 0);

  init(idx);

  // for (int i = 1; i <= 10; i++)
  // {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;

  for (int i = 1; i <= m; i++)
  {
    int a, b;
    cin >> a >> b;
    //  cout << pos[a] << " " << pos[b] << endl;
    cout << mp[queryST(pos[a], pos[b])] << endl;
  }
}