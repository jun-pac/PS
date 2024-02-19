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

#define N_PRIME 10000010

bool is_prime[N_PRIME];
vector<int> primes;
int datas[1010];
int cnt[664590];

void build_prime(int n){
    // n<N_PRIME
    fill(is_prime+2,is_prime+n+1,true);
    for(int i=2; i<=n; i++){
        if(!is_prime[i]) continue;
        for(int j=2; i*j<=n; j++) is_prime[i*j]=false;
    }
    for(int i=2; i<n-2; i++) if(is_prime[i]) primes.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    build_prime(N_PRIME-2);
    for(int i=2; i<N_PRIME-2; i++) if(is_prime[i]) primes.push_back(i);
    //cout<<primes.size()<<endl;
    while(t--){
        int n;
        cin>>n;
        int pn=primes.size();
        fill(cnt,cnt+pn,0);
        for(int i=0; i<n; i++) cin>>datas[i];
        int res=0, res2=0;
        for(int i=0; i<n; i++){
            int temp=datas[i];
            //cout<<"DATAS : "<<temp<<endl;
            for(int j=0; j<pn; j++){
                if(primes[j]>sqrt(temp) || primes[j]>=temp) break;
                while(temp>primes[j] && temp%primes[j]==0){
                    temp/=primes[j];
                    cnt[j]++;
                }
            }
            // 그럼 이제 지금 temp는 소수인 상황
            int idx=lower_bound(primes.begin(), primes.end(), temp)-primes.begin();
            //cout<<temp<<' '<<endl;
            cnt[idx]++;

        }
        for(int i=0; i<pn; i++){
            res+=cnt[i]/2;
            res2+=cnt[i]%2;
        }
        cout<<res+res2/3<<endl;
    }
    return 0;
}