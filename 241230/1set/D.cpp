
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)



class segtree{
public:	
	pii seg[1<<19];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]={0,l}; // val, idx
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		if(seg[2*idx].fi) seg[idx]=seg[2*idx];
        else seg[idx]=seg[2*idx+1]; // 불가능하면 어차피 0주면 됨
	}

	void update_seg(int idx, int l, int r, int t_idx){
		if(l==r){
			seg[idx]={1,l}; // 가능하다!
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx);
		else update_seg(2*idx+1,mid+1,r,t_idx);
		if(seg[2*idx].fi) seg[idx]=seg[2*idx];
        else seg[idx]=seg[2*idx+1]; // 불가능하면 어차피 0주면 됨
	}

	pii find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        pii ans={0,-1};
		if(t_l<=mid){
            pii res=find_seg(2*idx,l,mid,t_l,t_r);
            if(res.fi) ans=res;
        }
		if(t_r>mid){
            pii res=find_seg(2*idx+1,mid+1,r,t_l,t_r);
            if(res.fi) ans=res;
        }
		return ans;
	}
};

int datas[3][N]; // perm
int inv_datas[3][N];
segtree seg[3];
pii how_to_get[N]; // where, pred_idx


void Solve(){
    int n;
    cin>>n;
    rng(j,0,2){
        rng(i,0,n-1){
            int x;
            cin>>x;
            datas[j][n-x]=i;
            inv_datas[j][i]=n-x;
        }
        // rng(i,0,n-1) cout<<datas[j][i]+1<<' ';
        // cout<<'\n';
    }
    rng(j,0,2) seg[j].build_seg(1,0,n-1);
    
    rng(i,0,n-1) how_to_get[i]={-1,-1};
    rng(i,0,n-1){
        int flag=0;
        if(i==0){
            how_to_get[i]={INF,INF};
            flag=1;
        }
        else{
            rng(j,0,2){
                // cout<<"why "<<i<<' '<<j<<' '<<inv_datas[i][j]<<'\n';
                if(inv_datas[j][i]==0) continue;
            
                pii temp=seg[j].find_seg(1,0,n-1,0,inv_datas[j][i]-1);
                // cout<<temp.fi<<' '<<temp.se<<'\n';
                if(temp.fi){
                    how_to_get[i]={j,datas[j][temp.se]};
                    assert(datas[j][temp.se]<i);
                    flag=1;
                    break;
                }
            }
        }
        // cout<<i+1<<' '<<flag<<' '<<how_to_get[i].fi<<' '<<how_to_get[i].se+1<<'\n';
        if(flag){
            rng(j,0,2){
                // cout<<"upd "<<j<<' '<<inv_datas[j][i]<<'\n';
                seg[j].update_seg(1,0,n-1,inv_datas[j][i]);
            }
        }
    }
    if(how_to_get[n-1].fi==-1){
        cout<<"NO\n";
    }
    else{
        vc<pii> ans;
        int cur=n-1;
        while(cur!=0){
            ans.push_back({how_to_get[cur].fi,cur});
            cur=how_to_get[cur].se;
        }
        reverse(all(ans));
        cout<<"YES\n";
        cout<<ans.size()<<'\n';
        rng(i,0,(int)ans.size()-1){
            if(ans[i].fi==0){
                cout<<"q ";
            }
            else if(ans[i].fi==1){
                cout<<"k ";
            }
            else{
                cout<<"j ";
            }
            cout<<ans[i].se+1<<'\n';
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

