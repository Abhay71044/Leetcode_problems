class Solution {
public:
    bool binarySearch(int i, int n, vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (matrix[i][mid] == target) {
                return true;
            }
            else if (matrix[i][mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            if (binarySearch(i, n, matrix, target)) {
                return true;
            }
        }
        return false;
    }
};
