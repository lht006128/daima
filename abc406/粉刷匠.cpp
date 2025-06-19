#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010];
vector<int> mp[1000010];

int zhs(int x, int y)
{
  int tp1 = 1;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    mp[a[i]].push_back(i);
  }

  for (int i = 1; i <= n; i++)
  {
    sort(mp[a[i]].begin(), mp[a[i]].end());
  }

  int ans = 0;
  for (int i = 0; i <= n; i++)
  {
    ans += mp[i].size();
  }
}