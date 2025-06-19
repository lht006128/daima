#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 40010;
int crr[50010];
bitset<N> bt[N];
int ans = 0;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> crr[i];
  }

  for (int i = n; i >= 1; i--)
  {
    bt[i][crr[i]] = 1;
    if (i * 2 <= n)
    {
      bt[i] |= bt[i * 2];
    }

    if (i + crr[i] <= n)
    {
      bt[i] |= bt[i + crr[i]];
    }
    ans = max<int>(bt[i].count(), ans);
    // cout << bt[i].count() << endl;
  }
  cout << ans;
}
