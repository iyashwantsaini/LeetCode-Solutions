/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (45.60%)
 * Likes:    2378
 * Dislikes: 99
 * Total Accepted:    216.6K
 * Total Submissions: 472.3K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * The '.' character indicates empty cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool find_empty(vector<vector<char>>& board,int &row,int &col){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    row=i,col=j;
                    return true;
                }
            }
        }
        return false;
    }
    void set_char(vector<vector<char>>& board,int row,int col,char c){
        board[row][col]=c;
    }
    void reset_char(vector<vector<char>>& board,int row,int col){
        board[row][col]='.';
    }
    bool valid_h(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c){
                return false;
            }
        }
        return true;
    }
    bool valid_v(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c){
                return false;
            }
        }
        return true;
    }
    bool valid_b(vector<vector<char>>& board,int row,int col,char c){
        int startr=(row/3)*3;
        int startc=(col/3)*3;
        for(int i=startr;i<startr+3;i++){
            for(int j=startc;j<startc+3;j++){
                if(board[i][j]==c){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        
            int row,col;
            // find empty posn
            if(find_empty(board,row,col)){
                int flag=0;
                for(int i=1;i<10;i++){
                    char c='0'+i;
                    // check valid horizontal
                    bool h=valid_h(board,row,col,c);
                    // check valid vertical
                    bool v=valid_v(board,row,col,c);
                    // check valid in box
                    bool b=valid_b(board,row,col,c);
                    // if all valid => set and call solve again
                    if(h&&v&&b){
                        flag=1;
                        // set char
                        set_char(board,row,col,c);
                        if(solve(board)){
                            return true;
                        }
                        // reset in backtracking
                        reset_char(board,row,col);
                    }
                }
                if(flag==0){
                    return false;
                }
            }else{
                return true;
            }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
// @lc code=end

