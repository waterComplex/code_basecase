#include <iostream>
#include <vector>

using namespace std;


//recursion 
int fibonacci(int n) {
    if( n == 0 || n == 1) {
        return n;
    }
    cout<<"called for: "<<n<<endl;
    return fibonacci( n - 1 ) + fibonacci( n - 2);
}
/*
fib of 10is: called for: 10
called for: 9
called for: 8
called for: 7
called for: 6
called for: 5
called for: 4
called for: 3
called for: 2
called for: 2
called for: 3
called for: 2
called for: 4
called for: 3
called for: 2
called for: 2
called for: 5
called for: 4
called for: 3
called for: 2
called for: 2
called for: 3
called for: 2
called for: 6
called for: 5
called for: 4
called for: 3
called for: 2
called for: 2
called for: 3
called for: 2
called for: 4
called for: 3
called for: 2
called for: 2
called for: 7
called for: 6
called for: 5
called for: 4
called for: 3
called for: 2
called for: 2
called for: 3
called for: 2
called for: 4
called for: 3
called for: 2
called for: 2
called for: 5
called for: 4
called for: 3
called for: 2
called for: 2
called for: 3
called for: 2
called for: 8
called for: 7
called for: 6
called for: 5
called for: 4
called for: 3
called for: 2
called for: 2
called for: 3
called for: 2
called for: 4
called for: 3
called for: 2
called for: 2
called for: 5
called for: 4
called for: 3
called for: 2
called for: 2
called for: 3
called for: 2
called for: 6
called for: 5
called for: 4
called for: 3
called for: 2
called for: 2
called for: 3
called for: 2
called for: 4
called for: 3
called for: 2
called for: 2
55
*/


//dynamic programming
int fibonacciMemoized(int n ,vector<int> &qb ) {
    if( n == 0 || n == 1) {
        return n;
    }
    if(qb[n] != 0){
        return qb[n];
    }
    int a = fibonacciMemoized( n - 1 ,qb) ;
    int b =  fibonacciMemoized( n - 2,qb) ;
    qb[n] = a+b;
    cout<<"called for: "<<n<<endl;
    return a + b;
}
/*
fib of 10is: called for: 2
called for: 3
called for: 4
called for: 5
called for: 6
called for: 7
called for: 8
called for: 9
called for: 10
55
*/


int main() {
    int n{};
    cin>> n;
    // int qb [n+1];// 0 to n
    vector <int> qb(n+1 , 0);
    // cout<<"fib of "<<n<<"is: "<<fibonacci(n)<<endl;
    cout<<"fib of "<<n<<"is: "<<fibonacciMemoized(n,qb)<<endl;
}