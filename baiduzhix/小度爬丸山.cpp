#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int mod = 998244353;
int arr[300010];
int shu[300010];
int shu2[300010];
int lowbit(int x)
{
  return x & -x;
}

void add(int x, int val)
{
  while (x <= n)
  {
    shu[x] = ((LL)shu[x] + val) % mod;
    x += lowbit(x);
  }
}

int sum(int x)
{
  int res = 0;
  while (x > 0)
  {
    res = (res + shu[x]) % mod;
    x -= lowbit(x);
  }
  return res;
}

void add2(int x, int val)
{
  while (x <= n)
  {
    shu2[x] = ((LL)shu2[x] + val) % mod;
    x += lowbit(x);
  }
}

int sum2(int x)
{
  int res = 0;
  while (x > 0)
  {
    res = (res + shu2[x]) % mod;
    x -= lowbit(x);
  }
  return res;
}
set<int> st;
unordered_map<int, int> mp;
int dpl[300010];
int dpr[300010];
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    st.insert(arr[i]); //  离散化。
  }

  int idx = 0;
  for (auto x : st)
  {
    mp[x] = ++idx;
  }
  // idx 记录了当前的最大值
  for (int i = 1; i <= n; i++)
  {

    dpl[i] = (1 + (LL)sum(mp[arr[i]] - 1));
    add(mp[arr[i]], dpl[i]);
    dpr[i] = (1 + (LL)sum2(mp[arr[i]] - 1));
    add2(mp[arr[i]], dpr[i]);
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans = (ans + (LL)dpl[i] * dpr[i] % mod) % mod;
  }
  cout << ans;
  return 0;
}