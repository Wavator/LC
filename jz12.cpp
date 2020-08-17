//
// Created by Zhao on 2020/8/17.
//
class Solution {
public:

    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    bool ans = false;
    void dfs(vector<vector<char>> &board, string &word, int position, int x, int y) {
        board[x][y] -= 128;
        for (int i = 0; i < 4; ++i) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_y < 0 || next_x >= board.size() || next_y >= board[0].size() ||
                board[next_x][next_y] < 0 || word[position + 1] != board[next_x][next_y] || ans) {
                continue;
            }
            if (position + 1 == word.size() - 1) {
                ans = true;
                return;
            }
            dfs(board, word, position + 1, next_x, next_y);
        }
        board[x][y] += 128;
    }

    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    dfs(board, word, 0, i, j);
                    if (ans || word.size() == 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
//找出所有的起点dfs即可
