#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[120];
struct Node
{
  int num;
  int pos;
};

void slove()
{
  int n;
  int cnt[105] = {0};
  cin >> n;
  int maxnum = -1;
  vector<Node> qe;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    cnt[arr[i]]++;
    maxnum = max(maxnum, arr[i]);
    if (arr[i] != 0)
    {
      qe.push_back({arr[i], i});
    }
  }
  sort(qe.begin(), qe.end(), [](Node a, Node b)
       { return a.num < b.num; });

  for (int i = 1; i <= 100; i++)
  {

    if (cnt[i] >= 2)
    {
      cout << -1 << endl;
      return;
    }
  }

  int cur = 0;
  int idx = 0;
  cout << maxnum << endl;
  while (idx < qe.size())
  {
    cur++;
    cout << qe[idx].pos << " ";
    if (qe[idx].num == cur)
      idx++;
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