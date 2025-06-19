#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[100010];

void slove()
{
  int n;
  vector<int> brr;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 2; i <= n; i++)
  {
    if (arr[i] < arr[i - 1])
    {
      brr.push_back(arr[i - 1] - arr[i]);
      arr[i] = arr[i - 1];
    }
  }

  sort(brr.begin(), brr.end());
  int ans = 0;
  int jian = 0;
  for (int i = 0; i < brr.size(); i++)
  {
    int num = brr[i];
    num -= jian;
    if (num <= 0)
      continue;
    else
    {
      jian += num;
      ans += (brr.size() + 1 - i) * num;
    }
  }
  cout << ans << endl;
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