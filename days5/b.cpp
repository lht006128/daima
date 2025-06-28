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

  for (int i = 1; i <= n - 2; i++)
  {
    if (arr[i] < 0)
    {
      cout << "NO" << endl;
      return;
    }
    int jian = arr[i];
    arr[i + 1] -= arr[i] * 2;
    arr[i + 2] -= arr[i];
    arr[i] = 0;
  }

  if (arr[n] == 0 && arr[n - 1] == 0)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
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