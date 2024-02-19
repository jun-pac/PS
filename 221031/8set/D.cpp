// 
//./D<test.txt

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

int datas[500050];
int cnt[500050];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    for(int i=0; i<n; i++){
        cin>>datas[i];
    }
    fill(cnt,cnt+x+1,0);
    for(int i=0; i<n; i++){
        cnt[datas[i]]++;
    }
    bool flag=true;
    for(int i=1; i<x; i++){
         if(cnt[i]%(i+1)!=0){
            flag=false;
            break;
         }
         else cnt[i+1]+=cnt[i]/(i+1);
    }
    if(!flag) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}