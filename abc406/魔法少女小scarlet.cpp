#include <bits/stdc++.h>
using namespace std;
int jz[510][510];

void xz(int x, int y, int r, int z)
{
  // 顺时针旋转。
  if (z == 0)
  {

    int arr[510][4];
    for (int i = r; i >= 1; i--)
    {
      for (int j = -i; j <= i; j++)
      {
        arr[y + j][0] = jz[x - i][y + j]; // 上面
        arr[x + j][1] = jz[x + j][y + i]; // 右边
        arr[y - j][2] = jz[x + i][y - j]; // 下面
        arr[x - j][3] = jz[x - j][y - i]; // 左边

        // cout << arr[x - j][3] << " ";
      }
      // cout << endl;
      for (int j = -i; j <= i; j++)
      {
        jz[x - i][y + j] = arr[x - j][3]; // 上面
        jz[x + j][y + i] = arr[y + j][0]; // 右边
        jz[x + i][y - j] = arr[x + j][1]; // 下面
        jz[x - j][y - i] = arr[y - j][2]; // 左边
        // cout << arr[x - j][3] << " ";
      }
    }
  }
  else
  {

    int arr[510][4];
    for (int i = r; i >= 1; i--)
    {
      for (int j = -i; j <= i; j++)
      {
        arr[y + j][0] = jz[x - i][y + j]; // 上面
        arr[x + j][1] = jz[x + j][y + i]; // 右边
        arr[y - j][2] = jz[x + i][y - j]; // 下面
        arr[x - j][3] = jz[x - j][y - i]; // 左边

        // cout << arr[x - j][3] << " ";
      }
      // cout << endl;
      for (int j = -i; j <= i; j++)
      {
        jz[x - i][y + j] = arr[x + j][1]; // 上面
        jz[x + j][y + i] = arr[y - j][2]; // 右边
        jz[x + i][y - j] = arr[x - j][3]; // 下面
        jz[x - j][y - i] = arr[y + j][0]; // 左边
        // cout << arr[x - j][3] << " ";
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int num = 0;

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      jz[i][j] = ++num;
      // cout << jz[i][j] << " ";
    }
    // cout << endl;
  }
  // cout << endl;

  while (m--)
  {
    int x, y, r, z;
    cin >> x >> y >> r >> z;

    xz(x, y, r, z);
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << jz[i][j] << " ";
    }
    cout << endl;
  }
}