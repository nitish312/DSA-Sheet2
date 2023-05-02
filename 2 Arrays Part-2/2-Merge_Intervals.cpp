// 1. brute ? O(N*logN) + O(N^2) -> O(N^2*logN) : O(N)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVecOfVec(vector<vector<int>> matrix){

	int n = matrix.size();
	int m = matrix[0].size();

	for(int i=0; i<n; i++){

		for(int j=0; j<m; j++){

			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

vector<vector<int>> mergeOverlappers(vector<vector<int>>& intervals){

	vector<vector<int>> mergedIntervals;

	if(intervals.size() == 0) return mergedIntervals;

	sort(intervals.begin(), intervals.end());

	vector<int> curr = intervals[0];

	for(auto inter: intervals){

		if(inter[0] <= curr[1]){

			curr[1] = max(curr[1], inter[1]);
		}
		else{

			mergedIntervals.push_back(curr);
			curr = inter;
		}
	}

	// for(int i=1; i<intervals.size(); i++){

	// 	if(curr[1] > intervals[i][0]){

	// 		curr[1] = max(curr[1], intervals[i][1]);
	// 	}
	// 	else{

	// 		mergedIntervals.push_back(curr);
	// 		curr = intervals[i];
	// 	}
	// }

	mergedIntervals.push_back(curr);

	return mergedIntervals;
}

int main(){

	vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    printVecOfVec(intervals);

    vector<vector<int>> overlapped = mergeOverlappers(intervals);

    cout << "Merged Overlapping Intervals are " << endl;

    printVecOfVec(overlapped);

	return 0;
}



// 2. optimal ? O(N*logN) + O(N) -> O(N*logN) : O(N)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVecOfVec(vector<vector<int>> matrix){

	int n = matrix.size();
	int m = matrix[0].size();

	for(int i=0; i<n; i++){

		for(int j=0; j<m; j++){

			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

vector<vector<int>> mergeOverlappers(vector<vector<int>>& intervals){

	vector<vector<int>> mergedIntervals;

	if(intervals.size() == 0) return mergedIntervals;

	sort(intervals.begin(), intervals.end());

	vector<int> curr = intervals[0];

	for(int i=0; i<intervals.size(); i++){
	    
	    if(mergedIntervals.empty() || mergedIntervals.back()[1] < intervals[i][0]){
	      
		    vector<int> v = { intervals[i][0],
		        			  intervals[i][1] };

		    mergedIntervals.push_back(v);
	    } 
	    else{
	      
	      	mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
	    }
  	}

	return mergedIntervals;
}

int main(){

	vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    printVecOfVec(intervals);

    vector<vector<int>> overlapped = mergeOverlappers(intervals);

    cout << "Merged Overlapping Intervals are " << endl;

    printVecOfVec(overlapped);

	return 0;
}