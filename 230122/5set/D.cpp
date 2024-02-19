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

vector<int> datas[100000];
int ones[100000];
int sum;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        sum=0;
        for(int i=0; i<n; i++){
            vector<int> temp(m);
            int tt=0;
            for(int j=0; j<m; j++){
                cin>>temp[j];
                if(temp[j]==1) tt++;
            }
            datas[i]=temp;
            ones[i]=tt;
            sum+=tt;
        }

        int part=sum/n;
        /*
        cout<<n<<" "<<m<<" "<<part<<" "<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cout<<datas[i][j]<<' ';
            cout<<endl;
        }*/
        if(sum%n!=0){
            cout<<-1<<endl;
            continue;
        }
        int cnt=0;
        for(int i=0; i<n; i++) cnt+=abs(ones[i]-part);
        cout<<cnt/2<<endl;
        int idx=0;
        while(idx<n && ones[idx]>=part) idx++;
        for(int i=0; i<n; i++){
            if(ones[i]<=part) continue;

            //cout<<"I : "<<i<<" | Priblemn : "<<idx<<endl;

            if(idx==n) break;
            //cout<<idx<<endl;
            int rem=ones[i]-part;
            while(idx<n && rem>0){
                //cout<<"hello"<<endl;
                int j=0;
                //cout<<j<<' '<<rem<<' '<<ones[idx]<<' '<<part<<endl;
                while(j<m && rem>0 && ones[idx]<part){
                    //cout<<"J : "<<j<<" | datas[i][j] and datas[idx][j] : "<<datas[i][j]<<' '<<datas[idx][j]<<endl;
                    if(datas[i][j]==1 && datas[idx][j]==0){
                        rem--;
                        ones[idx]++;
                        ones[i]--;
                        datas[i][j]=0;
                        datas[idx][j]=1;
                        cout<<i+1<<' '<<idx+1<<' '<<j+1<<endl;
                    }
                    j++;
                }
                if(rem==0) break;
                while(idx<n && ones[idx]>=part) idx++;
            }
        }
        


    }
    return 0;
}