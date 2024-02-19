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

int a[200020];
int cula[200020];
bool visited[200020];
int numone[20];
int numone_true[20];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++) cin>>a[i];
    cula[0]=a[0];
    for(int i=1; i<n-1; i++) cula[i]=cula[i-1]^a[i];
    
    int st=0;
    int sz=1;
    for(int i=0; i<20; i++){
        if((1<<sz)>=n) break;
        sz<<=1;
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<20; j++) if(cula[i]&(1<<j)) numone[j]++;
        for(int j=0; j<20; j++) if(i&(1<<j)) numone_true[j]++;
    }
    for(int i=0; i<20; i++) if(numone[i]!=numone_true[i]){
        st+=(1<<i);    
    }
    cout<<st<<' ';
    for(int i=0; i<n-1; i++){
        st=(st^a[i]);
        cout<<st<<' ';
    }
    cout<<endl;

    return 0;
}