#include <bits/stdc++.h>
 using namespace std;
 int main() {
 ios::sync_with_stdio(0);
 cin.tie(0);
 long long n,m,k;
 cin>>n>>m>>k;
 vector<long long> app(n);
 vector<long long> apa(m);
 for(int i=0;i<n;i++){
    cin>>app[i];
 };
 for(int i=0;i<m;i++){
    cin>>apa[i];
 };
 sort(app.begin(),app.end());
 sort(apa.begin(),apa.end());
 long long num=0;
 int i=0,j=0;
 for(;i<n&&j<m;){
    long long diff=app[i]-apa[j];
    if(diff<=k && diff>=-k){num++;j++,i++;}
    else if(diff>k){j++;}
    else{i++;};
 }
 cout<<num;
 }