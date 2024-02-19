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

ll datas[200020];
ll temp[200020], temp_lmn[30], temp_rmx[30];
ll ssum[200020], lmn[200020], rmx[200020];

const ll INF=1000000000000000;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k,x;
        cin>>n>>k>>x; // k개를 반드시 선택.
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++) datas[i]-=x;
        // 이제 k개를 골라서 2x를 더하는 문제임

        for(int i=0; i<n; i++){
            ssum[i]=(i==0?datas[0]:ssum[i-1]+datas[i]);
            lmn[i]=(i==0?ssum[0]:min(lmn[i-1],ssum[i]));
        }
        for(int i=n-1; i>=0; i--){
            rmx[i]=(i==n-1?ssum[n-1]:max(rmx[i+1],ssum[i]));
        }

        if(x>=0){
            ll res=0;
            for(int i=0; i<n-k+1; i++){
                // i ~ i+k-1까지 +x로 채움
                ll l_mn=min(0LL,(i==0?0:lmn[i-1])); // 이쪽은 그야말로 아무것도 안뽑으면 된다.
                ll r_mx=(i+k==n?-INF:rmx[i+k])+2*x*k; // 
                for(int j=0; j<k; j++){
                    temp[j]=ssum[i+j]+(j+1)*2*x;
                }
                for(int j=0; j<k; j++){
                    temp_lmn[j]=(j==0?temp[j]:min(temp_lmn[j-1],temp[j]));
                }
                for(int j=k-1; j>=0; j--){
                    temp_rmx[j]=(j==k-1?max(r_mx,temp[j]):max(temp_rmx[j+1],temp[j]));
                }
                for(int j=0; j<k; j++){
                    res=max(res,max(r_mx,temp_rmx[j])-min(l_mn,temp_lmn[j]));
                }
            }
            cout<<res<<endl;
        }

        else{
            // 더해지는 애들끼리 뭉쳐서 배치되어야 함.
            ll res=0;
            for(int i=0; i<=k; i++){
                for(int j=0; j<i; j++){
                    temp[j]=ssum[j]+(j+1)*(2*x);
                }
                for(int j=0; j<n-k; j++){
                    temp[i+j]=ssum[i+j]+i*(2*x);
                }
                for(int j=i+n-k; j<n; j++){
                    temp[j]=ssum[j]+(j-n+k+1)*(2*x);
                }


                for(int j=0; j<n; j++){
                    lmn[j]=(j==0?temp[0]:min(lmn[j-1],temp[j]));
                }
                for(int j=n-1; j>=0; j--){
                    rmx[j]=(j==n-1?temp[n-1]:max(rmx[j+1],temp[j]));
                }
                for(int j=0; j<n; j++){
                    res=max(res,temp[j]-min(lmn[j],0LL));
                }
            }
            cout<<res<<endl;
        }
    }
    return 0;
}