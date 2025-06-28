#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[300010];

void slove()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  int sum = 0;
  for (int i = 2; i <= n; i++)
  {
    cout << arr[i] - arr[i - 1] << " ";
  }

  cout << endl;
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