#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int a[1000010];
int calc(int x)
{
  return to_string(x).length();
}

int ksm(int x, int k)
{
  int num = 1;

  while (k)
  {
    if (k)
      num *= x;
    x *= x;
    k >>= 1;
  }

  return num;
}
int jsq = 1;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++)
  {
    int last = jsq;
    int cnt1 = calc(jsq) - 1;
    int cnt2 = calc(a[i]) - 1;

    // // cout << cnt1 + cnt2 + 1 << endl;
    // if (cnt1 + cnt2 + 1 > k)
    // {
    //   jsq = 1;
    //   continue;
    // }

    jsq *= a[i];
    if (jsq <= 0 || calc(jsq) > k || jsq < last)
    {
      jsq = 1;
    }
  }

  cout << jsq;
}