#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int cnt;
  char c;
};
vector<Node> arr;

void slove()
{
  string a, b;
  int cnt = 0;
  cin >> a >> b;
  arr.clear();

  if (a.size() > b.size())
  {
    cout << "NO" << endl;
    return;
  }
  else if (a.size() * 2 < b.size())
  {
    cout << "NO" << endl;
    return;
  }
  for (int i = 0; i < a.size(); i++)
  {
    if (i == 0)
    {
      cnt++;
    }
    else
    {
      if (a[i] == a[i - 1])
      {
        cnt++;
      }
      else
      {
        arr.push_back(Node{cnt, a[i - 1]});
        cnt = 1;
      }
    }
  }
  arr.push_back(Node{cnt, a[a.size() - 1]});
  int tp = 0;
  int idx = 0;
  for (int i = 0; i < b.size(); i++)
  {
    if (i == 0)
    {
      if (b[i] != a[i])
      {
        cout << "NO" << endl;
        return;
      }
      else
      {
        tp++;
      }
    }
    else
    {
      if (b[i] == b[i - 1])
      {
        tp++;
      }
      else
      {
        if (tp > arr[idx].cnt * 2)
        {
          cout << "NO" << endl;
          return;
        }
        if (tp < arr[idx].cnt)
        {
          cout << "NO" << endl;
          return;
        }
        idx++;
        tp = 1;
        if (b[i] != arr[idx].c)
        {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }

  if (tp > arr[idx].cnt * 2)
  {
    cout << "NO" << endl;
    return;
  }
  if (tp < arr[idx].cnt)
  {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }
}