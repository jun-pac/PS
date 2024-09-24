
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

// 이 다음에 언제 벽을 만나지? 를 그냥 다 저장해놓는 수 밖에 없음...
string s;

class segtree{
public:	
	pii seg[1<<21];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]={(s[l]=='R'?1:(s[l]=='L'?-1:0)),(s[l]=='U'?1:(s[l]=='D'?-1:0))};
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]={seg[2*idx].fi+seg[2*idx+1].fi,seg[2*idx].se+seg[2*idx+1].se}; 
	}

	void update_seg(int idx, int l, int r, int t_idx, pii val){
		if(l==r){
			seg[idx]=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]={seg[2*idx].fi+seg[2*idx+1].fi,seg[2*idx].se+seg[2*idx+1].se}; 
	}

	pii find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        pii ans={0,0};
		if(t_l<=mid){
            pii temp=find_seg(2*idx,l,mid,t_l,t_r);
            ans={ans.fi+temp.fi,ans.se+temp.se};
        }
		if(t_r>mid){
            pii temp=find_seg(2*idx+1,mid+1,r,t_l,t_r);
            ans={ans.fi+temp.fi,ans.se+temp.se};
        }
		return ans;
	}
};

segtree seg;

void Solve(){
    ll n,k,w,h;
    cin>>s;
    seg.build_seg(1,0,n-1);
    ll res=0;
    ll cnt=0; // 말이 이동한 횟수
    pll pos={0,0}; // 현재 좌표
    while(cnt<k*n){
        ll l=cnt, r=k*n-1;
        while(l<r){
            ll mid=(l+r)>>1;
            pll addpos={pos.fi,pos.se};
            if(mid/k-1>l/k){
                pll temp=seg.find_seg(1,0,n-1,0,n-1);
                addpos.fi+=temp.fi*(mid/k-l/k-1);
                addpos.se+=temp.se*(mid/k-l/k-1);
            }
            if(mid/k>l/k){
                pll temp=seg.find_seg(1,0,n-1,l%k,n-1);
                addpos.fi+=temp.fi;
                addpos.se+=temp.se;
                temp=seg.find_seg(1,0,n-1,0,mid%k);
                addpos.fi+=temp.fi;
                addpos.se+=temp.se;
            }
            else{
                pll temp=seg.find_seg(1,0,n-1,l%k,mid%k);
                addpos.fi+=temp.fi;
                addpos.se+=temp.se;
            }
            if()
        }
    }
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

