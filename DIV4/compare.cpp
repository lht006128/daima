#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t = 0;
  while (1)
  {
    cout << "test：" << ++t << endl;
    system(" sjsc.exe > data.in ");
    system(" nb.exe < data.in > jy.out ");
    system(" sb.exe < data.in > bjy.out ");
    if (system(" fc jy.out > bjy.out "))
    {
      cout << "WA" << endl;
      break;
    }
    cout << "AC" << endl;
  }
  return 0;
}
