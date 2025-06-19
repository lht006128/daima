#include <bits/stdc++.h>
using namespace std;

void slove()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int all1 = 0;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '1')
      all1++;
  }

  int ans = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '1')
    {
      ans += (all1 - 1);
    }
    else if (s[i] == '0')
      ans += (all1 + 1);
  }

  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }

  return 0;
}