#include <bits/stdc++.h>
using namespace std;
string s[101];
string words;
vector<string> ts;

int ans = 0;
int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];
    transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);
  }
  getline(cin, words);
  getline(cin, words);
  transform(words.begin(), words.end(), words.begin(), ::tolower);

  // 寻找句号
  int last = 0;
  for (int i = 0; i < words.size(); i++)
  {
    if (words[i] == '.')
    {
      ts.push_back(words.substr(last, i - last + 1));
      last = i + 1;
    }
  }

  for (int j = 0; j < ts.size(); j++)
  {
    for (int i = 1; i <= n; i++)
    {
      int idx = 0;
    A:
      idx = ts[j].find(s[i], idx);
      if (idx != -1)
      {
        if (idx == 0 || ts[j][idx - 1] == ' ' || ts[j][idx - 1] == '.' || ts[j][idx - 1] == ',' || ts[j][idx - 1] == '\'')
        {
          // 保证是一个单词的格式。
          if (idx + s[i].size() == ts[j].size() || ts[j][idx + s[i].size()] == ' ' || ts[j][idx + s[i].size()] == '.' || ts[j][idx + s[i].size()] == ',' || ts[j][idx + s[i].size()] == '\'')
          {
            ans++;
          }
          else
          {
            idx++;
            goto A;
          }
        }
        else
        {
          idx++;
          goto A;
        }
      }
    }
  }
  transform(words.begin(), words.end(), words.begin(), ::toupper);
  cout << words << endl;

  // cout << ts[1] << endl;
  cout << ans;
}