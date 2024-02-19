
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

int datas[N], tar[N], cuts[N];
vc<int> pos[N]; // 각각의 값이 있는
map<int,int> comp; // 좌표압축값
int num_cuts[N]; // 이건 comp에 해당하는 값에 대해서만


class segtree{
public:	
	int seg[1<<19];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=tar[l];
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=max(seg[2*idx],seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]=val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=max(seg[2*idx],seg[2*idx+1]); // Modify
	}

	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=max(ans,find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=max(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;



void Solve(){
    int n,newval=1; // comp는 1-based일 것을 알 수 있음. 
    cin>>n;
    rng(i,0,n) pos[i].clear();
    comp.clear();
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1){
        cin>>tar[i];
        if(tar[i]==datas[i]) continue;
        if(comp[tar[i]]==0) comp[tar[i]]=newval++;
        pos[comp[tar[i]]].pb(i);
    }
    seg.build_seg(1,0,n-1);
    //cout<<"newval "<<newval<<'\n';
    // rng(i,1,newval-1){
    //     assert(pos[i].size()>0);
    //     cout<<"same val "<<i<<' '<<tar[pos[i][0]]<<'\n';
    //     rng(j,0,(int)pos[i].size()-1) cout<<pos[i][j]<<' '; cout<<'\n';
    // }


    int m;
    cin>>m;
    rng(i,0,m-1) cin>>cuts[i];
    fill(num_cuts,num_cuts+n+1,0);
    rng(i,0,m-1){
        if(comp[cuts[i]]!=0) num_cuts[comp[cuts[i]]]++;
    }
    // rng(i,1,newval-1){
    //     cout<<"cuts,num "<<i<<' '<<tar[pos[i][0]]<<' '<<num_cuts[i]<<'\n';
    // }    


    bool flag=1;
    // a에서 segment되어있지 않은게 b에서 segment될 수 있죠..
    rng(i,0,n-1) if(datas[i]<tar[i]) flag=0;
    if(!flag){
        //rng(i,0,n-1) cout<<datas[i]<<' '; cout<<'\n';
        //rng(i,0,n-1) cout<<tar[i]<<' '; cout<<'\n';
        //cout<<"NO1";
        cout<<"NO\n";
        return;
    } 


    rng(i,0,n-1){
        if(datas[i]==tar[i]) continue;
        if(comp[tar[i]]==0){
            flag=0;
            break;
        }
    }
    if(!flag){
        //cout<<"NO2";
        cout<<"NO\n";
        return;
    }

    // 각 pos들을 순서대로 돌면서, cut의 개수와, rmq로 계산되는 최소 cut의 개수를 비교하면 될 것 같다.
    rng(i,1,newval-1){
        //num_cuts[i]과 비교
        int temp=0;
        int val=tar[pos[i][0]]; // 실제 값
        rng(j,0,(int)pos[i].size()-1){
            if(j==0) temp++;
            else{
                if(seg.find_seg(1,0,n-1,pos[i][j-1],pos[i][j])>val) temp++;
            }
        }
        //cout<<"i val cut tmp "<<i<<' '<<val<<' '<<num_cuts[i]<<' '<<temp<<'\n';
        if(temp>num_cuts[i]){
            flag=0;
            break;
        }
    }
    cout<<(flag?"YES\n":"NO\n");
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

