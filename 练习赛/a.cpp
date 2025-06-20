#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[100010];
int ans1, ans2;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  sort(arr + 1, arr + 1 + n, greater<int>());

  for (int i = 1; i <= n; i++)
  {
    if (i % 2 == 1)
    {
      ans1 += arr[i];
    }
    else
    {
      ans2 += arr[i];
    }
  }

  cout << ans1 << " " << ans2;
}