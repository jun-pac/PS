// 
//./D<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;

const ll MOD=1000000007;

pair<ll,ll> gval[100];
vector<pair<ll,ll>> durs; // start, value;

inline ll get_gval(ll i, ll tar){
    // floor [log i tar]
    ll temp=1;
    ll cnt=0;
    while(temp<=tar/i){
        temp*=i;
        cnt++;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t;

    for(ll i=2; i<61; i++){
        gval[i].fi=get_gval(i,(1LL<<i));
        gval[i].se=get_gval(i,(1LL<<(i+1))-1);
        if(gval[i].fi!=gval[i].se){
            ll le=(1LL<<i);
            ll re=(1LL<<(i+1))-1;
            //수렴 포인트는 마지막으로 gval[i].fi와 같은 값이 나오면 된다.
            while(le<re){
                ll mid=(le+re+1)/2;
                if(get_gval(i,mid)==gval[i].fi) le=mid;
                else re=mid-1;
            }
            durs.push_back({(1LL<<i),gval[i].fi});
            durs.push_back({le+1,gval[i].se});
        }
        else{
            durs.push_back({(1LL<<i),gval[i].fi});
        }
    }
    durs.push_back({(1LL<<61),-1});

    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        ll res=0;
        for(ll i=0; i<(ll)durs.size()-1; i++){
            ll start=durs[i].fi;
            ll next=durs[i+1].fi; //[st, next-1]
            ll val=durs[i].se;
            //assert(val>0);
            if(start<=r && next>l){
                ll dur=(min(next,r+1)-max(l,start))%MOD;
                res=(res+dur*val)%MOD;
            }
        }
        cout<<(res%MOD+MOD)%MOD<<endl;
    }
    return 0;
}