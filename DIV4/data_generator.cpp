#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(0));
  int t = 10; // 生成10组测试数据
  cout << t << endl;
  while (t--)
  {
    int len = rand() % 10 + 1; // 随机字符串长度1-10
    string a, b;

    // 生成随机字符串a
    for (int i = 0; i < len; i++)
    {
      a += 'a' + rand() % 26;
    }

    // 生成字符串b，每个字符重复1-2次a对应位置的字符
    for (char c : a)
    {
      int repeat = rand() % 2 + 1; // 1或2次
      for (int i = 0; i < repeat; i++)
      {
        b += c;
      }
    }

    cout << a << ' ' << b << endl;
  }
  return 0;
}