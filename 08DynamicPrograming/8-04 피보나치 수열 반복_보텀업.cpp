#include <iostream>
using namespace std;

// 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화
long long dp[100];

int main(void) {
    // 첫 번째 피보나치 수와 두 번째 피보나치 수는 1
    dp[1] = 1;
    dp[2] = 1;
    int n = 50; // 50번째 피보나치 수를 계산

    // 피보나치 함수(Fibonacci Function) 반복문으로 구현(보텀업 다이나믹 프로그래밍)
    for (int i = 3; i <= n; i++) 
        dp[i] = dp[i - 1] + dp[i - 2];
    
    cout << d[n] << '\n';
}
