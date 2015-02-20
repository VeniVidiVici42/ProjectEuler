/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <bits/stdc++.h>
using namespace std;

map<long long, int> dp;

int length(long long n){
	
  if(n==1){
  	return dp[1]=1;
  }
	
  if(dp[n]!=0){
  	return dp[n];
  }
  
  if(n%2==0){
  	return dp[n]=1+length(n/2);
  }

  return dp[n]=1+length(3*n+1);
}

int main() {
  int maxlength=0, maxidx;
  
  for(int i=1; i<1000000; i++){
    if(length(i)>maxlength){
      maxlength=dp[i];
      maxidx=i;
    }
  }
  
  cout << maxidx << endl;
}
