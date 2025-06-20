#include <bits/stdc++.h>
#define unsigned int long long
using namespace std;

int pre[300010][30];
int premi[3000010][30];
int premax[3000010][30];
  string s;


bool pd(int mid)
{
  int l = 0 ;
  deque<int>qe;
  qe.push_back(0);
  

  for(int i=1;i<s.size();i++){



  }


}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int x;
  cin >> s >> x;

  for (int i = 0; i < s.size(); i++)
  {
    if (i != 0)
    {
      for (int j = 0; j <= 'z' - 'a'; j++)
      {
        pre[i][j] = pre[i - 1][j];
      }
    }
    pre[i][s[i] - 'a']++;
  }
  for (int j = 0; j <= 'z' - 'a'; j++)
  {
    pre[s.size()][j] = pre[s.size() - 1][j];
  }

  for (int i = 0; i <= s.size(); i++)
  {
    for (int j = 0; j <= 'z' - 'a'; j++)
    {

      for (int k = 0; k <= j - 1; k++)
      {
        premi[i][j] += pre[i][k];
      }
      for (int k = j + 1; k <= 'z' - 'a'; k++)
      {
        premax[i][j] += pre[i][k];
      }
    }
    // cout << premi[i][0] << endl;
  }
  int l = 0;
  int r = x + 1;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (pd(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
}