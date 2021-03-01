// Problem link : https://codeforces.com/contest/1492/problem/D

#include<bits/stdc++.h>
using namespace std;
#define loi long long
#define lod long double
#define doubel double
#define pb push_back
#define run ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
#define lim 5000000000000000000
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
#define mxn 2000001

int main()
{
  loi t = 1;
  // cin >> t;
  while(t--)
  {
    loi a, b, k, prev, temp, cap;
    cin >> a >> b >> k;

    prev = a + b - 2;
    cap = prev;
    prev++;

    temp = a;


    if(b == 1 or !a)
    {
      if(k == 0)
      {
        cout << "Yes\n";
        rep(i, b) cout << "1";
        rep(i, a) cout << "0";
        cout << "\n";

        rep(i, b) cout << "1";
        rep(i, a) cout << "0";
        cout << "\n";
      }

      else cout << "No\n";
      continue;
    }

    if(a + b - 2 < k) {cout << "No\n";
    continue;}

    cout << "YES\n";


        string x = "", y = "";
        rep(i, b) x += "1";
        rep(i, a) x += "0";

        if(!k)
        {
          cout << x << "\n";
          cout << x << "\n";
          continue;
        }

        b--;
        y += "1";
        a--;
        y += "0";

        rep3(i, 2, x.size() - 2) y += x[i];
        y += "1";

        // cout << "currently y : " << y << "\n";
        // cap++;
        while(cap != k)
        {
          cap--;
          swap(y[prev], y[prev - 1]);
          swap(x[prev], x[prev - 1]);
          prev--;

          // cout << "now :\n";
          // cout << "cap : " << cap << " prev : " << prev << "\n";
          // cout << x << "\n";
          // cout << y << "\n";
        }

        cout << x << "\n";
        cout << y << "\n";
  }
  return 0;
}
