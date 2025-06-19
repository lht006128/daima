#include <bits/stdc++.h>
#define int long long
using namespace std;

void slove()
{
  int a, b, c;
  cin >> a >> b >> c;

  if (a < b && b < c)
  {
    cout << "STAIR" << endl;
  }
  else if (a < b && b > c)
  {
    cout << "PEAK" << endl;
  }
  else
  {
    cout << "NONE" << endl;
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