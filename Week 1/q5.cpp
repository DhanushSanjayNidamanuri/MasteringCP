 #include <bits/stdc++.h>
 using namespace std;
 int main() {
 // solution comes here
 ios::sync_with_stdio(0);
 cin.tie(0);
 int testcases;
 cin>>testcases;
 for(int i=0;i<testcases;i++){
   long long n,k;
   cin>>n;
   cin>>k;
   long long num=0;
   map<int,int> arr;
   for(int i=0;i<n;i++){
     long long x;
     cin>>x;
     x%=k;
     if(x!=0){
       arr[x]++;
       num++;
      }
    }
    if(num==0){cout<<"0\n";}
    else{
        long long maxhi=0;
        long long min=k-1;
        for(auto x:arr){
            if(x.second>maxhi){
                maxhi=x.second;
                min=x.first;
            }
        }
    long long out=(k*(maxhi-1)+1+(k-min));
        cout<<out<<"\n";
        
    };
 }
 }