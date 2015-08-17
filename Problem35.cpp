/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/

#include <bits/stdc++.h>
using namespace std;

bool isprime[1000000];

bool circ_prime(int n){
  // Checks if each cycle of the digits of n is prime
  int copy=n, k=(int)(log(n)/log(10));
  
  do{
    
    if(!isprime[n]){
      return false;
    }
    n=(n%10)*pow(10,k)+n/10;
    
  }while(n!=copy);
  
  return true;
}

void sieve(){
  // Initializes the isprime array using a sieve
  for(int i=0; i<1000000; i++){
    isprime[i]=true;
  }
  
  isprime[1]=false;
  
  for(int i=2; i<1000; i++){
  	if(isprime[i]){
  	  for(int j=2*i; j<1000000; j+=i){
  	  	isprime[j]=false;
  	  }
  	}
  }
  
}

int main(){
  int ans=0;
  sieve();
  
  for(int i=2; i<1000000; i++){
    if(circ_prime(i)){
      ans++;	
    }
  }
  
  cout << ans << endl;
}
