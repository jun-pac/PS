// 
//./D<test.txt

#include <bits/stdc++.h>
//#define endl '\n'
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

class node{
public:
    int mx, mxidx;
    int mn, mnidx;
    node(){}
    node(int a, int b, int c, int d){
        mx=a;
        mxidx=b;
        mn=c;
        mnidx=d;
    }
    node operator+(node b){
        node res;
        res.mx=max(mx,b.mx);
        res.mxidx=(mx>b.mx?mxidx:b.mxidx);
        res.mn=min(mn,b.mn);
        res.mnidx=(mn<b.mn?mnidx:b.mnidx);
        return res;
    }
};
node seg[1<<20];
int datas[1<<19];
int n;

void build_seg(int idx, int l, int r){
    if(l==r){
        seg[idx]=node(datas[l],l,datas[l],l);
        return;
    }
    int mid=(l+r)>>1;
    build_seg(2*idx,l,mid);
    build_seg(2*idx+1,mid+1,r);
    seg[idx]=seg[2*idx]+seg[2*idx+1]; // Some other operation
}

node find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    int mid=(l+r)>>1;
    if(t_l<=mid && mid<t_r) return find_seg(2*idx,l,mid,t_l,t_r)+find_seg(2*idx+1,mid+1,r,t_l,t_r);
    if(t_l<=mid) return find_seg(2*idx,l,mid,t_l,t_r);
    if(t_r>mid) return find_seg(2*idx+1,mid+1,r,t_l,t_r);
    return seg[idx];
}

int path(int l, int r){
    if(r-l==1) return 1;
    if(r==l) return 0;
    node bo=find_seg(1,0,n-1,l,r);
    int mx=bo.mx, mxidx=bo.mxidx;
    int mn=bo.mn, mnidx=bo.mnidx;
    //cout<<"Q "<<l<<' '<<r<<' '<<mx<<' '<<mxidx<<' '<<mn<<' '<<mnidx<<endl;
    if(datas[l]==mx) return 1+path(mnidx,r);
    if(datas[l]==mn) return 1+path(mxidx,r);
    if(datas[r]==mx) return 1+path(l,mnidx);
    if(datas[r]==mn) return 1+path(l,mxidx);
    return 1+path(l,min(mxidx,mnidx))+path(max(mxidx,mnidx),r);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        //cout<<"N "<<n<<endl;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        build_seg(1,0,n-1);
        cout<<path(0,n-1)<<endl;
    }
    return 0;
}