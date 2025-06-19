#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[300010];
void slove()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  stack<int> st;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (st.empty())
    {
      st.push(arr[i]);
    }
    else
    {
      if (arr[i] - st.top() > 1)
      {
        ans++;
        st.pop();
        st.push(arr[i]);
      }
      else
      {
        continue;
      }
    }
  }

  cout << ans + 1 << endl;
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