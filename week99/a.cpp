#include <bits/stdc++.h>
#define int long long

using namespace std;

void slove()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  int f = 0;
  int cnt = -1;
  int ok = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '1')
      f = 1;
    else
      f = 0;

    if (s[i] == '1')
    {
      if (cnt == -1)
      {
        cnt = 1;
      }
      else
      {
        cnt++;
      }
    }
    else
    {
      if (cnt != -1)
      {
        if (cnt < 2 && !ok)
        {
          f = 1;
          break;
        }
        if (cnt >= 2)
        {
          ok = 1;
        }
        cnt = -1;
      }
    }
  }

  if (f)
  {
    cout << "NO" << endl;
  }
  else
  {
    cout << "YES" << endl;
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