#include <bits/stdc++.h>
#define int long long
using namespace std;

bool issuhsu(int x)
{
  if (x < 2)
    return false;
  for (int i = 2; i <= sqrt(x); i++)
  {
    if (x % i == 0)
      return false;
  }
  return true;
}
int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, -1};
signed main()
{
  // cerr << "{";
  int ans = 1;

  for (int i = 0; arr[i] != -1; i++)
  {

    int mc = 1;
    for (int j = 1; j <= 100; j++)
    {
      int n = j;
      while (n % arr[i] == 0)
      {
        mc++;
        n /= arr[i];
      }
    }
    ans *= mc;
  }
  cout << ans;
}