#include <bits/stdc++.h>
using namespace std;

int T, n;
bool a[100005];

int main()
{
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);
    memset(a, 0, sizeof(a)); // 多测不清空，爆零两行泪
    int cnt = 0;
    for (int i = 1, x; i <= n * 2; ++i)
    {
      scanf("%d", &x);
      if (a[x])
        ++cnt;
      a[x] = 1; // 标记出现过的 x
    }
    cout << cnt;
    puts(cnt >= n ? "Lose" : "Win");
  }
  return 0;
}