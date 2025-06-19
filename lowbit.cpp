#include <bits/stdc++.h>
#define int long long
using namespace std;

int lowbit(int x)
{
  return x & (-x);
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  cout << lowbit(n);
}