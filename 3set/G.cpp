
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

#define N 300030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

string a[5000], b[5000];
ll DP1[2020][2020], DP2[2020][2020], DP3[2020][2020];
ll bh1[2020][2020], bh2[2020][2020], bh3[2020][2020];
ll ah1, ah2, ah3;
bool check[2002][2002];
int num[2002][2002];

int na,ma;
int nb,mb;

#define MAX_DIGIT 62

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

void build_hash1(ll p, ll q){
    ll qmul=1;
    rng(i,0,nb-1){
        ll pmul=1;
        rng(j,0,mb-1){
            DP1[i][j]=(b[i][j]-'a')*pmul%MOD*qmul%MOD;
            if(i!=0) DP1[i][j]+=DP1[i-1][j];
            if(j!=0) DP1[i][j]+=DP1[i][j-1];
            if(i!=0 && j!=0) DP1[i][j]-=DP1[i-1][j-1];
            DP1[i][j]%=MOD;
            pmul*=p;
            pmul%=MOD;
        }
        // cout<<'\n';
        qmul*=q;
        qmul%=MOD;
    }

    ah1=0;
    qmul=1;
    rng(i,0,na-1){
        ll pmul=1;
        rng(j,0,ma-1){
            ah1+=pmul*qmul%MOD*(a[i][j]-'a');
            ah1%=MOD; 
            pmul=pmul*p%MOD;   
        }
        qmul=qmul*q%MOD;
    }


}

void build_hash2(ll p, ll q){
    ll qmul=1;
    rng(i,0,nb-1){
        ll pmul=1;
        rng(j,0,mb-1){
            DP2[i][j]=(b[i][j]-'a')*pmul%MOD*qmul%MOD;
            if(i!=0) DP2[i][j]+=DP2[i-1][j];
            if(j!=0) DP2[i][j]+=DP2[i][j-1];
            if(i!=0 && j!=0) DP2[i][j]-=DP2[i-1][j-1];
            DP2[i][j]%=MOD;
            pmul*=p;
            pmul%=MOD;
        }
        // cout<<'\n';
        qmul*=q;
        qmul%=MOD;
    }
    ah2=0;
    qmul=1;
    rng(i,0,na-1){
        ll pmul=1;
        rng(j,0,ma-1){
            ah2+=pmul*qmul%MOD*(a[i][j]-'a');
            ah2%=MOD; 
            pmul=pmul*p%MOD;   
        }
        qmul=qmul*q%MOD;
    }
}


void build_hash3(ll p, ll q){
    ll qmul=1;
    rng(i,0,nb-1){
        ll pmul=1;
        rng(j,0,mb-1){
            DP3[i][j]=(b[i][j]-'a')*pmul%MOD*qmul%MOD;
            if(i!=0) DP3[i][j]+=DP3[i-1][j];
            if(j!=0) DP3[i][j]+=DP3[i][j-1];
            if(i!=0 && j!=0) DP3[i][j]-=DP3[i-1][j-1];
            DP3[i][j]%=MOD;
            pmul*=p;
            pmul%=MOD;
        }
        // cout<<'\n';
        qmul*=q;
        qmul%=MOD;
    }
    ah3=0;
    qmul=1;
    rng(i,0,na-1){
        ll pmul=1;
        rng(j,0,ma-1){
            ah3+=pmul*qmul%MOD*(a[i][j]-'a');
            ah3%=MOD; 
            pmul=pmul*p%MOD;   
        }
        qmul=qmul*q%MOD;
    }
}


void Solve(){
    cin>>na>>ma;
    rng(i,0,na-1) cin>>a[i];
    cin>>nb>>mb;
    rng(i,0,nb-1) cin>>b[i];
    rng(i,0,nb-1) fill(check[i], check[i]+mb, 1);
    rng(i,0,na-1) fill(check[i], check[i]+ma, 0);
    check[na-1][ma-1]=1;
    
    build_hash1(7,4999);
    ll pp=ari_inv(7);
    ll qq=ari_inv(4999);
    ll qmul=1;
    rng(i,na-1,nb-1){
        ll pmul=1;
        rng(j,ma-1,mb-1){
            ll val1=DP1[i][j]-(i!=na-1?DP1[i-na][j]:0)-(j!=ma-1?DP1[i][j-ma]:0)+(i!=na-1 && j!=ma-1?DP1[i-na][j-ma]:0);
            val1=val1%MOD*pmul%MOD*qmul%MOD;
            if((val1%MOD+MOD)%MOD!=(ah1%MOD+MOD)%MOD) check[i][j]=0;
            pmul*=pp;
            pmul%=MOD;
        }
        qmul*=qq;
        qmul%=MOD;
    }

    // build_hash2(151,41);
    // pp=ari_inv(151);
    // qq=ari_inv(41);
    // qmul=1;
    // rng(i,na-1,nb-1){
    //     ll pmul=1;
    //     rng(j,ma-1,mb-1){
    //         ll val1=DP2[i][j]-(i!=na-1?DP2[i-na][j]:0)-(j!=ma-1?DP2[i][j-ma]:0)+(i!=na-1 && j!=ma-1?DP2[i-na][j-ma]:0);
    //         val1=val1%MOD*pmul%MOD*qmul%MOD;
    //         if((val1%MOD+MOD)%MOD!=(ah2%MOD+MOD)%MOD) check[i][j]=0;
    //         pmul*=pp;
    //         pmul%=MOD;
    //     }
    //     qmul*=qq;
    //     qmul%=MOD;
    // }
    

    // build_hash3(4999,17);
    // pp=ari_inv(4999);
    // qq=ari_inv(17);
    // qmul=1;
    // rng(i,na-1,nb-1){
    //     ll pmul=1;
    //     rng(j,ma-1,mb-1){
    //         ll val1=DP3[i][j]-(i!=na-1?DP3[i-na][j]:0)-(j!=ma-1?DP3[i][j-ma]:0)+(i!=na-1 && j!=ma-1?DP3[i-na][j-ma]:0);
    //         val1=val1%MOD*pmul%MOD*qmul%MOD;
    //         if((val1%MOD+MOD)%MOD!=(ah3%MOD+MOD)%MOD) check[i][j]=0;
    //         pmul*=pp;
    //         pmul%=MOD;
    //     }
    //     qmul*=qq;
    //     qmul%=MOD;
    // }


    // aggregation
    rng(i,na-1,nb-1){
        rng(j,ma-1,mb-1){
            num[i][j]=check[i][j];
            if(i!=na-1) num[i][j]+=num[i-1][j];
            if(j!=ma-1) num[i][j]+=num[i][j-1];
            if(i!=na-1 && j!=ma-1) num[i][j]-=num[i-1][j-1];
        }
    }

    // rng(i,0,nb-1){
    //     rng(j,0,mb-1) cout<<check[i][j];
    //     cout<<'\n';
    // }

    rng(i,0,nb-1){
        rng(j,0,mb-1){
            int val = num[min(nb-1,i+na-1)][min(mb-1,j+ma-1)];
            if(i!=0) val-=num[i-1][min(mb-1,j+ma-1)];
            if(j!=0) val-=num[min(nb-1,i+na-1)][j-1];
            if(i!=0 && j!=0) val+=num[i-1][j-1];

            if(val) cout<<b[i][j];
            else cout<<'.';
        }
        cout<<'\n';
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

