class Solution {
public:
    

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> result(m, vector<int>(n, -1)); // Initialize the result matrix with -1

        queue<pair<int, int>> q;

        // Initialize queue with all cells having value 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions for neighbors (up, down, left, right)
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // Perform BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newRow = row + dx[k];
                int newCol = col + dy[k];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && result[newRow][newCol] == -1) {
                    result[newRow][newCol] = result[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return result;
    }
};
