/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <bits/stdc++.h>
using namespace std;

// log_10(100!)<log_10(100^100)=100log_10(100)=200
// ==> at most 200 digits

int bignum[200];

void multiply(int n){
	
  for(int i=0; i<200; i++){
  	bignum[i]*=n;
  }
  
  for(int i=199; i>=0; i--){
  	if(bignum[i]>9){
  	  bignum[i-1]+=bignum[i]/10;
  	  bignum[i]%=10;
  	}
  }
  
}

int main() {
  bignum[199]=1;
  
  for(int i=2; i<=100; i++){
  	multiply(i);
  }
  
  int sum=0;
  
  for(int i=0; i<200; i++){
  	sum+=bignum[i];
  }
  
  cout << sum << endl;
}
