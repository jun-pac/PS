
#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define N 300030

int n,c;
int datas[N];

bool check(int dur){
    // 모두 duration 이상의 간격을 가지는 게 가능한지?
    int last=datas[0];
    int cur=1;
    rng(i,1,c-1){
        while(cur<n && datas[cur]-last<dur) cur++;
        if(cur==n) return 0;
        last=datas[cur];
        cur++; 
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>c;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    int l=1, r=datas[n-1]-datas[0];
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
    return 0;
}

