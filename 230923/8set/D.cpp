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

int datas[100010];
int in[100010], out[100010];
int cnt=0;

int cycle_sz(int idx){
    if(in[idx]!=0 && out[idx]==0){
        out[idx]=cnt;
        //cout<<cnt<<endl;
        return 1+cnt-in[idx];
    }
    else if(in[idx]!=0) return 0;
    in[idx]=++cnt;
    //cout<<"visit "<<idx<<' '<<in[idx]<<' '<<datas[idx]<<endl;
    int res=cycle_sz(datas[idx]);
    out[idx]=cnt;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int k,n;
        bool flag=true;
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++) datas[i]--;
        if(k==1){
            for(int i=0; i<n; i++) if(i!=datas[i]) flag=false;
            cout<<(flag?"YES":"NO")<<endl;
            continue;
        }
        fill(in,in+n,0);
        fill(out,out+n,0);
        for(int i=0; i<n; i++){
            if(in[i]==0){
                cnt=0;
                int temp=cycle_sz(i);
                //cout<<i+1<<' '<<temp<<endl;
                if(temp!=0 && temp!=k){
                    flag=false;
                    break;
                }
            }
        }
        cout<<(flag?"YES":"NO")<<endl;

    }
    return 0;
}