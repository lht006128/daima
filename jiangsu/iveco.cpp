#include <bits/stdc++.h>
// #define int long long
using namespace std;

// int c[2000000];

int n;
struct Node
{
  int color;
  int num;
};

bool cmp(Node a, Node b)
{
  return a.num < b.num;
}

Node a[2000000];

bool pd(int mid)
{
  multiset<int> s[2];

  for (int i = 1; i <= n; ++i)
  {
    if (!s[!a[i].color].empty())
    {
      auto it = s[!a[i].color].lower_bound(mid - a[i].num);
      if (it == s[!a[i].color].end())
      {
        return false;
      }
      else
      {
        s[!a[i].color].erase(it);
      }
    }
    else
    {
      s[a[i].color].insert(a[i].num);
    }
  }
  return true;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;

  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i].num;
  }

  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i].color;
  }

  int l = 1, r = 2e8;

  while (l <= r)
  {
    int mid = ((l + r) >> 1);
    if (pd(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << l - 1;
}