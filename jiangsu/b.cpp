#include <bits/stdc++.h>
// #define int long long

using namespace std;
// double B,t1,m1,t2,m2,tmp,tt1,tt2;

signed main()
{
  // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int B, t1, m1, t2, m2;
    double tmp = 0, tt1 = 0, tt2 = 0, ttmp = 0;
    // cin >> B >> t1 >> m1 >> t2 >> m2;
    scanf(" %d %d %d %d %d", &B, &t1, &m1, &t2, &m2);
    tmp = t2 - t1;
    if (tmp * B >= m1)
    {
      tt1 = 1.0 * m1 / B;
      tt2 = 1.0 * m2 / B;
      // cout << m1 / B << " " << m2 / B << endl;
      printf("%.9lf %.9lf\n", tt1, tt2);
    }
    else
    {
      m1 -= 1.0 * B * tmp;
      tt1 += tmp;

      if (m1 > m2)
      {
        tt2 += 1.0 * m2 / (B * 0.5);
        tt1 += 1.0 * (m1 - m2) / B + tt2;
      }
      else if (m1 < m2)
      {
        ttmp += 1.0 * m1 / (B * 0.5);
        tt2 += 1.0 * (m2 - m1) / B + ttmp;
        tt1 += 1.0 * ttmp;
      }
      else
      {
        tt2 += 1.0 * m2 / (B * 0.5);
        tt1 += 1.0 * tt2;
      }
      printf("%.9lf %.9lf\n", tt1, tt2);
    }
  }
  return 0;
}
