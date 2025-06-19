#include <bits/stdc++.h>
using namespace std;

void slove()
{
  int f = 1;
  int cnt = 0;
  int idx = 0;
  string p, s;
  cin >> p >> s;

  for (int i = 0; i < s.size(); i++)
  {
    if (cnt == 0)
    {
      if (s[i] == p[idx])
      {
        cnt++;
      }
      else
      {
        f = 0;
        break;
      }
    }
    else if (cnt == 1)
    {
      if (s[i] == p[idx])
      {
        cnt = 0;
        idx++;
      }
      else
      {
        idx++;
        if (s[i] == p[idx])
        {
          cnt = 1;
        }
        else
        {
          cout << i;
          f = 0;
          break;
        }
      }
    }
  }

  if (idx < p.size() - 1)
  {
    f = 0;
  }

  if (idx == p.size() - 1 && cnt == 0)
  {
    if (s[s.size() - 1] != p[idx])
    {
      f = 0;
    }
  }

  if (f)
  {
    cout << "YES" << endl;
  }
  else
    cout << "NO" << endl;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }
}