#include<bits/stdc++.h>
using namespace std;


void printer(priority_queue<pair<int,int>>pq){
    
    while(!pq.empty()){
        cout << pq.top().second << " " << -pq.top().first << endl;
        pq.pop();
    }
}



int main(){
    int n; cin >> n;

    // pid = process id, at = arrival time , bt = burst time
    vector<int> pid, at, bt;
    int total = 0;
    for(int i=0;i<n;i++){
        int p,a,b; cin >> p >> a >> b;
        pid.push_back(p);
        at.push_back(a);
        bt.push_back(b);
        total += b;
    }
    int timeq = total / n;
    // time quantum = mean()

    // sort on base of at or let given sorted...

    // ct = complete tiem , wt = waiting time, tt = turnaround time.
    vector<int>ct(n), wt(n), tt(n);
    // ready_queue, temporaray_queue.
    priority_queue<pair<int,int>> rq, tq;
    int it,ft;
    // initial time, final time...
    vector<int>vis(n, 0);
    // vis = 0 no operation. vis = 1 rr. vis = 2 end.

    tq.push({-bt[0], pid[0]});
    it = ft = at[0];
    int cnt = 0;
    int cs = 0;
    while(1){
        if(rq.empty() and tq.empty() and ft>at.back()) break;
        // placing temporary queue in ready queue...
        while(!tq.empty()){
            rq.push(tq.top());
            tq.pop();
        }
        // initial time now from last final time.
        it = ft;
        int id = rq.top().second;
        // cout << "ready queue now " << endl;
        // printer(rq);
        
        while(!rq.empty()){
            int cpid = rq.top().second;
            int cbt = -rq.top().first;
            rq.pop();
            // cout << "in cpu " << cpid << " " << cbt << endl;
            if(vis[cpid] == 1){
                // have already undergo a round robin so finish it .
                ft += cbt;
                ct[cpid] = ft;
                vis[cpid] = 2;
                // cout << "ending by srtf " << cpid << " " << cbt << endl;
            } else if(cbt > timeq){
                // apply round robin 
                cbt -= timeq;
                tq.push({-cbt, cpid});
                ft += timeq;
                vis[cpid] = 1;
                cs++;
                // cout << "rr applying " << cpid << " " << cbt << endl;
            } else{
                // cout << "ending by burst time " << cpid << " " << cbt << endl;
                ft += cbt;
                ct[cpid] = ft;
                vis[cpid] = 2;
            }
        }

        for(int i=id+1;i<n;i++){
            if(at[i] > ft) break;
            if(vis[i] == 0) tq.push({-bt[i], i});
        }

    }


    // cout << "check complete time " << endl; 
    int ttt = 0, twt = 0;
    for(int i=0;i<n;i++){
        cout << pid[i] << " " << at[i] << " " << bt[i] << " " << ct[i] << endl;
        tt[i] = ct[i] - at[i];
        wt[i] = tt[i] - bt[i];
        ttt += tt[i];
        twt += wt[i];
    }
    cout << cs << endl;
    cout << "awt = " << ttt/4.0 << endl;
    cout << "att = " << twt/4.0 << endl;
}