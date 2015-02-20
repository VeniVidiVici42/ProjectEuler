/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <bits/stdc++.h>
using namespace std;

bool is_prime[1000000]={true};

int main() {
  int count=0;
  
  for(int i=0; i<1000000; i++){
  	is_prime[i]=true;
  }
  
  for(int i=2; i<1000000; i++){
    if(is_prime[i]){
      count++;
      
      if(count==10001){
      	cout << i << endl;
      	break;
      }
      
      if(i<1000){
      	for(int j=2*i; j<1000000; j+=i){
      	  is_prime[j]=false;
      	}
      }
    }	
  }
}
