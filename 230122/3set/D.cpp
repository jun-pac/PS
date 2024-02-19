// 
//./D<test

#include <bits/stdc++.h>
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

bool visited[200000];

ll n,p0,p1,p2;
int cnt=0;
inline ll h(ll cur){
    cnt++;
    return (cur+p1+p2*cnt)%n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        ll res, res1, res2;
        p0=101, p1=4999,p2=17;
        if(n%101==0) p0=89;
        if(n%4999==0) p1=29;
        if(n%17==0) p2=5003;

        // first phase : [n/2]
        ll l=p0%n,r=p0%n;
        while(r==l){
            r=h(r);
        }
        ll mx=1;
        if(n==2){
            cout<<"! "<<1<<" "<<2<<endl;
            cin>>res;
            if(res==1) continue;
            else return 0;
        }
        int cntt=n+2;
        cout<<"? "<<l+1<<' '<<r+1<<endl;
        cin>>mx;
        cntt--;

        while(cntt>=0){
            ll cur=h(l);
            while(cur==l || cur==r){
                cur=h(cur);
            }
            cout<<"? "<<l+1<<' '<<cur+1<<endl;
            cntt--;
            cin>>res1;
            if(cntt>0 && res1>=mx){
                cntt--;
                cout<<"? "<<r+1<<' '<<cur+1<<endl;
                cin>>res2;
                if(res1>mx && res1>=res2){
                    r=cur;
                    mx=res1;
                }
                else if(res2>mx && res2>=res1){
                    l=cur;
                    mx=res2;
                }
            }
            else if(cntt==0 && res1>mx){
                r=cur;
                mx=res1;
            }
        }

        for(int i=0; i<n; i++){
            if(i==l || i==r) continue;
            cout<<"? "<<l+1<<' '<<i+1<<endl;
            cin>>res;
            if(res>mx){
                r=i;
            }
        }

        cout<<"! "<<l+1<<' '<<r+1<<endl;
        cin>>res;
        if(res==-1) return 0;

    }
    return 0;
}