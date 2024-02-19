
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

int ans[N];
pii ran[N];
bool visited[N];

void Solve(){
    int n;
    char x;
    cin>>n;
    rng(i,0,n-1) ran[i]={1,n-2};
    if(n==1){
        cout<<"! 1"<<endl;
        cin>>n;
        return;
    }


    int cur=0; // 현재 x의 값
    int k=1;
    fill(visited,visited+n,0);
    visited[0]=visited[n-1]=1;
    while((1<<k)<n) k++; // 2^k는 n이상의 최소의 거듭제곱

    //cout<<"deb "<<k<<'\n';


    // get mx
    int mxidx=0, mnidx;
    while(true){
        cout<<"? "<<1<<endl;
        cin>>x;
        if(x=='=') break;
    }
    int last=0; // 가장 마지막 최대 idx
    rng(i,1,n-1){
        cout<<"? "<<i+1<<endl;
        cin>>x;
        if(x=='<'){
            cout<<"? "<<last+1<<endl;
            cin>>x;
            assert(x=='>');
        } 
        else if(x=='>'){
            while(true){
                cout<<"? "<<i+1<<endl;
                cin>>x;
                if(x=='=') break;
                assert(x=='>');
            }
            last=i;
        }
        else{
            assert(false);
        }
    }
    mxidx=last;
    ran[mxidx]={n-1,n-1};


    while(true){
        cout<<"? "<<1<<endl;
        cin>>x;
        if(x=='=') break;
    }
    last=0; // 가장 마지막 최대 idx
    rng(i,1,n-1){
        cout<<"? "<<i+1<<endl;
        cin>>x;
        if(x=='>'){
            cout<<"? "<<last+1<<endl;
            cin>>x;
            assert(x=='<');
        } 
        else if(x=='<'){
            while(true){
                cout<<"? "<<i+1<<endl;
                cin>>x;
                if(x=='=') break;
                assert(x=='<');
            }
            last=i;
        }
        else{
            assert(false);
        }
    }
    mnidx=last;
    ran[mnidx]={0,0};
    visited[0]=visited[n-1]=1;

    gnr(i,k-1,0){
        int mul=(1<<i);
        vc<int> tars;
        rng(j,1,n/mul){
            cout<<j*mul-1<<endl;
            if(!visited[j*mul-1]){
                visited[j*mul-1]=1;
                tars.pb(j*mul-1);
            }
        }
        if(i%2==0) reverse(all(tars));
        for(auto val : tars){
            // make it val
            while(cur!=val){
                if(cur<val){
                    cout<<"? "<<mxidx+1<<endl;
                    cin>>x;
                    assert(x=='>');
                    cur++;
                }
                else{
                    cout<<"? "<<mnidx+1<<endl;
                    cin>>x;
                    assert(x=='<');
                    cur--;
                }
            }
            rng(idx, 0, n-1){
                if(ran[idx].fi<=val && ran[idx].se>=val){
                    cout<<"? "<<idx+1<<endl;
                    cin>>x;
                    if(x=='='){
                        ran[idx]={val,val};
                    }
                    else if(x=='>'){
                        ran[idx]={val+1,ran[idx].se};
                        cout<<"? "<<mnidx+1<<endl;
                        cin>>x;
                        assert(x=='<');
                    }
                    else{
                        ran[idx]={ran[idx].fi,val-1};
                        cout<<"? "<<mxidx+1<<endl;
                        cin>>x;
                        assert(x=='>');
                    }
                }
            }
        }
    }



    cout<<"! ";
    rng(i,0,n-1){
        assert(ran[i].fi==ran[i].se);
        cout<<ran[i].fi+1<<' ';
    }
    cout<<endl;
    int rttt;
    cin>>rttt;
    assert(rttt!=-1);
    return ;

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

