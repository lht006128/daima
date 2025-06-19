#include <iostream>
using namespace std;
char s[2000007];
char tmp[2000007];
void f()
{
  int n, idx = 0;
  cin >> n;
  cin >> s;
  char ch = s[0];
  for (int i = n - 1; i >= 0; i--)
  {
    if (s[i] == ch)
    {
      idx = i;
      break;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] != ch || i == idx)
    {
      tmp[cnt++] = s[i];
    }
  }
  if (tmp[0] == ch)
  {
    if (cnt >= 4)
      cout << "4" << endl;
    else
      cout << cnt << endl;
  }
  else
    cout << "2\n";
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    f();
  }
  return 0;
}