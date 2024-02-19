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

int ns[65], xs[65];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,x,m;
        cin>>n>>x;
        fill(ns,ns+65,0);
        fill(xs,xs+65,0);
        if((n&x)!=x){
            cout<<-1<<endl;
            continue;
        }
        ll temp=n, i=0, mx_idx=0;
        while(temp!=0){
            ns[i++]=temp%2;
            temp/=2;
            mx_idx=max(mx_idx,i);
            //cout<<ns[i-1];
        }
        //cout<<endl;
        temp=x, i=0;
        while(temp!=0){
            xs[i++]=temp%2;
            temp/=2;
            mx_idx=max(mx_idx,i);
            //cout<<xs[i-1];
        }
        //cout<<endl;

        int mx_alter=-1;
        bool not_change=true;
        bool ffflag=false;
        for(int i=0; i<mx_idx; i++){
            if(xs[i]!=ns[i]){
                if(!not_change){
                    ffflag=true;
                    break;
                }
                mx_alter=max(mx_alter,i);
            }
            if(ns[i]==1 && xs[i]==1) not_change=false;
        }
        //cout<<ffflag<<' '<<mx_alter<<' '<<mx_idx<<' '<<n<<endl;
        if(ffflag) cout<<-1<<endl;
        else if(mx_alter==-1) cout<<n<<endl;
        else if(mx_alter+1==mx_idx) cout<<(1LL<<mx_idx)<<endl;
        else if(ns[mx_alter+1]==0){
            cout<<n-(n&((1LL<<(mx_alter+1))-1))+(1LL<<(mx_alter+1))<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}