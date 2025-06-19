#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int x;
  int cnt;
};

int idx = 0;
int sushu[1000001];

bool issushu(int x)
{
  if (x < 2)
    return false;
  for (int i = 2; i <= sqrt(x); i += 2)
  {
    if (x % i == 0)
      return false;
    if (i == 2)
      i--;
  }

  return true;
}

void init()
{
  for (int i = 1; i <= 1000000; i++)
  {
    if (issushu(i))
    {
      sushu[++idx] = i;
    }
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  init();
  while (1)
  {
    cout << "Enter the number=" << endl;

    getline(cin, s);

    int num = 0;
    int f = 1;
    int f2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] >= '0' && s[i] <= '9')
      {
        num = num * 10 + s[i] - '0';
        f2 = 1;
      }

      if (num > 40000000)
      {
        f = 0;
        break;
      }
    }

    if (!f2)
      break;

    cout << "Prime? ";
    if (f != 1)
    {
      cout << "No!" << endl;
      cout << "The number is too large!" << endl;
    }
    else
    {
      if (issushu(num))
      {
        cout << "Yes!" << endl;
      }
      else
      {
        if (num < 2)
        {
          cout << "No!" << endl
               << endl;
          continue;
        }
        else
        {
          cout << "No!" << endl;
          cout << num << "=";

          vector<Node> ans;

          while (num)
          {
            for (int i = 1; i <= num; i++)
            {
              int t = 1;
              if (!issushu(i))
                continue;
              if (num % i == 0)
              {
                // cout << sushu[i] << endl;

                num /= i;
                while (1)
                {
                  if (num % i == 0)
                  {
                    num /= i;
                    t++;
                  }
                  else
                  {
                    break;
                  }
                }

                ans.push_back({i, t});
              }

              if (num <= 1)
                break;
            }
            if (num <= 1)
              break;
          }

          for (int i = 0; i < ans.size(); i++)
          {
            cout << ans[i].x << "^" << ans[i].cnt;
            if (i != ans.size() - 1)
            {
              cout << "*";
            }
          }
          cout << endl;
        }
      }
    }
    cout << endl;
  }
}