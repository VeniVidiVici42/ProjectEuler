/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <bits/stdc++.h>
using namespace std;

long long N=600851475143;

int largest_prime_factor(long long n, int min_poss_factor){
  for(int i=min_poss_factor; i*i<=n; i++){
  	while(n%i==0){
  	  n=n/i;
  	}
  	return largest_prime_factor(n,i+1);
  }
  return n;
}

int main() {
  cout << largest_prime_factor(N,2) << endl;
}
