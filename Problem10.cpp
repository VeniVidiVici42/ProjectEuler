/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=2000000;
bool is_prime[MAXN];

int main() {
	
  long long sum=0;
  
  for(int i=0; i<MAXN; i++){
    is_prime[i]=true;
  }
  
  for(int i=2; i<MAXN; i++){
  	if(is_prime[i]){
  	  sum+=i;
  	  if(i*i<MAXN){
  	    for(int j=2*i; j<MAXN; j+=i){
  	   	  is_prime[j]=false;
  	    }
  	  }  
  	}
  }
  
  cout << sum << endl;
}
