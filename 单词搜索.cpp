#include<iostream>
#include<vector> 
using namespace std;

bool backtrack(vector<vector<char>>& board,string word,int wordIndex,int x,int y)
{
	if(board[x][y]!=word[wordIndex])  //��ǰ��ĸ����ȣ�ֱ�ӷ��� 
		return false;
	if(word.size() - 1 == wordIndex) //������һ����ĸҲ��ȣ����ҵ� 
		return true;
	char temp = board[x][y];
	board[x][y] = 0;
	wordIndex++;
	if((x > 0 && backtrack(board, word, wordIndex, x - 1, y)) // ������
        || (y > 0 && backtrack(board, word, wordIndex, x, y - 1)) // ������
        || (x < board.size() - 1 && backtrack(board, word, wordIndex, x + 1, y)) // ������
        || (y < board[0].size() - 1 && backtrack(board, word, wordIndex, x, y + 1))){ // ������
            return  true; // ����һ������ͨ������ɹ�
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
