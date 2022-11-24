#include <iostream>
using namespace std;
#include <limits.h>
#include<conio.h>
#define V 9
int minDistance(int dist[], bool sptSet[])
{
int min = INT_MAX, min_index;
for (int v = 0; v < V; v++)
if (sptSet[v] == false && dist[v] <= min)
min = dist[v], min_index = v;
return min_index;
}
void printSolution(int dist[])
{
cout <<"Vertex \t Distance from Source" << endl;
for (int i = 0; i < V; i++)
cout << i << " \t\t"<<dist[i]<< endl;
}
void dijkstra(int graph[V][V], int src, int d, int t)
{
int dist[V]; 
bool sptSet[V]; 
for (int i = 0; i < V; i++)
dist[i] = INT_MAX, sptSet[i] = false;
dist[src] = 0;
for (int count = 0; count < V - 1; count++) {
int u = minDistance(dist, sptSet);
sptSet[u] = true;
for (int v = 0; v < V; v++)
if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
&& dist[u] + graph[u][v] < dist[v])
dist[v] = dist[u] + graph[u][v];
}
cout<<"\n\t The shortest time taken to travel is : "<<dist[d];
cout<<"\n\t Actual time of arrival is : "<<(t+dist[d])/24<<" day "<<(t+dist[d])%24<<":00 
hrs";
}
int main()
{
cout<<"\t Welcome to Ragul Train Services"<<endl;
cout<<"\n\t Places in which train service is available:";
cout<<"\n\t 1. Chennai";
cout<<"\n\t 2. Coimbatore";
cout<<"\n\t 3. Bangalore";
cout<<"\n\t 4. Mumbai";
cout<<"\n\t 5. Delhi";
cout<<"\n\t 6. Madurai";
cout<<"\n\t 7. Kolkata";
cout<<"\n\t 8. Pune";
cout<<"\n\t 9. Goa";
cout<<"\n\t Enter your departure place : ";
int d;cin>>d;
cout<<"\n\t Enter your arrival place : ";
int a;cin>>a;
cout<<"\n\t Enter departure time (24 hr) : ";
int t; cin>>t;
int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
dijkstra(graph, d-1, a-1, t);
return 0;
