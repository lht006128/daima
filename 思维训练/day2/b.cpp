#include <bits/stdc++.h>
#define int long long

using namespace std;

void slove()
{
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int cnt0 = 0;
  int cnt1 = 0;
  int cnt = 0;
  int hcnt0 = 0;
  int hcnt1 = 0;
  for (int i = 1; i <= n / 2; i++)
  {
    if (s[i - 1] == s[n - i])
    {
      cnt++;
      if (s[i - 1] == '1')
      {
        hcnt1++;
      }
      else
      {
        hcnt0++;
      }

      continue;
    }
    else
    {
      if (s[i - 1] == '1')
      {
        cnt1++;
      }
      else
      {
        cnt0++;
      }
    }
  }

  // cerr << cnt0 << " " << cnt1 << " " << cnt << " " << hcnt0 << " " << hcnt1 << endl;
  if (cnt == k)
  {
    cout << "YES" << endl;
  }
  else if (cnt < k)
  {
    int cha = k - cnt;
    if (cha % 2 != 0)
    {
      cout << "NO" << endl;
    }
    else
    {
      if ((cnt0 + cnt1) * 2 >= cha)
      {
        cout << "YES" << endl;
      }
      else
      {
        cout << "NO" << endl;
      }
    }
  }
  else if (cnt > k)
  {
    int cha = cnt - k;
    if (cha % 2 != 0)
    {
      cout << "NO" << endl;
    }
    else
    {

      if (min(hcnt0, hcnt1) * 2 >= cha)
      {
        cout << "YES" << endl;
      }
      else
      {
        cout << "NO" << endl;
      }
    }
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }
}