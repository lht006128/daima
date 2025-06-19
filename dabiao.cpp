#include <bits/stdc++.h>
using namespace std;
struct node
{
  vector<int> ve;
  int cnt;
  int id;
} brr[1000007];
unordered_map<int, int> mp;
set<vector<int>> st;
int n, t, len, c, cnt, tt, be;
string s;
int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cin.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= n; i++)
  {
    cin >> t;
    mp[t]++;
  }
  len = s.size();
  for (int i = 0; i < len; i++)
  {
    if (s[i] == '(')
      c++;
    else
    {
      brr[cnt].cnt = c;
      brr[cnt].id = cnt++;
      c = 0;
    }
  };
  auto it = mp.begin();
  stable_sort(brr, brr + cnt, [](node a, node b)
              { return a.cnt < b.cnt; });
  while (n > 0)
  {
    for (int i = be; i < cnt; i++)
    {
      if (brr[i].cnt)
      {
        while (it->second == 0)
        {
          it++;
          if (it == mp.end())
            it = mp.begin();
        }
        brr[i].ve.push_back(it->first);
        if (st.find(brr[i].ve) == st.end())
        {
          st.insert(brr[i].ve);
        }
        else
        {
          cout << "NO\n";
          return 0;
        }
        brr[i].cnt--;
        if (brr[i].cnt == 0)
          be++;
        n--;
        tt = it->first;
        it++;
        mp[tt]--;
        if (it == mp.end())
          it = mp.begin();
      }
    }
  }
  stable_sort(brr, brr + cnt, [](node a, node b)
              { return a.id < b.id; });
  cout << "YES\n";
  for (int i = 0; i < cnt; i++)
  {
    for (int f : brr[i].ve)
    {
      cout << f << " ";
    }
  }
  return 0;
}