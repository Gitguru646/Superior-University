#include <iostream>
using namespace std;
#define N 9


struct Node {
    int row, col;
    Node* next;
    Node(int r, int c) {
        row = r;
        col = c;
        next = NULL;
    }
};


class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void append(int r, int c) {
        Node* newNode = new Node(r, c);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void clear() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};


bool isSafe(int board[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}


bool solveSudoku(int board[N][N], Node* current) {
    if (current == NULL)
        return true;

    int row = current->row;
    int col = current->col;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board, current->next))
                return true;

            board[row][col] = 0; 
        }
    }

    return false;
}

void printBoard(int board[N][N])
 {
    cout << "Solved Sudoku:\n";
    for (int i = 0; i < N; i++)
	 {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    LinkedList emptyCells;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 0)
                emptyCells.append(i, j);

 
    if (solveSudoku(board, emptyCells.head))
        printBoard(board);
    else
        cout << "No solution exists.";

    emptyCells.clear(); 
    
    return 0;
}