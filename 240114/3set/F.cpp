
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 200030
#define MOD 998244353
#define INF 1000000007 

int cnt[N];
// Is this deterministic? --> Yes
int datas[N];
int ans[N];
// Only count of numbers are important.

// typically, counts for number in [mx-20, mx] are matter. But in some critical cases, mx-200000 can also be matter.
// but this case is hard to replicate. 
// How to manage this special cases?

class node{
public:
    node(){}
    node operator+(node b){
        node result;
        result.mx=max(mx,b.mx);
        result.mn=min(mn,b.mn);
        return result;
    }
    int mx=0, mn=1, lazy_val=-1;
};

class lazy_seg{
public:
	node seg[1<<19];
	
	lazy_seg(){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].mn=cnt[l]; 
            seg[idx].mx=cnt[l];
			seg[idx].lazy_val=-1;
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=(seg[2*idx]+seg[2*idx+1]);
		}
	}
	
	void update_down(int idx, int l, int r){
		if(l==r || seg[idx].lazy_val==-1) return;
		int mid=(l+r)>>1;
		seg[2*idx].mn=seg[2*idx].mx=seg[2*idx].lazy_val=seg[idx].lazy_val;
		seg[2*idx+1].mn=seg[2*idx+1].mx=seg[2*idx+1].lazy_val=seg[idx].lazy_val;
		seg[idx].lazy_val=-1;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			seg[idx].mx=seg[idx].mn=val;
			seg[idx].lazy_val=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]);
	}
	
	node find_seg(int idx, int l, int r, int t_l, int t_r){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
		node result;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=(result+find_seg(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) result=(result+find_seg(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}
};

lazy_seg s;

// 이게 Naive solution이 왜 TLE가 아니닌거지

set<pii> st;


void Solve(){
    int n,q,x,v,l,r,mx=0;
    cin>>n>>q;
    rng(i,0,n-1){
        cin>>datas[i];
        cnt[datas[i]]++;
    }
    
    rng(i,0,N-1){
        cnt[i+1]+=cnt[i]/2;
        cnt[i]=cnt[i]%2;
        if(cnt[i]) mx=i;
    }

    s.build_seg(1,0,N-1);
    rng(i,0,q-1){
        cin>>x>>v;
        x--;
        // deduct datas[x]
        int lone; // datas[x]이후에 처음으로 나오는 1이죠
        l=datas[x], r=N-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(s.find_seg(1,0,N-1,datas[x],mid).mx==1) r=mid;
            else l=mid+1;
        }
        lone=l;
        if(lone>datas[x]) s.update_seg(1,0,N-1,datas[x],lone-1,1);
        s.update_seg(1,0,N-1,lone,lone,0);
        if(lone==mx){
            if(lone==datas[x]){
                l=0, r=mx;
                while(l<r){
                    int mid=(l+r+1)>>1;
                    if(s.find_seg(1,0,N-1,mid,N-1).mx==1) l=mid;
                    else r=mid-1;
                }
                mx=l;
            }
            else mx--;
        }

        // add cnt[v]
        int lzero; // v이후에 처음으로 나오는 0임.
        l=v, r=N-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(s.find_seg(1,0,N-1,v,mid).mn==0) r=mid;
            else l=mid+1;   
        }
        lzero=l;
        if(lzero>v) s.update_seg(1,0,N-1,v,lzero-1,0);
        s.update_seg(1,0,N-1,lzero,lzero,1);
        if(lzero>mx) mx=lzero;

        // Modify datas.. Not cnt[x]
        datas[x]=v;
        
        // Get ans.
        // int last_val;// last nonzero value
        // l=0, r=N-1;
        // while(l<r){
        //     int mid=(l+r+1)>>1;
        //     if(s.find_seg(1,0,N-1,mid,N-1).mx==1) l=mid;
        //     else r=mid-1;
        // }
        // last_val=l;
        // //cout<<"lone, lzero, lastval "<<lone<<' '<<lzero<<' '<<last_val<<endl;
        // //rng(i,0,n-1) cout<<datas[i]<<' '; cout<<endl;
        cout<<mx<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

