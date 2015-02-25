/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include <bits/stdc++.h>
using namespace std;

int order(int n, int mod){
  int ret=1, base=n%mod;
  
  while(base%mod!=1){
  	ret++;
  	base*=n;
  	base%=mod;
  }
  
  return ret;
}

int main() {
  int maxorder=0, maxidx;
  
  for(int i=2; i<1000; i++){
  	if(i%2==0 || i%5==0){
  	  //2s and 5s are irrelevant because they just add some non-repeating digits
  	  continue;
  	  //we've already seen this (at i/2 or i/5)
  	}
  	else{
  	  // length of repeating part is minimum n such that 10^n*(1/i)-(1/i) is an integer
  	  // i.e. (10^n-1) is divisible by i
  	  // i.e. 10^n=1 mod i
  	  if(order(10,i)>maxorder){
  	  	maxorder=order(10,i);
  	  	maxidx=i;
  	  }
  	}
  }
  
  cout << maxidx << endl;
}
