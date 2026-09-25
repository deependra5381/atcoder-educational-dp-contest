// ========================================================
// 1. RECURSION + MEMOIZATION (Top-Down Approach)
// ======================================================== 
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int frog2bhai(int n , vector<int>&arr , vector<int>&dp , int k){
  if(n == 0) return 0;
  if(dp[n] != -1) return dp[n];
  int mini = INT_MAX;
  for(int i = 1 ; i <= k && i <= n; i++){
    int step = frog2bhai(n - i , arr , dp , k) + abs(arr[n] - arr[n - i]);
    mini = min(mini , step);
  }
  return dp[n] = mini;
}
int main(){
  int N , K;
  cin >> N >> K;
  vector<int>arr(N);
  for(int i = 0 ; i < N ; i++){
    cin >> arr[i];
  }
  vector<int>dp(N,-1);
  cout << frog2bhai(N - 1,arr,dp,K) << endl;
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
  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  for(int i = 0; i < N; i++) cin >> arr[i];
  vector<int> dp(N, INT_MAX);
  dp[0] = 0;
  int mini = INT_MAX;
  for(int i = 1 ; i < N ; i++){
    for(int j = 1 ; j <= K && j <= i; j++){
      int step = dp[i - j] + abs(arr[i] - arr[i - j]);
      dp[i] = min(dp[i] , step);
    }
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
  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  for(int i = 0; i < N; i++) cin >> arr[i];
  vector<int> window(K, 0);   
  window[0 % K] = 0;          
  int lastVal = 0;          
  for(int i = 1; i < N; i++){
    int curr = INT_MAX;
    for(int j = 1; j <= K && j <= i; j++){
      int prevVal = window[(i - j) % K];    
      int step = prevVal + abs(arr[i] - arr[i - j]);
      curr = min(curr, step);
    }
  window[i % K] = curr;
  }
  cout << window[(N - 1) % K];
}
