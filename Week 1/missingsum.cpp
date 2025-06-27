#include <bits/stdc++.h>
 using namespace std;
 int main() {
 ios::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin>>n;
 vector<long long> arr(n);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 sort(arr.begin(),arr.end());
 long long sum=0;
 bool found=false;
 for(int i=0;i<n;i++){
    if(arr[i]>sum+1){
        cout<<(sum+1);found=true;break;
    }
    else{
        sum+=arr[i];
    };

 }
 if(!found){cout<<sum+1;};
 }