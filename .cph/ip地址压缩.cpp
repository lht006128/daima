#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0), cin.tie(), cout.tie(0);

  string s;

  cin >> s;
  if (s == "0000:0000:0000:0000:0000:0000:0000:0000")
  {
    cout << "::";
    return 0;
  }
  // 先去掉前导零

  // for (int i = 0; i < 36 && i < s.size(); i += 5)
  // {
  //   string ts;
  //   ts = s.substr(i, 4);

  //   if (ts != "0000")
  //   {

  //     for (int j = i; j <= i + 3 && j < s.size(); j++)
  //     {
  //       if (s[j] == '0')
  //       {
  //         s.erase(j, 1);
  //       }
  //       else
  //       {
  //         break;
  //       }
  //     }
  //   }
  // }
  int fpos = 0;
  int f = 1;
  while (1)
  {
    if (fpos == -1)
      break;
    string ts;
    int tttp;
    if (f)
    {
      ts = s.substr(fpos, 4);
      tttp = fpos;
      f = 0;
    }
    else
    {
      ts = s.substr(fpos + 1, 4);
      tttp = fpos + 1;
    }

    if (ts != "0000")
    {
      // cout << ts << endl;

      for (int j = tttp; j <= tttp + 3 && j < s.size(); j++)
      {
        if (s[j] == '0')
        {
          s.erase(j, 1);
          j--;
        }
        else
        {
          break;
        }
      }
      // cout << endl;
    }
    fpos = s.find(":", fpos + 1);
  }

  // cout << s << endl;

  int pos = 0;
  int posr = 0;
  int maxl = -1;
  int tpos = -1;

  int lpos = -1;
  int rpos = -1;
  int l = -1;

  while (1)
  {
    int idx;
    idx = s.find("0000", tpos + 1);
    if (idx == -1)
      break;
    if (l == -1)
    {
      l = 1;
      lpos = idx;
      rpos = idx + 3;
    }
    else
    {

      if (idx == tpos + 5)
      {
        l++;
        rpos = idx + 3;
      }
      else
      {

        l = -1;
        lpos = -1;
        rpos = -1;
      }
    }

    tpos = idx;

    if (maxl < l)
    {
      maxl = l;
      pos = lpos;
      posr = rpos;
    }
  }

  if (maxl == -1)
  {
    cout << s;
  }
  else
  {

    if (posr == s.size() - 1 || pos == 0)
    {
      s.erase(pos, posr - pos + 1);
      s.insert(pos, ":");
    }
    else
    {
      s.erase(pos, posr - pos + 1);
    }

    int tposx = -1;
    while (1)
    {
      int tp;
      tp = s.find("0000", tposx + 1);
      if (tp == -1)
        break;
      else
      {
        s.erase(tp, 3);
      }
      tposx = tp;
      // cout << s << endl;
    }

    cout << s;
  }

  // int tposx = -1;
  // while (1)
  // {
  //   int tp;
  //   tp = s.find("0000", tposx + 1);
  //   if (tp == -1)
  //     break;
  //   else
  //   {
  //     s.erase(tp, 3);
  //   }
  //   tposx = tp;
  //   // cout << s << endl;
  // }
}