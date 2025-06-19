#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node
{
  char c;
  int pos;
};

int mod = 1e9 + 7;
int a[2011];
int qz[2011];
void slove()
{
  stack<Node> st;
  memset(a, 0, sizeof(a));
  memset(qz, 0, sizeof(qz));

  int n, m;
  int ans = 0;
  cin >> n >> m;

  string s;
  cin >> s;

  if (m % 2 != 0)
  {
    cout << 0 << endl;
    return;
  }

  int cnt = 0; // 记录有效括号序列。

  for (int i = 0; i < s.size(); i++)
  {
    if (st.empty())
    {
      st.push({s[i], i});
      continue;
    }

    if (s[i] == ')')
    {
      if (st.top().c == '(')
      {
        cnt++;
        a[i]++;

        st.pop();
      }
    }
    else
    {
      st.push({s[i], i});
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
      qz[i] = a[i];
    else
      qz[i] = qz[i - 1] + a[i];
  }

  int have = m - n;     // 可以用来填充的括号数量
  int need = st.size(); // 目前没有配对好的括号数量  如果是 0 就当原序列都为 （）（）（）

  if ((m - n) < need)
  {
    cout << 0 << endl;
    return;
  }
  else if (need > 0)
  {
    int sum = 1;
    int cnt2 = 0; // 记录右侧左括号数量

    while (!st.empty())
    {
      {
        if (st.top().c == '(')
        {
          sum = (sum * (cnt2 + 1 + qz[n - 1] - qz[st.top().pos]) % mod) % mod;
        }
        else
        {
          // cout << a[0] << endl;
          sum = (sum * (1 + qz[st.top().pos] - qz[0]) % mod) % mod;
        }
      }
      cnt2++;
      st.pop();
    }

    have -= need;
    int hefa = (m - have) / 2;

    for (int i = 0; i < have; i++)
    {
      sum = (sum * (hefa + 1 + i) % mod) % mod;
    }
    ans = sum;
  }
  else
  {
    // 没有需求的情况；
    int sum = 1;
    int hefa = n / 2;

    // cout << hefa << endl;

    for (int i = 0; i < have / 2; i++)
    {
      sum = (sum * (hefa + 1 + i) % mod) % mod;
    }
    ans = sum;
  }

  cout << ans % mod << endl;
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