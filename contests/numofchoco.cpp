<!-- Siya is a professional sleeper — so good at it that she earned a lot of money and eventually opened a small chocolate factory.

Now, she needs to prepare at least n chocolates.

She can produce chocolates in three types of batches:

Small batch → produces 6 chocolates (takes 15 minutes)
Medium batch → produces 8 chocolates (takes 20 minutes)
Large batch → produces 10 chocolates (takes 25 minutes)
Siya wants to prepare batches such that the total number of chocolates is at least n, while minimizing the total production time.

Input Format

The first line contains a single integer t — the number of test cases. Each test case consists of a single integer n — the required number of chocolates.

Constraints

(1≤t≤104)
(1≤n≤1016)
 -->

 #include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        if (n <= 6) {
            cout << 15 << endl;
        } else {
            if (n % 2 != 0) n++;  
            cout << (n / 2) * 5 << endl;
        }
    }

    return 0;
}