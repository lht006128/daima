#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[300000];
int h[300000];

map<int, int> mp;
map<int, int> mp2;
struct Node
{
  int tis;
  int isu;
  bool operator<(const Node &b) const
  {
    return tis > b.tis;
  }
};

void slove()
{
  int n;
  int ans = 1;
  int times = 0;
  int maxt = -1;
  int f = 1;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    mp[a[i]]++;
    maxt = max(maxt, a[i]);
    if (mp[a[i]] >= 3)
      f = 0;
  }

  if (!f)
  {
    cout << "NO" << endl;
    return;
  }

  sort(a + 1, a + 1 + n);
  deque<Node> qe;
  priority_queue<Node> qe2; // 已经被操作了的
  for (int i = 1; i <= n; i++)
  {
    qe.push_back({a[i], 0});
  }

  for (int i = 1; i <= maxt + 10; i++)
  {
    // i 代表时间
    if (qe2.empty() && !qe.empty())
    {
      Node tp;
      tp = qe.front();
      qe.pop_front();

      if (tp.tis < i)
      {

        cout << "NO" << endl;
        return;
      }
      else if (tp.tis == i)
      {
        qe2.push({tp.tis + 1, 1});
        mp2[tp.tis + 1]++;
      }
      else if (tp.tis == i + 1)
      {
        qe2.push({tp.tis + 1, 1});
        mp2[tp.tis + 1]++;
      }
      else
      {
        if (mp2[tp.tis - 1] != 0)
        {
          qe2.push({tp.tis + 1, 1});
          mp2[tp.tis + 1]++;
        }
        else
        {
          qe2.push({tp.tis - 1, 1});
          mp2[tp.tis - 1]++;
        }
      }
    }
    else
    {
      Node tp;
      tp = qe2.top();
      // cout << tp.tis << " " << mp2[42] << endl;
      if (tp.tis == i)
      {
        qe2.pop();
        mp2[tp.tis]--;
      }
      else if (tp.tis < i)
      {
        // cout << tp.tis << endl;
        cout << "NO" << endl;
        return;
      }
      else
      {
        if (qe.empty())
          break;

        tp = qe.front();
        qe.pop_front();
        // mp2[tp.tis]--;
        if (tp.tis < i)
        {
          cout << "NO" << endl;
          return;
        }
        else if (tp.tis == i)
        {
          qe2.push({tp.tis + 1, 1});
          mp2[tp.tis + 1]++;
        }
        else if (tp.tis == i + 1)
        {
          qe2.push({tp.tis + 1, 1});
          mp2[tp.tis + 1]++;
        }
        else
        {
          if (mp2[tp.tis - 1] != 0)
          {
            qe2.push({tp.tis + 1, 1});
            mp2[tp.tis + 1]++;
          }
          else
          {
            qe2.push({tp.tis - 1, 1});
            mp2[tp.tis - 1]++;
          }
        }
      }
    }
    if (qe2.empty() && qe.empty())
      break;
  }

  cout << "YES" << endl;
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
  return 0;
}