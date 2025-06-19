#include <bits/stdc++.h>
#define int long long

using namespace std;
// 数据结构 这种装东西的模型通常使用 堆来实现，以后要多加注意！！！
set<int> xia; // 记录矩形的下边界，这里其实用了贪心，要有最有解，必定有边界圆和举行相切，并且切的边大于1 小于2 其实这题我就枚举下边界然后从左往右跑切点。 相当于贪心了两个方向。
int n;
struct Node
{
  int x, y;
  int top;
  int left;
  int right;
  int foot;

  bool operator<(const Node &ohter) const
  {
    return left > ohter.left;
  }
};

Node arr[2000];

int cmp(Node a, Node b)
{
  return a.right < b.right;
}
int ans = -1;

void calc(int w, int h)
{
  int maxh;
  int boot;

  for (auto it : xia)
  {
    priority_queue<Node> dui; // 计算最左侧的圆是哪个。 这里指加了半径后的而不是圆心。
    boot = it;                // 下边界，这里跑的是N^2 的算法，符合题目条件
    maxh = boot + h;
    for (int i = 1; i <= n; i++)
    {
      if (arr[i].foot < boot)
        continue;
      if (arr[i].top > maxh)
        continue;
      dui.push(arr[i]);
      int curr = arr[i].right;
      while (!dui.empty())
      {
        int len = curr - dui.top().left;
        if (len > w)
        {
          dui.pop();
        }
        else
        {
          break;
        }
      }
      // cout << dui.size() << " " << boot << endl;
      ans = max<long long>(ans, dui.size());
    }
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int w, h;
  cin >> n >> w >> h;
  for (int i = 1; i <= n; i++)
  {
    int x, y, r;
    cin >> x >> y >> r;
    arr[i].x = x;
    arr[i].y = y;
    arr[i].top = y + r;
    arr[i].foot = y - r;
    arr[i].left = x - r;
    arr[i].right = x + r;

    xia.insert(arr[i].foot);
  }
  sort(arr + 1, arr + n + 1, cmp);

  calc(w, h);
  calc(h, w);

  cout << ans;
  return 0;
}