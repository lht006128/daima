#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, int> mp;

int w[300010];
vector<int> arr[300010];
int cnt[300010];
int sum[300010];

int t = 1;
int ans;
bool cmp(int a, int b)
{
  return sum[a] * (cnt[mp[a]] - cnt[a] - 1) < sum[b] * ((cnt[mp[b]] - cnt[b] - 1));
}

void dfs(int x, int fa)
{
  cnt[x] = 1;
  sum[x] = w[x];

  for (int i = 0; i < arr[x].size(); i++)
  {
    int j = arr[x][i];
    if (j == fa)
      continue;
    dfs(j, x);
    cnt[x] += cnt[j];
    sum[x] += sum[j];
  }

  stable_sort(arr[x].begin(), arr[x].end(), cmp);
}

void dfs2(int x, int fa)
{
  ans += w[x] * t;
  // cout << x << endl;

  for (int i = 0; i < arr[x].size(); i++)
  {
    int j = arr[x][i];
    if (j == fa)
      continue;
    t++;
    dfs2(j, x);
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> w[i];
  }

  for (int i = 2; i <= n; i++)
  {
    int tp;
    cin >> tp;

    arr[tp].push_back(i);
    mp[i] = tp;
  }

  dfs(1, -1);
  dfs2(1, -1);

  // cout << cnt[3] << endl;
  cout << ans;
}
