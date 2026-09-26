// ========================================================
// 1. RECURSION + MEMOIZATION (Top-Down Approach)
// ========================================================
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int vacbhai(int N , int last , vector<vector<int>>&arr , vector<vector<int>>&dp){
  if(N == 0){
    int maxi = -1e9;
    for(int i = 0 ; i < 3 ; i++){
      if(last != i){
        maxi = max(maxi,arr[0][i]);
      }
    }
    return maxi;
  }
  if(dp[N][last] != -1) return dp[N][last];
  int maxi = -1e9;
  for(int task = 0 ; task < 3 ; task++){
    if(task != last){
      int point = arr[N][task] + vacbhai(N - 1 , task , arr , dp);
      maxi = max(maxi , point);
    }
  }
  return dp[N][last] = maxi;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  vector<vector<int>>arr(N,vector<int>(3));
  for(int i = 0 ;  i < N ; i++){
    for(int j = 0 ; j < 3 ; j++){
      cin >> arr[i][j];
    }
  }
  vector<vector<int>>dp(N,vector<int>(4,-1));
  cout << vacbhai(N - 1 , 3 , arr , dp);
}


// ========================================================
// 2. TABULATION (Bottom-Up Approach)
// ========================================================
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>>arr(n,vector<int>(3));
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < 3 ; j++){
      cin >> arr[i][j];
    }
  }
  vector<vector<int>>dp(n,vector<int>(4,0));
  dp[0][0] = max(arr[0][1],arr[0][2]);
  dp[0][1] = max(arr[0][0],arr[0][2]);
  dp[0][2] = max(arr[0][0],arr[0][1]);
  dp[0][3] = max({arr[0][0] , arr[0][1] , arr[0][2]});
  for(int day = 1 ; day < n ; day++){
    for(int last = 0 ; last < 4 ; last++){
      for(int task = 0 ; task < 3 ; task++){
        if(task != last){
          int point = arr[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last] , point);
        }
      }
    }
  }
  cout << dp[n-1][3];
}


// ========================================================
// 3. SPACE OPTIMIZATION
// ========================================================
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>>arr(n,vector<int>(3));
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < 3 ; j++){
      cin >> arr[i][j];
    }
  }
  vector<int>prev(4,0);
  prev[0] = max(arr[0][1],arr[0][2]);
  prev[1] = max(arr[0][0],arr[0][2]);
  prev[2] = max(arr[0][0],arr[0][1]);
  prev[3] = max({arr[0][0] , arr[0][1] , arr[0][2]});
  for(int day = 1 ; day < n ; day++){
    vector<int>temp(4,0);
    for(int last = 0 ; last < 4 ; last++){
      for(int task = 0 ; task < 3 ; task++){
        if(task != last){
          int point = arr[day][task] + prev[task];
          temp[last] = max(temp[last] , point);
        }
      }
    }
    prev = temp;
  }
  cout << prev[3];
}
