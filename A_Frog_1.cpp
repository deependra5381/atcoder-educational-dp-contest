// ========================================================
// 1. RECURSION + MEMOIZATION (Top-Down Approach)
// ========================================================
#include<iostream> 
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int frogbhai(int n , vector<int>&arr , vector<int>&dp){
  if(n == 0) return 0;
  if(dp[n] != -1) return dp[n];
  int onestep = frogbhai(n - 1, arr , dp) + abs(arr[n] - arr[n-1]);
  int twostep = (n >= 2) ? frogbhai(n - 2, arr , dp) + abs(arr[n] - arr[n-2]) : INT_MAX;
  int mini = min(onestep , twostep);
  return dp[n] = mini;
}
int main(){
  int N;
  cin >> N;
  vector<int>arr(N);
  for(int i = 0 ; i < N ; i++){
    cin >> arr[i];
  }
  vector<int>dp(N+1,-1);
  cout << frogbhai(N - 1,arr,dp);
}


// ========================================================
// 2. TABULATION (Bottom-Up Approach)
// ========================================================
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int>arr(N);
  for(int i = 0 ; i < N ; i++){
    cin >> arr[i];
  }
  vector<int>dp(N,0);
  dp[0] = 0;
  for(int i = 1 ; i < N ; i++){
    int onestep = dp[i - 1] + abs(arr[i] - arr[i - 1]);
    int twostep = INT_MAX;
    if(i >= 2){
      twostep = dp[i - 2] + abs(arr[i] - arr[i - 2]);
    }
    dp[i] = min(onestep,twostep);
  }
  cout << dp[N-1];
}


// ========================================================
// 3. SPACE OPTIMIZATION
// ========================================================
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int>arr(N);
  for(int i = 0 ; i < N ; i++){
    cin >> arr[i];
  }
  int prev1 = 0;
  int prev2 = 0;
  for(int i = 1 ; i < N ; i++){
    int onestep = prev1 + abs(arr[i] - arr[i - 1]);
    int twostep = INT_MAX;
    if(i >= 2){
      twostep = prev2 + abs(arr[i] - arr[i - 2]);
    }
    int curr = min(onestep,twostep);
    prev2 = prev1;
    prev1 = curr;
  }
  cout << prev1;
}
