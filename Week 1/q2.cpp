 #include <bits/stdc++.h>
 using namespace std;

 int main() {
  ios::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin>>n;
 int sum=0;
 vector<int> coins;
 for(int i=0;i<n;i++){
     int x;
     cin>>x;
     coins.push_back(x);
     sum+=x;
 }
 sort(coins.begin(),coins.end());
 int su=0;
 int co=0;
 for(int i=coins.size()-1;su<=sum/2;i--){
     su+=coins[i];
     co++;
 };
 cout<<co;
 }