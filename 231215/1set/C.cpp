// 
//./C<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

vector<pair<ll,ll>> mss[100020];
map<ll,ll> tot_num;
pair<ll,pair<ll,ll>> mul_info[100020]; // tot_c,{l,r}
vector<pair<ll,ll>> fuck_vec[100020]; //{idx, x}; 
#define INFL 200000000000000007

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll m; // multiset수
        cin>>m;
        tot_num.clear();
        for(int i=0; i<m; i++) mss[i].clear();
        ll totl=0, totr=0, totrl=0, sumn=0; // sumn은 서로다른 숫자의 개수
        bool big_flag=false, too_many_flag=false;
        for(int i=0; i<m; i++){
            ll n,l,r;
            cin>>n>>l>>r;
            totl+=l, totr+=r;
            totrl+=(r-l);
            mul_info[i].se.fi=l;
            mul_info[i].se.se=r;

            if(totl>INFL) big_flag=true;
            if(r-l>200000) too_many_flag=true;
            ll tot_c=0;
            mss[i].reserve(n);
            for(int j=0; j<n; j++){
                ll a; // 값
                cin>>a;
                mss[i].push_back({a,0});
            }
            for(int j=0; j<n; j++){
                ll c;
                cin>>c;
                mss[i][j].se=c;
                tot_c+=c;
                if(tot_num[mss[i][j].fi]==0) sumn++;
                tot_num[mss[i][j].fi]+=c;
            }
            mul_info[i].fi=tot_c;
            //sort(mss[i].begin(),mss[i].end());
        }
        
        if(big_flag|| too_many_flag || totrl+1>sumn){
            cout<<0<<endl;
        }
        else{
            bool zero_flag=false;
            for(int i=totl; i<=totr; i++){
                if(tot_num[i]==0){
                    zero_flag=true;
                    break;
                }
            }
            if(zero_flag){
                cout<<0<<endl;
                continue;
            }


            //cout<<"cs "<<totl<<' '<<totr<<' '<<totrl<<endl;
            ll mn=INFL; // ans는 totr보다 작다.
            for(int i=0; i<=totrl+1; i++) fuck_vec[i].clear();
            for(int i=0; i<m; i++){
                for(int j=0; j<mss[i].size(); j++){
                    if(mss[i][j].fi>=totl && mss[i][j].fi<=totr) fuck_vec[mss[i][j].fi-totl].pb({i,mss[i][j].se});
                }
            }
            for(ll i=totl; i<=totr; i++){
                // i는 len을 의미. 우리는 i개를 뽑을거고, 그 와중에 뽑힌 i의 개수를 최소화 할거임
                // 지금 이건 min(sumn+1,100000)이하임
                // totr까지는 문제가 없는게 기본이다.
                // 어떤 multiset이 i를 가지고 있다면, 빼줘야 하기는 한다.
                ll mx_draw=totr; // 주어진 조건에서 penalty없이 뽑을 수 있는 최대의 i
                //cout<<"draw i "<<i<<' '<<totr<<endl;
                ll must_penalty=0;
                for(auto temp : fuck_vec[i-totl]){
                    ll tl=mul_info[temp.fi].se.fi;
                    ll tr=mul_info[temp.fi].se.se;
                    ll totc=mul_info[temp.fi].fi;
                    ll x=temp.se;
                    if(tl>totc-x) must_penalty+=tl-totc+x;
                    //cout<<temp.fi<<' '<<x<<' '<<tl<<' '<<tr<<' '<<totc<<' '<<endl;
                    if(tl>=totc-x){
                        mx_draw=mx_draw-tr+totc-x;
                    }
                    else if(tr<=totc-x) mx_draw-=0;
                    else mx_draw=mx_draw-(tr)+(totc-x);
                }
                //cout<<mx_draw<<endl;
                ll temp_mn=max((i<=mx_draw?0LL:i-mx_draw),must_penalty);
                mn=min(mn,temp_mn);
                //cout<<"temp ans : "<<must_penalty<<' '<<temp_mn<<endl;
            }
            cout<<mn<<endl;
        }
        
    }
    return 0;
}