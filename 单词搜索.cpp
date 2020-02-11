#include<iostream>
#include<vector> 
using namespace std;

bool backtrack(vector<vector<char>>& board,string word,int wordIndex,int x,int y)
{
	if(board[x][y]!=word[wordIndex])  //当前字母不相等，直接返回 
		return false;
	if(word.size() - 1 == wordIndex) //如果最后一个字母也相等，则找到 
		return true;
	char temp = board[x][y];
	board[x][y] = 0;
	wordIndex++;
	if((x > 0 && backtrack(board, word, wordIndex, x - 1, y)) // 往左走
        || (y > 0 && backtrack(board, word, wordIndex, x, y - 1)) // 往上走
        || (x < board.size() - 1 && backtrack(board, word, wordIndex, x + 1, y)) // 往右走
        || (y < board[0].size() - 1 && backtrack(board, word, wordIndex, x, y + 1))){ // 往下走
            return  true; // 其中一条能走通，就算成功
        }
    board[x][y] = temp;
	return false; 
}
bool exist(vector<vector<char>>& board,string word)
{
	for(int i = 0;i<board.size();++i)
	{
		for(int j = 0;j<board[0].size();++j)
		{
			if(backtrack(board,word,0,i,j))
				return true;
		}
	}
	return false;
}
int main()
{
	
	return 0;
 } 
