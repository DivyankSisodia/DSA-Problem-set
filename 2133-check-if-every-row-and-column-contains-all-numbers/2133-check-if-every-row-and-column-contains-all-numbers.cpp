class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> m;
            for (int j = 0; j < n; j++)
            {
                m[matrix[i][j]]++;
            }
            if (m.size() != n)
            {
                return false;
            }
        }
        for (int i = 0; i < n; i++)
        {
           unordered_map<int, int> m;
            for (int j = 0; j < n; j++)
            {
                m[matrix[j][i]]++;
            }
            if (m.size() != n)
            {
                return false;
            }
        }
        return true;
    }
};