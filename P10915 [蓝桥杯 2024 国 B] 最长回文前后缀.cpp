#include <bits/stdc++.h>
#define int long long

using namespace std;
int mod = 1e9 + 7; // 独家取模
int p = 131;       // 定制底数
// abcdebijbba
// ab    bijbba
// cdebijb
int len = 0;
int hqian[500010];
int hhou[500010];
int qp[500010];

void makeh1(string s)
{
  for (int i = 1; i <= s.size(); i++)
  {
    hqian[i] = (hqian[i - 1] * p + s[i - 1]) % mod;
  }
}
void makeh2(string s)
{
  for (int i = s.size(); i >= 1; i--)
  {
    hhou[i] = (hhou[i + 1] * p + s[i - 1]) % mod;
  }
}

void init(int n)
{
  qp[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    qp[i] = (qp[i - 1] * p) % mod;
  }
}

int geth1(int l, int r)
{
  return (hqian[r] - hqian[l - 1] * qp[r - l + 1] % mod + mod) % mod;
}

int geth2(int l, int r)
{
  return (hhou[l] - hhou[r + 1] * qp[r - l + 1] % mod + mod) % mod;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  init(s.size() + 100);
  for (int i = 0; i < s.size() / 2; i++)
  {
    if (s[i] == s[s.size() - 1 - i])
    {
      len++;
    }
    else
    {
      break;
    }
  }
  if (len == s.size())
  {
    cout << len;
    return 0;
  }

  string ts;
  int addlen = 0;
  ts = s.substr(len, s.size() - 2 * len);
  makeh1(ts);
  makeh2(ts);
  // 构造哈希

  // 删掉前缀
  for (int i = 1; i <= ts.size(); i++)
  {
    int l = 1;
    int r = ((ts.size() - i) + 1) / 2;

    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (geth1(i, i + mid - 1) == geth2(ts.size() - mid + 1, ts.size()))
        l = mid + 1;
      else
        r = mid - 1;
    }
    addlen = max(addlen, l - 1);
  }
  // cout << ts << endl;
  // cout << geth1(4, 5) << endl;
  // cout << geth2(6, 7) << endl;
  // 删掉后缀
  for (int i = 1; i <= ts.size(); i++)
  {
    int l = 1;
    int r = ((ts.size() - i) + 1) / 2;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (geth1(1, mid) == geth2(ts.size() - i - mid + 1, ts.size() - i))
        l = mid + 1;
      else
        r = mid - 1;
    }
    addlen = max(addlen, l - 1);
  }

  cout << addlen + len;
}