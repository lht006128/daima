#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

set<int> num;
int last = -1;
int same = 1;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int tp;
    cin >> tp;
    num.insert(tp);
    if (last == -1)
    {
      last = tp;
    }
    else
    {
      if (tp != last)
        same = 0;
    }
  }
  if (same)
  {
    cout << 0;
    return 0;
  }

  for (auto it : num)
  {
    cout << it << endl;
  }
}