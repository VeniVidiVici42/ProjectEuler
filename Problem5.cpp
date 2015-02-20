/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <bits/stdc++.h>
using namespace std;

int primes[20];
int prime_list[]={2,3,5,7,11,13,17,19};
int primenum=8;

int v_p(int p, int n){
  int ret=0;
  
  while(n%p==0){
  	ret++;
  	n=n/p;
  }
  
  return ret;
}

int main() {
  for(int i=2; i<20; i++){
  	for(int j=0; j<primenum; j++){
  	  primes[prime_list[j]]=max(primes[prime_list[j]], v_p(prime_list[j], i));	
  	}
  }
  
  long long ans=1;
  
  for(int i=0; i<primenum; i++){
  	for(int j=0; j<primes[prime_list[i]]; j++){
  	  ans*=prime_list[i];
  	}
  }
  
  cout << ans << endl;
}
