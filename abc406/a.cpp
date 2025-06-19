#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int sum1;
  int sum2;
  sum1 = a * 60 + b;
  sum2 = c * 60 + d;

  if (sum1 > sum2)
  {
    cout << "Yes" << endl;
  }
  else
    cout << "No" << endl;
}