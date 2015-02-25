/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#include <bits/stdc++.h>
using namespace std;

int d[10000];

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

  for(int i=1; i<10000; i++){
  	d[i]=sum_of_divisors(i, 2);
  }
  
  for(int i=1; i<10000; i++){
  	//only want proper divisors
  	d[i]-=i;
  }
  
  for(int i=1; i<10000; i++){
  	if(i<=d[i]){
      //don't overcount and don't count perfect numbers
  	  continue;
  	}
  	if(d[i]<10000 && d[d[i]]==i){
  	  ans+=i+d[i];
  	}
  }
  
  cout << ans << endl;
}
