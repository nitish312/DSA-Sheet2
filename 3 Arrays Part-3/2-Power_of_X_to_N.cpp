// // 1. brute ? O(N) : O(1)
// #include<iostream>
// using namespace std;

// double myPow(double x, int n){
    
//     int neg = n;
//     double ans = 1;

//     while(n--){

//         ans *= x;
//     }

//     return (neg < 0) ? (1.0)/ans : ans;
// }

// int main(){

//     double x = 2.10000, n = 3;

//     double ans = myPow(x, n);

//     cout << x <<" raised to the power "<< n <<" is "<< ans << endl;

//     return 0;
// }


// // 2. optimal ? O(log(N)) : O(1)
#include<iostream>
using namespace std;

double myPow(double x, int n){
    
    double ans = 1.0;

    long nn = n;

    if(nn < 0) nn = -1 * nn; // if neg, make it pos

    while(nn > 0){

        if(nn % 2 == 1){

            ans *= x;
            nn = nn - 1;
        }
        else{

            x *= x;
            nn = nn / 2;
        }
    }

    if(n < 0) ans = (1.0) / (ans);

    return ans;
}

int main(){

    double x = 2.10000, n = 3;

    double ans = myPow(x, n);

    cout << x <<" raised to the power "<< n <<" is "<< ans << endl;

    return 0;
}