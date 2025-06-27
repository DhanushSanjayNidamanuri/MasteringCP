 #include <bits/stdc++.h>
 using namespace std;
 int main() {
 // solution comes here
 ios::sync_with_stdio(0);
 cin.tie(0);
int n;
cin>>n;
int cols[n];
int maxcol=0;
for(int i=0;i<n;i++){
  int x;
  cin>>x;
  cols[i]=x;
  if(x>maxcol)maxcol=x;
}
int rows[maxcol];
int maxrow=0;
for(int i=1;i<=maxcol;i++){
  int t=0;
  for(auto x:cols){
    if(x>=i)t++;}
  rows[i-1]=t;
  if(t>maxrow)maxrow=t;
}
for(int i=maxrow;i>=1;i--){
  int k=0;
  for(auto x:rows){
    if(x>=i)k++;
  }
  cout<<k<<" ";
}
 }