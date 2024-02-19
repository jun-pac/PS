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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll q,c,a,b,n;
        ll l, r;
        cin>>q;
        l=0, r=1000000000000000000;
        for(int i=0; i<q; i++){
            cin>>c;
            if(c==1){
                cin>>a>>b>>n;
                // ((a-b)*(n-1), (a-b)*n]
                ll nl, nr;
                nl=(n==1?1:(a-b)*(n-1)+b+1);
                nr=(a-b)*n+b;
                if(r>=nl && l<=nr){
                    r=min(r,nr);
                    l=max(l,nl);
                    cout<<1<<' ';
                }
                else cout<<0<<' ';
            }
            else{
                cin>>a>>b;
                if(r<=a){
                    if(r==0) cout<<0<<' '; // 존재하는 경우인가?
                    else cout<<1<<' ';
                }
                else{
                    ll ls=(l-b-1)/(a-b)+1;
                    ll rs=(r-b-1)/(a-b)+1;
                    if(ls==rs) cout<<ls<<' ';
                    else cout<<-1<<' ';
                }
            }
        }
        cout<<endl;
    }
    return 0;
}