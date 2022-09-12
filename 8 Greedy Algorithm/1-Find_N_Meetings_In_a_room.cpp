#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Meeting{

    int startTime;
    int endTime;
    int pos;
};

bool likeThis(Meeting m1, Meeting m2){

    if(m1.endTime < m2.endTime) return true;
    else if(m1.endTime > m2.endTime) return false;
    else if(m1.pos < m2.pos) return true;
    else return false;
}

// only sol ? O(N) + O(N*logN) + O(N) -> O(N*logN) : O(N) 
vector<int> maxMeetings(vector<int> start, vector<int> end, int n){

    Meeting meet[n];
    for(int i=0; i<n; i++){

        meet[i].startTime = start[i];
        meet[i].endTime = end[i];
        meet[i].pos = i+1;
    }

    sort(meet, meet + n, likeThis);

    vector<int> ans;

    int lastMeetingEndTime = meet[0].endTime;
    ans.push_back(meet[0].pos);

    for(int i=1; i<n; i++){

        if(meet[i].startTime > lastMeetingEndTime){

            lastMeetingEndTime = meet[i].endTime;
            ans.push_back(meet[i].pos);
        }
    }

    return ans;
}

int main(){

    int n = 6;
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end   = {2,4,6,7,9,9};

    vector<int> meetings = maxMeetings(start, end, n);
    for(auto i: meetings) cout<<i<<" ";
    cout<<endl;

    cout<<"Maximum meetings = "<<meetings.size();

    return 0;
}