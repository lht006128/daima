#include <bits/stdc++.h>
#define int long long
using namespace std;
char c[3000000];
int dp[3000000];

void slove()
{
  int n;
  int ans = -1;
  cin >> n;
  int cnta = 0, cntb = 0;
  int cnt = 0;
  char tp = 'C';
  for (int i = 1; i <= n; i++)
  {
    cin >> c[i];

    if (c[i] == 'A')
    {
      cnta++;
    }
    else
    {
      cntb++;
    }

    if (tp == 'C')
    {
      tp = c[i];
    }
    else if (tp != c[i])
    {
      cnt++;
      tp = c[i];
    }
  }

  if (cnta == 0 || cntb == 0)
  {
    cout << 1;
  }
  else if (cnt == 1)
  {
    cout << 2;
  }
  else
  {
    cout << 3;
  }
  cout << endl;
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