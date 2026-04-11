// You are playing a mobile game called The Energy Balance Game while walking home. In this game, there are (n + 1) towers numbered from 0 to n. Tower 0 has a height of 0, and each tower i (i > 0) has a height given by height hi. Your objective is to reach the final tower (tower n) while maintaining a safe level of energy.
// You start at tower 0 with an initial energy of 0. From your current tower, you can only move to the next tower (current + 1). After each move, your energy increases by the height of the current tower minus the height of the next tower (that is, height[current]− height[current + 1]). If this value is negative, you lose energy; otherwise, you gain energy. At no point during the journey should your energy become negative.
// To help you maintain energy balance, the game provides a special option: you can spend 1 dollar to increase the height of any tower by 1 unit. You may use this option multiple times, but your goal is to spend the minimum amount of money required to successfully reach the final tower without your energy ever dropping below zero.
// Input Format

// * The first line contains an integer n
// * The second line contains n space-separated integers h₁, h₂, ..., hₙ
// Constraints

// * 1≤𝑛≤105
// * 1≤hi≤105
// Output Format
// Print a single integer denoting the minimum amount of money required to complete the game without the energy ever becoming negative.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> height(n + 1);
    height[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> height[i];
    }

    long long energy = 0;
    long long min_energy = 0;

    // Simulate the journey
    for (int i = 0; i < n; i++)
    {
        energy += (height[i] - height[i + 1]);
        min_energy = min(min_energy, energy);
    }

    // Cost = absolute value of minimum negative energy
    long long cost = max(0LL, -min_energy);

    cout << cost << "\n";

    return 0;
}