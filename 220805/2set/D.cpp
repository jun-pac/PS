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

ll datas[1005];
ll query[1005];
set<ll> red, black;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=0; i<n; i++) cin>>datas[i];
        
    for(int i=0; i<q; i++){
        red.clear();
        for(int i=0; i<n; i++) red.insert(datas[i]);
        cin>>query[i];
        int q=query[i];
        while(q!=0){
            if(q%2==0){
                auto it=--ss.end();
                ll temp=*it;
                cout<<"debug "<<(q%2==0?'-':'+')<<' '<<q<<' '<<temp<<endl;
                ss.erase(it);
                ss.insert(temp-q);
            }
            else{
                auto it=ss.begin();
                ll temp=*it;
                cout<<"debug "<<(q%2==0?'-':'+')<<' '<<q<<' '<<temp<<endl;
                ss.erase(it);
                ss.insert(temp+q);
            }
            q--;
        }
        ll sum=0;
        for(auto it=ss.begin(); it!=ss.end(); it++){
            sum+=*it;
        }
        cout<<*ss.begin()<<' '<<endl;
        cout<<endl;
    }
    return 0;
}