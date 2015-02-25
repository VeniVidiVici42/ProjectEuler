/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <bits/stdc++.h>
#define MAXN 28123
using namespace std;

int d[MAXN];
vector<int> abun;
bool poss[MAXN];

int sum_of_divisors(int n, int min_poss_div){
  /*
   * n=p_1^e_1*p_2^e^2*...*p_k^e_k
   * d(n)=(1+p_1+p_1^2+...+p_1^e_1)(1+p_2+p_2^2+...+p_2^e_2)...(1+p_k+p_k^2+...+p_k^e_k)
   */
   
  int anchor=n;
  
  if(n==1){
  	//sum of 1 is 1
  	return 1;
  }
  
  if(d[n]>0){
  	//already calculated
  	return d[n];
  }
  
  int mult, to_add;
  
  for(int i=min_poss_div; i*i<=n; i++){
  	//find smallest prime divisor
  	mult=1, to_add=1;
    while(n%i==0){
      //clear smallest prime divisor
      n=n/i;
      to_add*=i;
      mult+=to_add;
    }
    return d[anchor]=mult*sum_of_divisors(n,i+1);
  }
  
  //if we get here then n is prime
  return d[n]=n+1;
}

int main() {
  int ans=0;	
  
  for(int i=1; i<MAXN; i++){
  	d[i]=sum_of_divisors(i,2);
  	if(d[i]>2*i){
  	  abun.push_back(i);
  	}
  }
  
  for(int i=0; i<abun.size(); i++){
  	for(int j=i; j<abun.size(); j++){
  	  if(abun[i]+abun[j]<MAXN){
  	  	poss[abun[i]+abun[j]]=true;
  	  }
  	}
  }
  
  for(int i=0; i<MAXN; i++){
  	if(!poss[i]){
  	  ans+=i;	
  	}
  }
  
  cout << ans << endl;
}
