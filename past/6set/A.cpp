// 
//./A<test.txt

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

int datas[1000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        bool flag=false;
        for(int k=0; k<n; k++){
            int res=0;
            for(int i=0; i<n; i++){
                if(i!=k) res=res^datas[i];
            }
            if(res==datas[k]){
                flag=true;
                cout<<datas[k]<<endl;
                break;
            }
        }
        if(!flag) cout<<-1<<endl;
    }
    return 0;
}