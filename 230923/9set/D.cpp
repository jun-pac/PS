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

pair<int,int> datas[200020];
//int seg[1<<19];
int res[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i].fi;
            datas[i].se=-i;
        }
        fill(res,res+n,0);
        cin>>k;
        sort(datas,datas+n);
        for(int i=0; i<n; i++) datas[i].se=-datas[i].se;
        //for(int i=0; i<n; i++) cout<<"c "<<datas[i].fi<<' '<<datas[i].se<<endl;
        int cnt=1, lidx=datas[0].se, lval=datas[0].fi;
        for(int i=1; i<n; i++){
            if(datas[i].fi!=lval && datas[i].se>lidx){
                datas[cnt++]=datas[i];
                lidx=datas[i].se;
                lval=datas[i].fi;
                //cout<<"s "<<datas[i].fi<<' '<<datas[i].se<<endl;
            }
        }
        //cout<<"k "<<k<<endl;
        //fill(seg,seg+min(4*n,(1<<19)),0);
        int lup=-1;
        int mx=k/datas[0].fi;
        for(int i=0; i<cnt; i++){
            int dev=datas[i].fi-(i==0?0:datas[i-1].fi);
            //cout<<"debug "<<k<<' '<<dev<<endl;
            if(k<=0 || k<dev) break;
            int temp=min(k/dev,mx);
            //int temp=k/dev;
            mx=temp;
            for(int j=lup+1; j<=datas[i].se; j++) res[j]=temp;
            //update_seg(1,0,n-1,lup+1,datas[i].se,k/dev);
            lup=datas[i].se;
            k=k-temp*dev;
        }
        for(int i=0; i<n; i++) cout<<res[i]<<' ';
        cout<<endl;
    }
    return 0;
}