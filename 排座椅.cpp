#include <bits/stdc++.h>
using namespace std;
// 经典贪心模板；
struct Node
{
  int pos;
  int v;
};
Node txh[2010]; // 贪心数组
Node txl[2010];

int cnth[2010]; // 普通数组
int cntl[2010];
vector<int> ansh;
vector<int> ansl;
bool cmp(Node a, Node b)
{
  return a.v > b.v;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int m, n, k, l, d;
  cin >> n >> m >> k >> l >> d; // n行M 列 不用题目的

  for (int i = 1; i <= d; i++)
  {
    int x, y, p, q;
    cin >> x >> y >> p >> q;

    // 同一行
    if (x == p)
    {
      if (q > y)
      {
        cntl[y]++; // 因为题目计算的是 k和 K+1 的影响
      }
      else
      {
        cntl[q]++;
      }
    }
    else
    {
      // 同一列 行有影响
      if (p > x)
      {
        cnth[x]++; // 因为题目计算的是 k和 K+1 的影响
      }
      else
      {
        cnth[p]++;
      }
    }
  }

  // 赋值 准备贪心：
  for (int i = 1; i <= n; i++)
  {
    txh[i].pos = i;
    txh[i].v = cnth[i];
  }

  for (int i = 1; i <= m; i++)
  {
    txl[i].pos = i;
    txl[i].v = cntl[i];
  }

  sort(txh + 1, txh + 1 + n, cmp);
  sort(txl + 1, txl + 1 + n, cmp);

  for (int i = 1; i <= k; i++)
  {
    ansh.push_back(txh[i].pos);
  }

  for (int i = 1; i <= l; i++)
  {
    ansl.push_back(txl[i].pos);
  }

  sort(ansh.begin(), ansh.end());
  sort(ansl.begin(), ansl.end());

  for (int i = 0; i < ansh.size(); i++)
  {
    cout << ansh[i];
    if (i != ansh.size() - 1)
      cout << " ";
  }
  cout << endl;

  for (int i = 0; i < ansl.size(); i++)
  {
    cout << ansl[i];
    if (i != ansl.size() - 1)
      cout << " ";
  }
}