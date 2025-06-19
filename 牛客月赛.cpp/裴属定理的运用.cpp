#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[300000];
int b[300000];
vector<int> arr;
void slove()
{
  int n, k;
  int f = 1;
  cin >> n >> k;
  int gys = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    gys = gcd(a[i], gys);
  }

  if (n == 1)
  {
    if (a[1] < k)
    {
      cout << k << endl;
    }
    else
    {
      cout << k - 1 << endl;
    }
    return;
  }

  b[0] = -gys;
  for (int i = 1; i <= n; i++)
  {
    b[i] = b[i - 1] + gys;
  }
  int last = -1;
  for (int i = 1; i <= n; i++)
  {
    // cout << b[i] << " " << last << " " << k << endl;
    if (k <= b[i] - last - 1)
    {
      break;
    }
    k -= (b[i] - last - 1);
    last = b[i];
  }
  cout << last + k << endl;
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