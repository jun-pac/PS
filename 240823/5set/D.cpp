
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

vc<int> edges[N];
int iton[N], ntoi[N];
int sz[N];
int state[N];
int cnt;
int datas[N];

void DFS(int idx, int s){
    iton[idx]=cnt;
    ntoi[cnt]=idx;
    sz[cnt]=s-1;
    cnt++;
    for(auto i : edges[idx]){
        DFS(i,s/2);
    }
}

class node{
public:
    node(){}
    node operator+(node b){
        node result;
        result.mx=max(mx,b.mx);
        result.mn=min(mn,b.mn);
        return result;
    }
    int mx=0, mn=INF;
};


class segtree{
public:	
	node seg[1<<19];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].mx=datas[l];
            seg[idx].mn=datas[l];
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx].mx=val; // Modify
            seg[idx].mn=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	node find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        node ans;
        ans.mx=0;
        ans.mn=INF;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) edges[i].clear(); 
    rng(i,1,n-1){
        int a;
        cin>>a;
        a--;
        edges[a].push_back(i);
    }
    cnt=0;
    DFS(0,n+1);
    // rng(i,0,n-1) cout<<iton[i]<<' ';
    // cout<<"\n";
    // rng(i,0,n-1) cout<<sz[i]<<' ';
    // cout<<"\n";
    rng(i,0,n-1){
        int x;
        cin>>x;
        x--;
        datas[i]=iton[x];
    }
    seg.build_seg(1,0,n-1);
    
    int num=0; // sum of state
    rng(i,0,n-1){
        if(sz[i]==1){
            state[i]=1;
            num++;
        }
        else{
            auto temp=seg.find_seg(1,0,n-1,i+1,i+sz[i]-1);
            if(datas[i]+1==temp.mn && datas[i]+sz[i]-1==temp.mx){
                state[i]=1;
                num++;
            }
            else state[i]=0;
        }
    }
    rng(i,0,q-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        swap(datas[a],datas[b]);
        seg.update_seg(1,0,n-1,a,datas[a]);
        seg.update_seg(1,0,n-1,b,datas[b]);
        while(true){
            if(sz[a]!=1){
                auto temp=seg.find_seg(1,0,n-1,a+1,a+sz[a]-1);
                if(datas[a]+1==temp.mn && datas[a]+sz[a]-1==temp.mx){
                    if(state[a]==0){
                        state[a]=1;
                        num++;
                    }
                }
                else{
                    if(state[a]==1){
                        state[a]=0;
                        num--;
                    }
                }
            }
            int aa=ntoi[a];
            if(aa==0) break;
            aa=(aa+1)/2-1;
            a=iton[aa];
        }
        while(true){
            if(sz[b]!=1){
                auto temp=seg.find_seg(1,0,n-1,b+1,b+sz[b]-1);
                if(datas[b]+1==temp.mn && datas[b]+sz[b]-1==temp.mx){
                    if(state[b]==0){
                        state[b]=1;
                        num++;
                    }
                }
                else{
                    if(state[b]==1){
                        state[b]=0;
                        num--;
                    }
                }
            }
            int bb=ntoi[b];
            if(bb==0) break;
            bb=(bb+1)/2-1;
            b=iton[bb];
        }
        //cout<<"num "<<num<<'\n';
        if(n==num){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
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

