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

const ll INF=100000000000000007;

class gold{
    public:
    gold(){}
    gold(ll a, ll b, ll c, ll d){
        cc=a, uc=b, cu=c, uu=d;
    }
    ll cc, uc, cu, uu; // c는 connected, u는 unconn(그니까 unconnected끼리 연속 불가능)
    gold operator+(gold &b){
        gold res;
        res.cc=min(min(cc+b.uc,cu+b.cc),cc+b.cc); // cc+uc, cu+cc, cc+cc
        res.uc=min(min(uc+b.uc,uc+b.cc),uu+b.cc);
        res.cu=min(min(cc+b.uu,cc+b.cu),cu+b.cu);
        res.uu=min(min(uc+b.uu,uc+b.cu),uu+b.cu);
        res.cc=min(res.cc,INF);
        res.uc=min(res.uc,INF);
        res.cu=min(res.cu,INF);
        res.uu=min(res.uu,INF);
        return res;
    }
};

ll datas[200020];
gold seg[1<<19];


void build_seg(int idx, int l, int r){
    if(l==r){
        seg[idx]=gold(datas[l],INF,INF,0);
        return;
    }
    int mid=(l+r)>>1;
    build_seg(2*idx,l,mid);
    build_seg(2*idx+1,mid+1,r);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}

// 원소를 찾으면 disable도 같이 해주면 될 거 같음
void update_seg(int idx, int l, int r, int t_idx, int val){
    if(l==r){
        seg[idx]=gold(val,INF,INF,0);
        return;
    }
    int mid=(l+r)>>1;
    if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx,val);
    else update_seg(2*idx+1,mid+1,r,t_idx,val);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++) cin>>datas[i];
    build_seg(1,0,n-2);
    ll q,a,b;
    cin>>q;
    for(int i=0; i<q; i++){
        cin>>a>>b;
        a--;
        update_seg(1,0,n-2,a,b);
        cout<<seg[1].cc*2<<endl;
    }
    return 0;
}
