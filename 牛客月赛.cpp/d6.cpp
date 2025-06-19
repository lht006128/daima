#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int k;
  cin >> k;

  for (int i = 1; i <= 1e7; i++)
  {
    int tp = (i * i + k) / (i + 1);
    int tp2 = (int)(ceil((i * i + k) * 1.0 / (i + 1)));
    if (tp == tp2 && tp != k)
    {
      cout << tp << " " << k - tp;
      return 0;
    }
  }

  cout << -1;
}