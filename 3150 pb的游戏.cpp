#include <bits/stdc++.h>
using namespace std;
int a[1000000];
map<int, int> mp;
void slove()
{
  int n;
  cin >> n;
  mp.clear();
  for (int i = 1; i <= n * 2; i++)
  {
    cin >> a[i];
    mp[a[i]]++;
  }
  int sum = n * 2;
  int cnt = 0;
  for (auto [x, y] : mp)
  {
    if (y >= 2)
    {
      sum -= y;
    }
    if (y >= 3)
    {
      cnt += (y - 2);
    }
  }

  if (cnt >= sum)
    cout << "Lose" << endl;
  else
    cout << "Win" << endl;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    /* code */
    slove();
  }
}