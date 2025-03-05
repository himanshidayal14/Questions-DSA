class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int maxLength = 0;

        // Iterate through each pair of elements
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                int a = arr[i], b = arr[j];
                int length = 2; // We already have two elements in the sequence
                
                // Attempt to find the next Fibonacci-like number
                while (true) {
                    int c = a + b; // Next Fibonacci-like number
                    bool found = false;

                    // Look for c in the remaining part of the array
                    for (int k = j + 1; k < n; ++k) {
                        if (arr[k] == c) {
                            found = true;
                            break;
                        }
                    }

                    if (!found) break; // Stop if the next number isn't found
                    length++; // Increment the length of the valid sequence
                    a = b;    // Move forward in the sequence
                    b = c;    // Update b to be the new Fibonacci number
                }

                // Update the maximum length found
                maxLength = max(maxLength, length);
            }
        }

        return maxLength >= 3 ? maxLength : 0; // Return 0 if no valid sequence found
    }
};