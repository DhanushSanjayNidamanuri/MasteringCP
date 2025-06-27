 #include <bits/stdc++.h>
 using namespace std;
 int main() {
 // solution comes here
 ios::sync_with_stdio(0);
 cin.tie(0);
 int testcases;
 cin>>testcases;
 for(int i=0;i<testcases;i++){
   int n,k;
   cin>>n;
   cin>>k;
   vector<int> a(n);
   vector<int> b(n);
   int sum=0;
   for(int i=0;i<n;i++){
       cin>>a[i];
       sum+=a[i];
   }
    for(int i=0;i<n;i++){
       cin>>b[i];
   }
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   for(int i=0;i<k;i++){
       if(a[i]<b[n-1-i]){
           sum+=(b[n-1-i]-a[i]);
       }
   };
   cout<<sum<<"\n";
 }
 }