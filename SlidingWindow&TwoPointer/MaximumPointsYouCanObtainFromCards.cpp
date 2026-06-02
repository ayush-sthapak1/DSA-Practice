// LC 1423: Maximum Points You Can Obtain from Cards (Medium)
// Approach: Ultra-Optimal Sliding Window (O(k) Boundary Substitution)
// Time: O(k) - completely skips traversing the middle cards!
// Space: O(1) auxiliary

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int currSum = 0;

        // 1. Initially take all k cards from the left
        for (int i = 0; i < k; i++) {
            currSum += cardPoints[i];
        }

        int maxScore = currSum;

        // 2. Systematically substitute left cards with right cards
        // left cards are removed from right-to-left: indices (k-1) down to 0
        // right cards are added from right-to-left: indices (n-1) down to (n-k)
        for (int i = 0; i < k; i++) {
            currSum -= cardPoints[k - 1 - i];
            currSum += cardPoints[n - 1 - i];
            maxScore = max(maxScore, currSum);
        }

        return maxScore;
    }
};
