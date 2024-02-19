// 
//./B<test

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

pair<int,int> datas[200000];
int mnp[200000]; // min until i

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>datas[i].fi; // health
        for(int i=0; i<n; i++) cin>>datas[i].se; // power
        sort(datas,datas+n);
        reverse(datas,datas+n);
        mnp[0]=datas[0].se;
        for(int i=1; i<n; i++){
            mnp[i]=min(mnp[i-1],datas[i].se);
        }
        bool flag=true;
        int sub=0;
        int last_idx=n-1;
        while(k>0){
            sub+=k;
            while(last_idx>=0 && datas[last_idx].fi<=sub) last_idx--;
            if(last_idx==-1) break;
            k-=mnp[last_idx];
            if(k<=0) flag=false;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}