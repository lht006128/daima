#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[100010];
int ans = 0;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int a = 0, b = 0;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
    {
      a++;
    }
    if (s[i] == ')')
    {
      b++;
    }
    if (a - 2 >= b && s[i] == '(')
    {
      dp[i] = 1;
    }
    else if (s[i] == ')')
    {
      dp[i] = 1;
    }
    else
    {
      dp[i] = 0;
    }
    cout << dp[i] << " ";
  }
  cout << endl;
  a = 0;
  b = 0;

  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (s[i] == ')')
    {
      a++;
    }
    if (s[i] == '(')
    {
      b++;
    }
    if (a - 2 < b && s[i] == ')')
    {
      dp[i] = 0;
    }
    else if (s[i] == '(')
    {
    }
    else
    {
      if (dp[i] == 1)
      {
        dp[i] = 1;
      }
      else
      {
        dp[i] = 0;
      }
    }

    cout << dp[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < s.size(); i++)
  {
    ans += dp[i];
  }
  cout << ans;
}