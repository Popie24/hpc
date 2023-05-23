#include <bits/stdc++.h> 
#include <omp.h> 
using namespace std;



 
#define N 1000 
vector<int> adj[N]; 
bool visited[N];
 
void bfs(int start) { 
	queue<int> q; 
 	q.push(start); 
	visited[start] = true; 
 	while (!q.empty()){ 
 		int u = q.front(); 
 		q.pop(); 
		cout << u << " "; 
 		#pragma omp parallel for 
		for (int i = 0; i < adj[u].size(); i++) { 
			int v = adj[u][i]; 
			if (!visited[v]) { 
 				visited[v] = true; 
 				q.push(v); 
 			} 
 		} 
 	} 
}

void dfs(int node) { 
 	stack<int> s;
	s.push(node);
	visited[node] = true;
	while(!s.empty()){
		int curr_node = s.top();
		s.pop();
		cout<<curr_node<<" ";


		#pragma omp parallel for
		for(int i =0;i<adj[curr_node].size();i++){
			int adj_node = adj[curr_node][i];
			if(!visited[adj_node]){
				s.push(adj_node);
				visited[adj_node] = true;
			}
		}
	}
}  


void setFalse(){
	for(int i =0;i<N;i++){
		visited[i] = false;
	}

}
int main() 
{ 	int n, m; 
	cin >> n >> m; 
 	for (int i = 0; i < m; i++) { 
 		int x, y; 
 		cin >> x >> y; 
		adj[x].push_back(y); 
		adj[y].push_back(x); 
 	} 
 	int start; 
	cin >> start; 

 	cout << "BFS: ";
	setFalse();
	bfs(start); 



 	cout << "DFS: ";
	setFalse();
	dfs(start); 


 	return 0; 
}
