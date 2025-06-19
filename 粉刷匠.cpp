#include <bits/stdc++.h>
#define int long long
using namespace std;
string s[60];

struct Node
{
  int c0;
  int c1;
  int fg;
  char zuida;
};

struct Node2
{
  char ty;
  int cnt;
  int use;
};

bool cmp(Node a, Node b)
{
  return max(a.c0, a.c1) > max(b.c0, b.c1);
}

bool cmp2(Node2 a, Node2 b)
{
  return a.cnt > b.cnt;
}

Node arr[2600];
vector<Node2> kuai[2600];

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, t;
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++)
  {
    char tp = '3';
    int cnt = 0;
    int cnt_c0 = 0;
    int cnt_c1 = 0;
    for (int j = 0; j < m; j++)
    {
      if (tp == '3')
      {
        tp = s[i][j];
      }
      else
      {
        if (tp != s[i][j])
        {
          cnt++;
          tp = s[i][j];
        }
      }

      if (s[i][j] == '0')
      {
        cnt_c0++;
      }
      else
      {
        cnt_c1++;
      }
    }

    arr[i].c0 = cnt_c0;
    arr[i].c1 = cnt_c1;
    arr[i].fg = cnt;
    arr[i].zuida = cnt_c0 > cnt_c1 ? '0' : '1';
  }

  for (int i = 1; i <= n; i++)
  {
    char tp = '3';
    int cnt = 0;
    for (int j = 0; j < m; j++)
    {
      if (tp == '3')
      {
        tp = s[i][j];
        cnt++;
      }
      else
      {
        if (tp != s[i][j])
        {
          if (tp != arr[i].zuida)
          {
            kuai[i].push_back({tp, cnt, 0});
          }
          tp = s[i][j];
          cnt = 1;
        }
        else
        {
          cnt++;
        }
      }
    }

    if (tp != arr[i].zuida)
    {
      kuai[i].push_back({tp, cnt});
    }

    stable_sort(kuai[i].begin(), kuai[i].end(), cmp2);
    // cout << kuai[i].size() << endl;
  }

  stable_sort(arr + 1, arr + 1 + n, cmp);
  int ans = 0;
  // 优先涂满所有行
  for (int i = 1; i <= n; i++)
  {
    if (t <= 0)
      break;
    t--;
    ans += max(arr[i].c0, arr[i].c1);
    if (t <= 0)
      break;
  }

  // 开始搞一段一段的 优先处理大的。
  while (t > 1)
  {
    // 每一次都暴力找可以产生最大贡献的行
    int idx;
    int idx2;
    int maxk = -1;
    for (int i = 1; i <= n; i++)
    {
      if (kuai[i].size() > 0)
      {
        for (int j = 0; j < kuai[i].size(); j++)
        {

          if (kuai[i][j].use != 1)
          {
            if (kuai[i][j].cnt > maxk)
            {
              maxk = kuai[i][j].cnt;
              idx = i;
              idx2 = j;
            }
            break;
          }
        }
      }
    }
    t -= 2;
    ans += kuai[idx][idx2].cnt;
    kuai[idx][idx2].use = 1;
  }

  cout << ans;
}