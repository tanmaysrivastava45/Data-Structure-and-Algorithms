// C++ program of the above approach
#include <bits/stdc++.h>
using namespace std;

// Function which returns
// the largest possible string
string lexicographicallyLargest(string S, int K)
{
	// Finding length of the string
	int n = S.length();

	// Creating two priority queues of pairs
	// for odd and even indices separately
	priority_queue<pair<char, int> > pqOdd, pqEven;

	// Storing all possible even
	// indexed values as pairs
	for (int i = 2; i < n; i = i + 2) {
		// Stores pair as {character, index}
		pqEven.push({S[i], i});
	}

	// Storing all possible odd indexed
	// values as pairs
	for (int i = 3; i < n; i = i + 2) {
		// Stores pair as {character, index}
		pqOdd.push(make_pair(S[i], i));
	}

	for (int i = 0; i < n; i++) {
		// For even indices
		if (i % 2 == 0) {

			// Removing pairs which
			// cannot be used further
			while (!pqEven.empty()
				&& pqEven.top().second <= i)
				pqEven.pop();

			// If a pair is found whose index comes after
			// the current index and its character is
			// greater than the current character
			if (!pqEven.empty()
				&& pqEven.top().first > S[i]) {

				// Swap the current index with index of
				// maximum found character next to it
				swap(S[i], S[pqEven.top().second]);

				int idx = pqEven.top().second;
				pqEven.pop();
				// Push the updated character at idx index
				pqEven.push({ S[idx], idx });
				K--;
			}
		}
		// For odd indices
		else {
			// Removing pairs which cannot
			// be used further

			while (!pqOdd.empty()
				and pqOdd.top().second <= i)
				pqOdd.pop();

			// If a pair is found whose index comes after
			// the current index and its character is
			// greater than the current character

			if (!pqOdd.empty()
				and pqOdd.top().first > S[i]) {

				// Swap the current index with index of
				// maximum found character next to it
				swap(S[i], S[pqOdd.top().second]);
				int idx = pqOdd.top().second;
				pqOdd.pop();

				// Push the updated character at idx index
				pqOdd.push({ S[idx], idx });
				K--;
			}
		}
		// Breaking out of the loop if K=0
		if (K == 0)
			break;
	}

	return S;
}
// Driver Code
int main()
{
	// Input
	string S = "geeksforgeeks";
	int K = 2;

	// Function Call
	cout << lexicographicallyLargest(S, K);
	return 0;
}
