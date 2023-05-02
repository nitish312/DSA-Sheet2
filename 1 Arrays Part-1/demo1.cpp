#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, n;
	string s;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> s;

		string ans = "";
        ans.push_back(s[0]);

        for(int i = 1; i < n; i++){
            if(ans.size() % 2 == 1){
                if(ans.back() != s[i]){
                    ans.push_back(s[i]);
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }

        if(ans.size() % 2 == 1) ans.pop_back();

        int diff = s.size() - ans.size();

        cout << diff << endl;
        cout << ans << endl;
	}

	return 0;
}