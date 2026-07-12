// LC 127: Word Ladder (Hard)
// Link: https://leetcode.com/problems/word-ladder/
// Approach: Single-Source BFS. Finds the shortest transformation sequence 
//           by changing one character at a time and checking against a set.
// Time: O(N * L * 26) where N is number of words, L is word length.
// Space: O(N) to store words in the set and queue.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Queue stores {word, steps}
        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        // Use set for O(1) lookups and tracking unvisited words
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // Try changing each character position
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        if(word == endWord) return steps + 1; // Target reached
                        st.erase(word); // Mark as visited
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original; // Backtrack/restore
            }
        }
        return 0;
    }
};
