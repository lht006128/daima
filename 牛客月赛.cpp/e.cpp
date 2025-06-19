#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main()
{
  int n;
  int idx = 1;
  int now = 0;

  cin >> n;
  cout << 1 << endl;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++)
  {
    int cnt = a[i];
    int next = a[i + 1];
    int nextid = now + cnt;
    for (int j = 1; j <= cnt; j++)
    {
      if (next > 0)
      {
        cout << ++nextid << " ";
        next--;
      }
      else
      {
        cout << -1 << " ";
      }
      if (next > 0)
      {
        cout << ++nextid << endl;
        next--;
      }
      else
      {
        cout << -1 << endl;
      }
    }
    now = now + cnt;
  }
}