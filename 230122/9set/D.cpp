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

ll a[1000];
ll diff[1000];
const double epsilon=0.0000001; 
inline bool is_sq(ll x){
    ll rt=sqrt(x)+epsilon;
    return x==rt*rt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        
        int res=1;
        for(int ik=0; ik<n-1; ik++){
            for(int j=ik; j<n-1; j++) diff[j]=a[j+1]-a[ik];
            for(int ii=ik; ii<n-1; ii++){
                if(diff[ii]%2==0 && diff[ii]%4!=0) continue;
                //cout<<"idx "<<ii<<endl;
                
                
                ll mx=sqrt(diff[ii])+epsilon;
                if(diff[ii]%2==0){
                    for(ll j=2; j<=mx; j+=2){
                        if(diff[ii]%j==0 && j<=diff[ii]/j){
                            ll m=(diff[ii]/j-j)/2;
                            //cout<<diff[ii]<<" is divisible in "<<j<<' '<<j+2*m<<endl;
                            if(a[ik]>m*m) continue;
                            int temp_cnt=2;
                            for(int u=ii+1; u<n-1; u++){
                                //cout<<m*m+diff[u]<<" is sq? "<<endl;
                                if(is_sq(m*m+diff[u])){
                                    //cout<<"YES "<<temp_cnt<<endl;
                                    temp_cnt++;
                                }
                            }
                            res=max(res,temp_cnt);
                        }
                    }
                }
                else{
                    for(ll j=1; j<=mx; j+=2){
                        if(diff[ii]%j==0 && j<=diff[ii]/j){
                            ll m=(diff[ii]/j-j)/2;
                            //cout<<diff[ii]<<" is divisible in "<<j<<' '<<j+2*m<<endl;
                            if(a[ik]>m*m) continue;
                            int temp_cnt=2;
                            for(int u=ii+1; u<n-1; u++){
                                //cout<<m*m+diff[u]<<" is sq? "<<endl;
                                if(is_sq(m*m+diff[u])){
                                    //cout<<"YES "<<temp_cnt<<endl;
                                    temp_cnt++;
                                }
                            }
                            res=max(res,temp_cnt);
                        }
                    }
                }
            }
        }
        cout<<res<<endl; 
    }
    return 0;
}