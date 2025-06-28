#include <bits/stdc++.h>
#define int long long
using namespace std;

string ans;

string adds(string a, string b)
{
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string c;
  bool jinwei = false;

  for (int i = 0; i < min(a.size(), b.size()); i++)
  {
    bool jbjw = false;
    if (a[i] == b[i])
    {
      if (a[i] == '0')
      {
        c += '0';
      }
      else
      {
        c += '0';
        jbjw = true;
      }
    }
    else
    {
      if (a[i] == '1' || b[i] == '1')
      {
        c += '1';
      }
      else
      {
        c += '0';
      }
    }
    if (jinwei)
    {
      if (c[c.size() - 1] == '1')
      {
        c[c.size() - 1] = '0';
        jbjw = true;
      }
      else
      {
        c[c.size() - 1] = '1';
      }
    }

    jinwei = jbjw;
  }

  if (a.size() != b.size())
  {
    if (a.size() > b.size())
    {

      for (int i = min(a.size(), b.size()); i < a.size(); i++)
      {
        bool jbjw = false;
        if (a[i] == '1')
        {
          c += '1';
        }
        else
        {
          c += '0';
        }

        if (jinwei)
        {
          if (c[c.size() - 1] == '1')
          {
            c[c.size() - 1] = '0';
            jbjw = true;
          }
          else
          {
            c[c.size() - 1] = '1';
          }
        }
        jinwei = jbjw;
      }
    }
    else
    {
      for (int i = min(a.size(), b.size()); i < b.size(); i++)
      {
        bool jbjw = false;
        if (b[i] == '1')
        {
          c += '1';
        }
        else
        {
          c += '0';
        }

        if (jinwei)
        {
          if (c[c.size() - 1] == '1')
          {
            c[c.size() - 1] = '0';
            jbjw = true;
          }
          else
          {
            c[c.size() - 1] = '1';
          }
        }
        jinwei = jbjw;
      }
    }
  }
  else
  {
  }
  if (jinwei)
  {
    c += '1';
  }
  reverse(c.begin(), c.end());
  return c;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;

  ans = s;
  for (int i = 1; i <= 20; i++)
  {
    ans = adds(ans, s);
  }
  cout << ans << endl;
}