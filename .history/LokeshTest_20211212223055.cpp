#include <bits/stdc++.h>
using namespace std;

int dp[500][1001][21][2];
int maxPoints(int i, int n, int totalPoints, vector<int> &points, vector<int> &cost, 
    int limit, int count, int tLimit, bool tDone){
    
    if(count == 0)return totalPoints;
    if(i==n || limit<0 || count<0)return 0;
    if(dp[i][limit][count][tDone]!=-1){
        return dp[i][limit][count][tDone];
    }
    int val = maxPoints(i+1,n,totalPoints,points,cost,limit,count,tLimit,tDone);
    if(cost[i]<=limit){
        int temp = maxPoints(i+1,n,totalPoints+points[i],points,cost,limit-cost[i],count-1,
        tLimit,tDone);
        val = max(val,temp);
        if(tDone == 0 && cost[i]<=tLimit){
            temp = maxPoints(i+1,n,totalPoints+2*points[i],points,cost,limit-cost[i],count-1,
            tLimit,1);
            val = max(val,temp);
        }
    }
    dp[i][limit][count][tDone] = val
}

int main(){

}