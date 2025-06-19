#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int a[100010];
map<int, int> mp;
map<int, int> bj;
struct Node
{
  int num;
  int cnt;
};
vector<Node> arr;

bool cmp(Node a, Node b)
{
  return a.cnt > b.cnt;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    mp[a[i]]++;
  }

  for (auto [num, cnt] : mp)
  {
    if (cnt == 2)
    {
      bj[num] = 1;
      continue;
    }
    else
    {
      if (cnt > 2)
      {
        bj[num] = 1;
        arr.push_back({num, cnt - 2});
      }
      else
      {
        arr.push_back({num, cnt});
      }
    }
  }
  sort(arr.begin(), arr.end(), cmp);

  deque<int> qe;
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = 1; j <= arr[i].cnt; j++)
    {
      qe.push_back(arr[i].num);
    }
  }

  int ans = 0;

  while (!qe.empty())
  {
    int tou = qe.front();
    qe.pop_front();
    int wei = qe.back();
    qe.pop_back();
    if (bj[tou] == 0)
    {
      bj[tou] = 1;
      ans++;
    }
    else if (bj[wei] == 0)
    {
      bj[wei] = 1;
      ans++;
    }
    else
    {
      ans += 2;
    }
  }
  cout << ans;
}