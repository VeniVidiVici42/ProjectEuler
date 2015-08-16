/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#include<bits/stdc++.h>
using namespace std;

/*
 * Suppose we have (a-digit number)*(b-digit number)=(c-digit number)
 * Then c=a+b-1 or a+b
 * Since a+b+c=9 (there are nine digits), must have c=a+b-1 and thus a+b=5 -> c=4
 * i.e. the product is a 4-digit number, and the multipliers are both at most 4 digits
 */
 
bool is_pandig_prod[10000];

bool pandig(int a, int b, int c){
  // Checks if {a,b,c} form a 9-digit pandigital
  int digits[9], idx=0;
  
  while(a>0){ //add digits of a to the list
  	digits[idx]=a%10;
  	a=a/10;
  	idx++;
  }
  
  while(b>0){ //add digits of b to the list
  	digits[idx]=b%10;
  	b=b/10;
  	idx++;
  }
  
  while(c>0){ //add digits of c to the list
  	digits[idx]=c%10;
  	c=c/10;
  	idx++;
  }
  
  if(idx!=9){ //not enough digits
  	return false;
  }
  
  sort(digits, digits+9); //sort list; pandigital will have digits={1,2,3,4,5,6,7,8,9}
  
  for(int i=0; i<9; i++){
  	if(digits[i]!=i+1){ //not pandigital
  	  return false;
  	}
  }
  
  return true;
}

int main(){
  
  // WLOG assume b>=a; i.e. a<=2; i.e. mult1 has at most 2 digits, mult2 has at least 3
  
  int mult1, mult2, prod;
  
  for(mult1=1; mult1<100; mult1++){
  	for(mult2=100; mult2<10000; mult2++){
  	  prod=mult1*mult2;
  	  if(pandig(mult1, mult2, prod)){
  	  	//cout << mult1 << "*" << mult2 << "=" << prod << endl;
  	  	is_pandig_prod[prod]=true;
  	  }
  	}
  }
  
  int sum=0;
  
  for(prod=1000; prod<10000; prod++){
  	if(is_pandig_prod[prod]){
  	  sum+=prod;
  	}
  }
  
  cout << sum << endl;
}
