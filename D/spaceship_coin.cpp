// You’ll be given a grid as below:
    // 0 1 0 2 0
    // 0 2 2 2 1
    // 0 2 1 1 1
    // 1 0 1 0 0
    // 0 0 1 2 2
    // 1 1 0 0 1
//     x x S x x
//    In the grid above,
//   1: This cell has a coin.
//   2: This cell has an enemy.
//   0: It contains nothing.
//   The highlighted(yellow) zone is the control zone. S is a spaceship that we need to 
//   control so that we can get maximum coins.
//   Now, S’s initial position will be at the center and we can only move it right or left by one 
//   cell or do not move.
//   At each time, the non-highlighted part of the grid will move down by one unit.
//   We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the 
//   control zone will be killed.
//   If we use a bomb at the very beginning, the grid will look like this:
    // 0 1 0 2 0
    // 0 0 0 0 1
    // 0 0 1 1 1
    // 1 0 1 0 0
    // 0 0 1 0 0
    // 1 1 0 0 1
//     x x S x x
//   As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
//   For example,
//   At the very first instance, if we want to collect a coin we should move left( coins=1). This is 
//   because when the grid comes down by 1 unit we have a coin on the second position and by moving left we 
//   can collect that coin. Next, we should move right to collect another coin( coins=2).
//   After this, remain at the same position( coins=4).
//   This is the current situation after collecting 4 coins.
//     0 1 0 2 0 
    // 0 1 0 0 0
//     0 2 2 2 1 -->after using 0 0 0 0 1
//     x x S x x -->bomb x x S x x
//    Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. 
//    So maximum coins=5.

#include <iostream>
#include <climits> // For INT_MIN

using namespace std;

int ans = INT_MIN; // This global variable will store our final answer

void getMaxCoins(int board[][5], int isRowSafe, int cur_row, int cur_col, bool bombUsed, int coins)
{
    if (cur_row < 0 || cur_col >= 5 || cur_col < 0)
    {
        ans = max(ans, coins);
        return;
    }

    // If cell is 1 or 0
    if (board[cur_row][cur_col] == 1 || board[cur_row][cur_col] == 0)
    {
        int new_coins = coins;
        if (board[cur_row][cur_col] == 1)
        {
            new_coins++;
        }
        if (bombUsed)
        {
            isRowSafe--;
        }
        // Recursively explore neighboring cells
        getMaxCoins(board, isRowSafe, cur_row - 1, cur_col, bombUsed, new_coins);
        getMaxCoins(board, isRowSafe, cur_row - 1, cur_col + 1, bombUsed, new_coins);
        getMaxCoins(board, isRowSafe, cur_row - 1, cur_col - 1, bombUsed, new_coins);
    }
    else if (board[cur_row][cur_col] == 2)
    { // If cell contains bomb (2)
        if (bombUsed && isRowSafe <= 0)
        {
            ans = max(ans, coins);
            return;
        }
        else if (bombUsed && isRowSafe > 0)
        {
            isRowSafe--;
            // Continue searching recursively with the updated isRowSafe
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col, bombUsed, coins);
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col + 1, bombUsed, coins);
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col - 1, bombUsed, coins);
        }
        else
        {
            bombUsed = true;
            isRowSafe = 4;
            // Use bomb and continue recursively
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col, bombUsed, coins);
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col + 1, bombUsed, coins);
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col - 1, bombUsed, coins);
        }
    }
}

int main()
{
    int rows;
    cin >> rows;

    int board[rows][5];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }
    }

    int isRowSafe = 0;

    getMaxCoins(board, isRowSafe, rows - 1, 1, false, 0);
    getMaxCoins(board, isRowSafe, rows - 1, 2, false, 0);
    getMaxCoins(board, isRowSafe, rows - 1, 3, false, 0);
    cout << "Max_coins : " << ans << endl;

    return 0;
}
