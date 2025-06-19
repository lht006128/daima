#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[300100];

void slove()
{
  int n;
  cin >> n;
  int bit0[31] = {0};
  int bit1[31] = {0};
  int ans = -1;
  int idx = -1;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];

    for (int j = 30; j >= 0; j--)
    {
      int num;
      num = (1 << j);
      if ((a[i] & num) != 0)
      {
        bit1[j]++;
      }
      else
      {
        bit0[j]++;
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    int tp = 0;
    for (int j = 30; j >= 0; j--)
    {
      int num;
      num = (1 << j);
      if ((a[i] & num) != 0)
      {
        tp += num * bit0[j];
      }
      else
      {
        tp += num * bit1[j];
      }
    }
    // cout << tp << endl;
    if (tp > ans)
    {
      ans = tp;
      idx = i;
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++)
  {
    sum += (a[idx] ^ a[i]);
  }
  cout << sum << endl;
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