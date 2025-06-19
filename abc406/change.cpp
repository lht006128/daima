#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
struct Node
{
  int num;
  int id;
};

bool cmp(Node a, Node b)
{
  if (a.num == b.num)
  {
    return a.id > b.id;
  }
  return a.num > b.num;
}

signed main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    if (k == 0)
    {
      for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
      puts("");
      continue;
    }
    vector<Node> b(n);
    for (int i = 0; i < n; ++i)
    {
      b[i] = {a[i], i};
    }
    sort(b.begin(), b.end(), cmp);
    vector<bool> st(n + 1, false);
    long long sum = 0;
    for (int i = 0; i < k + 1; ++i)
    {
      sum += b[i].num;

      st[b[i].id] = true;
      if (b[i].num == 0)
        break;
    }
    vector<int> res;
    res.push_back(sum);
    for (int i = 0; i < n; ++i)
    {
      if (!st[i])
      {
        res.push_back(a[i]);
      }
    }
    for (int i = 0; i < res.size(); i++)
    {
      cout << res[i] << " ";
    }
    puts("");
  }
  return 0;
}