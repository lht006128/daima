#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int arr[60010];
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int l;
  cin >> l;
  int n;
  cin >> n;

  int mintimes = 0;
  int maxtimes = 0;
  int sum = 0;
  int mid = l / 2;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  sort(arr + 1, arr + 1 + n);
  for (int i = 1; i <= n; i++)
  {
    if (arr[i] <= mid)
    {
      mintimes = max(mintimes, arr[i]);
      maxtimes = max(maxtimes, l - arr[i] + 1);
    }
    else
    {
      mintimes = max(mintimes, l - arr[i] + 1);
      maxtimes = max(maxtimes, arr[i]);
    }
  }

  cout << mintimes << " " << maxtimes;
}