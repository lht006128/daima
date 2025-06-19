#include <bits/stdc++.h>
#define int long long
using namespace std;

int h[500];
deque<int> qe;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> h[i];
  }

  sort(h + 1, h + 1 + n);

  for (int i = 1; i <= n; i++)
  {
    qe.push_back(h[i]);
  }

  int ans = 0;
  int cur = 0;
  while (!qe.empty())
  {
    ans += (qe.back() - cur) * (qe.back() - cur);

    cur = qe.back();
    qe.pop_back();

    if (!qe.empty())
    {
      ans += (qe.front() - cur) * (qe.front() - cur);

      cur = qe.front();
      qe.pop_front();
    }
  }

  cout << ans;
}