/*Fishmonger
Send Feedback
A fishmonger wants to bring his goods from port to the market. On his route, he has to traverse an area with many tiny city states. Of course he has to pay a toll at each border.
Because he is a good business man, he wants to choose the route in such a way that he has to pay as little money for tolls as possible. On the other hand, he has to be at the market within a certain time, otherwise his fish start to smell.
Given n number of states and the time t in which he has to reach the market. You need to find and print the minimum toll amount that he has to pay in order to reach the market in given time. The first state is the port and last one is the market.
Input Format :
Line 1 : Two integers, n and t
Next n lines : n numbers, specifying for each state the travel time to the i-th state.      
This table is terminated with an empty line. The table of the tolls follows in the same format
Output Format :
Print in one line the total amount of tolls
Constraints :
3 <= n <= 100
1 <= t <= 1000
Sample Input :
4 7
0 5 2 3
5 0 2 3
3 1 0 2
3 3 2 0

0 2 2 7
2 0 1 2
2 2 0 5
7 2 5 0
Sample Output :
6
Sample Case Explanation :
This corresponds to the following situation, the connections are labeled with (time, toll) -
Alt text

The optimal path is Port -> State B -> State A -> Market*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair; 
 
class ntc
{
    public:
        int node;
        int time;
        int cost;
    ntc(int n,int t,int c)
    {
        node=n;
        time=t;
        cost=c;
    }
};
int main()
{
    int n,t;
    cin >>n>>t; 
    t++;
    vector<vector<int>>visited(n,vector<int>(t));
 
    for(int i=0;i<n;i++)
      for(int j=0;j<t;j++)
       visited[i][j]=INT_MAX;
 
    int cost[100][100];
    int time[100][100];
 
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
           cin>> time[i][j];
 
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
           cin>> cost[i][j];
    queue<ntc>q;
    q.push(ntc(0,0,0));
    visited[0][0] = 0;
    int anst=INT_MAX,ansc=INT_MAX;
    while(!q.empty())
    {
        ntc temp = q.front();
        int start = temp.node;
        int cu = temp.cost;
        int tu = temp.time;
        q.pop(); 
        for(int i=0;i<n;i++)
        {
              if(visited[i][tu+time[start][i]]>cu+cost[start][i] && i!=start && tu+time[start][i]<=t)
              {
                  	 visited[i][tu+time[start][i]]=cu+cost[start][i];
                     q.push(ntc(i,tu+time[start][i],cu+cost[start][i]));
                     if(i==n-1)// if last node then update ans if possible 
                      {
                         if(ansc>cu+cost[start][i])
                          {
                              ansc=cu+cost[start][i];
                              anst=tu+time[start][i];
                          }
                      }
              }
        }
    }
    cout<<ansc<<endl;
}    
