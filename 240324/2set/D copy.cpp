
#include <bits/stdc++.h>
using namespace std;

#define N 1010

map<string,int> idx; // Map ticket to ticket idx {ticket, idx}
int cnt[N]; // Count of each ticket so far
int price[N]; // Price for each ticket
pair<int,int> order[N];

void Solve(vector<pair<string,int>> tickets, int roll, vector<vector<string>> shop, int money){
    int n=shop.size();
    int ticketnum=tickets.size();
    idx.clear();
    for(int i=0; i<tickets.size(); i++){
        idx[tickets[i].first]=i;
        price[i]=tickets[i].second;
        order[i]={price[i],i};
        cnt[i]=0;
    }
    sort(order,order+ticketnum);

    // Refresh를 0번 했을 때 부터, n-1번 했을 때까지
    int mx=0;
    for(int k=0; k<n; k++){ // k가 refresh의 횟수를 의미함.
        for(int m=0; m<shop[k].size(); m++){
            cnt[idx[shop[k][m]]]++;
        }
        int cur_money=money-k*roll; // roll을 하고 현재 남은 돈
        int gold_ticket=0;
        for(int i=0; i<ticketnum; i++){
            int num=min(cnt[order[i].second]/3*3, cur_money/(3*price[order[i].second])*3);
            gold_ticket+=num/3;
            cur_money-=price[order[i].second]*num;
        }
        mx=max(mx,gold_ticket);
    }
    cout<<mx<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tick_num;
    int n;
    int m;
    int roll, money;
    cin>>tick_num>>n>>m;
    vector<pair<string,int>> ticks;
    for(int i=0; i<tick_num; i++){
        string s;
        int price;
        cin>>s>>price;
        ticks.push_back({s,price});
    }
    
    cin>>roll;

    vector<vector<string>> shops;
    for(int i=0; i<n; i++){
        vector<string> cur;
        for(int j=0; j<m; j++){
            string s;
            cin>>s;
            cur.push_back(s);
        }
        shops.push_back(cur);
    }

    cin>>money;

    Solve(ticks,roll,shops,money);
    return 0;
}

