// A C++ program to find the largest subsquare
// surrounded by 'X' in a given matrix of 'O' and 'X'
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int findSubSquare(vector<vector<int> > &mat){
    int n = mat.size();
    //constructing vertical,horizontal matrix
    vector<pair<int,int>> k(n,make_pair(0,0));
    vector< vector<pair<int,int>> > hor_vert_mat(n, vector<pair<int,int>>(n,make_pair(0,0)));
    if(0)for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
            cout << hor_vert_mat[i][j].first << ":" << hor_vert_mat[i][j].second <<" , ";
    	}
    	cout << endl;
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(mat[i][j]=='X'){
    			if(!i && !j) hor_vert_mat[i][j].first = hor_vert_mat[i][j].second = 1;
    			else if(!i){ hor_vert_mat[i][j].second = 1;hor_vert_mat[i][j].first = 1 + hor_vert_mat[i][j-1].first;}
    			else if(!j){ hor_vert_mat[i][j].first = 1;hor_vert_mat[i][j].second = 1 + hor_vert_mat[i-1][j].second;}
    			else{ hor_vert_mat[i][j].first = 1 + hor_vert_mat[i][j-1].first;hor_vert_mat[i][j].second = 1 + hor_vert_mat[i-1][j].second;}
    		}
    	}
    }
#if 1
    int max = 1;
    pair<int,int> max_index(-1,-1);
    for(int i = n-1; i >= 0; i--){
    	for(int j = n-1; j >= 0; j--){
    		int small = min(hor_vert_mat[i][j].first, hor_vert_mat[i][j].second);
    		while(small > max){
    			//leftmostvertical and topmostleft is greater than small
    			if(hor_vert_mat[i][j-small+1].second >= small && hor_vert_mat[i-small+1][j].first >= small){
    			    max = small;
    			    max_index = make_pair(i,j);
    			}
    			small--;
    		}
    	}
    }
#endif
cout << "max_index = " << max_index.first << ":" << max_index.second << endl;
return max;
}
// Driver program to test above function
int main()
{
	vector<vector<int> > mat = {{'X', 'O', 'X', 'X', 'X', 'X'},
					            {'X', 'O', 'X', 'X', 'O', 'X'},
					            {'X', 'X', 'X', 'O', 'O', 'X'},
					            {'O', 'X', 'X', 'X', 'X', 'X'},
					            {'X', 'X', 'X', 'O', 'X', 'O'},
					            {'O', 'O', 'X', 'O', 'O', 'O'},
					           };
	cout << findSubSquare(mat);
	return 0;
}
