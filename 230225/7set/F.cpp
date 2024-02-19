// 
//./F<test

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

int sqrtN;
int datas[300000];

class Query{
public:
	int idx, s, e;
	bool operator < (Query &x){
		if(s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
		return e < x.e;
	}
};

Query qs[1000000];
int ans[1000000];

const int INF=1000000007;

class node{
public:
    int l=INF,r=-INF,mndif=INF;
    bool visit=false;
    node(){
        l=INF,r=-INF,mndif=INF;
        visit=false;
    }
    node operator+(node b){
        node res=node();
        if(!visit && !b.visit){
            res.l=INF,res.r=-INF,res.mndif=INF,res.visit=false;
        }
        if(visit && !b.visit){
            res.l=l,res.r=r,res.mndif=mndif,res.visit=true;
        }
        else if(!visit && b.visit){
            res.l=b.l,res.r=b.r,res.mndif=b.mndif,res.visit=true;
        }
        else{
            res.l=min(l,b.l);
            res.r=max(r,b.r);
            res.mndif=min(mndif,b.mndif);
            res.mndif=min(res.mndif,abs(b.l-r));
            res.mndif=min(res.mndif,abs(b.r-l));
            res.visit=true;
        }
        return res;
    }
};

node seg[1200000];

/*
void build_seg(int idx, int l, int r){
    if(l==r){
        // seg[idx]=
        return;
    }
    int mid=(l+r)>>1;
    build_seg(2*idx,l,mid);
    build_seg(2*idx+1,mid+1,r);
    //seg[idx]=min(seg[2*idx],seg[2*idx+1]); // Some other operation
}*/

// 원소를 찾으면 disable도 같이 해주면 될 거 같음
void update_seg(int idx, int l, int r, int t_idx, bool flag){
    if(l==r){
        if(flag){
            seg[idx].l=l;
            seg[idx].r=l;
            seg[idx].mndif=INF;
            seg[idx].visit=true;
        }
        else{
            seg[idx].l=INF;
            seg[idx].r=-INF;
            seg[idx].mndif=INF;
            seg[idx].visit=false;
        }
        return;
    }
    int mid=(l+r)>>1;
    if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx,flag);
    else update_seg(2*idx+1,mid+1,r,t_idx,flag);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}

node find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    int mid=(l+r)>>1;
    node ans=node();
    if(t_l<=mid) ans=ans+find_seg(2*idx,l,mid,t_l,t_r);
    if(t_r>mid) ans=ans+find_seg(2*idx+1,mid+1,r,t_l,t_r);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q,a,b;
    cin>>n>>q;
    //sqrtN = sqrt(n);
    sqrtN=2000;
    for(int i=0; i<n; i++){
        cin>>a;
        datas[i]=a-1;
    }
    for(int i=0; i<q; i++){
        cin>>a>>b;
        a--, b--;
        qs[i].idx=i;
        qs[i].s=a;
        qs[i].e=b;
    }
    sort(qs,qs+q);


    int s = qs[0].s, e = qs[0].e;
	for(int i=s; i<=e; i++){
		update_seg(1,0,n-1,datas[i],true);
	}
	//ans[qs[0].idx] = find_seg(1,0,n-1,0,n-1).mndif;
    ans[qs[0].idx] = seg[1].mndif;

	for(int i=1; i<q; i++){
		while(s < qs[i].s) update_seg(1,0,n-1,datas[s++], false);
		while(s > qs[i].s) update_seg(1,0,n-1,datas[--s], true);
		while(e < qs[i].e) update_seg(1,0,n-1,datas[++e], true);
		while(e > qs[i].e) update_seg(1,0,n-1,datas[e--], false);
		//ans[qs[i].idx] = find_seg(1,0,n-1,0,n-1).mndif;
        ans[qs[i].idx] = seg[1].mndif;
	}
	for(int i=0; i<q; i++) cout << ans[i] << endl;

    return 0;
}