#include <bits/stdc++.h>
using namespace std;

void slove()
{
  int n, x;
  cin >> n >> x;
  // 先输出比他小的 在输出比他大的 最后在输出自己
  for (int i = 0; i < x; i++)
  {
    cout << i << " ";
  }

  for (int i = x + 1; i < n; i++)
  {
    cout << i << " ";
  }
  if (x == n)
    cout << endl;
  else
    cout << x << endl;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }

  return 0;
}