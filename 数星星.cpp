#include <bits/stdc++.h>
using namespace std;
int a[5000000];
int tree[5000000];
int maxr = 500000;
int dj[20000];

int find(int p, int l, int r, int x, int y)
{
  if (l == x && y == r)
  {
    return tree[p];
  }

  int mid = (l + r) / 2;

  if (mid < x)
    return find(p * 2 + 1, mid + 1, r, x, y);
  if (mid >= y)
    return find(p * 2, l, mid, x, y);
  else
  {
    return find(p * 2 + 1, mid + 1, r, mid + 1, y) + find(p * 2, l, mid, x, mid);
  }
}
void add(int p, int l, int r, int x)
{
  if (l == r)
  {
    tree[p]++;
    return;
  }

  int mid = (l + r) / 2;
  if (x > mid)
    add(p * 2 + 1, mid + 1, r, x);
  else if (x <= mid)
    add(p * 2, l, mid, x);

  tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int x, y;
    cin >> x >> y;
    x++;
    int cnt;

    cnt = find(1, 1, maxr, 1, x);

    dj[cnt]++;

    add(1, 1, maxr, x);
  }

  for (int i = 0; i <= n - 1; i++)
  {
    cout << dj[i] << endl;
  }
}