class Solution{
    public:
	void frequencyCount(vector<int>& arr, int N, int P){
        
        	unordered_map<int, int> mpp;
       	 	for(int i = 0; i < N; i++){
            	mpp[arr[i]]++;
        }
        for(int i = 1; i <= N; i++){
            arr[i-1] = mpp[i];
        }
    }
};
