#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int num;
  int cnt;
  Node(int a, int b)
  {
    num = a;
    cnt = b;
  }
  const bool operator<(const Node &other) const
  {
    if (cnt != other.cnt)
    {
      return cnt < other.cnt;
    }
    else
    {
      return num < other.num;
    }
  }
};

signed main()
{
  set<pair<int, int>> st;
  set<int> all;
  map<int, int> mp;
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int tp;
    cin >> tp;
    mp[tp]++;
  }

  vector<pair<int, int>> arr;
  for (auto [x, cnt] : mp)
  {
    st.insert({x, cnt});
    arr.push_back({x, cnt});
  }

  // for (auto x : st)
  // {
  //   cout << x.num << " " << x.cnt << endl;
  // }
  // 对第I个数+1 第 j 个数 -1
  for (int i = 0; i < arr.size(); i++)
  {

    for (int j = 0; j < arr.size(); j++)
    {
      if (i == j && arr[i].second < 2)
      {
        continue;
      }
      if (i == j)
      {
        st.erase(arr[i]);
        st.insert({arr[i].first, arr[i].second - 2});

        // 加一的数
        int addnum = arr[i].first + 1;
        // 他原来的cnt
        int addlastcnt = mp[addnum];

        st.erase({addnum, addlastcnt});

        // 加入修改后的数
        st.insert({addnum, addlastcnt + 1});

        // 减一的数
        int eranum = arr[j].first - 1;
        // 他原来的cnt
        int eralastcnt = mp[eranum];
        st.erase({eranum, eralastcnt});

        // 加入修改后的数
        st.insert({eranum, eralastcnt + 1});

        // 统计
        all.insert(st.rbegin()->first);

        // 复原
        st.erase({addnum, addlastcnt + 1});
        st.erase({eranum, eralastcnt + 1});

        st.insert({eranum, eralastcnt});
        st.insert({addnum, addlastcnt});

        st.erase({arr[i].first, arr[i].second - 2});
        st.insert(arr[j]);
        continue;
      }

      if ((arr[j].first - arr[i].first) == 1)
      {
        all.insert(st.rbegin()->first);
        continue;
      }

      st.erase(arr[i]);
      st.erase(arr[j]);
      st.insert({arr[i].first, arr[i].second - 1});
      st.insert({arr[j].first, arr[j].second - 1});
      // 加一的数
      int addnum = arr[i].first + 1;
      // 他原来的cnt
      int addlastcnt = mp[addnum];
      if (mp[addnum] != 0)
      {
        st.erase({addnum, addlastcnt});
      }

      // 加入修改后的数
      st.insert({addnum, addlastcnt + 1});

      // 减一的数
      int eranum = arr[j].first - 1;

      // 他原来的cnt
      int eralastcnt = mp[eranum];
      if (mp[eranum] != 0)
      {
        st.erase({eranum, eralastcnt});
      }

      // 加入修改后的数
      st.insert({eranum, eralastcnt + 1});

      // 统计
      all.insert(st.rbegin()->first);

      // 复原
      st.erase({addnum, addlastcnt + 1});
      st.erase({eranum, eralastcnt + 1});

      st.insert({eranum, eralastcnt});
      st.insert({addnum, addlastcnt});

      st.erase({arr[i].first, arr[i].second - 1});
      st.erase({arr[j].first, arr[j].second - 1});
      st.insert(arr[i]);
      st.insert(arr[j]);
    }
  }
  for (auto i : all)
  {
    cout << i << " ";
  }
}