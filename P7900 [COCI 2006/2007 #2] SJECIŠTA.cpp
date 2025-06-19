#include <bits/stdc++.h>
using namespace std;
// 0 1 5 15

int C(int a, int b)
{ // 组合数简单计算公式
  int res = 1;
  for (int i = 1; i <= b; i++)
    res = res * (a - i + 1) / i;

  return res;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  cout << C(n, 4);
}