// 
//./B<test

#include <bits/stdc++.h>
//#define endl '\n'
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

int tar[8];
vector<int> edges[1<<14];
vector<int> non_zero;
bool visited[1<<14];
int min_d[1<<14];
int ans[100000];
#define INF 100000000

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;

    int N=(1<<(2*7));
    for(int i=0; i<N; i++){
        int n1=0, n2=0, n3=0, n4=0;
        int mul=1;
        for(int j=0; j<7; j++){
            int cur_val=(i>>(2*j))%4;
            n1+=(cur_val==2?0:cur_val)*mul;
            n2+=(cur_val==1?3:cur_val)*mul;
            n3+=((cur_val&2)?cur_val^1:cur_val)*mul;
            n4+=(j>=3?(cur_val^1):cur_val)*mul;
            mul<<=2;
        }
        edges[i].push_back(n1);
        edges[i].push_back(n2);
        edges[i].push_back(n3);
        edges[i].push_back(n4);
    }

    int initial=0;
    int mul=1;
    for(int i=1; i<8; i++){
        initial+=(i%4)*mul;
        mul<<=2;
    }
    //cout<<"init : "<<initial<<endl;
    fill(visited,visited+N,0);
    fill(min_d,min_d+N,INF);
    queue<pair<int,int>> q;
    q.push({initial,0});
    while(!q.empty()){
        int cur=q.front().fi;
        int dist=q.front().se;
        q.pop();
        if(visited[cur]) continue;
        min_d[cur]=dist;
        visited[cur]=true;
        for(auto next : edges[cur]){
            if(!visited[next]) q.push({next,dist+1});
        }
    }
    int cur=0, cnt=0;
    for(int a=0; a<=4; a++){
        for(int b=0; b<=4; b++){
            for(int c=0; c<=4; c++){
                for(int d=0; d<=4; d++){
                    for(int e=0; e<=4; e++){
                        for(int f=0; f<=4; f++){
                            for(int g=0; g<=4; g++){
                                //cur=a*15625+b*3125+c*625+d*125+e*25+f*5+g;
                                //cout<<cur<<' '<<a*15625+b*3125+c*625+d*125+e*25+f*5+g<<endl;
                                ans[cur]=INF;
                                if(a==4) for(int i=0; i<4; i++) ans[cur]=min(ans[cur],ans[cur-(i+1)*15625]);
                                else if(b==4) for(int i=0; i<4; i++) ans[cur]=min(ans[cur],ans[cur-(i+1)*3125]);
                                else if(c==4) for(int i=0; i<4; i++) ans[cur]=min(ans[cur],ans[cur-(i+1)*625]);
                                else if(d==4) for(int i=0; i<4; i++) ans[cur]=min(ans[cur],ans[cur-(i+1)*125]);
                                else if(e==4) for(int i=0; i<4; i++) ans[cur]=min(ans[cur],ans[cur-(i+1)*25]);
                                else if(f==4) for(int i=0; i<4; i++) ans[cur]=min(ans[cur],ans[cur-(i+1)*5]);
                                else if(g==4) for(int i=0; i<4; i++) ans[cur]=min(ans[cur],ans[cur-(i+1)]);
                                else ans[cur]=min_d[cnt++];
                                cur++;
                            }
                        }
                    }
                }
            }
        }
    }
    //cout<<cur<<endl;
    while(t--){
        ll a,b,c,d,m;
        cin>>a>>b>>c>>d>>m;
        fill(tar,tar+8,-1);
        bool flag=true;
        for(ll i=0; i<30; i++){
            ll mul=(1<<i);
            int cur=(m&mul?1:0)*4+(a&mul?1:0)*2+(b&mul?1:0);
            int temp=(c&mul?1:0)*2+(d&mul?1:0);
            if(tar[cur]!=-1 && tar[cur]!=temp){
                flag=false;
                break;
            }
            tar[cur]=temp;
        }
        if(tar[0]!=-1 && tar[0]!=0) flag=false;
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        
        int target=0, mul=1;
        for(int i=1; i<8; i++){
            target+=(tar[i]==-1?4:tar[i])*mul;
            //cout<<(tar[i]==-1?4:tar[i])<<' '<<mul<<endl;
            mul*=5;
        }
        //cout<<"init : "<<initial<<endl;
        //cout<<"target : "<<target<<endl;
        cout<<(ans[target]>=INF?-1:ans[target])<<endl;
    }
    return 0;
}