/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.

#include <bits/stdc++.h>
using namespace std;

int fact[10];

int fact_sum_of_dig(int n){
  int sum=0;
  
  while(n>0){
    sum+=fact[n%10];
    n=n/10;
  }
  
  return sum;
}

int main(){
  
  /* Suppose such a number n has k>=2 digits, and let f(n) be the sum of the factorials of its digits
   * Then n>=10^(k-1), f(n)<=9!*k; as n=f(n) we have 10^(k-1)<=9!*k, implying k<=7
   * If k=7, then max f(n) is 9!*7=2540160, so first digit is at most 2; max f(n) is then actually 
   * 2!+9!*6, which isn't 7 digits, so k!=7
   */
   
  fact[0]=1;
  for(int i=1; i<10; i++){
  	fact[i]=i*fact[i-1];
  }
   
  int sum=0;
   
  for(int n=10; n<1000000; n++){
    if(n==fact_sum_of_dig(n)){
      sum+=n;  
    }
  }
  
  cout << sum << endl;
}
