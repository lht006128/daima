#include <bits/stdc++.h>
#define int long long
using namespace std;
deque<int> qe;
deque<int> qe2;
int sumz = 0;
int sum2 = 0;
void slove()
{
  qe.clear();
  sumz = 0;
  int sumn = 0;
  sum2 = 0;
  int f = 1;
  int q;
  cin >> q;

  while (q--)
  {
    int s;
    cin >> s;
    if (s == 1)
    {
      if (f)
      {
        sumz = sumz - (qe.back() * qe.size()) + sum2 - qe.back() + qe.back();
        sumn = sumn - sum2 + qe.back() * qe.size();
      }
      else
      {
        sumz = sumz - (qe2.back() * qe2.size()) + sum2 - qe2.back() + qe2.back();
        sumn = sumn - sum2 + qe2.back() * qe2.size();
      }

      // cout << "---w123" << endl;
      // cout << sumn << endl;
      // cout << "---e" << endl;
      if (f)
      {
        qe.push_front(qe.back());
        qe.pop_back();

        qe2.push_back(qe2.front());
        qe2.pop_front();
      }
      else
      {
        qe.push_back(qe.front());
        qe.pop_front();

        qe2.push_front(qe2.back());
        qe2.pop_back();
      }
    }
    else if (s == 2)
    {
      // reverse(qe.begin(), qe.end());
      f = 1 - f;
      swap(sumz, sumn);
    }
    else if (s == 3)
    {
      int k;
      cin >> k;
      if (f)
      {
        qe.push_back(k);
        qe2.push_front(k);
      }
      else
      {
        qe.push_front(k);
        qe2.push_back(k);
      }

      sumz += (qe.size()) * k;
      sumn = sumn + sum2 + k;
      sum2 += k;
    }

    cout << sumz << endl;
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