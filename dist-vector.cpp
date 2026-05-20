#include <bits/stdc++.h>
using namespace std;

void distanceVector(int dist[20][20],int via[20][20], int nodes){
    for(int k=0;k<nodes;k++){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    via[i][j] = via[i][k];
                }
            }
        }
    }
}

int main()
{
    int cost[20][20], dist[20][20], via[20][20];
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the cost matrix: " << endl;
    for(int i=0;i<nodes;i++)
        for(int j=0;j<nodes;j++){
            cin >> cost[i][j];
            dist[i][j] = cost[i][j];
            via[i][j] = j;
        }
    
    distanceVector(dist,via,nodes);
    
    cout << endl;
    cout << "Final Distance Vector Table: " << endl;
    for(int i=0;i<nodes;i++){
        cout << endl;
        cout << "Router " << i + 1 << ":" << endl;
        cout << "Dest\tNextHop\tDistance\n";
        for(int j=0;j<nodes;j++)
            cout << j + 1 << "\t" << via[i][j] + 1 << "\t" << dist[i][j] << endl;
    }
    return 0;
}