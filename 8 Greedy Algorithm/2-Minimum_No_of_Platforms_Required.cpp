#include<bits/stdc++.h>
using namespace std;

// sort & greedy ? O(2*(N*logN)) + O(2N) -> O(N*logN) : O(1)
int calculateMinPlatforms(int at[], int dt[], int n){

    sort(at, at + n);
    sort(dt, dt + n);

    int ans = 1, plat_needed = 1;
    int i = 1, j = 0;

    while(i < n && j < n){

        if(at[i] <= dt[j]){

            plat_needed++;
            i++;
        }
        else if(at[i] > dt[j]){

            plat_needed--;
            j++;
        }

        if(plat_needed > ans)
            ans = plat_needed;
    }

    return ans;
}

int main(){

    // int n = 6;
    // int at[] = {900, 940, 950, 1100, 1500, 1800};
    // int dt[] = {910, 1200, 1120, 1130, 1900, 2000};

    int n = 4;
    int at[] = {1,2,3,4};
    int dt[] = {2,3,4,5};

    int platforms = calculateMinPlatforms(at, dt, n);
    cout<<"Railways station requires atleast "<<platforms<<" platforms";

    return 0;
}