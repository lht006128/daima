#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node
{
  int x, y;
};
// 这题不难发现 状态存在无后向性，因为可以暴力枚举 所以前面的贪心不会影响后面的状态 而且前面都是最优化解
Node arr[5001];
double dp[5100];

double calc(Node a, Node b)
{
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int x, y;
    cin >> x >> y;
    arr[i] = {x, y};

    for (int j = 1; j <= i; j++)
    {
      dp[i] = max<double>(dp[i], dp[j - 1] + calc(arr[j], arr[i]));
    }
  }

  printf("%.9lf", dp[n]);
}