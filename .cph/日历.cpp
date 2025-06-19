#include <bits/stdc++.h>
using namespace std;
#define int long long
map<string, int> mp;
int days = 0, year = 0;
int arr2[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int arr1[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string month;
string s;
void init()
{
  mp["JAN"] = 1; // 1
  mp["FEB"] = 2; // 2
  mp["MAR"] = 3; // 3
  mp["APR"] = 4; // 4
  mp["MAY"] = 5; // 5
  mp["JUN"] = 6; // 6
  mp["JUL"] = 7; // 7
  mp["AUG"] = 8; // 8
  mp["SEP"] = 9;
  mp["OCT"] = 10;
  mp["NOV"] = 11;
  mp["DEC"] = 12;

  int pos = 0;
  for (int i = pos; i < s.size(); i++)
  {
    if (s[i] >= '0' && s[i] <= '9')
    {
      days = days * 10 + s[i] - '0';
    }
    else
    {
      pos = i;
      break;
    }
  }

  for (int i = pos; i < s.size(); i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
    {
      month += s[i];
    }
    else
    {
      pos = i;
      break;
    }
  }
  for (int i = pos; i < s.size(); i++)
  {
    if (s[i] >= '0' && s[i] <= '9')
    {
      year = year * 10 + s[i] - '0';
    }
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> s;
  init();

  int sum1 = 0; // 这一年的天数。

  if (year <= 1582)
  {

    if (year % 4 == 0)
    {
      // 这一年是闰年
      for (int i = 1; i < mp[month]; i++)
      {
        sum1 += arr1[i];
      }
      sum1 += days;
    }
    else
    {
      // 这一年不是闰年
      for (int i = 1; i < mp[month]; i++)
      {
        sum1 += arr2[i];
      }
      sum1 += days;
    }
    if (year == 1582 && mp[month] >= 10)
    {
      if (mp[month] == 10)
      {
        if (days >= 15)
        {
          sum1 -= 10;
        }
      }
      else
      {
        sum1 -= 10;
      }
    }
  }
  else
  {
    sum1 -= 10; // 减掉误差
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
      // 这一年是闰年
      for (int i = 1; i < mp[month]; i++)
      {
        sum1 += arr1[i];
      }
      sum1 += days;
    }
    else
    {
      // 这一年不是闰年
      for (int i = 1; i < mp[month]; i++)
      {
        sum1 += arr2[i];
      }
      sum1 += days;
    }
  }

  // 计算与 第一年 相差了多少 假设全部都不是闰年
  int sumy = 0;

  for (int i = 1; i <= 12; i++)
  {
    sumy += arr2[i];
  }

  int sumdays = 0;

  sumdays = sumy * (year - 1);

  int qian = 0;
  int hou = 0;
  if (year > 1582)
  {
    qian = 1582 / 4;

    for (int i = 1583; i < year; i++)
    {
      if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
      {
        hou++;
      }
    }
  }
  else
  {
    qian = (year - 1) / 4;
    hou = 0;
  }

  int ans;
  ans = sum1 + sumdays + qian + hou - 1;

  cout << ans;
}