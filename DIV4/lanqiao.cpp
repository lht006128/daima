#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans = 0;
string s = "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
vector<int> number;
vector<int> fuhao;

void dfs(int x, int len, int hnum, int hfuhao)
{
  // cout << x << endl;

  if (s[x] >= '0' && s[x] <= '9')
  {
    hnum = 1;
  }
  if (!(s[x] >= '0' && s[x] <= '9') && !(s[x] >= 'a' && s[x] <= 'z'))
  {
    hfuhao = 1;
  }

  if (len >= 8 && hnum == 1 && hfuhao == 1)
  {
    ans++;
  }
  if (len == 15 && hnum == 0 && hfuhao == 0)
  {
    return;
  }
  if (len >= 16)
  {
    return;
  }

  if (hfuhao == 0)
  {
    int idx = *upper_bound(fuhao.begin(), fuhao.end(), x);
    if (idx < s.size())
      dfs(idx, len + (idx - x), hnum, 1);
  }

  if (hnum == 0)
  {
    int idx = *upper_bound(number.begin(), number.end(), x);
    if (idx < s.size())
      dfs(idx, len + (idx - x), 1, hfuhao);
  }

  if (hnum == 1 && hfuhao == 1)
  {
    for (int i = x + 1; i < s.size(); i++)
    {
      dfs(i, len + 1, hnum, hfuhao);
    }
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] >= '0' && s[i] <= '9')
    {
      number.push_back(i);
    }
    if (!(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'a' && s[i] <= 'z'))
    {
      fuhao.push_back(i);
    }
  }

  for (int i = 0; i < s.size(); i++)
  {
    dfs(i, 1, 0, 0);
  }
  cout << ans;

  return 0;
}