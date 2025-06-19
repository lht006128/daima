#include <bits/stdc++.h>
using namespace std;

int n, a;
int x, c = 1;
int arr[5007];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n, [](int a, int b)
       { return a > b; });
  x = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (x == arr[i])
    {
      c++;
    }
    else
      break;
  }
  if (c & 1)
    cout << "Alice";
  else
    cout << "Bob";
  return 0;
}