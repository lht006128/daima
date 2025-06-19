#include <bits/stdc++.h>
using namespace std;

void slove()
{
  int sum = 0;
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int tp;
    cin >> tp;
    sum ^= tp;
  }
  if (sum)
  {
    cout << "Yes" << endl;
  }
  else
    cout << "No" << endl;
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
}