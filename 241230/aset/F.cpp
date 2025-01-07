
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

int datas[N];

pll qs[N];
pair<int,ll> DP[N][64]; 
class node{
public:
    pll DP[64]; // {최소개수, 가짓수}
    node(){}
    node(int val){
        rng(i,0,63) DP[i]={-1,0};
        DP[val]={1,1};
    }
    node operator+(node &b){
        node res;
        rng(i,0,63) res.DP[i]=DP[i]; // 일단은 그대로 유지
        rng(j,0,63){
            if(b.DP[j].fi!=-1){
                if(res.DP[j].fi==-1 || b.DP[j].fi<res.DP[j].fi) res.DP[j]=b.DP[j];
                else if(b.DP[j].fi==res.DP[j].fi) res.DP[j].se=res.DP[j].se+b.DP[j].se;
            }
        }
        // 무조건 양쪽에서 한 개 이상은 남기는 경우
        rng(i,0,63){
            if(DP[i].fi==-1) continue;
            rng(j,0,63){
                if(b.DP[j].fi!=-1){ // 일단 둘 다 가능해야 가치가 있음
                    int t=DP[i].fi+b.DP[j].fi;
                    int k=i^j;
                    int l=res.DP[k].fi;
                    if(l==-1 ||  t < l){
                        // 우리로 replace
                        res.DP[k]={t, (DP[i].se * b.DP[j].se)%MOD};
                    }
                    else if(t == l){
                        // 우리를 더함
                        res.DP[k].se=(res.DP[k].se+(DP[i].se * b.DP[j].se))%MOD;
                    }
                }
            }
        }
        return res;
    }
};

class segtree{
public:	
	node seg[1<<18];
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=node(datas[l]);
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]);
	}

	node find_seg(int idx, int l, int r, int t_l, int t_r, bool top){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        node ans;
        bool clean=1;
		if(t_l<=mid){
            clean=0;
            ans=find_seg(2*idx,l,mid,t_l,t_r,0);
        }
		if(t_r>mid){
            if(clean) ans=find_seg(2*idx+1,mid+1,r,t_l,t_r,0);
            else{
                if(top){
                    node temp=find_seg(2*idx+1,mid+1,r,t_l,t_r,0);
                    if(temp.DP[0].fi!=-1){
                        if(ans.DP[0].fi==-1 || temp.DP[0].fi<ans.DP[0].fi) ans.DP[0]=temp.DP[0];
                        else if(temp.DP[0].fi==ans.DP[0].fi) ans.DP[0].se=(ans.DP[0].se+temp.DP[0].se)%MOD;
                    }
                    rng(i,0,63) if(ans.DP[i].fi!=-1 && temp.DP[i].fi!=-1){
                        if(ans.DP[0].fi==-1 || ans.DP[i].fi+temp.DP[i].fi < ans.DP[0].fi){
                            ans.DP[0]={ans.DP[i].fi+temp.DP[i].fi,ans.DP[i].se*temp.DP[i].se%MOD};
                        }
                        else if(ans.DP[i].fi+temp.DP[i].fi == ans.DP[0].fi){
                            ans.DP[0].se=(ans.DP[0].se+ans.DP[i].se*temp.DP[i].se)%MOD;
                        }
                    }
                }
                else ans=(find_seg(2*idx+1,mid+1,r,t_l,t_r,0)+ans);
            }
        }
		return ans;
	}
};

segtree seg;

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    seg.build_seg(1,0,n-1);

    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        if(a>b){
            cout<<-1<<'\n';
            continue;
        }
        node res=seg.find_seg(1,0,n-1,a,b,1);
        if(res.DP[0].fi==-1) cout<<-1<<'\n';
        else cout<<(b-a+1)-res.DP[0].fi<<' '<<(res.DP[0].se%MOD+MOD)%MOD<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

