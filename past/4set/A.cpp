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

int datas[100][100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b,x;
        cin>>a>>b;
        int mx,my;
        int mv=-1000000000;
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                cin>>datas[i][j];
                if(datas[i][j]>mv){
                    mv=datas[i][j];
                    mx=i;
                    my=j;
                }
            }
        }
        cout<<max(mx+1,a-mx)*max(my+1,b-my)<<endl;
    }
    return 0;
}