// GFG: Minimum Multiplications to Reach End (Medium)
// Link: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
// Approach: BFS (unweighted shortest path) on nodes from 0 to 999 (modulo 1000).
// Time: O(1000 * N) where N is the size of arr.
// Space: O(1000) for the steps/visited array.

class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        
        // Queue stores {current_node, steps_taken}
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        vector<int> steps(1000, INT_MAX);
        steps[start] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int nodeSteps = q.front().second;
            q.pop();
            
            // Prune stale queue entries
            if(nodeSteps > steps[node]) continue;

            for(int i = 0; i < arr.size(); i++){
                int curr = (node * arr[i]) % 1000;
                int currSteps = nodeSteps + 1;
                
                // Return steps immediately when end is reached
                if(curr == end) return currSteps;
                
                if(steps[curr] > currSteps){ 
                    steps[curr] = currSteps;
                    q.push({curr, currSteps});
                }
            }
        }
        return -1; // Unreachable
    }
};
