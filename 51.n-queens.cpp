/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (48.69%)
 * Likes:    2631
 * Dislikes: 98
 * Total Accepted:    239.4K
 * Total Submissions: 484K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [["Q"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool placevalid(int row,int col,int n,int **table){
        // check horizontal
        for(int i=0;i<n;i++){
            if(table[row][i]==1){
                return false;
            }
        }
        // check vertical
        for(int i=0;i<n;i++){
            if(table[i][col]==1){
                return false;
            }
        }
        // check diagonal left
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(table[i][j]==1){
                return false;
            }
        }
        // check diagonal right
        for(int i=row,j=col;i>=0&&j<n;j++,i--){
            if(table[i][j]==1){
                return false;
            }
        }
        return true;
    }
    void nqueen(int n,int row,vector<vector<string>> &ans,int **table){
        // base case
        if(row>=n){
            cout<<"1";
            vector<string> temp;
            for(int i=0;i<n;i++){
                string strrow;
                for(int j=0;j<n;j++){
                    if(table[i][j]==1){
                        strrow.push_back('Q');
                    }else{
                        strrow.push_back('.');
                    }
                }
                temp.push_back(strrow);
            }
            ans.push_back(temp);
            return;
        }
        // try to fill each column of the current row
        for(int i=0;i<n;i++){
            if(placevalid(row,i,n,table)){
                // fill
                table[row][i]=1;
                // call
                nqueen(n,row+1,ans,table);
                // revert
                table[row][i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int **table=new int*[n+1];
        for(int i=0;i<=n;i++){
            table[i]=new int[n+1]{};
        }
        vector<vector<string>> ans;
        nqueen(n,0,ans,table);
        return ans;
    }
};
// @lc code=end

