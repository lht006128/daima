#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int ans = 0;
  string s;
  cin >> s;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (i == s.size() - 1)
    {
      ans += s[i] - '0';
    }
    else
    {
      ans += (10 + s[i] - s[i + 1]) % 10;
    }
  }

  cout << ans + s.size();
  return 0;
}