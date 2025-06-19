#include <bits/stdc++.h>
using namespace std;
struct Node
{
  char c;
  int cnt;
};

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    []() -> void
    {
      int n;
      cin >> n;
      string s;
      cin >> s;

      if (n == 1)
      {
        cout << s << endl;
        return;
      }
      map<char, int> mp;
      int maxx = 0;

      char c;
      for (int i = 0; i < n; i++)
      {
        mp[s[i]]++;

        maxx = max(maxx, mp[s[i]]);
        if (maxx == mp[s[i]])
        {
          c = s[i];
        }
      }

      vector<Node> arr;
      for (auto [x, cnt] : mp)
      {
        arr.push_back({x, cnt});
      }
      if (arr.size() == 1)
      {
        cout << s << endl;
        return;
      }

      sort(arr.begin(), arr.end(), [](Node a, Node b) -> bool
           { return a.cnt < b.cnt; });
      int idx = 0;
      if (arr[idx].c == c)
      {
        idx++;
      }
      for (int i = 0; i < n; i++)
      {
        if (s[i] == arr[idx].c)
        {

          s[i] = c;
          break;
        }
      }
      cout << s << endl;
    }();
  }
}