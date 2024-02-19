// 
//./C<test.txt

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

int A[100000], B[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        long long sum_a=0, sum_b=0;
        cin>>n>>m; // m¿Ã magic
        for(int i=0; i<n; i++){
            cin>>A[i];
            sum_a=sum_a+A[i];
        }
        cin>>k;
        for(int i=0; i<k; i++){
            cin>>B[i];
            sum_b=sum_b+B[i];
        }
        //cout<<sum_a<<" "<<sum_b<<endl;
        if(sum_a!=sum_b){
            cout<<"No"<<endl;
            continue;
        }
        int aidx=0, anum, acnt=0;
        int bidx=0, bnum, bcnt=0;
        bool flag=true;
        while(aidx<n || bidx<k){
            if(acnt==0 && aidx<n){
                anum=A[aidx];
                acnt=1;
                while(anum%m==0){
                    anum/=m;
                    acnt*=m;
                }
                aidx++;
            }
            if(bcnt==0 && bidx<k){
                bnum=B[bidx];
                bcnt=1;
                while(bnum%m==0){
                    bnum/=m;
                    bcnt*=m;
                }
                bidx++;
            }
            //cout<<"A "<<acnt<<' '<<anum<<' '<<aidx<<endl;
            //cout<<"B "<<bcnt<<' '<<bnum<<' '<<bidx<<endl;
            if(anum==bnum){
                int temp=min(acnt,bcnt);
                acnt-=temp;
                bcnt-=temp;
            }
            else{
                flag=false;
                break;
            }
        }
        if(acnt!=0 || bcnt!=0) flag=false;
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}