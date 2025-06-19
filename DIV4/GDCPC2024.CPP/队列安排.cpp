#include <bits/stdc++.h>
using namespace std;

int head = 0;
int end = 0;
struct Node
{
  int is;
  int pre;
  int next;
};

Node h[100010];

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  h[1].is = 1;
  h[1].next = 0;
  h[1].pre = 0;
  head = 1;
  cin >> n;
  for (int i = 2; i <= n; i++)
  {
    int k, p;
    cin >> k >> p;
    h[i].is = 1;
    h[i].next = 0;
    h[i].pre = 0;
    if (p == 0)
    {
      // 往左边插入一个
      if (head == k)
      {
        head = i;
        // cout << head << " ";
        h[i].next = k;
        h[i].pre = 0;
        h[k].pre = i;
      }
      else
      {
        h[h[k].pre].next = i;
        h[i].pre = h[k].pre;
        h[i].next = k;
        h[k].pre = i;
      }
    }
    else
    {
      if (h[k].next == 0)
      {
        h[k].next = i;
        h[i].pre = k;
        h[i].next = 0;
      }
      else
      {
        h[h[k].next].pre = i;
        h[i].next = h[k].next;

        h[k].next = i;
        h[i].pre = k;
      }
    }
  }

  int m;
  cin >> m;
  for (int i = 1; i <= m; i++)
  {
    int tp;
    cin >> tp;

    if (h[tp].is)
    {
      h[tp].is = 0;

      if (tp == head)
      {
        head = h[tp].next;
      }
      else
      {
        if (h[tp].next == 0)
        {
          h[h[tp].pre].next = 0;
        }
        else
        {
          h[h[tp].pre].next = h[tp].next;
          h[h[tp].next].pre = h[tp].pre;
        }
      }
    }
  }

  // cout << head;
  while (1)
  {
    cout << head << " ";
    head = h[head].next;
    if (head == 0)
      break;
  }
}