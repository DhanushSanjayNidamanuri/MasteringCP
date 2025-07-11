#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define int long long

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define sz(x) (int)(x).size()
#define F first
#define S second

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = b-1; i >= a; --i)

using vi = vector<int>;
using pii = pair<int, int>;

void backtrace(int i,int j,vector<vector<char>>& parent){
    cout<<"YES\n";
    vector<char> out;
    while(parent[i][j]!='A'){
        out.push_back(parent[i][j]);
        if(parent[i][j]=='U')i++;
        else if(parent[i][j]=='L')j++;
        else if(parent[i][j]=='D')i--;
        else j--;
    }
    cout<<out.size()<<"\n";
    reverse(out.begin(),out.end());
    for(auto x:out){cout<<x;}
}

int32_t main() {
    FAST
    int n,m;
    cin>>n>>m;
    vector<vector<char>> mat(n+2,vector<char>(m+2,'#'));
    vector<vector<char>> parent(n+1,vector<char>(m+1));
    int starti,startj;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='A'){starti=i;startj=j;}
        }
    }
    parent[starti][startj]='A';
    int count=1;bool found=false;
    queue<pair<int,int>> updatesM,updatesA;

    if(starti==n || startj==m || starti==1 || startj==1)cout<<"YES\n0";

    else{while(!found && count){
        count=0;
        for(int i=1;i<=n && !found;i++){
            for(int j=1;j<=m && !found;j++){
                if((mat[i][j]=='A' || mat[i][j]=='.') && mat[i+1][j]=='#' && mat[i][j+1]=='#' && mat[i-1][j]=='#' && mat[i][j-1]=='#')mat[i][j]='#';
                else if(mat[i][j]=='.'){
                    if(mat[i+1][j]=='A'){updatesA.push(make_pair(i,j));parent[i][j]='U';}
                    else if(mat[i][j+1]=='A'){updatesA.push(make_pair(i,j));parent[i][j]='L';}
                    else if(mat[i-1][j]=='A'){updatesA.push(make_pair(i,j));parent[i][j]='D';}
                    else if(mat[i][j-1]=='A'){updatesA.push(make_pair(i,j));parent[i][j]='R';}

                    if(mat[i+1][j]=='M')updatesM.push(make_pair(i,j));
                    else if(mat[i][j+1]=='M')updatesM.push(make_pair(i,j));
                    else if(mat[i-1][j]=='M')updatesM.push(make_pair(i,j));
                    else if(mat[i][j-1]=='M')updatesM.push(make_pair(i,j));

                    
                }
                else if(mat[i][j]=='A'){count++;
                    if(i==n || j==m || i==1 || j==1){found=true;backtrace(i,j,parent);}
                    else{
                        if(mat[i+1][j]=='M')updatesM.push(make_pair(i,j));
                        else if(mat[i][j+1]=='M')updatesM.push(make_pair(i,j));
                        else if(mat[i-1][j]=='M')updatesM.push(make_pair(i,j));
                        else if(mat[i][j-1]=='M')updatesM.push(make_pair(i,j));
                    }
                }
            }
        }
        if(!found){
            while(!updatesA.empty()){
                mat[updatesA.front().first][updatesA.front().second]='A';
                updatesA.pop();
            }
            while(!updatesM.empty()){
                mat[updatesM.front().first][updatesM.front().second]='M';
                updatesM.pop();
            }
        }
    }

    if(!found || count==0)cout<<"NO";}
}
