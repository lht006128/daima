#include <bits/stdc++.h>
using namespace std;

string s[300000];
vector<bitset<520720>> a;

signed main()
{

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];

    for (int j = 1; s[i].size() <= 520720; j++)
    {
      s[i] += s[i];
    }
    bitset<520720> tp(s[i]);
    // cout << tp << endl;
    a.push_back(tp);
  }
  // bitset<5> te("10111111");
  // cout << te << endl;

  bitset<520720> sum;
  for (int i = 0; i < a.size(); i++)
  {
    if (i == 0)
    {
      sum = a[i];
    }
    else
    {
      sum = (sum & a[i]);
    }
  }

  // cout << sum;
  // cout << endl;
  // cout << endl;
  int t = -1;
  // cout << sum << endl
  //      << endl;

  for (int i = 520720 - 1; i >= 0; i--)
  {
    if (sum[i] == 1)
    {
      t = 520720 - i;
      break;
    }
    // cout << sum[i];
  }

  cout << t;
}