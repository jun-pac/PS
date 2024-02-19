// 
//./D<test.txt

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

int datas[200000];
long long ssum[200000];
const ll INF=5000000000000000;
pair<long long, long long> seg[800000];
pair<long long, long long> mxseg[800000];

void build_seg(int idx, int l, int r){
    if(l==r){
        seg[idx]={ssum[l],ssum[l]};
        mxseg[idx]={datas[l],l};
    }
    else{
        int mid=(l+r)>>1;
        build_seg(2*idx,l,mid);
        build_seg(2*idx+1,mid+1,r);
        seg[idx]={min(seg[2*idx].fi,seg[2*idx+1].fi),max(seg[2*idx].se,seg[2*idx+1].se)};
        mxseg[idx]={max(seg[2*idx].fi,seg[2*idx+1].fi),(seg[2*idx].fi>seg[2*idx+1].fi?seg[2*idx].se:seg[2*idx+1].se)};
    }
}

pair<long long, long long> find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    else{
        int mid=(l+r)>>1;
        pair<long long, long long> res={-INF,INF};
        if(t_l<=mid){
            pair<ll,ll> temp=find_seg(2*idx,l,mid,t_l,t_r);
            umin(res.fi,temp.fi);
            umax(res.se,temp.se);
        }
        if(t_l>mid){
            pair<ll,ll> temp=find_seg(2*idx+1,mid+1,r,t_l,t_r);
            umin(res.fi,temp.fi);
            umax(res.se,temp.se);
        }
        return res;
    }
}

pair<long long, long long> find_mx(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return mxseg[idx];
    else{
        int mid=(l+r)>>1;
        pair<long long, long long> res={-INF,INF};
        if(t_l<=mid){
            pair<ll,ll> temp=find_mx(2*idx,l,mid,t_l,t_r);
            if(temp.fi>res.fi){
                res=temp;
            }
        }
        if(t_l>mid){
            pair<ll,ll> temp=find_mx(2*idx+1,mid+1,r,t_l,t_r);
            if(temp.fi>res.fi){
                res=temp;
            }
        }
        return res;
    }
}

bool flag;
int n;

void cch(int l, int r){
    if(l==r) return;
    pair<ll,ll> mid=find_mx(1,0,n-1,l,r);  
    if(mid.fi<=0) return;
    if(mid.se!=0 && ssum[mid.se-1]-find_seg(1,0,n-1,0,mid.se-1).fi>0){
        flag=false;
        return;
    }
    if(mid.se!=r && ssum[r]-find_seg(1,0,n-1,mid.se+1,r).se>0){

    }
    pair<ll,ll>

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        flag=true;
        int last;
        long long sum=0;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            if(i==0) ssum[i]=datas[i];
            else ssum[i]=ssum[i-1]+datas[i];
        }
        build_seg(1,0,n-1);
        flag=true;
        cch(0,n-1);
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}