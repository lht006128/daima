#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[2000];
void slove()
{
  int n;
  cin >> n;

  int cnt0 = 0;
  int cnt1 = 0;
  int f = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];

    if (arr[i] == 1)
      cnt1++;
    else
      cnt0++;

    if (i > 1)
    {
      if (arr[i] == 0 && arr[i - 1] == 0)
      {
        f = 1;
      }
    }
  }
  if (f)
  {
    cout << "YES" << endl;
  }

  else if (cnt1 != 0 && cnt0 == 0)
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