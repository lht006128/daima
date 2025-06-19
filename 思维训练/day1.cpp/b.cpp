#include <bits/stdc++.h>
#define int long long
using namespace std;

void slove()
{
  string s;
  cin >> s;
  int f = 0;
  int ph = 0;
  for (int i = 0; i < s.size() - 1; i++)
  {
    if (s[i] == '(')
    {
      ph++;
    }
    else
    {
      ph--;
    }

    if (s[i] == ')' && s[i + 1] == '(' && ph == 0)
    {
      f = 1;
    }
  }

  if (f)
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