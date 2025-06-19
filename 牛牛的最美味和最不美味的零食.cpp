#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[4000100];

struct Node
{
  int num;
  int maxn;
  int minn;
};

Node tree[4000100];
void build(int p, int l, int r)
{
  if (l == r)
  {
    tree[p].num = 1;
    tree[p].maxn = a[l];
    tree[p].minn = a[l];
    return;
  }

  int mid = (l + r) / 2;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  tree[p].maxn = max(tree[p * 2].maxn, tree[p * 2 + 1].maxn);
  tree[p].minn = min(tree[p * 2].minn, tree[p * 2 + 1].minn);
  tree[p].num = tree[p * 2].num + tree[p * 2 + 1].num;
}

void del(int p, int l, int r, int k)
{
  if (l == r)
  {
    tree[p].num = 0;
    tree[p].maxn = -1e9 - 10;
    tree[p].minn = 1e9 + 10;

    return;
  }
  int mid = (l + r) / 2;

  if (tree[p * 2].num >= k)
    del(p * 2, l, mid, k);
  else
    del(p * 2 + 1, mid + 1, r, k - tree[p * 2].num);
  tree[p].num = tree[p * 2].num + tree[p * 2 + 1].num;
  tree[p].maxn = max(tree[p * 2].maxn, tree[p * 2 + 1].maxn);
  tree[p].minn = min(tree[p * 2].minn, tree[p * 2 + 1].minn);
}

Node find(int p, int l, int r, int x, int y)
{
  // 第一步不知道如何判断可以先写下面的；
  if (tree[p].num == (y - x) + 1)
  {
    return tree[p];
  }
  int mid = (l + r) / 2;
  if (tree[p * 2].num >= y)
    return find(p * 2, l, mid, x, y);
  else if (tree[p * 2].num < x)
    return find(p * 2 + 1, mid + 1, r, x - tree[p * 2].num, y - tree[p * 2].num);
  else
  {
    Node t1, t2;
    t1 = find(p * 2, l, mid, x, tree[p * 2].num);
    t2 = find(p * 2 + 1, mid + 1, r, 1, y - tree[p * 2].num);
    t1.maxn = max(t1.maxn, t2.maxn);
    t1.minn = min(t1.minn, t2.minn);
    return t1;
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  build(1, 1, n);

  while (m--)
  {
    int q;
    cin >> q;
    if (q == 1)
    {
      int k;
      cin >> k;
      del(1, 1, n, k);
    }
    else
    {
      int i, j;
      cin >> i >> j;
      Node tp = find(1, 1, n, i, j);
      cout << tp.minn << " " << tp.maxn << endl;
    }
  }
}