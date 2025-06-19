#include <bits/stdc++.h>
#define int long long
using namespace std;

int d[200010];
int lasth[200010];
struct Node
{
  int l;
  int r;
};
Node arr[200010];

void slove()
{
  queue<int> pos; // 记录下标
  int add = 0;
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> d[i];
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i].l >> arr[i].r;
  }

  // 下面是飞行的模拟
  int cur = 0;

  for (int i = 1; i <= n; i++)
  {
    if (d[i] != -1)
    {
      cur += d[i];
      if (cur < arr[i].l)
      {
        if (arr[i].l - cur >= 1)
        {
          if (arr[i].l > (pos.size() + cur))
          {
            cout << -1 << endl;
            return;
          }
          else
          {
            while (cur < arr[i].l && !pos.empty())
            {

              if (lasth[pos.front()] + 1 + add <= arr[pos.front()].r)
              {
                cur++;
                d[pos.front()] = 1;
                add++;
              }
              else
              {
                d[pos.front()] = 0;
              }
              pos.pop();
            }
          }
        }
      }
    }
    else
    {

      if (cur < arr[i].l)
      {
        if (arr[i].l - cur >= 1)
        {
          if (arr[i].l > (1 + pos.size() + cur))
          {
            // cout << i << " " << pos.size() << " " << cur << endl;
            cout << -1 << endl;
            return;
          }
          else
          {
            while (cur < arr[i].l && !pos.empty())
            {

              if (lasth[pos.front()] + 1 + add <= arr[pos.front()].r)
              {
                cur++;
                add++;
                d[pos.front()] = 1;
              }
              else
              {
                d[pos.front()] = 0;
              }
              pos.pop();
            }
            if (cur < arr[i].l)
            {
              cur++;
              d[i] = 1;
            }
            else
            {
              pos.push(i);
            }
          }
        }
      }
      else
      {
        if (cur + 1 <= arr[i].r)
        {
          pos.push(i);
        }
      }
    }

    if (cur > arr[i].r || cur < arr[i].l)
    {
      cout << -1 << endl;
      return;
    }
    lasth[i] = cur; // 记录当前时间段H的情况；
  }

  for (int i = 1; i <= n; i++)
  {

    cout << (d[i] == -1 ? 0 : d[i]) << " ";
  }
  cout << endl;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }
}