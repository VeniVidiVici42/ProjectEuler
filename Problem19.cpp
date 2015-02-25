/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <bits/stdc++.h>
using namespace std;

int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
  int month=1, day=1, year=1900, c=1, ans=0; // 1/1/1900=Monday
  
  while(year<=2000){
  	//increment the day
  	day++;
  	c++;
  	c=c%7;
  	
  	if(day>months[month-1]){
  	  if(day==29 && month==2 && year%4==0 && year!=1900){
  	  	//leap year
  	  	continue;
  	  }
  	  else{
  	  	//time for next month
  	  	month++;
  	  	if(month==13){
  	  	  //time for next year
  	  	  month=1;
  	  	  year++;
  	  	}
  	  	day=1;
  	  	if(c==0 && year>=1901 && year<=2000){
  	  	  //first of month + sunday
  	  	  ans++;
  	  	}
  	  }
  	}
  }
  
  cout << ans << endl;
}
