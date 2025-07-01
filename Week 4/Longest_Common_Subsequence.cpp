#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0);
void compute(int i,int j,vector<vector<int>>& ans,vector<int> & arr1,vector<int> & arr2){
    if(arr1[i]==arr2[j])ans[i][j]=ans[i-1][j-1]+1;
    else ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
    return;
}

int32_t main() {
    FAST
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    vector<vector<int>> ans(n,vector<int>(m));
    for(int i=0;i<n;i++)cin>>arr1[i];
    for(int i=0;i<m;i++)cin>>arr2[i];
    if(arr1[0]==arr2[0])ans[0][0]=1;
    else ans[0][0]=0;
    for(int j=1;j<m;j++){
        if(arr1[0]==arr2[j]){ans[0][j]=1;while(j<m){ans[0][j]=1;j++;};break;}
        else ans[0][j]=0;
    }
    for(int i=0;i<n;i++){
        if(arr1[i]==arr2[0]){ans[i][0]=1;while(i<n){ans[i][0]=1;i++;}break;}
        else ans[i][0]=0;
    }
    if(!ans[n-1][0] && !ans[0][m-1])cout<<0;
    else{
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                compute(i,j,ans,arr1,arr2);
            }
        }
        cout<<ans[n-1][m-1]<<"\n";
        int i=n-1,j=m-1;
        int ansi=ans[n-1][m-1];
        vector<int> lcs(ansi);
     
        ansi--;
        while(i>=0 && j>=0) {
            if(arr1[i]==arr2[j]) {
                lcs[ansi--]=arr1[i];
                i--;
                j--;
            } else if(j>0 && (i==0 || ans[i][j-1]>ans[i-1][j])) {
                j--;
            } else {
                i--;
            }
        }
        for (int x : lcs) cout << x << " ";
    }

}
