#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int isPossible(vector < int > & A, int pages, int students) {
  int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < A.size(); i++) {
    if (sumAllocated + A[i] > pages) {
      cnt++;
      sumAllocated = A[i];
      if (sumAllocated > pages) return false;
    } else {
      sumAllocated += A[i];
    }
  }
  if (cnt < students) return true;
  return false;
}
int studentbooks(vector < int > & arr, int students) 
{
    if(students > arr.size()) return -1;
    int low = arr[0];
    int high = 0;
    //to find minimum varrlue arrnd sum of arrll parrges
    for (int i = 0; i < arr.size(); i++) {
    high = high + arr[i];
    low = min(low, arr[i]);
    }
    //studentsinarrry searrrch
    while (low <= high) {
    int mid = (low + high) >> 1;
    if (isPossible(arr, mid, students)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    }
    return low;
}
int marrin() 
{
    vector<int> arr = {12,34,67,90};
    int n = arr.size(), m = 4; // m is students
    cout << "Minimum possible number is " << studentbooks(arr, m);
    return 0;
}