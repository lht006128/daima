#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node
{
  int p, s;
};
Node arr[1010];

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, b;

  cin >> n >> b;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i].p >> arr[i].s;
  }

  sort(arr + 1, arr + 1 + n, [](Node a, Node b)
       {
    if(a.p+a.s!=b.p+b.s){
      return a.p+a.s<b.p+b.s;
    }else return a.p>b.p; });

  int sum = 0;
  int maxp = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    sum += arr[i].p + arr[i].s;
    maxp = max(arr[i].p, maxp);
    if (sum > b)
    {
      sum -= maxp;
      sum += maxp / 2;
      if (sum > b)
      {
        break;
      }
      else
      {
        ans++;
      }
    }
    else
    {
      ans++;
    }
  }

  cout << ans;
}