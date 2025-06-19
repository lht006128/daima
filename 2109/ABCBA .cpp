#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

set<int> st;
int arr[1000010];
struct Node
{
  int num;
  int cnt;
};

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  map<int, int> mp;

  for (int i = 1; i <= n; i++)
  {
    mp[arr[i]]++;
  }

  vector<Node> brr;
  int lastmaxcntx = 0;
  int maxx = -1;
  int maxcnt = -1;
  for (auto [x, cnt] : mp)
  {
    brr.push_back({x, cnt});
    maxcnt = max(maxcnt, cnt);
  }

  for (int i = 0; i < brr.size(); i++)
  {
    if (brr[i].cnt == maxcnt)
    {
      maxx = max(maxx, brr[i].num);
    }
  }
  st.insert(maxx);
  int lastx = -1;
  for (int i = 0; i < brr.size(); i++)
  {
    if (brr[i].cnt == maxcnt && brr[i].num < maxx)
    {
      lastx = max(lastx, brr[i].num);
    }
  }
  // 找次大的数字；
  int maxrx = -1;
  for (int i = 0; i < brr.size(); i++)
  {
    if (brr[i].cnt == maxcnt - 1)
    {
      maxrx = max(maxrx, brr[i].num);
    }
  }

  // 最多的最大数字 maxx 最多次数 maxcnt 等次数次大lastx 少一次最大 maxrx

  for (int i = 0; i < brr.size(); i++)
  {
    if (mp[brr[i].num] + 1 > maxcnt)
    {
      st.insert(brr[i].num);
    }
    else if (mp[brr[i].num] + 1 == maxcnt)
    {
      if (brr[i].num >= lastx)
      {
        st.insert(lastx);
      }
    }
    else if (mp[brr[i].num] + 1 == maxcnt - 1 && lastx == -1)
    {
      if (brr[i].num >= maxrx && brr[i].num >= maxx)
      {
        st.insert(brr[i].num);
      }
    }
  }

  for (auto x : st)
  {
    cout << x << " ";
  }
}