#include <bits/stdc++.h>
#define int long long
using namespace std;

void slove()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  map<char, int> mp;
  int maxx = -1;

  for (int i = 0; i < s.size(); i++)
  {
    mp[s[i]]++;
  }

  for (auto [x, y] : mp)
  {
    maxx = max(maxx, y);
  }

  int have = n - maxx;

  if (have == maxx)
  {
    cout << 0 << endl;
  }
  else if (maxx > have)
  {
    cout << maxx - have << endl;
  }
  else
  {
    cout << (have - maxx) % 2 << endl;
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