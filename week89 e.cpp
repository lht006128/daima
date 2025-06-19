#include <bits/stdc++.h>
#define int long long

using namespace std;

int mp[101][101];
string s[101];
struct Node
{
  int x1, y1, x2, y2;
};

vector<Node> ans;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  int cnt = 0;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];
  }

  // 转换成数字
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      mp[i][j] = s[i][j - 1] - '0';
      if (s[i][j - 1] == '0')
        cnt++;
    }
  }

  if (cnt % 2 == 1)
  {
    cout << -1;
    return 0;
  }

  // 构造

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (mp[i][j] == 0)
      {
        if (j != m)
        {
          mp[i][j] = 1;
          mp[i][j + 1] = 1 - mp[i][j + 1];
          ans.push_back({i, j, i, j + 1});
        }
        else
        {
          mp[i][j] = 1;
          mp[i + 1][j] = 1 - mp[i + 1][j];
          ans.push_back({i, j, i + 1, j});
          // cout << i << " " << j << " " << i + 1 << " " << j << endl;
        }
      }
    }
  }

  cout << ans.size() << endl;

  for (int i = 0; i < ans.size(); i++)
  {

    cout << ans[i].x1 << " " << ans[i].y1 << " " << ans[i].x2 << " " << ans[i].y2 << endl;
  }

  return 0;
  //
}
