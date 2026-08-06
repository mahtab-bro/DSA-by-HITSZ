3248: Snake in Matrix
📖 The Question (As stated on LeetCode)
There is a snake in an n x n matrix grid and can move in four possible directions. Each cell in the grid is identified by the position: grid[i][j] = (i * n) + j.

The snake starts at cell 0 and follows a sequence of commands.

You are given an integer n representing the size of the grid and an array of strings commands where each command[i] is either "UP", "RIGHT", "DOWN", or "LEFT". It's guaranteed that the snake will remain within the grid boundaries throughout its movement.

Return the position of the final cell where the snake ends up after executing commands.

  -------------------------------------------------------------------------------------------------------------------------------

class Solution {                                // LeetCode requires Solution class
public:                                         // Make function accessible outside class

    int finalPositionOfSnake(int n, vector<string>& commands) {
        // n = grid size, commands = list of moves, &: pass by reference (avoid copy)

        int pos = 0;                            // Snake starts at cell 0

        for (string cmd : commands) {           // Loop through each command

            if (cmd == "RIGHT") {               // Check if command is RIGHT
                pos = pos + 1;                  // In row-major, right = +1
            } else if (cmd == "LEFT") {         // Check if command is LEFT
                pos = pos - 1;                  // Left = -1 in row-major
            } else if (cmd == "DOWN") {         // Check if command is DOWN
                pos = pos + n;                  // Down = +n (jump to next row)
            } else if (cmd == "UP") {           // Check if command is UP
                pos = pos - n;                  // Up = -n (jump to previous row)
            }
        }

        return pos;                             // Return final cell position
    }
};
