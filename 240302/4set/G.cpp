
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

int datas[N];

class lazy_cnt_tree{
public:
	lazy_cnt_tree(){}
	set<pii> seg[1<<19]; // {val, num} // num은 언제 지웠는지
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].insert({datas[l],-1});
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
        seg[idx].insert({0,-1}); // 어차피 mx에 영향 안 줌
	}

	void update_seg(int idx, int l, int r, int t_l, int t_r, int val, int num){
		if(t_l<=l && r<=t_r){
			seg[idx].insert({val,num});
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val,num);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val,num);
	}

    void delete_seg(int idx, int l, int r, int t_l, int t_r, int val, int num){
		if(t_l<=l && r<=t_r){
			seg[idx].erase({val,num});
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) delete_seg(2*idx,l,mid,t_l,t_r,val,num);
		if(t_r>mid) delete_seg(2*idx+1,mid+1,r,t_l,t_r,val,num);
	}

	int find_seg(int idx, int l, int r, int t_idx){
		if(l==r) return (prev(seg[idx].end())->fi);
		int res=(prev(seg[idx].end())->fi); // 원소가 하나는 있음이 보장됨.
		int mid=(l+r)>>1;
		if(t_idx<=mid) res=max(res,find_seg(2*idx,l,mid,t_idx));
		if(t_idx>mid) res=max(res,find_seg(2*idx+1,mid+1,r,t_idx));
		return res;
	}
};

lazy_cnt_tree lct;
array<int,3> qs[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    lct.build_seg(1,0,n-1);
    int c,a,b,x;
    int q;
    cin>>q;
    rng(i,0,q-1){
        cin>>c;
        if(c==1){
            cin>>a>>b>>x;
            a--, b--;
            lct.update_seg(1,0,n-1,a,b,x,i);
            qs[i]={a,b,x};
        }
        else if(c==2){
            cin>>a;
            a--;
            lct.delete_seg(1,0,n-1,qs[a][0],qs[a][1],qs[a][2],a);
        }
        else{
            cin>>a;
            a--;
            cout<<lct.find_seg(1,0,n-1,a)<<'\n';
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

