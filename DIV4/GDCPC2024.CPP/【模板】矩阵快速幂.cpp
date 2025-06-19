#include <bits/stdc++.h>
using namespace std;
#define int long long
// a b p
// a^b mod p
// a^b/2 modp *a^b/2 modp
const int MOD = 1e9 + 7;
int n, k;

// int ksm(int a,int b,int p){
// 	int num;
// 	if(b==1)return a%p;
// 	num=ksm(a,b/2,p)%p;
// 	num=num*num%p;
// 	if(b%2==1)num=num*a%p;
// 	return num%p;
// }

struct jvzhen
{
  int c[101][101];
  jvzhen()
  {

    memset(c, 0, sizeof(c));
  }
};

jvzhen A;
jvzhen res; // 单位矩阵
jvzhen operator*(jvzhen &x, jvzhen &y)
{
  jvzhen t;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 1; k <= n; k++)
      {
        t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % MOD;
      }
    }
  }
  return t;
}

void ksm(int k)
{
  for (int i = 1; i <= n; i++)
    res.c[i][i] = 1;
  while (k)
  {
    if (k & 1)
      res = res * A;
    A = A * A;
    k >>= 1;
  }
}

signed main()
{

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> A.c[i][j];
    }
  }
  ksm(k);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << res.c[i][j] << " ";
    }
    cout << endl;
  }
}
