#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, less<int>> pr_0;
priority_queue<int, vector<int>, greater<int>> pr_1;
int arr[200007];
int fu[200007];
int ans = 0x7fffffff;
int main()
{
  int n;
  cin >> n;
  int flag;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++)
  {
    cin >> fu[i];
  }
  for (int i = 1; i <= n; i++)
  {
    if (i == 1)
    {
      flag = fu[i];
      if (fu[i] == 0)
      {
        pr_0.push(arr[i]);
      }
      else
      {
        pr_1.push(arr[i]);
      }
    }
    else
    {
      if (fu[i] == flag)
      {
        if (fu[i] == 0)
        {
          pr_0.push(arr[i]);
        }
        else
        {
          pr_1.push(arr[i]);
        }
      }
      else
      {
        flag = fu[i];
        int len = 0;
        if (flag == 1)
        {
          len = pr_0.size();
          int tt = 0;
          for (int j = i; j < i + len && flag == fu[j]; j++)
          {
            tt++;
            pr_1.push(arr[j]);
          }
          while (pr_0.size() && pr_1.size())
          {
            ans = min(pr_0.top() + pr_1.top(), ans);
            pr_0.pop();
            pr_1.pop();
          }

          i += tt - 1;
        }
        else
        {
          len = pr_1.size();
          int tt = 0;
          for (int j = i; j < i + len && flag == fu[j]; j++)
          {
            tt++;
            pr_0.push(arr[j]);
          }
          while (pr_0.size() && pr_1.size())
          {
            ans = min(pr_0.top() + pr_1.top(), ans);
            pr_0.pop();
            pr_1.pop();
          }

          i += tt - 1;
        }
      }
    }
  }
  cout << ans;
  return 0;
}