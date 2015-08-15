/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/

#include <bits/stdc++.h>
using namespace std;

int currencies[8]={1,2,5,10,20,50,100,200};
int dp[250][8];

int main() {
  
  // dp[i][j] counts the number of ways to form i without using any of the first j denominations
  // We're looking for dp[200][0]
  
  for(int i=0; i<8; i++){
    dp[0][i]=1;
  }
  
  for(int i=1; i<250; i++){
    for(int j=7; j>=0; j--){
      //decide whether to use a coin of the jth denomination
      if(j<7){
        dp[i][j]+=dp[i][j+1]; //nope, don't use any more currency[j] coins
      }
      if(i>=currencies[j]){
        dp[i][j]+=dp[i-currencies[j]][j]; //yep, add a currency[j] coin
      }
    }
  }
  
  cout << dp[200][0] << endl;
}
