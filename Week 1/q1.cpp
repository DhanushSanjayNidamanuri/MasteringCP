 #include <bits/stdc++.h>
 using namespace std;
 int main() {
 // solution comes here
 ios::sync_with_stdio(0);
 cin.tie(0);
 int testcases;
 cin>>testcases;
 for(int i=0;i<testcases;i++){
     int n;
     cin>>n;
     int t=n;
     int no_of_digits=1;
     while(n>=10){
         n/=10;
         no_of_digits++;
     }
     int ans=9*(no_of_digits-1);
     int extra=0;
      for(int i=1;i<=9;i++){
          int num=0;
          for(int j=0;j<no_of_digits;j++){
              num=(num*10)+i;
          }
          if(num>t){
              break;
          }
          extra++;
      }
      cout<<(ans+extra)<<"\n";
 }
 }