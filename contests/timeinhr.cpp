// In the ancient kingdom of Horologium, time governs every aspect of life. At its center lies the legendary Chrono Dial, an artifact that has faithfully tracked time for centuries using the traditional 24-hour format.
// Over time, however, the people of the kingdom have grown accustomed to the simpler 12-hour format, dividing the day into AM and PM. As a result, the readings of the Chrono Dial have become difficult for them to interpret, leading to confusion in daily activities.
// To restore order, the Royal Timekeeper Guild has assigned you the task of translating the Dial’s readings into a format the citizens can understand.

// Input Format

// The first line contains an integer t - the number of test cases.
// Each of the next t lines contains a string s representing time in the format hh:mm.
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string time;
        cin >> time;

        int hours = stoi(time.substr(0, 2));
        string minutes = time.substr(3, 2);

        string period = (hours >= 12) ? "PM" : "AM";

        hours = (hours % 12 == 0) ? 12 : (hours % 12);

        // Output
        cout << setfill('0') << setw(2) << hours << ":" << minutes << " " << period << "\n";
    }

    return 0;
}