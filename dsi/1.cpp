// Q.Given a string s, process it from left to right. Whenever you encounter the character 'i' at position p:
// Reverse the substring s[0 : p) (from index 0 to p-1)
// Remove the character 'i' from the string
// If the character 'i' occurs multiple times, apply the same operation each time it is encountered. Return the final resulting string after processing the entire input.
// Input: s = "string", Output: "rtsng"
// Input: s = "poiinter", Output: "ponter"

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

string solve(string s) {
    deque<char> dq;
    bool isReversed = false;

    for (char c : s) {
        if (c == 'i') {
            // "i" means we flip our perspective of the string
            isReversed = !isReversed;
        } else {
            // If flipped, adding to the front is equivalent to 
            // adding to the back and then reversing the whole thing later.
            if (isReversed) {
                dq.push_front(c);
            } else {
                dq.push_back(c);
            }
        }
    }

    // Convert deque back to string
    string result(dq.begin(), dq.end());

    // If we ended in a reversed state, the final string must be flipped
    if (isReversed) {
        reverse(result.begin(), result.end());
    }

    return result;
}

int main() {
    // Testing the 5 cases
    cout << "1. abcid    -> " << solve("abcid") << endl;    // Expected: cbad
    cout << "2. abii     -> " << solve("abii") << endl;     // Expected: ab
    cout << "3. aibic    -> " << solve("aibic") << endl;    // Expected: bac
    cout << "4. ihello   -> " << solve("ihello") << endl;   // Expected: hello
    cout << "5. poiinter -> " << solve("poiinter") << endl; // Expected: ponter
    
    return 0;
}
