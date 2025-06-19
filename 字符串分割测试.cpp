#include <bits/stdc++.h>
using namespace std;

int main()
{

  string s;
  cin >> s;
  istringstream iss(s);

  string token;
  while (getline(iss, token, '+'))
  {
    cout << token << endl;
  }
}