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
    typedef unsigned int ui;
    typedef unsigned long long ull;

    template<typename T>
    inline T umax(T &u, T v){return u = max(u, v);}
    template<typename T>
    inline T umin(T &u, T v){return u = min(u, v);}

    ll p[1100000], q[1100000];
    string a,b;

    #define MOD 998244353
    #define MAX_DIGIT 60

    // Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
    ll ari_inv(ll num){
        // Calculate num^(MOD-2)
        ll res=1, mult=num;
        for(int i=0; i<MAX_DIGIT; i++){
            if((MOD-2)&(1LL<<i)){
                res=(res*mult)%MOD;
            }
            mult=(mult*mult)%MOD;
        }
        return res;
    }

    int main(){
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin>>t;
        //for(int i=0; i<10; i++) cout<<"arithmatic inv of "<<i<<" is : "<<ari_inv(i)<<endl;

        while(t--){
            ll n;
            cin>>n;
            cin>>a>>b;
            int cnt=0;
            for(int i=0; i<n; i++){
                if(a[i]!=b[i]) cnt++;
            }
            p[n]=1, q[n]=1;
            for(ll i=n-1; i>0; i--){
                ll k=n-i;
                p[i]=(p[i+1]*k+n*q[i+1])%MOD;
                q[i]=q[i+1]*i%MOD;
            }
            ll rp=0, rq=q[1];
            ll mult=1;
            for(int i=1; i<=cnt; i++){
                if(i==1) rp=(rp+p[i])%MOD;
                else{
                    mult=(mult*(i-1))%MOD;
                    rp=(rp+p[i]*mult)%MOD;
                }
            }
            //cout<<"res : "<<rp<<' '<<rq<<endl;
            cout<<((rp*ari_inv(rq))%MOD)<<endl;
        }
        return 0;
    }