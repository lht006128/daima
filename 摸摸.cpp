#include <bits/stdc++.h>
using namespace std;
int a[3000];
int t[3000];
int b[3000];
int t2[3000];

void slove()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> t[i];
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> b[i];
  }

  for (int i = 1; i <= n; i++)
  {
    t2[i] = t[i] + t[n - i + 1];
  }

  int f = 0;
  int x = 0;

  // for (int i = 1; i <= n; i++)
  // {
  //   cout << b[i] << " ";
  // }

  while (1)
  {
    if (x * t[1] > b[1])
      break;

    if ((b[1] - x * t[1]) % t2[1] == 0)
    {
      int y = (b[1] - x * t[1]) / t2[1];

      int tf = 1;
      for (int i = 1; i <= n; i++)
      {
        if (x * t[i] + y * t2[i] != b[i])
        {
          tf = 0;
          break;
        }
      }
      if (tf)
      {
        f = 1;
      }
    }

    if (f)
    {
      break;
    }
    x++;
  }

  if (f)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
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