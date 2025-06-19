#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

priority_queue<int, vector<int>, greater<int>> chadui;
queue<char> yuan;
string ans;

char arr[100010];
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++)
  {
    yuan.push(s[i]);
  }

  for (int i = 1; i <= m; i++)
  {
    cin >> arr[i];
    chadui.push(arr[i]);
  }

  for (int i = 1; i <= n + m; i++)
  {
    if (!yuan.empty() && !chadui.empty())
    {
      if (chadui.top() < yuan.front())
      {
        ans += chadui.top();
        chadui.pop();
      }
      else
      {
        ans += yuan.front();
        yuan.pop();
      }
    }
    else if (!yuan.empty())
    {
      ans += yuan.front();
      yuan.pop();
    }
    else if (!chadui.empty())
    {
      ans += chadui.top();
      chadui.pop();
    }
  }

  cout << ans;
}
