#include<iostream>
#include<vector>

using namespace std ;

void explore(vector<vector<int> > &adj, int v, vector<int> &visited){

	visited[v] = 1 ;
	for(int i = 0 ; i < adj[v].size() ; i++ ){
		if( !visited[adj[v][i]] )
			explore(adj, adj[v][i], visited) ;
			
	}
}

int count_components(vector<vector<int> > &adj){
	int res = 0 ;
	vector<int> visited(adj.size()) ;
	
	for(int i = 0 ; i < adj.size() ; i++ ){
		if( !visited[i] ){
			explore(adj, i, visited) ;
			res++ ;
		}
	}

	return res ;
}

int main(){

	int n, m ;
	cin >> n >> m ;
	vector<vector<int> > adj(n, vector<int>()) ;
	int x, y ;

	for(int i = 0 ; i < m ; i++ ){	
		cin >> x >> y ;
		adj[x-1].push_back(y-1) ;
		adj[y-1].push_back(x-1) ;
	}

	cout << count_components(adj) ;

	return 0 ;
}
