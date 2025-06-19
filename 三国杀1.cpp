#include <bits/stdc++.h>
using namespace std;

struct Node
{
  string x;
  string y;
};

Node pai[100010];
Node pai2[100010];
vector<int> wj[1010];

void slove()
{
  int n;
  cin >> n;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, k, m, p;
  cin >> n >> k >> m >> p;

  if (n * 4 > k)
  {
    cout << "Error:cards not enough";
    return 0;
  }

  for (int i = 1; i <= k; i++)
  {
    string x, y;
    cin >> x >> y;
    pai[i] = {x, y};
  }

  while (m--)
  {
    int idx = 1;
    for (int i = 1; i <= k / 2; i++)
    {
      pai2[idx++] = pai[k / 2 + i];
      pai2[idx++] = pai[i];
    }

    for (int i = 1; i <= k; i++)
    {
      pai[i] = pai2[i];
    }
  }

  for (int i = 1; i <= k; i++)
  {
    int j;
    j = (i - 1) % n + 1;
    wj[j].push_back(i);
  }

  for (int i = 0; i < 4; i++)
  {
    cout << pai[wj[p][i]].x << " " << pai[wj[p][i]].y << endl;
  }
}
