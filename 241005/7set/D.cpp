
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

// h<=632
vc<int> seg[700];

class segtree{
public:	
	segtree(){}
	void build_seg(int row, int idx, int l, int r){
		if(l==r){
			seg[row][idx]=1;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(row, 2*idx,l,mid);
		build_seg(row, 2*idx+1,mid+1,r);
		seg[row][idx]=(seg[row][2*idx]+seg[row][2*idx+1]); 
	}
	void update_seg(int row, int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[row][idx]=val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(row, 2*idx,l,mid,t_idx, val);
		else update_seg(row, 2*idx+1,mid+1,r,t_idx, val);
		seg[row][idx]=(seg[row][2*idx]+seg[row][2*idx+1]); // Modify
	}

	int find_seg(int row, int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[row][idx];
		int mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=(ans+find_seg(row, 2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(row, 2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree s;
vc<int> datas[700];

void Solve(){
    int h,w,q;
    cin>>h>>w>>q;
    bool swapped=0;
    if(h>w){
        swap(h,w);
        swapped=1;
    }
    rng(i,0,h-1) seg[i].resize(4*w,0);
    rng(i,0,h-1) datas[i].resize(w,1);
    
    rng(i,0,h-1) s.build_seg(i,1,0,w-1);
    

    int delnum=0;
    rng(qq,0,q-1){
        int r,c;
        cin>>r>>c;
        r--, c--;
        
        if(swapped) swap(r,c);
        //cout<<r<<' '<<c<<' '<<h<<' '<<w<<'\n';

        assert(r<h && c<w);

        if(datas[r][c]==1){
            s.update_seg(r,1,0,w-1,c,0);
            datas[r][c]=0;
            delnum++;
        }
        else{
            if(s.find_seg(r,1,0,w-1,c,w-1)!=0){
                int le=c, re=w-1;
                while(le<re){
                    int mid=(le+re)>>1;
                    if(s.find_seg(r,1,0,w-1,c,mid)!=0) re=mid;
                    else le=mid+1; 
                }
                s.update_seg(r,1,0,w-1,le,0);
                datas[r][le]=0;
                delnum++;
            }
            if(s.find_seg(r,1,0,w-1,0,c)!=0){
                int le=0, re=c;
                while(le<re){
                    int mid=(le+re+1)>>1;
                    if(s.find_seg(r,1,0,w-1,mid,c)!=0) le=mid;
                    else re=mid-1; 
                }
                s.update_seg(r,1,0,w-1,le,0);
                datas[r][le]=0;
                delnum++;
            }
            // 위로
            int cur=r-1;
            while(cur>=0){
                if(datas[cur][c]==1){
                    s.update_seg(cur,1,0,w-1,c,0);
                    datas[cur][c]=0;
                    delnum++;
                    break;
                }
                cur--;
            }
            // 아래로
            cur=r+1;
            while(cur<h){
                if(datas[cur][c]==1){
                    s.update_seg(cur,1,0,w-1,c,0);
                    datas[cur][c]=0;
                    delnum++;
                    break;
                }
                cur++;
            }
        }
        // cout<<"cur delnum : "<<delnum<<'\n';
        // rng(i,0,h-1){
        //     rng(j,0,w-1) cout<<datas[i][j]<<' ';
        //     cout<<'\n';
        // }
        // rng(i,0,h-1){
        //     rng(j,0,w-1) cout<<s.find_seg(i,1,0,w-1,j,j)<<' ';
        //     cout<<'\n';
        // }
    }
    cout<<h*w-delnum<<'\n';
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

