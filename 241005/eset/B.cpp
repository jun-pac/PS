
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)


int solution(vector<int> &A){
    int n=A.size();
    if(A[n-1]==0) return 0;
    int res=1;
    for(int i=1; i<=n; i++){
        // i-size square
        if(A[n-i]>=i) res=i;
        else break;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m;
    cin>>m;
    vector<int> A;
    rng(i,0,m-1){
        int h;
        cin>>h;
        A.push_back(h);
    }
    int n=A.size();
    if(A[n-1]==0) return 0;
    int res=1;
    for(int i=1; i<=n; i++){
        // i-size square
        if(A[n-i]>=i) res=i;
        else break;
    }
    cout<<res<<'\n';
    
    return 0;
}

