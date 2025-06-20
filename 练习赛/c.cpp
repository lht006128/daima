#include <bits/stdc++.h>
#define unsigned int long long
using namespace std;

int pre[300010][30];
int premi[3000010][30];
int premax[3000010][30];

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  int x;
  cin >> s >> x;

  for (int i = 0; i < s.size(); i++)
  {
    if (i != 0)
    {
      for (int j = 0; j <= 'z' - 'a'; j++)
      {
        pre[i][j] = pre[i - 1][j];
      }
    }
    pre[i][s[i] - 'a']++;
  }
  for (int j = 0; j <= 'z' - 'a'; j++)
  {
    pre[s.size()][j] = pre[s.size() - 1][j];
  }

  for (int i = 0; i <= s.size(); i++)
  {
    for (int j = 0; j <= 'z' - 'a'; j++)
    {

      for (int k = 0; k <= j - 1; k++)
      {
        premi[i][j] += pre[i][k];
      }
      for (int k = j + 1; k <= 'z' - 'a'; k++)
      {
        premax[i][j] += pre[i][k];
      }
    }
    // cout << premi[i][0] << endl;
  }

  int num = 0;
  int ans = 1e18 + 2;
  int l = 0;
  deque<int> qe;
  qe.push_back(0);

  for (int i = 1; i < s.size(); i++)
  {
    // if (qe.size() == 0)
    // {
    //   qe.push_back(i);
    //   continue;
    // }

    qe.push_back(i);
    if (l == 0)
    {
      num += premax[i][s[i] - 'a'];
    }
    else
    {
      num += premax[i][s[i] - 'a'] - premax[l][s[i] - 'a'];
    }

    ans = min(ans, abs(num - x));
    // cout << premax[i]['b' - 'a'] << endl;

    while (num > x)
    {
      int f = qe.front();
      qe.pop_front();
      num -= (premi[i + 1][s[f] - 'a'] - premi[f][s[f] - 'a']);
      l = f;
    }
  }
  // cout << 666;
  if (s.size() == 1)
  {
    cout << x;
  }
  else
  {
    cout << ans;
  }
}