#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[100010];
int ans[100010];
int n, m;

struct Node
{
  int t;
  int is;
};

bool pd(int mid)
{
  deque<Node> qe;
  map<int, int> mp;
  int cnt = 0;
  qe.push_back({arr[1], 0});
  for (int i = 2; i <= n; i++)
  {

    if (arr[i] != qe.back().t)
    {
      qe.push_back({arr[i], 0});
    }
    else
    {
      if (cnt < mid)
      {
        qe.push_back({1 - arr[i], 1});
        cnt++;
      }
      else
      {
        while (cnt >= mid)
        {
          Node f = qe.front();
          if (f.is != 0)
          {
            cnt--;
          }
          qe.pop_front();
        }
        qe.push_back({1 - arr[i], 1});
        cnt++;
      }
    }

    if (qe.size() >= m)
      return true;
  }

  return false;
}

bool pd2(int mid)
{
  deque<Node> qe;
  map<int, int> mp;
  int cnt = 1;
  qe.push_back({1 - arr[1], 1});
  for (int i = 2; i <= n; i++)
  {

    if (arr[i] != qe.back().t)
    {
      qe.push_back({arr[i], 0});
    }
    else
    {
      if (cnt < mid)
      {
        qe.push_back({1 - arr[i], 1});
        cnt++;
      }
      else
      {
        while (cnt >= mid)
        {
          Node f = qe.front();
          if (f.is != 0)
          {
            cnt--;
          }
          qe.pop_front();
        }
        qe.push_back({1 - arr[i], 1});
        cnt++;
      }
    }

    if (qe.size() >= m)
      return true;
  }

  return false;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    int tp;
    cin >> tp;
    if (tp % 2 == 0)
    {
      arr[i] = 0;
    }
    else
    {
      arr[i] = 1;
    }
  }

  int l = 0;
  int r = n + 1;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (pd(mid) || pd2(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << r + 1;
}