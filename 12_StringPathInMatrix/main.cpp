#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <string>
#include <stack>
#include<cstring>

using namespace std;


bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    for(int i = 0;i<rows;i++)
    {
        for(int j = 0;j<cols;j++)
        {
            if(board[i][j]==word[0])
            {
                int l = 1;
                vector<vector<bool>> visited(rows,vector<bool>(cols,0));
                visited[i][j] = 1;
                vector<int> _t;
                _t.push_back(i);
                _t.push_back(j);
                vector<vector<int>> tmp;
                vector<vector<int>> tmp1;
                tmp.push_back(_t);
                while(tmp.size()!=0)
                {
                    vector<int> item = tmp[tmp.size()-1];
                    tmp.pop_back();
                    vector<int> up = {item[0]-1,item[1]};
                    vector<int> down = {item[0]+1,item[1]};
                    vector<int> left = {item[0],item[1]-1};
                    vector<int> right = {item[0],item[1]+1};
                    if(l == word.size())
                    {
                        return true;
                    }
                    if(up[0]<rows && up[0]>=0 && up[1]<cols && up[1]>=0 && board[up[0]][up[1]]==word[l] && visited[up[0]][up[1]]==0)
                    {
//                        visited[up[0]][up[1]]=1;
                        tmp1.push_back(up);
                    }
                    if(down[0]<rows && down[0]>=0&&down[1]<cols && down[1]>=0 && board[down[0]][down[1]]==word[l]&& visited[down[0]][down[1]]==0)
                    {
//                        visited[down[0]][down[1]]=1;
                        tmp1.push_back(down);
                    }
                    if(left[0]<rows && left[0]>=0&&left[1]<cols && left[1]>=0 && board[left[0]][left[1]]==word[l]&& visited[left[0]][left[1]]==0)
                    {
//                        visited[left[0]][left[1]]=1;
                        tmp1.push_back(left);
                    }
                    if(right[0]<rows && right[0]>=0&&right[1]<cols && right[1]>=0 && board[right[0]][right[1]]==word[l]&& visited[right[0]][right[1]]==0)
                    {
//                        visited[right[0]][right[1]]=1;
                        tmp1.push_back(right);
                    }
                    if(tmp1.size()!=0)
                    {
                        visited[item[0]][item[1]]=1;
                    }
                    if(tmp.size()==0)
                    {

                        tmp = tmp1;
                        tmp1.clear();
                        l++;
                    }

                }

            }
        }

    }
           return false;
}

int cols;
int rows;
vector<vector<int>> dxy = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool dfs(vector<vector<char>>& board, vector<bool>& visit, int i, int j, string& word, int idx){
        if(board[i][j] != word[idx]) return false;
        visit[i*cols+j] = true;
        idx++;
        for(auto xy : dxy){
            int x = xy[0] + i;
            int y = xy[1] + j;
            if(x < 0 || x >= rows || y < 0 || y >= cols || visit[x*cols+y]) continue;
            else{
                if(dfs(board, visit, x, y, word, idx)) return true;
            }
        }
        visit[i*cols+j] = false;
        if(idx == word.size()) return  true;
        return false;
}

bool exist_dfs(vector<vector<char>>& board, string word) {
        if(word == "")  return false;
        rows = board.size();
        cols = board[0].size();
        vector<bool> visit(rows * cols, false);
        for(int i = 0;i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, visit, i, j, word, 0)) return true;
                }
            }
        }
        return false;
}

int main()
{
    vector<char> row1 = {'A','B','C','E'};
    vector<char> row2 = {'S','F','E','S'};
    vector<char> row3 = {'A','D','E','E'};
    vector<vector<char>> matrix = {row1,row2,row3};
    cout<<matrix.size()<<","<<matrix[0].size()<<endl;
    string s1 = "ABCESEEEFS";
    bool res = exist(matrix,s1);
    cout << "restult:"<<res << endl;


    return 0;
}
