#include <bits/stdc++.h>
 using namespace std;
int main() {
    int n,m;
    cin >> n>>m;
    vector<int> arr(n), pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    int rounds = 1;
    for (int i = 2; i <= n; ++i) {
        if (pos[i] < pos[i - 1]) {
            ++rounds;
        }
    }
    int a1,a2;

    for(int i=0;i<m;i++){
        cin>>a1>>a2;
            a1--;
    a2--;
        if(arr[a1]-arr[a2]==-1 || arr[a1]-arr[a2]==1){
            if(arr[a1]<arr[a2]){
                if(arr[a1]>1){
                if(pos[arr[a1]]<pos[arr[a1]-1] && !(pos[arr[a2]]<pos[arr[a1]-1]))rounds--;
                else if(!(pos[arr[a1]]<pos[arr[a1]-1]) && (pos[arr[a2]]<pos[arr[a1]-1]))rounds++;
                 }
                if(arr[a2]+1<=n){
                    if(pos[arr[a2]+1]<pos[arr[a2]] && !(pos[arr[a2]+1]<pos[arr[a1]]))rounds--;
                    else if(!(pos[arr[a2]+1]<pos[arr[a2]]) && (pos[arr[a2]+1]<pos[arr[a1]]))rounds++;
                }
                if(pos[arr[a1]]<pos[arr[a2]])rounds++;
                else rounds--;
            }
            else{
                if(arr[a1]+1<=n){
                    if(pos[arr[a1]+1]<pos[arr[a1]] && !(pos[arr[a1]+1]<pos[arr[a2]]))rounds--;
                    else if(!(pos[arr[a1]+1]<pos[arr[a1]]) && (pos[arr[a1]+1]<pos[arr[a2]]))rounds++;
                }
                if(arr[a2]>1){
                if(pos[arr[a2]]<pos[arr[a2]-1] && !(pos[arr[a1]]<pos[arr[a2]-1]))rounds--;
                else if(!(pos[arr[a2]]<pos[arr[a2]-1]) && (pos[arr[a1]]<pos[arr[a2]-1]))rounds++;
                }
                if(pos[arr[a1]]>pos[arr[a2]])rounds++;
                else rounds--;
            }
        }
        else{
                if(arr[a1]>1){
                if(pos[arr[a1]]<pos[arr[a1]-1] && !(pos[arr[a2]]<pos[arr[a1]-1]))rounds--;
                else if(!(pos[arr[a1]]<pos[arr[a1]-1]) && (pos[arr[a2]]<pos[arr[a1]-1]))rounds++;
                 }
            if(arr[a1]+1<=n){
            if(pos[arr[a1]+1]<pos[arr[a1]] && !(pos[arr[a1]+1]<pos[arr[a2]]))rounds--;
            else if(!(pos[arr[a1]+1]<pos[arr[a1]]) && (pos[arr[a1]+1]<pos[arr[a2]]))rounds++;
            }
                if(arr[a2]>1){
                if(pos[arr[a2]]<pos[arr[a2]-1] && !(pos[arr[a1]]<pos[arr[a2]-1]))rounds--;
                else if(!(pos[arr[a2]]<pos[arr[a2]-1]) && (pos[arr[a1]]<pos[arr[a2]-1]))rounds++;
                }
            if(arr[a2]+1<=n){
            if(pos[arr[a2]+1]<pos[arr[a2]] && !(pos[arr[a2]+1]<pos[arr[a1]]))rounds--;
            else if(!(pos[arr[a2]+1]<pos[arr[a2]]) && (pos[arr[a2]+1]<pos[arr[a1]]))rounds++;
        }
        }
        swap(pos[arr[a1]],pos[arr[a2]]);
        swap(arr[a1],arr[a2]);
        cout<<rounds<<"\n";
    }
    
}
