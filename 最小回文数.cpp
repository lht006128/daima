#include <bits/stdc++.h>
using namespace std;

string gz(string s)
{
  string ts = "";
  string q = "";
  if (s.size() % 2 == 0)
  {

    for (int i = 0; i < s.size() / 2; i++)
    {
      q += s[i];
    }
    ts = q;
    for (int i = 0; i < q.size(); i++)
    {
      ts += q[q.size() - i - 1];
    }
    return ts;
  }
  else
  {
    for (int i = 0; i <= s.size() / 2; i++)
    {
      q += s[i];
    }
    ts = q;
    for (int i = 1; i < q.size(); i++)
    {
      ts += q[q.size() - i - 1];
    }
    return ts;
  }
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string s;
  cin >> s;

  if (s.size() == 1)
  {
    if (s != "9")
    {
      s[0]++;
      cout << s;
    }
    else
    {
      cout << "11";
    }
    return 0;
  }

  string hw;
  hw = gz(s);

  // 比原来大直接输出
  if (hw > s)
  {
    cout << hw;
  }
  else
  {
    // 进位操作

    if (s.size() % 2 == 0)
    {
      for (int i = s.size() / 2 - 1; i >= 0; i--)
      {
        if (s[i] >= '9')
        {
          s[i] = '0';
          if (i == 0)
          {
            string tt = "1";
            tt = tt + s;
            s = tt;
            break;
          }
          else
          {
            // s[i - 1]++;
          }
          continue;
        }
        else
        {
          s[i]++;
          break;
        }
      }
      hw = gz(s);
      cout << hw;
    }
    else
    {
      for (int i = s.size() / 2; i >= 0; i--)
      {
        if (s[i] >= '9')
        {
          s[i] = '0';
          if (i == 0)
          {
            string tt = "1";
            tt = tt + s;
            s = tt;
            break;
          }
          else
          {
            // s[i - 1]++;
          }
          continue;
        }
        else
        {
          s[i]++;
          break;
        }
      }
      hw = gz(s);
      cout << hw;
    }
  }
}