#include <bits/stdc++.h>
#define int long long
using namespace std;

void slove()
{
  int n;
  cin >> n;

  map<int, int> mp;
  map<int, int> h;
  for (int i = 1; i <= n; i++)
  {
    int c;
    cin >> c;
    mp[c]++;
  }
  vector<int> arr;

  for (auto [x, cnt] : mp)
  {
    arr.push_back(cnt);
  }
  sort(arr.begin(), arr.end());

  int ans = 0;
  int cnt = 0;
  int idx = 0;
  while (1)
  {
    // ailise get it
    if (arr[idx] > 0)
    {
      if (h[idx] == 0 || h[idx] == 2)
      {
        ans++;
        if (h[idx] == 2)
        {
          h[idx] = 3;
        }
        else
        {
          h[idx] = 1;
        }
      }

      arr[idx]--;
      cnt++;
    }
    if (arr[idx] <= 0)
    {
      if (h[idx] == 1)
      {
        ans++;
      }
      idx++;
    }
    if (cnt >= n)
      break;

    // baobo get it ,choose aili same, or new one best
    arr[idx]--;
    if (h[idx] == 0)
    {
      h[idx] = 2;
    }
    else
    {
      h[idx] = 3;
    }
    cnt++;
    if (arr[idx] <= 0)
    {
      idx++;
    }

    if (cnt >= n)
      break;
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