#include <bits/stdc++.h>
using namespace std;

// int c[2000000];

int n;
struct Node
{
  int color;
  int num;
  bool operator<(const Node &other) const
  {
    return num > other.num;
  }
};

Node a[2000000];

bool pd(int mid)
{
  Node c[n + 1];

  priority_queue<Node> dui0;
  priority_queue<Node> dui1;
  priority_queue<Node> tp_dui;

  int c0 = 0, c1 = 0;

  for (int i = 1; i <= n; i++)
  {
    c[i] = a[i];
  }

  for (int i = 1; i <= n; i++)
  {
    if (c[i].color == 1)
    {
      if (!dui0.empty())
      {
        int f = 0;
        while (!dui0.empty())
        {
          Node tp = dui0.top();
          dui0.pop();
          if (tp.num + c[i].num >= mid)
          {
            f = 1;
            break;
          }
          else
          {
            tp_dui.push(tp);
          }
        }

        if (!f)
          return false;

        while (!tp_dui.empty())
        {
          dui0.push(tp_dui.top());
          tp_dui.pop();
        }
      }
      else
      {
        dui1.push(c[i]);
      }
    }
    else
    {
      if (!dui1.empty())
      {
        int f = 0;
        while (!dui1.empty())
        {
          Node tp = dui1.top();
          dui1.pop();
          if (tp.num + c[i].num >= mid)
          {
            f = 1;
            break;
          }
          else
          {
            tp_dui.push(tp);
          }
        }
        if (!f)
          return false;

        while (!tp_dui.empty())
        {
          dui1.push(tp_dui.top());
          tp_dui.pop();
        }
      }
      else
      {
        dui0.push(c[i]);
      }
    }
  }
  return true;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i].num;
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i].color;
  }

  int l = 1, r = 1e10;

  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (pd(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << l - 1;
}