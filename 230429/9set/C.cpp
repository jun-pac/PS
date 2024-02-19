// 
//./C<test

#include <bits/stdc++.h>
//#define endl '\n'
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
        int n,m;
        cin>>n>>m;
        bool sw=false; // n,m역할 switch
        if(n>m){
            sw=true;
            swap(n,m);
        }
        int a,b;
        cout<<"? "<<1<<' '<<1<<endl;
        cin>>a;
        if(!sw) cout<<"? "<<1<<' '<<m<<endl;
        else cout<<"? "<<m<<' '<<1<<endl;
        cin>>b;
        
        if(a+b<m){
            assert(a+b==m-1);
            // a+b==m-1인 구간임
            // c는 a+1로 확정
            if(!sw) cout<<"? "<<n<<' '<<a+1<<endl;
            else cout<<"? "<<a+1<<' '<<n<<endl;
            int x;
            cin>>x;
            if(!sw) cout<<"! "<<n-x<<' '<<a+1<<endl;
            else cout<<"! "<<a+1<<' '<<n-x<<endl;
        }
        else{
            if(a>b){
                if(!sw) cout<<"! "<<b+1<<' '<<a+1<<endl;
                else cout<<"! "<<a+1<<' '<<b+1<<endl;
            }
            else if(a<b){
                if(!sw) cout<<"! "<<a+1<<' '<<m-b<<endl;
                else cout<<"! "<<m-b<<' '<<a+1<<endl;
            }
            else{
                int x;
                if(!sw) cout<<"? "<<a+1<<' '<<1<<endl;
                else cout<<"? "<<1<<' '<<a+1<<endl;
                cin>>x;
                if(!sw) cout<<"! "<<a+1<<' '<<x+1<<endl;
                else cout<<"! "<<x+1<<' '<<a+1<<endl;
            }
        }
    }
    return 0;
}