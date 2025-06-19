#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int t;
  int w;
  int next;
};

Node edge[200000];
int head[100010];
int sum[100010];
int cnt = 0;

int ch[3100000][2];

void addedge(int x, int y, int w)
{
  edge[++cnt].t = y;
  edge[cnt].w = w;
  edge[cnt].next = head[x];
  head[x] = cnt;
}

void dfs(int id, int fa)
{
  // cout << id << endl;
  for (int i = head[id]; i != -1; i = edge[i].next)
  {
    int next;
    next = edge[i].t;
    if (next == fa)
      continue;
    else
    {
      sum[next] = (sum[id] ^ edge[i].w);
      dfs(next, id);
    }
  }
}
int tot = 0;
void build(int x)
{
  int p = 0;
  for (int i = (1 << 30); i; i = (i >> 1))
  {
    bool tp = x & i;
    if (!ch[p][tp])
    {
      ch[p][tp] = ++tot;
    }
    p = ch[p][tp];
  }
}

int query(int x)
{
  int p = 0;
  int sum = 0; // 注意这里初始值为0，因为如果自己高位是1但是找不到另外一个数是0那么这个高位就被异或成0了。
  // 一定要从30 开始，对齐每个数的位数。
  for (int i = (1 << 30); i; i = (i >> 1))
  {
    bool tp = x & i;
    if (ch[p][!tp])
    {
      sum += i;
      p = ch[p][!tp]; // 高位优先，这个高位可以异或为1那么就继续走这条路
    }
    else
      p = ch[p][tp]; // 没有高位就只能走地位。就是 异或后这一位位0的位。
  }
  return sum;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(head, -1, sizeof(head));
  int n;
  cin >> n;

  for (int i = 1; i <= n - 1; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    addedge(u, v, w);
    addedge(v, u, w);
  }

  dfs(1, -1); // 求出所有点到根节点的异或值 这里有个trick 两个节点到根的异或值异或，
              // 就等于这两个点的唯一路径上的所有边权的异或，因为如果这俩的根不在我们定义的1号节点，那么他们的根到1号节点会重复异或，值不变。

  // 构建01 字典树。
  for (int i = 1; i <= n; i++)
  {
    build(sum[i]);
    // cout << sum[i] << endl;
  }

  int ans = 0;
  // 贪心查询答案；
  for (int i = 1; i <= n; i++)
  {
    ans = max(ans, query(sum[i]));
  }

  cout << ans;
}