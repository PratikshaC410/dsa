#include<bits/stdc++.h>
using namespace std;

bool canSort(vector<long long>& a, vector<bool>& increase) {
    int n = a.size();
    
    // Find the range of valid k values
    long long min_k = 1;
    long long max_k = 2e9;
    
    for(int i = 1; i < n; i++) {
        // We need: a[i] + (increase[i] ? k : 0) >= a[i-1] + (increase[i-1] ? k : 0)
        
        if(increase[i] && !increase[i-1]) {
            // a[i] + k >= a[i-1]
            // k >= a[i-1] - a[i]
            if(a[i-1] > a[i]) {
                min_k = max(min_k, a[i-1] - a[i] + 1);
            }
        } else if(!increase[i] && increase[i-1]) {
            // a[i] >= a[i-1] + k
            // k <= a[i] - a[i-1]
            max_k = min(max_k, a[i] - a[i-1] - 1);
        }
        // If both same: a[i] >= a[i-1] must hold
    }
    
    if(min_k > max_k || min_k <= 0) return false;
    
    long long k = min_k;
    
    for(int i = 1; i < n; i++) {
        long long prev_val = a[i-1] + (increase[i-1] ? k : 0);
        long long curr_val = a[i] + (increase[i] ? k : 0);
        if(curr_val < prev_val) return false;
    }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Check if already sorted
        bool sorted = true;
        for(int i = 1; i < n; i++) {
            if(a[i] < a[i-1]) {
                sorted = false;
                break;
            }
        }
        
        if(sorted) {
            cout << "Yes\n";
            continue;
        }
        
        bool found = false;
        
        // Key insight: Try increasing all elements from position i onwards
        for(int i = 0; i < n && !found; i++) {
            vector<bool> increase(n, false);
            for(int j = i; j < n; j++) {
                increase[j] = true;
            }
            
            if(canSort(a, increase)) {
                found = true;
            }
        }
        
        cout << (found ? "Yes" : "No") << "\n";
    }
    
    return 0;
}