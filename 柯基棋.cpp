#include <bits/stdc++.h>
using namespace std;
unsigned long long x[10000005];
unsigned long long xor_shift(unsigned long long &seed)
{
  return seed ^= seed >> 12, seed ^= seed << 25, seed ^= seed >> 27, seed * 0x2545F4914F6CDD1D;
}

void slove()
{
  // your code here
  int n, q;
  unsigned long long seed;
  cin >> n >> q >> seed;
  for (int i = 1; i <= q; i++)
  {
    x[i] = x[i - 1] + ((xor_shift(seed) % (unsigned long long)(2 * 2) + 1)) * 2;
  }
  // your code here

  if (n % 2 == 1)
  {
    cout << "A won" << endl;
  }
  else
    cout << "B won" << endl;
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
