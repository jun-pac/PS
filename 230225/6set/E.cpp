// 
//./E<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

int INF=10000000;
ll datas[200000], ssum[200000];
pair<ll,ll> sorted[200000];
int idx_to_seg[200000];
pair<int,int> seg[800000];
int DP[200000];

void build_seg(int idx, int l, int r){
    if(l==r){
        seg[idx]={-INF,sorted[l].se};
        return;
    }
    int mid=(l+r)>>1;
    build_seg(2*idx,l,mid);
    build_seg(2*idx+1,mid+1,r);
    seg[idx]=max(seg[2*idx],seg[2*idx+1]); // Some other operation
}

void update_seg(int idx, int l, int r, int t_idx, int val){
    if(l==r){
        seg[idx].fi=val;
        return;
    }
    int mid=(l+r)>>1;
    if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx,val);
    else update_seg(2*idx+1,mid+1,r,t_idx,val);
    seg[idx]=max(seg[2*idx],seg[2*idx+1]);
}

pair<int,int> find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    int mid=(l+r)>>1;
    pair<int,int> ans={-INF-1,-1};
    if(t_l<=mid) ans=max(ans,find_seg(2*idx,l,mid,t_l,t_r));
    if(t_r>mid) ans=max(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int cur_mx=0;
    cin>>n;
    for(int i=0; i<n; i++) cin>>datas[i];
    for(int i=0; i<n; i++){
        if(i==0) ssum[i]=datas[i];
        else ssum[i]=ssum[i-1]+datas[i];
        sorted[i]={ssum[i],i};
    }
    sort(sorted,sorted+n);
    for(int i=0; i<n; i++) idx_to_seg[sorted[i].se]=i;
    build_seg(1,0,n-1);

    DP[0]=(ssum[0]>=0?1:0);
    update_seg(1,0,n-1,idx_to_seg[0],DP[0]-0);

    umax(cur_mx,DP[0]);
    for(int i=1; i<n; i++){
        int segidx=idx_to_seg[i];
        if(ssum[i]>=0) DP[i]=i+1;
        else if(segidx!=0){
            pair<int,int> mx_DP_minus_i=find_seg(1,0,n-1,0,segidx-1);
            if(mx_DP_minus_i.fi<=-INF) DP[i]=cur_mx;
            else DP[i]=mx_DP_minus_i.fi+mx_DP_minus_i.se;
        }
        update_seg(1,0,n-1,segidx,DP[i]-i);
        umax(cur_mx,DP[i]);
    }
    cout<<cur_mx<<endl;
    return 0;
}