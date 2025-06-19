#include <bits/stdc++.h>
using namespace std;

/*
  总结:
  可以封装成函数写就封装成函数写，便于修改懂不懂的
*/

int a[3000];
struct Node
{
  int num;
  int cnt;
  Node(int a, int b)
  {
    num = a;
    cnt = b;
  }
  const bool operator<(const Node &other) const
  {
    return (cnt != other.cnt) ? cnt < other.cnt : num < other.num;
  }
};
int cnt[1000100];
set<Node> st;
set<int> zhongshu;
void add(int x)
{
  st.erase({x, cnt[x]});
  cnt[x]++;

  st.insert({x, cnt[x]});
}

void del(int x)
{
  st.erase({x, cnt[x]});
  cnt[x]--;
  st.insert({x, cnt[x]});
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    add(a[i]);
  }
  // cout << st.rbegin()->num << endl;
  // for (auto it : st)
  // {
  //   cout << it.num << " " << it.cnt << endl;
  // }
  for (int i = 1; i <= n; i++)
  {

    for (int j = 1; j <= n; j++)
    {
      if (j == i)
        continue;
      // i 加一 j - 1
      del(a[i]);
      add(a[i] + 1);

      del(a[j]);
      add(a[j] - 1);
      // cout << st.rbegin()->num << endl;
      zhongshu.insert(st.rbegin()->num);

      del(a[j] - 1);
      add(a[j]);

      del(a[i] + 1);
      add(a[i]);
    }
  }

  for (auto x : zhongshu)
  {
    cout << x << " ";
  }
}