#include<iostream>
#include<vector>

using namespace std ;

int explore(vector<vector<int> > &adj, int x, int y, vector<int> &visited){

	if( x == y )
		return 1 ;

	visited[x] = 1 ;
	for(int i = 0 ; i < adj[x].size() ; i++ ){
		if( !visited[adj[x][i]] )
			if( explore(adj, adj[x][i], y, visited) )
				return 1 ;
	}

	return 0 ;
}

int reach(vector<vector<int> > &adj, int x, int y){

	vector<int> visited(adj.size()) ;
	return explore(adj, x, y, visited) ;
}

int main(){

	size_t n, m ;
	cin >> n >> m ;
	int x, y ;

	vector<vector<int> > adj(n, vector<int>()) ;

	for(size_t i = 0 ; i < m ; i++ ){

		cin >> x >> y ;
		adj[x-1].push_back(y-1) ;
		adj[y-1].push_back(x-1) ;
	}

	cin >> x >> y ;

	cout << reach(adj, x-1, y-1) ;

	return 0 ;
}


