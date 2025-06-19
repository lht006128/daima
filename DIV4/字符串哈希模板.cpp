#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 1000020001;  // 独家定制模数
int mod2 = 1000099999; // 独家定制模数2
int p = 131;           // 独家定制底数

struct Node
{
  int mod1;
  int mod2;

  bool operator<(const Node &other) const
  {
    return mod1 < other.mod1;
  }
};

map<Node, int> mp1;
vector<Node> arr;
int makehash2(string &s);
void makehash(string &s)
{
  int tpsum = 0;
  int x = 1;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    tpsum = (tpsum + s[i] * x % mod) % mod;
    x = (x * p) % mod;
  }
  // cout << tpsum << endl;
  int h2 = makehash2(s);
  arr.push_back({tpsum, h2});
}

int makehash2(string &s)
{
  int tpsum = 0;
  int x = 1;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    tpsum = (tpsum + s[i] * x % mod2) % mod2;
    x = (x * p) % mod2;
  }
  // cout << tpsum << endl;
  return tpsum % mod2;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    makehash(s);
  }
  int cnt = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (mp1[arr[i]] == 0)
    {
      mp1[arr[i]]++;
      cnt++;
    }
  }
  cout << cnt;
}