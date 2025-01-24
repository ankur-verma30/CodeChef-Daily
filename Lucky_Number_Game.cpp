/*
Lucky Number Game

Bob and Alice are playing a game with the following rules:

Initially, they have an integer sequence A1, A2, ..., AN; in addition, Bob has a lucky number a and Alice has a lucky number b. The players alternate turns. In each turn, the current player must remove a non-zero number of elements from the sequence; each removed element should be a multiple of the lucky number of this player. If it is impossible to remove any elements, the current player loses the game.

It is clear that one player wins the game after a finite number of turns. Your task is to find the winner of the game if Bob plays first and both Bob and Alice play optimally.

Input

- The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
- The first line for each test case contains three space-separated integers N, a, and b.
- The second line contains N space-separated integers A1, A2, ..., AN.

Output

For each test case, print a single line containing the string "ALICE" if the winner is Alice or "BOB" if the winner is Bob (without quotes).

Constraints

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 2 × 10^5
- 1 ≤ a, b ≤ 100
- 1 ≤ Ai ≤ 10^9 for each valid i

Subtasks

- Subtask #1 (18 points): a = b
- Subtask #2 (82 points): original constraints

Sample Input
2
5 3 2
1 2 3 4 5
5 2 4
1 2 3 4 5

Sample Output
ALICE
BOB

Explanation
- In the first test case, Bob removes 3, and the sequence becomes [1, 2, 4, 5]. Then, Alice removes 2, and the sequence becomes [1, 4, 5]. Now, Bob is left with no moves, so Alice is the winner.
- In the second test case, Bob can remove 2, and Alice will be left with no valid moves, making Bob the winner.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

// Ankur Verma
bool solve(int n, vector<int> &numbers, int a, int b)
{
    int bobCount = 0, AliceCount = 0;

    for (const auto number : numbers)
    {
        if (number % a == 0)
            bobCount++;
        else if (number % b == 0)
            AliceCount++;
    }

    if (AliceCount == bobCount)
        return false;
    else if (bobCount - AliceCount >= 1)
        return true;

    return false;
}

int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> numbers(n);
        for (int i = 0; i < n; i++)
            cin >> numbers[i];

        if (solve(n, numbers, a, b))
            cout << "BOB" << endl;
        else
            cout << "ALICE" << endl;
    }
    return 0;
}
