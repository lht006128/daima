#include <bits/stdc++.h>
#define int long long
using namespace std;

string s[300000];
vector<bitset<300>> a;

int gbs = -1;
int lca(int a, int b)
{
  return (a * b) / gcd(a, b);
}

signed main()
{

  int n;
  int f = 1;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];

    for (int j = 1; s[i].size() <= 300 + 10; j++)
    {
      s[i] += s[i];
    }
    bitset<300> tp(s[i]);
    // cout << tp << endl;
    a.push_back(tp);
    if (gbs == -1)
    {
      int ff = 0;
      for (int j = 257 - 1; j >= 0; j--)
      {
        if (tp[j] == 1)
        {
          gbs = 257 - j;
          ff = 1;
          break;
        }
      }
      if (!ff)
        f = 0;
    }
    else
    {
      int cd = 0;
      int ff = 0;
      for (int j = 300 - 1; j >= 0; j--)
      {
        if ((tp[j] & a[a.size() - 2][j]) == 1)
        {
          cd = 300 - j;
          ff = 1;
          break;
        }
      }
      if (!ff)
        f = 0;
      gbs = lca(gbs, cd);
    }
  }
  if (f)
    cout << gbs;
  else
    cout << -1;
  // bitset<5> te("10111111");
  // cout << te << endl;
}