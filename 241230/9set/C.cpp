
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

int datas[2][N];
ll sum[2][N]; // check는 O(n)이면 된다.
int n;
class node{
public:
    // Do something!
    node(){}
    //node(int val){this->val=val;}
    node operator+(node b){
        node result;
        result.val=max(val,b.val); // Modify
        return result;
    }
    ll val=-INF, lazy_val=0;
};

class lazy_seg{
public:
	node seg[1<<12];
	
	lazy_seg(){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].val=sum[0][l]+sum[1][n-1]-(l==0?0:sum[1][l-1]);
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
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, ll val){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			seg[idx].val+=val;
			seg[idx].lazy_val+=val;
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


void Solve(){
    cin>>n;
    rng(i,0,1) rng(j,0,n-1) cin>>datas[i][j];
    // rng(i,0,n-1) if(datas[1][i]>datas[0][i]) swap(datas[1][i],datas[0][i]);
    // ll mx=-INF;
    // rng(i,0,n-1) if(datas[1][i]>mx) mx=datas[1][i];
    // ll sum=0;
    // rng(i,0,n-1) sum+=datas[0][i];
    // sum+=mx;
    // cout<<sum<<'\n';
    rng(k,0,1) rng(i,0,n-1) sum[k][i]=(i==0? 0:sum[k][i-1]) +datas[k][i];
    
    s.build_seg(1,0,n-1);
    ll mx=s.find_seg(1,0,n-1,0,n-1).val;
    // cout<<"MX "<<mx<<'\n';
    rng(i,0,n-1){
        rng(j,i+1,n-1){
            // i,j swap
            // [i, j]
            ll temp=(datas[1][i]+datas[0][j])-(datas[0][i]+datas[1][j]);
            s.update_seg(1,0,n-1,i,j,temp);
            mx=max(mx,s.find_seg(1,0,n-1,0,n-1).val);
            cout<<i+1<<' '<<j+1<<' '<<s.find_seg(1,0,n-1,0,n-1).val<<' '<<temp<<'\n';
            s.update_seg(1,0,n-1,i,j,-temp);
            // cout<<"DE "<<s.find_seg(1,0,n-1,0,n-1).val<<'\n';
        }
    }
    cout<<mx<<'\n';
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

