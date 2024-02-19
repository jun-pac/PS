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

int datas[200000];
int A[200000]; // modifyable +1
int B[200000];  // modiable -1
bool check[200000];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        int sum=0;
        for(int i=0; i<n; i++) sum+=datas[i];
        //cout<<sum<<' '<<(sum%2+1)%2<<endl;
        if(sum%2!=0){
            cout<<-1<<endl;
        }
        else{
            A[0]=B[0]=0;
            for(int i=1; i<n; i++){
                A[i]=A[i-1];
                B[i]=B[i-1];
                if(i>=1) A[i]=max(A[i],(i==1?0:A[i-2])+(datas[i]==1?1:0));
                if(i>=2) A[i]=max(A[i],(i==2?0:A[i-3])+(datas[i]==1?1:0));
                if(i>=1) B[i]=max(B[i],(i==1?0:B[i-2])+(datas[i]==-1?1:0));
                if(i>=2) B[i]=max(B[i],(i==2?0:B[i-3])+(datas[i]==-1?1:0));
            }
            /*
            cout<<"debug"<<endl;
            cout<<"A ";
            for(int i=0; i<n; i++) cout<<A[i]<<' ';
            cout<<endl;
            cout<<"B ";
            for(int i=0; i<n; i++) cout<<B[i]<<' ';
            cout<<endl;
            */
            if(!(sum-2*A[n-1]<=0 || sum+2*B[n-1]>=0)){
                cout<<-1<<endl;
            }
            else if(sum==0){
                cout<<n<<endl;
                for(int i=0; i<n; i++) cout<<i+1<<' '<<i+1<<endl;
            }
            else if(sum<0){
                int last=0;
                int ncnt=0;
                fill(check,check+n,false);
                while(last<n && B[last]<(-sum)/2) last++;
                while(last>0){
                    int nlast=last-1;
                    if(datas[last]==-1){
                        check[last]=true;
                        ncnt++;
                        if(last>=2 && B[last-2]==B[last]-1) nlast=last-2;
                        if(last>=3 && B[last-3]==B[last]-1) nlast=last-3;
                    }
                    last=nlast;
                }
                //cout<<"check ";
                //for(int i=0; i<n; i++) cout<<check[i]<<' ';
                //cout<<endl;
                last=0;
                cout<<n-ncnt<<endl;
                while(last<n){
                    if(last<n-1 && check[last+1]){
                        cout<<last+1<<' '<<last+2<<endl;
                        last+=2;
                    }
                    else{
                        cout<<last+1<<' '<<last+1<<endl;
                        last++;
                    }
                }
            }
            else{
                int last=0;
                int ncnt=0;
                fill(check,check+n,false);
                while(last<n && A[last]<(sum)/2) last++;
                while(last>0){
                    int nlast=last-1;
                    if(datas[last]==1){
                        check[last]=true;
                        ncnt++;
                        if(last>=2 && A[last-2]==A[last]-1) nlast=last-2;
                        if(last>=3 && A[last-3]==A[last]-1) nlast=last-3;
                    }
                    last=nlast;
                }
                //cout<<"check ";
                //for(int i=0; i<n; i++) cout<<check[i]<<' ';
                //cout<<endl;
                last=0;
                cout<<n-ncnt<<endl;
                while(last<n){
                    if(last<n-1 && check[last+1]){
                        cout<<last+1<<' '<<last+2<<endl;
                        last+=2;
                    }
                    else{
                        cout<<last+1<<' '<<last+1<<endl;
                        last++;
                    }
                }
            }
        }
    }
    return 0;
}