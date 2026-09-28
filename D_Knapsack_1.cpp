// ========================================================
// 1. RECURSION + MEMOIZATION (Top-Down Approach)
// ========================================================
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
typedef long long ll;
using namespace std;
ll f(ll ind , ll W , vector<ll>&wt , vector<ll>&val , vector<vector<ll>>&dp){
  if(ind == 0){
    if(wt[0] <= W) return val[0];
    return 0;
  }
  if(dp[ind][W]  != -1) return dp[ind][W];
  ll notake = f(ind - 1 , W , wt , val , dp);
  ll take = LLONG_MIN;
  if(wt[ind] <= W){
    take = val[ind] + f(ind - 1 , W - wt[ind] , wt , val , dp);
  }
  return dp[ind][W] = max(take , notake);
}
int main(){
  ll n , W;
  cin >> n >> W;
  vector<ll>wt(n);
  vector<ll>val(n);
  for(ll i = 0 ; i < n ; i++){
    cin >> wt[i] >> val[i];
  }
  vector<vector<ll>>dp(n,vector<ll>(W + 1 , -1));
  cout << f(n - 1 , W , wt , val , dp);
}


// ========================================================
// 2. TABULATION (Bottom-Up Approach)
// ========================================================
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
typedef long long ll;
using namespace std;
int main(){
  ll n , W;
  cin >> n >> W;
  vector<ll>wt(n);
  vector<ll>val(n);
  for(ll i = 0 ; i < n ; i++){
    cin >> wt[i] >> val[i];
  }
  vector<vector<ll>>dp(n,vector<ll>(W + 1 , 0));
  for(ll ind = wt[0] ; ind <= W ; ind++){
    dp[0][ind] = val[0];
  }
  for(ll ind = 1 ; ind < n ; ind++){
    for(ll w = 0 ; w <= W ; w++){
      ll notake = dp[ind - 1][w];
      ll take = LLONG_MIN;
      if(wt[ind] <= w){
        take = val[ind] + dp[ind - 1][w - wt[ind]];
      }
      dp[ind][w] = max(take , notake);
    }
  }
  cout << dp[n-1][W];
}


// ========================================================
// 3. SPACE OPTIMIZATION
// ========================================================
// यहाँ अपना Frog 2 का Space Optimization वाला और main() कोड पेस्ट करें
