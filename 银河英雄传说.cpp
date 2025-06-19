#include <bits/stdc++.h>
#define int long long
using namespace std;
int fa[30010];
int d[30010]; // 记录上面的箱子的个数
int s[30010]; // 记录 下面的箱子的个数

void init()
{
  for (int i = 1; i <= 30000; i++)
  {
    fa[i] = i;
    s[i] = 0;
  }
}

int find(int x)
{
  if (fa[x] == x)
    return x;
  else
  {
    int tp = fa[x];
    fa[x] = find(fa[x]);
    d[x] += d[tp];
    return fa[x];
  }
}

void join(int a, int b)
{
  // cout << a << " " << b << endl;
  int ga, gb;
  ga = find(a);
  gb = find(b);
  fa[ga] = gb;
  d[ga] = s[gb] + 1;
  // cout << endl;

  s[gb] = s[gb] + s[ga] + 1;
  // cntfa[ga];
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(), cout.tie(0);

  init();

  int t;
  cin >> t;

  while (t--)
  {
    char c;
    int i, j;

    cin >> c >> i >> j;
    if (c == 'M')
    {
      join(i, j);
    }
    else
    {
      int gi, gj;
      int deepi = 0, deepj = 0;

      gj = find(j);
      gi = find(i);

      if (gi != gj)
      {
        cout << -1 << endl;
      }
      else
      {
        // cout<<deepi<<" "<<deepj<<endl;
        // cout << d[5] << endl;
        cout << abs(d[i] - d[j]) - 1 << endl;
      }
    }
  }
  // cout << "123";
}