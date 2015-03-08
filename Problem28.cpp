/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include <bits/stdc++.h>
using namespace std;

int nums[1001][1001];
int k=1; //number we're placing
int dir=0;
int x[]={0,1,0,-1}, y[]={1,0,-1,0}, i=500, j=500; //where we will place next number

void spiral(){
  if(i==-1 || i==1001 || j==-1 || j==1001){
  	return;
  }
  nums[i][j]=k;
  i+=x[(dir+1)%4]; //update to next position
  j+=y[(dir+1)%4];
  if(nums[i][j]){ //position already occupied, go straight instead
  	i-=x[(dir+1)%4];
  	j-=y[(dir+1)%4];
  	i+=x[dir];
  	j+=y[dir];
  }
  else{ //update direction
  	dir++;
  	dir%=4;
  }
  k++;
  spiral();
}
  

int main() {
  spiral();
  int sum=0;
  
  for(int i=0; i<=1000; i++){
  	sum+=nums[i][i]; 
  	sum+=nums[i][1000-i];
  }
  sum-=nums[500][500]; //don't overcount center
  
  cout << sum << endl;
}
