#include<iostream>
#include<vector>;
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> matrix)
	    {
	        priority_queue<pair<int, int>,
			               vector<pair<int, int> >, greater<pair<int, int>>> pq;

			vector<int> vis(V, 0);
			// {wt, node}
			vector<int> parent(V, -1);
			pq.push({0, 0});
			int sum = 0;
			while (!pq.empty()) {
				auto it = pq.top();
				cout << "content in priority Queue :" << it.first << " " << it.second << endl ;
				pq.pop();
				int node = it.second;
				int wt = it.first;
				if (vis[node] == 1) continue;
				// add it to the mst
				vis[node] = 1;
				sum += wt;
				for (int i=0;i<V;i++){
					if(matrix[node][i] != 0){
						int adjNode = i;
						int edW = matrix[node][i];
						if (!vis[adjNode]){
							pq.push({edW, adjNode});
							parent[adjNode] = node;
						}
				   }
			   }
			}
			cout << endl;
			cout << "Minimum Spanning Tree : " << endl;
	 		for(int i=0;i<V;i++){
	 		    printf("%d - %d\n", parent[i], i);
	 		}
			return sum;
		}
int main(){
	ifstream text_file("asn.txt");

	if(!text_file){
		cout << "File not created";
	}
	else{
 	vector<vector<int>> matrix(8, vector<int>(8, 0));;
 	string row_data, word;
 	int i = 0;
 	while(getline(text_file, row_data)){
 			stringstream str(row_data);
			int j = 0;
            while(getline(str,word,' ')){
                stringstream s(word);
                int n;
                s>>n;
                matrix[i][j] = n;
                j++;
            }
            i++;
		}
    for(int i=0;i<matrix.size();i++){
		for(int j = 0;j<matrix[0].size();j++){
			cout << matrix[i][j] << " ";
		}
	cout << endl;
    }
    int ans = spanningTree(8, matrix);
    cout << "Minimum cost :" << ans;
   }
	return 0;
}
