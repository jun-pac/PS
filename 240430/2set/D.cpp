
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

#define INF 1000000007 

ll score[1010][1010];
ll cur_mx[1010][5050];
ll num[1010];

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1){
        if(i<18) num[i]=min((1<<(i+1)),k);
        else num[i]=k;
    }

    rng(i,0,n-1){
        rng(j,i,n-1){
            cin>>score[i][j];
        }
    }

    if(k==1){
        cur_mx[0][0]=max(score[0][0],0LL);
    }
    else{
        cur_mx[0][0]=min(score[0][0],0LL);
        cur_mx[0][1]=max(score[0][0],0LL);
    }    
    //cout<<"zero : "<<cur_mx[0][0]<<' '<<cur_mx[0][1]<<'\n';
    rng(i,1,n-1){
        //cout<<"idx, num[idx] : "<<i<<' '<<num[i]<<'\n';
        ll l=-INF,r=INF;
        while(l<r){
            ll mid=(l+r+1)/2;

            ll cnt=0; //(cur_mx[idx][j]>=l-score[idx+1][i]) 인 j의 개수
            rng(dur,0,i-1){
                ll idx=(i-1-dur);
                ll pos=lower_bound(cur_mx[idx],cur_mx[idx]+num[idx],mid-(idx==i-1?0:score[idx+2][i]))-cur_mx[idx];
                cnt+=(num[idx]-pos);
            }
            if(score[1][i]>=mid) cnt++;
            if(score[0][i]>=mid) cnt++;

            if(cnt>=num[i]) l=mid;
            else r=mid-1;
        }
        // l보다 큰 것 다 모으고, 부족하면 l을 집어넣는다.
        //cout<<"L : "<<l<<"\n";

        ll cnt=0;
        rng(dur,0,i-1){
            ll idx=(i-1-dur);
            ll j=num[idx]-1;
            while(j>=0){
                if(cur_mx[idx][j]<=l-(idx==i-1?0:score[idx+2][i])) break;
                cur_mx[i][cnt++]=cur_mx[idx][j]+(idx==i-1?0:score[idx+2][i]);
                j--;
            }
        }
        if(score[1][i]>l) cur_mx[i][cnt++]=score[1][i];
        if(score[0][i]>l) cur_mx[i][cnt++]=score[0][i];
        while(cnt<num[i]) cur_mx[i][cnt++]=l;
        sort(cur_mx[i],cur_mx[i]+num[i]);
    }

    gnr(i,k-1,0) cout<<cur_mx[n-1][i]<<' ';
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

