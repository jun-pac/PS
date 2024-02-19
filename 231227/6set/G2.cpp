
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 

int datas[N];
vc<int> poss[N];

class mntree{
public:	
	int seg[1<<20];
	int info;
	mntree(){}
	mntree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=l;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=min(seg[2*idx],seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]=val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=min(seg[2*idx],seg[2*idx+1]); // Modify
	}

	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1, ans=INF;
		if(t_l<=mid) ans=min(ans,find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=min(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

mntree mnseg;


using namespace std;
class sumtree{
public:	
	int seg[1<<20];
	int info;
	sumtree(){}
	sumtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=0;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]=val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

sumtree sumseg;

int tcs;

void Solve(){
    tcs++;
    int n,a;
    cin>>n;
    rng(i,0,n-1) poss[i].clear();
    sumseg.build_seg(1,0,2*n-1);
    mnseg.build_seg(1,0,2*n-1);
    
    rng(i,0,2*n-1){
        cin>>a;
        a--;
        datas[i]=a;
        poss[a].pb(i);
    }
    
    vc<ll> ans;

    
    int start=0, last=-1, last_minus=0, minus=0;
    stack<pii> st;
    rng(i,1,2*n-1){
        if(poss[datas[i]][0]==i) continue; // i==poss[datas[i]][1]
        int mn=mnseg.find_seg(1,0,2*n-1,poss[datas[i]][0],i);
        mnseg.update_seg(1,0,2*n-1,i,mn);
        sumseg.update_seg(1,0,2*n-1,poss[datas[i]][0],1);
        sumseg.update_seg(1,0,2*n-1,poss[datas[i]][1],1);
        int num=sumseg.find_seg(1,0,2*n-1,mn,i);
        if(start!=mn && num==i-mn+1){
            while(!st.empty() && st.top().fi>=mn) st.pop();
            st.push({i,num});
        }
        else if(start==mn && num==i-mn+1){
            int ss=0;
            while(!st.empty()){
                ss+=st.top().se;
                st.pop();
            }
            ans.pb(num-ss);
            minus=0;
            start=i+1;
        }
    }
    
    cout<<ans.size()<<' ';
    ll res=1;
    rng(i,0,(int)ans.size()-1){
        res=(res*(ans[i]))%MOD;
    }
    cout<<(res+MOD)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    tcs=0;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

