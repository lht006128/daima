#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
map<int, int> vis;
int n, s;

void slove()
{

  cin >> n >> s;
  int ans1 = s - 1;

  int ans2 = 1e18;
  int cur = 1;
  // for (int i = 1; i <= s; i++)
  // {
  //   if (cur + abs(n / cur - s) + 1 < ans2)
  //   {
  //     ans2 = cur - 1 + abs(n / cur - s) + 1;
  //     cur++;
  //   }
  //   else
  //   {
  //     break;
  //   }
  // }

  int l = 1, r = s;

  while (l <= r)
  {
    int mid = (l + r) / 2;
    if ((n / mid) >= s)
      l = mid + 1;
    else
      r = mid - 1;
  }

  ans2 = l - 1 + abs(n / (l - 1) - s);
  cout << min(ans1, ans2) << endl;
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