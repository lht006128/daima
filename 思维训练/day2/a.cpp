#include <bits/stdc++.h>
#define int long long

using namespace std;

void slove()
{
  int n;
  cin >> n;
  if (n == 0)
  {
    cout << 0 << " " << 0 << endl;
    return;
  }
  if (sqrt(n) == (int)(sqrt(n)))
  {
    int num = sqrt(n);
    cout << num - 1 << " " << 1 << endl;
  }
  else
  {
    cout << -1 << endl;
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