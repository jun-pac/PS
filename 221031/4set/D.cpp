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

int score[300001];
pair<int,int> ab[300000];
pair<int,int> sab[300000];
pair<int,int> pack[300000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    int mid, mx=0;
    cin>>n;
    ll sum=0;
    for(int i=0; i<n; i++){
        cin>>ab[i].fi>>ab[i].se;
        sab[i]={ab[i].fi-ab[i].se,i};
        sum+=ab[i].se;
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>pack[i].fi>>pack[i].se;
    }

    sort(sab,sab+n);
    score[0]=sum;
    mid=0, mx=sum;
    for(int i=0; i<n; i++){
        sum+=sab[n-1-i].fi;
        score[i+1]=sum;
        if(score[i+1]>mx){
            mx=score[i+1];
            mid=i+1;
        }
    }
    for(int i=0; i<m; i++) cin>>pack[i].fi>>pack[i].se;

    int lmx, rmx; // 양 옆에서 가장 가까운애들
    for(int i=0; i<m; i++){
        int a=pack[i].fi, b=pack[i].se;
        bool lflag=false, rflag=false;
        lmx=mid/a*a, rmx=mid/a*a+1;
        while(lmx>=0){
            if((n-lmx)%b==0){
                lflag=true;
                break;
            }
            lmx=min(lmx-a,n-((n-lmx)/b+1)*b);
        }
        while(rmx<=n){
            if((n-rmx)%b==0){
                rflag=true;
                break;
            }
            rmx=max(rmx+a,n-((n-rmx)/b)*b);
        }
        if(lflag&&rflag) cout<<max(score[lmx],score[rmx])<<endl;
        else if(lflag) cout<<score[lmx]<<endl;
        else if(rflag) cout<<score[rmx]<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}