#include <bits/stdc++.h>
#define int long long
using namespace std;

char c[6] = {'0', 'a', 'e', 'i', 'o', 'u'};
void slove()
{
  int n;
  cin >> n;

  int cnt = n / 5;
  int last = n % 5;

  for (int i = 1; i <= 5; i++)
  {
    int tcnt = cnt;
    if (i >= 5 - last + 1)
    {
      tcnt++;
    }

    for (int j = 1; j <= tcnt; j++)
    {
      cout << c[i];
    }
  }
  cout << endl;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }
}