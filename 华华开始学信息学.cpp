#include <bits/stdc++.h>
#define int long long
using namespace std;
int jia[200100];
int arr[200100];
int n, m;

int lowbit(int x)
{
  return x & (-x);
}

void add(int i, int val)
{
  while (i <= n)
  {
    arr[i] += val;
    i += lowbit(i);
  }
}

int sum(int i)
{
  int s = 0;
  while (i > 0)
  {
    s += arr[i];
    i -= lowbit(i);
  }
  return s;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;

  // while (lowbit(n) != n)
  // {
  //   n += lowbit(n);
  // }

  while (m--)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int d, k;
      cin >> d >> k;

      if (d * d <= n)
      {
        jia[d] += k;
      }
      else
      {
        for (int i = d; i <= n; i += d)
        {
          add(i, k);
        }
      }
    }
    else
    {
      int l, r;
      cin >> l >> r;
      int tsum = 0;
      tsum = sum(r) - sum(l - 1);
      for (int i = 1; i * i <= n; i++)
      {
        tsum += (r / i - (l - 1) / i) * jia[i];
      }
      cout << tsum << endl;
    }
  }
}