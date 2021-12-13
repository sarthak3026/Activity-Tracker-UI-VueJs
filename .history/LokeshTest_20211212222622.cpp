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
    int val = maxPoints(i+1,totalPoints)
}

int main(){

}