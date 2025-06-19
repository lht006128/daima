#include <bits/stdc++.h>
using namespace std;
// int cnt[3000001];
// char ch[3000001][100];
int cnt[3000000];
int ch[3000000][80];
int idx = 0;
void insert(string s)
{
  int p = 0;
  for (int i = 0; i < s.size(); i++)
  {
    int j = s[i] - '0';
    if (!ch[p][j])
      ch[p][j] = ++idx;
    p = ch[p][j];
    cnt[p]++; // 放在这里就是求子串个数 放在外面就是求连续子串个数
  }
}

int query(string s)
{
  int p = 0;
  for (int i = 0; i < s.size(); i++)
  {
    int j = s[i] - '0';
    if (!ch[p][j])
      return 0;
    p = ch[p][j];
  }
  return cnt[p];
}

void slove()
{
  int n, q;
  cin >> n >> q;

  // cout << ch[0][0];

  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    insert(s);
  }
  for (int i = 1; i <= q; i++)
  {
    string s;
    cin >> s;
    cout << query(s) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  int t;
  cin >> t;

  while (t--)
  {
    for (int i = 0; i <= idx; i++)
    {
      cnt[i] = 0;
    }
    for (int i = 0; i <= idx; i++)
    {
      for (int j = 0; j <= 80; j++)
      {
        ch[i][j] = 0;
      }
    }
    idx = 0;
    slove();
  }
}