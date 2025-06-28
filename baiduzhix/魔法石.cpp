#include <bits/stdc++.h>
#define int long long
using namespace std;

set<int> st;
int arr[1010];
int ans1 = 0;
int ans2 = 0;
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    st.insert(arr[i]);
  }
  int tp = 0;
  for (int i = 1; i <= n; i++)
  {
    if (arr[i] == arr[i - 1])
    {
      tp++;
    }
    else
    {
      tp = 1;
    }
    ans1 = max(tp, ans1);
  }

  for (auto it : st)
  {
    // cout<<it<<endl;
    int tp2 = 0;
    int last = 0;
    for (int i = 1; i <= n; i++)
    {
      if (arr[i] == it)
        continue;
      if (arr[i] == last)
      {
        tp2++;
      }
      else
      {
        tp2 = 1;
      }

      last = arr[i];
      ans2 = max(ans2, tp2);
    }
  }

  // cout << ans1 << " " << ans2 << endl;
  if (ans2 >= ans1)
  {
    cout << ans2 - ans1;
  }
  else
  {
    cout << 0;
  }
}