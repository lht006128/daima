#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200000];
// int tree[500000];
int lazycf[500000];
int tree_add[510000];
int lazy[510000];
int m;
void build(int id, int l, int r)
{
  if (l == r)
  {
    // cout<<a[l];
    tree_add[id] = a[l] % m;
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);

  tree_add[id] = (tree_add[id * 2] % m + tree_add[id * 2 + 1] % m) % m;
}
void pushdown(int id, int l, int r)
{
  int mid = (l + r) / 2;
  // 更新左节点的加法和乘法
  lazy[2 * id] = (lazy[2 * id] * lazycf[id]) % m; // 不要忘记 他原来的要先乘上去，因为我们只是队加法乘了我要乘的
  lazy[2 * id] = (lazy[2 * id] + lazy[id]) % m;
  lazycf[2 * id] = (lazycf[2 * id] * lazycf[id]) % m;

  // 更新右节点的加法和乘法
  lazy[2 * id + 1] = (lazy[2 * id + 1] * lazycf[id]) % m;
  lazy[id * 2 + 1] = (lazy[id * 2 + 1] + lazy[id]) % m;
  lazycf[2 * id + 1] = (lazycf[2 * id + 1] * lazycf[id] % m) % m;

  // 更新左侧节点的值为多少。
  tree_add[id * 2] = (tree_add[id * 2] * lazycf[id]) % m;
  tree_add[id * 2] = (tree_add[id * 2] + lazy[id] * (mid - l + 1)) % m;

  // 更新右侧节点的值为多少
  tree_add[id * 2 + 1] = (tree_add[id * 2 + 1] * lazycf[id]) % m;
  tree_add[id * 2 + 1] = (tree_add[id * 2 + 1] + lazy[id] * (r - (mid + 1) + 1)) % m;

  lazy[id] = 0;
  lazycf[id] = 1;
}
// void pushdown(int id, int l, int r)
// {
//   int mid = (l + r) / 2;
//   int left = id * 2, right = id * 2 + 1;

//   // 先处理乘法标记
//   tree_add[left] = (tree_add[left] * lazycf[id]) % m;
//   tree_add[right] = (tree_add[right] * lazycf[id]) % m;
//   lazy[left] = (lazy[left] * lazycf[id]) % m;
//   lazy[right] = (lazy[right] * lazycf[id]) % m;
//   lazycf[left] = (lazycf[left] * lazycf[id]) % m;
//   lazycf[right] = (lazycf[right] * lazycf[id]) % m;

//   // 再处理加法标记
//   tree_add[left] = (tree_add[left] + lazy[id] * (mid - l + 1)) % m;
//   tree_add[right] = (tree_add[right] + lazy[id] * (r - mid)) % m;
//   lazy[left] = (lazy[left] + lazy[id]) % m;
//   lazy[right] = (lazy[right] + lazy[id]) % m;

//   lazy[id] = 0;
//   lazycf[id] = 1;
// }
int find(int id, int l, int r, int x, int y)
{
  if (x <= l && y >= r)
  {
    return tree_add[id] % m;
  }
  int re = 0;
  // zuobian
  int mid = (l + r) / 2;
  if (lazy[id] != 0 || lazycf[id] != 1)
    pushdown(id, l, r);
  if (y <= mid)
    return find(id * 2, l, mid, x, y) % m;
  if (x > mid)
    return find(id * 2 + 1, mid + 1, r, x, y) % m;
  return (find(id * 2, l, mid, x, mid) + find(id * 2 + 1, mid + 1, r, mid + 1, y)) % m;
}

void add(int id, int l, int r, int x, int y, int num)
{
  if (x <= l && y >= r)
  {
    tree_add[id] = (tree_add[id] + num * (r - l + 1)) % m; // 节点值加上区间加法值后取模
    lazy[id] = (lazy[id] + num) % m;                       // 加法标记加上当前加法值后取模
    return;
  }
  if (lazy[id] != 0 || lazycf[id] != 1)
  {
    pushdown(id, l, r);
  }

  int mid = (l + r) / 2;
  if (y <= mid)
    add(id * 2, l, mid, x, y, num);
  else if (x > mid)
    add(id * 2 + 1, mid + 1, r, x, y, num);
  else
  {
    add(id * 2, l, mid, x, mid, num);
    add(id * 2 + 1, mid + 1, r, mid + 1, y, num);
  }
  tree_add[id] = (tree_add[id * 2] + tree_add[id * 2 + 1]) % m;
}

void mutipl(int id, int l, int r, int x, int y, int num)
{
  if (x <= l && y >= r)
  {
    tree_add[id] = (tree_add[id] * num) % m;
    lazy[id] = (num * lazy[id]) % m;

    lazycf[id] = (lazycf[id] * num) % m;

    return;
  }

  if (lazy[id] != 0 || lazycf[id] != 1)
  {
    pushdown(id, l, r);
  }

  int mid = (l + r) / 2;
  if (y <= mid)
    mutipl(id * 2, l, mid, x, y, num);
  else if (x > mid)
    mutipl(id * 2 + 1, mid + 1, r, x, y, num);
  else
  {
    mutipl(id * 2, l, mid, x, mid, num);
    mutipl(id * 2 + 1, mid + 1, r, mid + 1, y, num);
  }
  tree_add[id] = (tree_add[id * 2] + tree_add[id * 2 + 1]) % m;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, q;
  cin >> n >> q >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i <= 500000; i++)
  {
    lazycf[i] = 1;
  }

  build(1, 1, n);

  while (q--)
  {
    int op;
    cin >> op;
    if (op == 3)
    {
      int x, y;
      cin >> x >> y;
      cout << find(1, 1, n, x, y) % m << endl;
    }
    else if (op == 2)
    {
      int x, y, k;
      cin >> x >> y >> k;
      add(1, 1, n, x, y, k);
    }
    else if (op == 1)
    {
      // 乘法操作 。
      int x, y, k;
      cin >> x >> y >> k;
      mutipl(1, 1, n, x, y, k);
    }
  }
}