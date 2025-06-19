#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200000];
int tree[500000];
int cf[500000];
void build(int id, int l, int r)
{
  if (l == r)
  {
    // cout<<a[l];
    tree[id] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);

  tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int find(int id, int l, int r, int x, int y)
{
  if (x <= l && y >= r)
  {
    return tree[id];
  }

  // zuobian
  int mid = (l + r) / 2;
  if (y <= mid)
    return find(id * 2, l, mid, x, y);
  if (x > mid)
    return find(id * 2 + 1, mid + 1, r, x, y);
  return find(id * 2, l, mid, x, mid) + find(id * 2 + 1, mid + 1, r, mid + 1, y);
}

void add(int id, int l, int r, int x, int y, int num)
{
  if (l == r)
  {
    cf[id] += num;
    tree[id] += num;
    return;
  }
  int mid = (l + r) / 2;
  if (y <= mid)
  {
    add(id * 2, l, mid, x, y, num);
  }
  else if (x > mid)
  {
    add(id * 2 + 1, mid + 1, r, x, y, num);
  }
  else
  {
    add(id * 2, l, mid, x, mid, num);
    add(id * 2 + 1, mid + 1, r, mid + 1, y, num);
  }
  cf[id] += cf[id * 2] + cf[id * 2 + 1];
  tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  build(1, 1, n);

  while (m--)
  {
    int op;
    cin >> op;
    if (op == 2)
    {
      int x, y;
      cin >> x >> y;
      cout << find(1, 1, n, x, y) << endl;
    }
    else
    {
      int x, y, k;
      cin >> x >> y;
      add(1, 1, n, x, y, 1);
    }
  }
}