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
 
//Problem Link : https://www.codechef.com/problems/NCL1706

/**Unlike many other solutions, this solution finds optimal values of x, y, and z in O(1)
 *printing takes O(n) time
 *Author : stunner2k18
 *Pre-requisites -> Diophantine equation and other Number Theory Concepts
**/

/**
 * My approach -> The required equation will be 15x + 10y + 6z = n
 * We need to find a pair of triplet(x, y, z) such that the number formed by concatenating 15x times 2,
 * 10y times 3 and 6z times 5 is maximum possible in reverse order
 * 
 * for example is n = 16 then answer will be 5555553333333333
 * similarly for n = 6 answer is 555555
 * 
 * Well, we can break the above equation into 2 diophantine equations 
 * let t = 3x + 2y --------- (1)
 * then tranformed equation will be 5t + 6z = n
 * Using Extended Euclids Algorithm we can find t0 and z0 which will be used to find the kth root such that zk >= 0 and tk should be such that- 
 * there should exist mth root of equation (1) if we replace t with tk
 * 
 * using these 2 equations we find the upper and lower bound of K
 * let the range of valid/acceptable value of K be [L, R]
 * 
 * greedily to make the largest number possible(as asked in question), we should first try to maximise the count of 5 then count of 3 and at last-
 * count of 2
 * 
 * so if we formulate the equation of the kth root of z then the equation will come out to be 
 * zk = n - 5k, which is a decreasing function w.r.t k therefore out optimal strategy is to choose 'k' as the lower bound of the range-
 * since then the count of 5 will be maximum possible
 * 
 * PS -> There is a corner case in finding the value of optimal 'k', this thinking is left for the user as an exercise.
 * 
 * Time Complexity -> O(n) -> Because we have to print the whole string otherwise the optimal answer can be found in O(1) time
 * Space Complexity -> O(1)
 * 
 **/

//z -> cnt of 5
//y -> cnt of 3
//x -> cnt of 2

int main()
{
  run;
  loi t;
  cin >> t;
  while(t--)
  {
     loi n;
     cin >> n;
     
     loi l = ceil(n / 6.00);
     loi r = floor(n / 5.00);

     if(l > r)
       cout << "-1\n";
     else
     {
       loi cntz = n - (5 * l);
       loi tk = (6 * l) - n;
       
       if(tk == 1)
       {
         tk = 7;
         if(l + 1 > r) {cout << "-1\n";
         continue;}

         l++;
         cntz = n - (5 * l);
       }

       l = ceil((-1 * tk) / 2.00);
       r = floor((-1 * tk) / 3.00);

       if(l > r)
       {
         cout << "-1\n";
         continue;
       }

       loi cnty = -1 * (tk + (3 * l));
       loi cntx = tk + (2 * l);

       cntz *= 6, cnty *= 10, cntx *= 15;

       rep(i, cntz) cout << "5";
       rep(i, cnty) cout << "3";
       rep(i, cntx) cout << "2";
       cout << "\n";
     }
  }
  return 0;
}
