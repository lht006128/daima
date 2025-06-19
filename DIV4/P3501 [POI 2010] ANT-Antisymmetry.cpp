#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int mod = 1e9 + 99999;
int p = 131;
int h1[600000];
int h2[600000];
int yp[600000];
int ans = 0;

void makehash1(string s)
{
  // int x=1;
  for (int i = 1; i <= s.size(); i++)
  {
    h1[i] = h1[i - 1] * p + s[i - 1];
  }
}
void makehash2(string s)
{
  // int x=1;
  for (int i = s.size(); i >= 1; i--)
  {
    h2[i] = h2[i + 1] * p + s[i - 1];
  }
}
void erfen(int x)
{
  int l = 1;
  int r = min(x, n - x);

  while (l <= r)
  {
    int mid = (l + r) / 2;
    // cout << h1[x] - h1[x - mid] * yp[mid] << endl;

    if (h1[x] - h1[x - mid] * yp[mid] == h2[x + 1] - h2[x + 1 + mid] * yp[mid])
    {
      l = mid + 1;
    }
    else
      r = mid - 1;
  }
  ans += l - 1;
}

void init(int n)
{
  yp[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    yp[i] = yp[i - 1] * p;
  }
}
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  init(n);
  string s;
  cin >> s;

  string t = s; // 反转串 求回文
  makehash1(s);

  for (int i = 0; i < t.size(); i++)
  {
    if (t[i] == '1')
    {
      t[i] = '0';
    }
    else
    {
      t[i] = '1';
    }
  }

  makehash2(t);

  for (int i = 1; i < n; i++)
  {
    erfen(i);
  }

  cout << ans;
}