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

#define MOD 1000000007
#define N 20000

using namespace std;

long long fact[N], f_inv[N];

void fill_fact(){
    fact[0]=1;
    for(int i=1; i<N; i++) fact[i]=fact[i-1]*i%MOD;
    fill(f_inv,f_inv+N,1);
    for(int k=0; k<30; k++){
        for(int i=0; i<N; i++){
            f_inv[i]=f_inv[i]*f_inv[i]%MOD;
            if((MOD-2)&(1<<(29-k))) f_inv[i]=f_inv[i]*fact[i]%MOD;
        }
    }
}

long long nCr(int n, int r){
    if(n<r) return 0;
    if(r<0) return 0;
    return ((fact[n]*f_inv[r])%MOD)*f_inv[n-r]%MOD;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    fill_fact();
    while(t--){
        int n,i,j,x,y;
        cin>>n>>i>>j>>x>>y;
        if(x>y){
            swap(x,y);
            int temp=i;
            i=n+1-j;
            j=n+1-temp;
        }
        // always x<y
        if(y==n){
            //cout<<n<<' '<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
            if(j==n) cout<<0<<endl;
            else cout<<(nCr(y-x-1,j-i-1)*nCr(x-1,i-1))%MOD<<endl;
        }
        else{
            ll sum=0;
            //cout<<n<<' '<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
            for(int idx=i+1; idx<=j-1; idx++){
                // idx is highest point
                //cout<<"ds "<<idx<<' '<<y<<endl;
                //cout<<"debug "<<n-y-1<<' '<<j-idx-1<<' '<<y-x-1<<' '<<y+j-n-i-1<<' '<<y+j-n-i-1<<endl;
                if(!(n-y-1>=j-idx-1 && y-x-1>=y+j-n-i-1 && y+j-n-i-1>=0)) continue;
                ll temp=((nCr(n-y-1,j-idx-1)*nCr(y-x-1,y+j-n-i-1))%MOD*nCr(x-1,i-1))%MOD;
                //cout<<idx<<' '<<temp<<endl;
                sum=(sum+temp)%MOD;
            }
            for(int idx=j+1; idx<=n-1; idx++){
                // idx is highest point
                ll temp=((nCr(n-y-1,idx-j-1)*nCr(y-x-1,j-i-1))%MOD*nCr(x-1,i-1))%MOD;
                sum=(sum+temp)%MOD;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}