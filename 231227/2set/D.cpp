
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N (1<<20)
#define MOD 998244353
#define INF 1000000007 

ll datas[N];
ll pos[N];

class segtree{
public:	
	ll seg[1<<21];
	segtree(){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=pos[l];
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=max(seg[2*idx],seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]+=val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=max(seg[2*idx],seg[2*idx+1]); // Modify
	}

	ll find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        ll ans=0;
		if(t_l<=mid) ans=max(ans,find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=max(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;


class node{
public:
    // Do something!
    node(){}
    //node(int val){this->val=val;}
    node operator+(node b){
        node result;
        result.val=val+b.val; // Modify
        result.lazy_val=INF;
        return result;
    }
    ll val=0, lazy_val=INF; // sum
};

class lazy_seg{
public:
	node seg[1<<21];
	
	lazy_seg(){}
	//lazy_seg(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].val=0; // seg[idx].val=datas[l];
			seg[idx].lazy_val=INF;
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=(seg[2*idx]+seg[2*idx+1]);
		}
	}
	
	void update_down(int idx, int l, int r){
		if(l==r || seg[idx].lazy_val==INF) return;
		int mid=(l+r)>>1;
		// seg[2*idx], seg[2*idx+1]
		seg[2*idx].val=(mid-l+1)*seg[idx].lazy_val;
		seg[2*idx].lazy_val=seg[idx].lazy_val;
		seg[2*idx+1].val=(r-mid)*seg[idx].lazy_val;
		seg[2*idx+1].lazy_val=seg[idx].lazy_val;
		// seg[idx]의 lazy_val초기화
		seg[idx].lazy_val=INF;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		if(t_l<=l && r<=t_r){
			// // seg[idx].val과 seg[idx].lazy_val업데이트
			seg[idx].val=((long long)r-l+1)*val;
			seg[idx].lazy_val=val;
			return;
		}
        update_down(idx, l, r);
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]);
	}
	
	node find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
        update_down(idx, l, r);
		node result;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=(result+find_seg(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) result=(result+find_seg(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}
};

lazy_seg s;

void Solve(){
    ll n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) pos[datas[i]]=i;
    s.build_seg(1,0,n-1);
    seg.build_seg(1,0,n-1);

    ll mx=0;
    rng(i,0,n-1){
        mx=max(mx,pos[i]);
        s.update_seg(1,0,n-1,mx,n-1,i+1);
    }
    ll res=0;
    rng(j,0,n-1){
        if(j!=0){
            // update해준다. datas[j-1]가 맨 오른쪽으로. [j,n-1+j]구간에서 가장 0,...,datas[j-1]-1까지 등장하는 가장 왼쪽
            ll posi;
            seg.update_seg(1,0,n-1,datas[j-1],n);
            if(datas[j-1]==0) posi=j;
            else posi=seg.find_seg(1,0,n-1,0,datas[j-1]-1); // n이상일 수 있음.
            //cout<<"ch "<<j<<' '<<pos<<'\n';
            posi=posi%n;
            if(j==1) s.update_seg(1,0,n-1,posi,n+j-2,datas[j-1]);
            else{
                if(posi>=j){
                    s.update_seg(1,0,n-1,posi,n-1,datas[j-1]);
                    s.update_seg(1,0,n-1,0,j-2,datas[j-1]);
                }
                else s.update_seg(1,0,n-1,posi,j-2,datas[j-1]);
            }
            s.update_seg(1,0,n-1,j-1,j-1,n);
        }
        res=max(res,s.find_seg(1,0,n-1,0,n-1).val);
        //cout<<"pos "<<j<<' '<<s.find_seg(1,0,n-1,0,n-1).val<<'\n';
    }
    cout<<res<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

