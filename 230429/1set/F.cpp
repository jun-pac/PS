// 
//./F<test

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

int n, m, si, sj, dsi, dsj, ti, tj;
int cnt;

bool test(int i, int j, int di, int dj){
    //cout<<"pos dir : "<<i<<' '<<j<<' '<<di<<' '<<dj<<endl;
    if(cnt>1 && i==si && j==sj && di==dsi && dj==dsj) return false;
    
    // state가 나타내는 직선위에 있는지?
    if((di*ti+dj*tj)==(di*i+dj*j)){
        if((ti-i)*di<=0 && (tj-j)*dj>=0) return true;
    }
    // 다음 종착역은 어디인지
    int ni=(di==1?1:n);
    int nj=(dj==1?m:1);
    
    int nij=((di*i+dj*j)-di*ni)/dj; // i==n일때 j의 값
    int nji=((di*i+dj*j)-dj*nj)/di;
    if(1<=nij && nij<=m && 1<=nji && nji<=n){
        //cout<<"BNG"<<endl;
        if(cnt==0) si=ni,sj=nj,dsi=-di,dsj=-dj;
        cnt++;
        return test(ni,nj,-di,-dj);
    }
    else if(1<=nij && nij<=m){
        if(cnt==0) si=ni,sj=nij,dsi=-di,dsj=dj;
        cnt++;
        return test(ni,nij,-di,dj);
    }
    else{
        if(cnt==0) si=nji,sj=nj,dsi=di,dsj=-dj;
        cnt++;
        return test(nji,nj,di,-dj);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string DR;
        cnt=0;
        cin>>n>>m>>si>>sj>>ti>>tj>>DR;
        dsi=(DR[0]=='U'?1:-1);
        dsj=(DR[1]=='R'?1:-1);
        bool ans=test(si,sj,dsi,dsj);
        cout<<(ans?cnt:-1)<<endl;
    }
    return 0;
}