#include <iostream>
#include<limits>
using namespace std;

//Dynamic and non dynamic way to find the ith fibbonacci number
int fibbonacci(int i){
    if(i == 0) return 0;
    if(i == 1) return 1;
    return fibbonacci(i - 1) + fibbonacci(i - 2);
}

int fib [1000] = { };
int fibbonacciDP(int i) {
    if(i == 0) return 0;
    if(i == 1) return 1;
    if(fib[i] != 0)return fib[i]; // return cached result
    fib[i] = fibbonacci(i-1) + fibbonacci(i-2);
    return fib[i];
}


//A child is running up a staircase with n steps, and can hop 1 or 2 or 3 steps at a time. How many possible ways
//can the child run up the stairs

//Non dynamic
int countWays(int n){
    if(n < 0){
        return 0;
    } else if(n == 0){
        return 1;
    } else{
        return countWays(n - 1) + countWays(n-2) + countWays(n-3);
    }
}
//Dynamic
int countWaysDP(int n, int waysmap[]){
    if(n < 0){
        cout << "Hit0\n";
        return 0;
    } else if(n == 0){
        cout << "Hit1\n";
        return 1;
    }else if(waysmap[n] > -1){
        cout << "Hit2\n";
        return waysmap[n];
    }else{
        cout << "Hit3\n";
        waysmap[n] = countWaysDP(n-1, waysmap)+countWaysDP(n-2, waysmap)+countWaysDP(n-3, waysmap);
        return waysmap[n];
    }
}
/*
int main()
{int n = 0;
int waysmap[1000] = {};
    while (n < 100){
        cin >> n;
        cout << "Variations with " << n << " stairs: " << countWaysDP(n, waysmap) << endl;
        cout << n << "th Fibbonaci number is " << " is: " << fibbonacciDP(n) << endl;
    }
}*/

int noOfSteps(int n, int arr[]){
	if(arr[n])
		return arr[n];
	if(n<4){
		if(n==1)
			arr[n] = 1;
		else if(n==2){
			arr[2] = 2;
		}
		else if(n==3){
			arr[3] = 4;
		}
	}
	else
		arr[n] = noOfSteps(n-1, arr) + noOfSteps(n-2, arr) + noOfSteps(n-3, arr);
	return arr[n];
}

int main(){
	int n = 4;
	int arr[n+1] = {-1};
	cout<<noOfSteps(n, arr);
	return 0;
}
