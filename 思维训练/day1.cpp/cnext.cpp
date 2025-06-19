#include <bits/stdc++.h>
#define int long long

using namespace std;

int d[2001010];
int r[2000100];
int l[2000010];

void slove()
{
  queue<int> qe;
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> d[i];
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> r[i] >> l[i];
  }

  int left = 0;

  for (int i = 1; i <= n; i++)
  {
    if(d[i]!=-1){
      left+=d[i];
    }else{
      qe.push(i);
    }

    while(left+qe.size()>)

  }
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