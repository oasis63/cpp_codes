#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Element {
    int num;  // Number
    int freq; // Frequency

    // Custom comparison for priority queue (higher frequency first)
    bool opeoperatorrator < (const Element &other) const {
        return freq < other.freq;
    }
};

int minOperations(int A[], int N, int K) {
    unordered_map<int, int> freq_map; // Hash table for frequency counting

    // Count frequencies
    for (int i = 0; i < N; i++) {
        freq_map[A[i]]++;
    }

    // Create a priority queue with custom comparison for descending order of
    // frequency
    priority_queue<Element> pq;
    for (auto it = freq_map.begin(); it != freq_map.end(); ++it) {
        pq.push({it->first, it->second});
    }

    int min_operations = 0;
    while (!pq.empty()) {
        // Get the element with the highest frequency (front of pq)
        Element top_element = pq.top();
        pq.pop();

        // Skip if the element is already K
        if (top_element.num == K) {
            continue;
        }

        // Calculate the difference in frequencies
        int diff = top_element.freq - freq_map[K];
        if (diff <= 0) {
            break; // No more operations needed if current freq is less than or
                   // equal to K's freq
        }

        // Update frequencies and pq
        freq_map[top_element.num] -= diff;
        freq_map[K] += diff;
        pq.push({top_element.num,
                 freq_map[top_element.num]}); // Update element in pq with new
                                              // frequency
        min_operations += diff;
    }

    return min_operations;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int min_ops = minOperations(A, N, K);
        cout << min_ops << endl;
    }

    return 0;
}

/*

2
3 1
1 1 3
4 1
1 1 3 3

*/`
