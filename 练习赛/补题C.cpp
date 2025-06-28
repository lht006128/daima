#include <bits/stdc++.h>
#define int long long
using namespace std;
int cntzm[30];
int l = 1;

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  int x;
  cin >> s >> x;

  if (s.size() == 1)
  {
    cout << x;
    return 0;
  }

  int ans = 1e18 + 10;
  int sum = 0;
  for (int i = 1; i <= s.size(); i++)
  {
    int num = s[i - 1] - 'a' + 1;
    int tp = 0;
    for (int j = num + 1; j <= 26; j++)
    {
      tp += cntzm[j];
    }

    sum += tp;
    ans = min<int>(ans, abs(sum - x));

    cntzm[num]++;

    while (l <= i && sum >= x)
    {
      int tp2 = 0;
      int num2 = s[l - 1] - 'a' + 1;
      for (int j = num2 - 1; j >= 1; j--)
      {
        tp2 += cntzm[j];
      }
      sum -= tp2;
      cntzm[num2]--;
      l++;
      ans = min<int>(ans, abs(sum - x));
    }
    ans = min<int>(ans, abs(sum - x));
  }
  cout << ans;
}