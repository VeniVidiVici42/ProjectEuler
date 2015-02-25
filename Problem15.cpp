/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

#include <bits/stdc++.h>
using namespace std;

long long dp[21][21];

int main() {
	
  for(int i=0; i<=20; i++){
  	dp[i][0]=dp[0][i]=1;
  }
  
  for(int i=1; i<=20; i++){
  	for(int j=i; j<=20; j++){
  	  dp[i][j]=dp[j][i]=dp[i-1][j]+dp[i][j-1];
  	}
  }
  
  cout << dp[20][20] << endl;
}
