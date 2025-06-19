#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr1[300100];
int arr2[300100];

void slove()
{
  int n, m, k;
  cin >> n >> m >> k;
  int num = 1;
  int f = 1;
  int need = 0;
  if (m % k == 0)
    need = 1;
  for (int i = 1; i <= k; i++)
  {
    arr1[i - 1] = i;
  }

  for (int i = 1; i <= k - 1; i++)
  {
    arr2[i - 1] = arr1[i];
  }
  arr2[k - 1] = arr1[0];
  int idx = 0;
  for (int i = 1; i <= n; i++)
  {

    for (int j = 1; j <= m; j++)
    {
      if (f)
      {
        cout << arr1[idx++ % k] << " ";
      }
      else
      {
        cout << arr2[idx++ % k] << " ";
      }
    }
    if (need)
      f = 1 - f;

    cout << endl;
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while ((t--))
  {
    slove();
  }
}