#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  n--;
  for (int i = 1; i <= n / 2; i++)
  {
    cout << "a";
  }
  cout << "_";
  for (int i = n / 2 + 1; i <= n; i++)
  {
    cout << "b";
  }
}