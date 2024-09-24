
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

pii datas[N]; // {mn, mx}

class ortree{
public:	
	int seg[1<<19];
	int info=0;
	ortree(){}
	ortree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=datas[l].se;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]|seg[2*idx+1]); // Modify
	}

	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=(ans|find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans|find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

class numtree{
public:	
	int seg[1<<19];
	int info=0;
	numtree(){}
	numtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=((datas[l].se&(1<<info))?1:0);
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
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
class difftree{
public:	
	bool seg[1<<19];
	int info=0;
	difftree(){}
	difftree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=((datas[l].se&(1<<info)) && (((datas[l].se-(1<<info))|((1<<info)-1))>=datas[l].fi));
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	bool find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        bool ans=0;
		if(t_l<=mid) ans=(ans|find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans|find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};
ortree ors;
numtree numbit[30]; // mx에서의 1의 개수의 단순합
difftree diffbit[30]; // mx와 mn의 비트의 값이 다른지만 확인하는 것 


void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i].fi>>datas[i].se;
    
    ors.build_seg(1,0,n-1);
    rng(i,0,29){
        numbit[i].info=i;
        numbit[i].build_seg(1,0,n-1);
    }
    rng(i,0,29){
        diffbit[i].info=i;
        diffbit[i].build_seg(1,0,n-1);
    }

    int q;
    cin>>q;
    rng(i,0,q-1){
        int l,r;
        cin>>l>>r;
        l--, r--;
        int res=ors.find_seg(1,0,n-1,l,r);
        int last=29;
        while(last>0 && (1<<last)>res) last--;
        while(last>0){
            if(diffbit[last].find_seg(1,0,n-1,l,r) && numbit[last].find_seg(1,0,n-1,l,r)>=2) break;
            last--;
        }
        res=res|((1<<last)-1);
        cout<<res<<' ';
    }
    cout<<'\n';
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

