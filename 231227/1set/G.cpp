
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

#define N 200030
#define MOD 998244353
#define INF 1000000007 

class node{
public:
    // Do something!
    node(){}
    node operator+(node b){
        node result;
        result.val=max(val,b.val); 
        return result;
    }
    int val=0, lazy_val=0;
};


int datas[N];

class lazy_seg{
public:
	node seg[1<<19];
	
	lazy_seg(){}
	//lazy_seg(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].val=datas[l];
			seg[idx].lazy_val=0;
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=(seg[2*idx]+seg[2*idx+1]);
		}
	}
	
	void update_down(int idx, int l, int r){
		if(l==r) return;
		int mid=(l+r)>>1;
		seg[2*idx].val+=seg[idx].lazy_val;
		seg[2*idx].lazy_val+=seg[idx].lazy_val;
		seg[2*idx+1].val+=seg[idx].lazy_val;
		seg[2*idx+1].lazy_val+=seg[idx].lazy_val;
		seg[idx].lazy_val=0;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			seg[idx].val+=val;
			seg[idx].lazy_val+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
		seg[idx]=seg[2*idx]+seg[2*idx+1];
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

lazy_seg ls; 

void Solve(){
	int n,q,a,b;
	cin>>n>>q;
	rng(i,0,n-1) cin>>datas[i];
	ls.build_seg(1,0,n-1);
	
	ll val=0;
	// initial val구하기.
	stack<pll> st; // {val,idx} 언제나 val은 감소함.
	st.push({datas[0],0});
	rng(i,1,n-1){
		ll bottom=-1;
		while(!st.empty() && (datas[i]>=st.top().fi)){
			if(bottom==-1) bottom=st.top().fi;
			else{
				val+=(i-st.top().se-1)*(st.top().fi-bottom);
				bottom=st.top().fi;
			}
			st.pop();
		}
		if(bottom!=-1 && !st.empty()){
			val+=(i-st.top().se-1)*(datas[i]-bottom);
		}
		st.push({datas[i],i});
	}
	cout<<val<<'\n';

	rng(i,0,q-1){
		cin>>a>>b;
		a--, b--;
		int mxl=(a==0?-1:ls.find_seg(1,0,n-1,0,a-1).val);
		int mxr=(b==n-1?-1:ls.find_seg(1,0,n-1,b,n-1).val);
		int mxm=ls.find_seg(1,0,n-1,a,b).val;
		if(min(mxl,mxr)>mxm){
			val=val-(b-a+1);
		}
		else{
			if(mxl!=-1 && mxl<=mxm){
				// 처음으로 mxl이상이 되는 idx를 찾아야 한다.
				int l=a,r=b;
				while(l<r){
					int mid=(l+r)>>1;
					if(ls.find_seg(1,0,n-1,a,mid).val>=mxl) r=mid;
					else l=mid+1;
				}
				val-=(l-a);
			}
			else if(mxl!=-1){
				int l=0, r=a-1; // 처음으로 l>mxm이 되는
				while(l<r){
					int mid=(l+r+1)>>1;
					if(ls.find_seg(1,0,n-1,mid,a-1).val>mxm) l=mid;
					else r=mid-1;
				}
				val+=(a-l-1);

			}
			if(mxr!=-1 && mxr<=mxm){
				// 우측에서 처음으로 mxr이상이 되는 idx
				int l=a,r=b;
				while(l<r){
					int mid=(l+r+1)>>1;
					if(ls.find_seg(1,0,n-1,mid,b).val>=mxr) l=mid;
					else r=mid-1;
				}
				val-=(b-l);
			}
			else if(mxr!=-1){
				int l=b+1, r=n-1; // 처음으로 r>mxm이 되는
				while(l<r){
					int mid=(l+r)>>1;
					if(ls.find_seg(1,0,n-1,b+1,mid).val>mxm) r=mid;
					else l=mid+1;
				}
				val+=(l-b-1);
			}
		}
		cout<<val<<'\n';
		ls.update_seg(1,0,n-1,a,b,1);
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

