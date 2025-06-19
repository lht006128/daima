#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

// 试除法分解质因数 - 基础版本 (O(√n))
vector<pair<int, int>> factorize(int n)
{
  vector<pair<int, int>> factors;

  // 处理2的因子
  if (n % 2 == 0)
  {
    int cnt = 0;
    while (n % 2 == 0)
    {
      n /= 2;
      cnt++;
    }
    factors.emplace_back(2, cnt);
  }

  // 处理奇数因子
  for (int i = 3; i <= sqrt(n); i += 2)
  {
    if (n % i == 0)
    {
      int cnt = 0;
      while (n % i == 0)
      {
        n /= i;
        cnt++;
      }
      factors.emplace_back(i, cnt);
    }
  }

  // 如果剩下的n是大于2的质数
  if (n > 1)
  {
    factors.emplace_back(n, 1);
  }

  return factors;
}

// 预处理最小质因子的优化版本 (O(log n) 分解，但需要O(n)预处理)
class PrimeFactorizer
{
private:
  vector<int> min_prime; // 记录每个数的最小质因子

public:
  PrimeFactorizer(int max_num)
  {
    // 线性筛法预处理最小质因子
    min_prime.resize(max_num + 1, 0);
    for (int i = 2; i <= max_num; i++)
    {
      if (min_prime[i] == 0)
      { // i是质数
        min_prime[i] = i;
        if ((long long)i * i > max_num)
          continue;
        for (int j = i * i; j <= max_num; j += i)
        {
          if (min_prime[j] == 0)
          {
            min_prime[j] = i;
          }
        }
      }
    }
  }

  vector<pair<int, int>> factorize(int n)
  {
    vector<pair<int, int>> factors;

    while (n > 1)
    {
      int p = min_prime[n];
      int cnt = 0;
      while (n % p == 0)
      {
        n /= p;
        cnt++;
      }
      factors.emplace_back(p, cnt);
    }

    return factors;
  }
};

std::vector<int> manacher(std::string s)
{
  std::string t = "#";
  for (auto c : s)
  {
    t += c;
    t += '#';
  }
  int n = t.size();
  std::vector<int> r(n);
  for (int i = 0, j = 0; i < n; i++)
  {
    if (2 * j - i >= 0 && j + r[j] > i)
    {
      r[i] = std::min(r[2 * j - i], j + r[j] - i);
    }
    while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]])
    {
      r[i] += 1;
    }
    if (i + r[i] > j + r[j])
    {
      j = i;
    }
  }
  return r;
}

int main()
{
  string s;
  cin >> s;

  vector<int> r = manacher(s);
  for (auto i : r)
  {
    cout << i << " ";
  }
  return 0;
}