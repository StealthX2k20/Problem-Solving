#include<bits/stdc++.h>
using namespace std;
#define loi long long
#define lod long double
#define doubel double
#define pb push_back
#define run ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lim 5000000001
#define in(ar, n) for(loi i = 0; i < n; i++) cin >> ar[i];
#define out(ar, n) for (loi i = 0; i < n; i++) cout << ar[i] << " "; cout << "\n";
#define rep(i, n) for(loi i = 0; i < n; i++)
#define rep1(i, n) for(loi i = 1; i <= n; i++)
#define rev(i, n) for(loi i = n - 1; ~i; i--)
#define rep3(i, l, r) for(loi i = l; i <= r; i++)
#define rev3(i, r, l) for(loi i = r; i >= l; i--)
#define rep4(i, r, l) for(loi i = r; i >= l; i--)
#define all(x) x.begin(), x.end ()
#define mkp make_pair
#define vii vector<loi>
#define mii map<loi, loi>
#define sii set<loi>
#define pii pair<loi, loi>
#define mxdepth 23 // FOR LCA til N = 1e6
#define mxn 1000005

loi dijkstra(sii graph[], loi src, loi sink)
{
  mii dist;
  dist[src] = 0;

  set <pii> st;
  st.insert({0ll, src});
  pii vert;

  while(st.size())
  {
    vert = *(st.begin());

    st.erase(st.begin());

    for(loi adj : graph[vert.second])
    {
      if(dist.find(adj) == dist.end())
      {
        dist[adj] = vert.first + 1ll;
        st.insert({dist[adj], adj});
      }

      else if(dist[adj] > vert.first + 1ll)
      {

        if(st.find({dist[adj], adj}) !=  st.end())
        st.erase(st.find({dist[adj], adj}));
        dist[adj] = vert.first + 1ll;
        st.insert({dist[adj], adj});
      }
    }
  }

  if(dist.find(sink) == dist.end()) return 100ll;
  else return dist[sink];
}

int main()
{
  loi t = 1;
  while(t--)
  {
    loi n;
    cin >> n;
    loi ar[n];
    in(ar, n);


    loi mat[62];
    memset(mat, 0, sizeof(mat));

    loi flg = 0;
    rep(i, n)
    {
      rep(j, 61)
      {
        if(ar[i] & (1ll << j)) mat[j]++;
        if(mat[j] > 2) flg = 1;
      }
    }

    if(flg) cout << "3\n";
    
    else
    {
      map<loi, vii> mp;
      sii graph[n], graph1[n];


      rep(i, n)
      {
        rep(j, 61)
        {
          if(ar[i] & (1ll << j))
          {
            if(mp[j].size() != 0)
            {
              graph[i].insert(mp[j][0]);
              graph[mp[j][0]].insert(i);

              graph1[i].insert(mp[j][0]);
              graph1[mp[j][0]].insert(i);
            }
            mp[j].pb(i);
          }
        }
      }

      loi cur;
      loi res = 100;

      rep(i, n)
      {
        for(loi adj : graph1[i])
        {
          cur = adj;
          graph[i].erase(graph[i].find(cur));
          graph[cur].erase(graph[cur].find(i));

          res = min(res, dijkstra(graph, i, cur) + 1ll);
          
          graph[i].insert(cur);
          graph[cur].insert(i);
        }
      }

      if(res > 99) res = -1;
      cout << res << "\n";

    }
  }
  return 0;
}
