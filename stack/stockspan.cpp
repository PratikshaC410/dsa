#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> calculateSpan(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> span(n);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - s.top();
        }
        s.push(i);
    }
    return span;
}

int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = calculateSpan(prices);

    cout << "Stock Prices: ";
    for (int p : prices)
        cout << p << " ";

    cout << "\nSpan Values:  ";
    for (int s : result)
        cout << s << " ";
    cout << endl;

    return 0;
}