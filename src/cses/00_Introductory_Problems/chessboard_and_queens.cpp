#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define endl "\n"

int is_valid(vector<vector<char>> &board, int r, int c)
{
  if (board[r][c] == '*')
    return 0;

  for (int i = 0; i < r; i++)
  {
    if (board[i][c] == 'q')
      return 0;
  }

  for (int i = 0; i < c; i++)
  {
    if (board[r][i] == 'q')
      return 0;
  }

  for (int i = 1; r - i >= 0 && c - i >= 0; i++)
  {
    if (board[r - i][c - i] == 'q')
      return 0;
  }

  for (int i = 1; r - i >= 0 && c + i < board.size(); i++)
  {
    if (board[r - i][c + i] == 'q')
      return 0;
  }

  return 1;
}

int cnt = 0;
void solve(vector<vector<char>> &board, int row)
{
  if (row == board.size())
  {
    cnt++;
    return;
  }

  for (int i = 0; i < board.size(); i++)
  {
    if (is_valid(board, row, i))
    {
      board[row][i] = 'q';
      solve(board, row + 1);
      board[row][i] = '.';
    }
  }
}

int main()
{
  vector<vector<char>> board;
  for (int i = 0; i < 8; i++)
  {
    vector<char> row;
    for (int j = 0; j < 8; j++)
    {
      char c;
      cin >> c;
      row.push_back(c);
    }
    board.push_back(row);
  }

  solve(board, 0);
  cout << cnt << endl;
}
