#include <bits/stdc++.h>
using namespace std;
double ans;
double dp[30000010];
int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int a, b, p, q;
  cin >> a >> b >> p >> q;

  double glp = p / 100.0;
  double glq = q / 100.0;

  // cout << glp << " " << glq << endl;

  for (int i = b; i <= a; i++)
  {
    dp[i] = max<double>(glp * (dp[i - b] + 2) + (1.0 - glp) * (dp[i - b] + 1), glq * (dp[i - b + 1] + 1) + (1.0 - glq) * ((dp[i - b]) + 1));
    // cout << glp * (dp[i - b] + 2) + (1.0 - glp) * (dp[i - b] + 1) << " ";
  }
  if (b == 1)
  {
    printf("%.15lf", max(1.0 * a / (1 - glq), dp[a]));
  }
  else
  {
    printf("%.15lf", dp[a]);
  }
}