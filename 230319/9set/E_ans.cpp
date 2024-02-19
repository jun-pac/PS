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

int pred[1<<20][20];
bool DP[1<<20][20];
int neighbor[1<<20];
int func[20];
queue<pair<int,int>> q;
int edges[20];

#define N 6
string conv(int idx){
    string res;
    while(idx!=0){
        res.push_back(idx%2?'1':'0');
        idx/=2;
    }
    while(res.size()<N) res.push_back('0');
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--, b--;
        edges[a]|=(1<<b);
        edges[b]|=(1<<a);
    }

    // Finding neighbors 
    for(int idx=0; idx<(1<<n); idx++){
        neighbor[idx]=idx;
        for(int i=0; i<n; i++){
            if(idx&(1<<i)){
                neighbor[idx]=neighbor[idx]|edges[i];
            }
        }
        //cout<<"Nei : "<<conv(idx)<<' '<<conv(neighbor[idx])<<endl;
    }

    // Finding cycles
    for(int i=0; i<n; i++){
        pred[1<<i][i]=-1;
        q.push({(1<<i),i});
        DP[1<<i][i]=true; // true를 여기서 체크함에 주의
    }
    while(!q.empty()){
        int idx=q.front().fi;
        int last=q.front().se;
        q.pop();
        int f_bit=-1;
        for(int i=0; i<n; i++){
            if((idx&(1<<i)) && f_bit==-1){
                f_bit=i;
                break;
            }
        }
        for(int j=f_bit; j<n; j++){
            if((edges[last]&(1<<j)) && !(idx&(1<<j)) && (!DP[idx|(1<<j)][j])){
                pred[idx|(1<<j)][j]=last;
                q.push({(idx|(1<<j)),j});
                DP[idx|(1<<j)][j]=true;
            }
        }
    }
    for(int idx=1; idx<(1<<n); idx++){
        for(int i=0; i<n; i++){
            int j=0;
            while(!(idx&(1<<j))) j++;
            if(!(edges[j]&(1<<i))) DP[idx][i]=false;
        }
    }

    // Main loop
    bool flag=false;
    for(int idx=1; idx<(1<<n); idx++){
        //cout<<"tenp "<<idx<<' '<<neighbor[idx]<<endl;
        if(neighbor[idx]==(1<<n)-1){
            // neighbor condition satisfied
            //cout<<"catch "<<conv(idx)<<' '<<conv(neighbor[idx])<<endl;
            for(int i=0; i<n; i++){
                if((idx&(1<<i)) && DP[idx][i]){
                    //cout<<"catch and cycle "<<conv(idx)<<' '<<conv(neighbor[idx])<<' '<<i<<endl;
                    flag=true;
                    int temp=idx;
                    int last=i;
                    while(temp!=0){
                        if(pred[temp][last]==-1){
                            func[last]=i;
                            break;
                        }
                        func[last]=pred[temp][last];
                        temp-=(1<<last);
                        last=func[last];
                    }
                    for(int j=0; j<n; j++){
                        if(!(idx&(1<<j))){
                            for(int k=0; k<n; k++){
                                if((edges[j]&(1<<k)) && (idx&(1<<k))){
                                    func[j]=k;
                                    break;
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
        for(int j=0; j<n; j++) cout<<func[j]+1<<' ';
        cout<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}