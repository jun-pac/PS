
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

int datas[N];

inline pair<pii,pii> add_pi(pair<pii,pii> temp, pair<pii,pii> ans){
    if(temp.fi.fi>ans.fi.fi){
        if(temp.se.fi==ans.fi.fi) ans={temp.fi,{temp.se.fi,temp.se.se+ans.fi.se}};
        else if(temp.se.fi>ans.fi.fi) ans=temp;
        else ans={temp.fi,ans.fi};
    }
    else if(temp.fi.fi==ans.fi.fi){
        if(temp.se.fi==ans.se.fi) ans={{temp.fi.fi,temp.fi.se+ans.fi.se},{temp.se.fi,temp.se.se+ans.se.se}};
        else if(temp.se.fi>ans.se.fi) ans={{temp.fi.fi,temp.fi.se+ans.fi.se},temp.se};
        else ans={{temp.fi.fi,temp.fi.se+ans.fi.se},ans.se};
    }
    else if(temp.fi.fi<ans.fi.fi){
        if(temp.fi.fi==ans.se.fi) ans={ans.fi,{ans.se.fi,ans.se.se+temp.fi.se}};
        else if(temp.fi.fi<ans.se.fi) ans=ans;
        else ans={ans.fi,temp.fi};
    }   
    return ans;
}

class segtree{
public:	
	pair<pii,pii> seg[1<<19];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]={{datas[l],1},{-1,0}};
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		//seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
        //rng(i,l,r) seg[idx][datas[i]]++;
        seg[idx]=add_pi(seg[2*idx],seg[2*idx+1]);
	}

	void update_seg(int idx, int l, int r, int t_idx){
		if(l==r){
            seg[idx]={{datas[l],1},{-1,0}};
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx);
		else update_seg(2*idx+1,mid+1,r,t_idx);
        seg[idx]=add_pi(seg[2*idx],seg[2*idx+1]);
	}

	pair<pii,pii> find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r){
            return seg[idx];
        }
		int mid=(l+r)>>1;
        pair<pii,pii> ans={{-1,0},{-1,0}};
		if(t_l<=mid){
            pair<pii,pii> temp=find_seg(2*idx,l,mid,t_l,t_r);
            ans=add_pi(ans,temp);
        }
		if(t_r>mid){
            pair<pii,pii> temp=find_seg(2*idx+1,mid+1,r,t_l,t_r); // Modify
            ans=add_pi(ans,temp);
        }
        assert(ans.fi.se!=0);
		return ans;
	}
};

segtree seg;

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    seg.build_seg(1,0,n-1);
    rng(i,0,q-1){
        int a,b,c;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            b--; // datas[b]=c
            int ori_val=datas[b];
            datas[b]=c;
            seg.update_seg(1,0,n-1,b);
        }
        else{
            cin>>b>>c;
            b--, c--;
            cout<<seg.find_seg(1,0,n-1,b,c).se.se<<'\n';
        }
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

