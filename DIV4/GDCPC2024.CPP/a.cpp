#include <iostream>
using namespace std;

string s = "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
int ans = 0;

int main()
{

  for (int i = 0; i <= s.size() - 9; i++)
  {

    for (int j = 8; i + j <= s.size() && j <= 16; j++)
    {
      string ts;

      ts = s.substr(i, j);
      int havenum = 0;
      int haveother = 0;
      for (int o = 0; o < ts.size(); o++)
      {
        if (ts[o] >= '0' && ts[o] <= '9')
        {
          havenum++;
        }
        if (!(ts[o] >= 'a' && ts[o] <= 'z') && !(ts[o] >= '0' && ts[o] <= '9'))
        {
          haveother++;
        }
        if (havenum && haveother)
          break;
      }
      if (havenum && haveother)
        ans++;
    }
  }
  cout << ans;
  return 0;
}