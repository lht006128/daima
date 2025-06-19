#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int sum = 36;
int arr[10] = {0, 0, 36, 35, 33, 30, 26};

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x, y;
  cin >> x >> y;
  int ans = 0;

  for (int i = 1; i <= 6; i++)
  {
    for (int j = 1; j <= 6; j++)
    {
      if (i + j >= x || abs(i - j) >= y)
      {
        ans++;
      }
    }
  }
  cout << (double)(ans * 1.0 / 36);
  // printf("%.9lf", ans * 1.0 / 36);
}