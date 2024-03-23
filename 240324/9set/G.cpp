
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

#define N 300030
#define MOD 998244353
#define INF 1000000007


class nnz_seg{
public:
	pii seg[1<<19]; // {cnt, nnz}
	nnz_seg(){}

	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].fi=seg[idx].se=0;
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
            seg[idx].fi=seg[idx].se=0;
		}
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		if(t_l<=l && r<=t_r){
			seg[idx].fi+=val;
            if(l==r) seg[idx].se=(seg[idx].fi>0);
            else if(seg[idx].fi>0) seg[idx].se=r-l+1;
            else seg[idx].se=seg[2*idx].se+seg[2*idx+1].se;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
        if(seg[idx].fi==0) seg[idx].se=seg[2*idx].se+seg[2*idx+1].se;
	}
	
	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r){
			return seg[idx].se;
		}
		int result=0;
		int mid=(l+r)>>1;
        if(seg[idx].fi>0) return r-l+1;
		if(t_l<=mid) result=(result+find_seg(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) result=(result+find_seg(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}
};

nnz_seg s;

int datas[N];
int predpos[N];
int last[N];

void Solve(){
    ll n;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    fill(last,last+n+1,-1);
    rng(i,0,n-1){
        predpos[i]=last[datas[i]];
        last[datas[i]]=i;
    }
    ll res=0;
    s.build_seg(1,0,n-1);
    rng(i,0,n-1){
        if(predpos[i]!=-1){
            int predpred=predpos[predpos[i]];
            s.update_seg(1,0,n-1,predpred+1,predpos[i],-1);
        }
        s.update_seg(1,0,n-1,predpos[i]+1,i,1);
        res+=s.seg[1].se;
        //cout<<"end at "<<i<<' '<<s.seg[1].se<<'\n';
    }
    cout<<res<<'\n';
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

