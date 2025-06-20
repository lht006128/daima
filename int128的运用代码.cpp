#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

// 重载输入运算符以支持__int128类型
std::istream &operator>>(std::istream &is, __int128 &val)
{
  std::string s;
  bool flag = true;
  is >> s, val = 0;
  if (s[0] == '-')
    flag = false, val = std::stoi(s.substr(0, 2)), s = s.substr(2);
  for (char &c : s)
    val = val * 10 + (c - '0') * (!flag ? -1 : 1);
  return is;
}

// 重载输出运算符以支持__int128类型
std::ostream &operator<<(std::ostream &os, __int128 val)
{
  if (val < 0)
    os << "-", val = -val;
  if (val > 9)
    os << val / 10;
  os << static_cast<char>(val % 10 + '0');
  return os;
}

template <typename T>
struct Fenwick
{
  int n;
  std::vector<T> a;

  Fenwick(int n_ = 0)
  {
    init(n_);
  }

  void init(int n_)
  {
    n = n_;
    a.assign(n + 5, T{});
  }

  void add(int x, const T &v)
  {
    for (int i = x; i <= n; i += i & -i)
    {
      a[i] = a[i] + v;
    }
  }

  T sum(int x)
  {
    T ans{};
    for (int i = x; i > 0; i -= i & -i)
    {
      ans = ans + a[i];
    }
    return ans;
  }

  T rangeSum(int l, int r)
  {
    return sum(r) - sum(l);
  }

  int select(const T &k)
  {
    int x = 0;
    T cur{};
    for (int i = 1 << std::__lg(n); i; i /= 2)
    {
      if (x + i <= n && cur + a[x + i] <= k)
      {
        x += i;
        cur = cur + a[x];
      }
    }
    return x;
  }
};

void DAOQI()
{
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
  {
    std::cin >> a[i];
  }

  std::vector<i128> l(n + 1), r(n + 1), ll(n + 1), rr(n + 1);
  Fenwick<i128> fw1(n + 1), fw2(n + 1);

  for (int i = 1; i <= n; i++)
  {
    l[i] = fw1.sum(a[i] - 1);
    ll[i] = fw2.sum(a[i] - 1);
    fw2.add(a[i], fw1.sum(a[i]));
    fw1.add(a[i], 1);
  }

  fw1.init(n + 1), fw2.init(n + 1);
  for (int i = n; i >= 1; i--)
  {
    r[i] = fw1.rangeSum(a[i], n);
    rr[i] = fw2.rangeSum(a[i], n);
    fw2.add(a[i], fw1.rangeSum(a[i] - 1, n));
    fw1.add(a[i], 1);
  }

  i128 ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += (l[i] * (l[i] - 1) / 2 - ll[i]) * (r[i] * (r[i] - 1) / 2 - rr[i]);
  }
  std::cout << ans << "\n";
}

signed main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T = 1;
  // std::cin >> T;
  while (T--)
    DAOQI();
  return 0;
}
