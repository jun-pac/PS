#include <bits/stdc++.h>
using namespace std;

int arr[2023][3];

void Solve(int tc){
    int n, base_cost=0;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) cin>>arr[i][j];
        int optimal=max(arr[i][0], max(arr[i][1],arr[i][2]));
        base_cost+=arr[i][0]+arr[i][1]+arr[i][2]-optimal;   
        for(int j=0; j<3; j++) arr[i][j]=optimal-arr[i][j];
    }
    
    int res=1e9;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(i==j || j==k || k==i) continue;
                res=min(res,arr[i][0]+arr[j][1]+arr[k][2]);
            }
        }
    }
    cout<<"#"<<tc<<' '<<(res==1e9?-1:res+base_cost)<<'\n';
}

int main(){
    int t=1;
    cin>>t;
    for(int tc=1; tc<=t; tc++) Solve(tc);
    return 0;
}

