#include <bits/stdc++.h>
 using namespace std;
 int main() {
 ios::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin>>n;
 vector<long long> arr(n);
 long long sum,minsum,maxdiff,max,maxsum,globalmax;
 long long temp=0;
 cin>>arr[0];
 sum=arr[0];
 maxdiff=sum;
 minsum=sum;
 maxsum=sum;
 max=sum;
 globalmax=sum;
 for(int i=1;i<n;i++){
    cin>>temp;
    sum+=temp;
    arr[i]=sum;
    if(temp>max)max=temp;
    if(sum>globalmax)globalmax=sum;
    if(sum<minsum){minsum=sum;maxsum=minsum;}
    else if(sum>maxsum){maxsum=sum;
    if(maxsum-minsum>maxdiff){maxdiff=maxsum-minsum;};}; 
 }
 vector<long long> a(3);
 a[0]=max;
 a[1]=globalmax;
 a[2]=maxdiff;
 sort(a.begin(),a.end());
 cout<<a[2];
 }