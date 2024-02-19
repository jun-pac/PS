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

ll datas[100000];
ll rn[100000];
ll rm[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=0; i<k; i++){
            cin>>datas[i];
            rn[i]=datas[i]/n;
            rm[i]=datas[i]/m;
        }
        sort(rn,rn+k);
        reverse(rn,rn+k);
        sort(rm,rm+k);
        reverse(rm,rm+k);
        //for(int i=0; i<k; i++) cout<<rn[i]<<' '<<rm[i]<<endl;
        bool row_flag=true;
        ll obj=m;
        if(m%2==1){
            if(rn[0]<3) row_flag=false;
        }
        for(int i=0; i<k; i++){
            if(rn[i]>=2) obj-=rn[i];
        }
        if(obj>0) row_flag=false;

        bool col_flag=true;
        obj=n;
        if(n%2==1){
            if(rm[0]<3) col_flag=false;
        }
        for(int i=0; i<k; i++){
            if(rm[i]>=2) obj-=rm[i];
        }
        if(obj>0) col_flag=false;
        

        if(row_flag || col_flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}