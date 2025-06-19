#include <bits/stdc++.h>
using namespace std;
char gouzao[1000][2];

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int idx = 1;
  for (int i = 0; i < 26; i++)
  {
    for (int j = i; j < 26; j++)
    {
      gouzao[idx][0] = i;
      gouzao[idx][1] = j;
      idx++;
      // cout << char(i + 'a') << char(j + 'a') << endl;
    }
  }
  if (m >= k)
  {
    cout << "No" << endl;
    return 0;
  }
  if (m == 0)
  {
    if (n > 26)
    {
      cout << "No";
      return 0;
    }
    else
    {
      cout << "Yes" << endl;
      for (int i = 1; i <= n; i++)
      {
        for (int j = 1; j <= k; j++)
        {
          cout << char(i - 1 + 'a');
        }
        cout << endl;
      }
    }
    return 0;
  }

  // 其他的正常情况 已经计算出必有解 是一个等差数列 1+ 26*25/2
  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++)
  {

    for (int j = 1; j <= m - 1; j++)
    {
      cout << 'a';
    }
    int f = 0;
    for (int o = m; o <= k; o++)
    {
      cout << char(gouzao[i][f] + 'a');
      f = !f;
    }

    cout << endl;
  }
}