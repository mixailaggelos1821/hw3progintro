#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIMENSION 10000
#define MAX_MOVES 4

// κουτι creation
typedef struct {
    int x;
    int y;
} Cell;

// ελεγχος για τα κουτια (αν μπρουμε να κινηθουμαι)
bool isSafe(int x, int y, int room[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    return (x >= 0 && x < dimension && y >= 0 && y < dimension && room[x][y] == 0);
}

void printPath(Cell path[], int pathLength) {
    if (pathLength <= 0)
        return;
    printPath(path, pathLength - 1);
    printf("%c", path[pathLength - 1].direction);
}

// γρηγορο pathfind
bool findPath(int room[MAX_DIMENSION][MAX_DIMENSION], int dimension, int startX, int startY, int targetX, int targetY) {
    // Define the directions Zoomba can move: Up, Down, Left, Right
    int moveX[MAX_MOVES] = {0, 0, -1, 1};
    int moveY[MAX_MOVES] = {1, -1, 0, 0};
    char moves[MAX_MOVES] = {'U', 'D', 'L', 'R'};
    
    // F για καποια cells
    bool visited[MAX_DIMENSION][MAX_DIMENSION];
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            visited[i][j] = false;
        }
    }

    // store + explore bits
    Cell queue[MAX_DIMENSION * MAX_DIMENSION];
    int front = 0, rear = 0;
    queue[rear++] = (Cell){startX, startY};

    // Loop για ολά
    while (front < rear) {
        Cell current = queue[front++];
        int currentX = current.x;
        int currentY = current.y;

        //τελική απαντηση για το path
        if (currentX == targetX && currentY == targetY) {
            int pathLength = 0;
            Cell path[MAX_DIMENSION * MAX_DIMENSION];
            while (currentX != startX || currentY != startY) {
                for (int j = 0; j < MAX_MOVES; ++j) {
                    int nextX = currentX + moveX[j];
                    int nextY = currentY + moveY[j];
                    if (isSafe(nextX, nextY, room, dimension) && visited[nextX][nextY]) {
                        path[pathLength++] = (Cell){nextX, nextY, moves[j]};
                        currentX = nextX;
                        currentY = nextY;
                        break;
                    }
                }
            }
            // γρηγορο Pathfind
            printPath(path, pathLength);
            printf("\n");
            return true;
        }

        // scanning
        for (int i = 0; i < MAX_MOVES; ++i) {
            int nextX = currentX + moveX[i];
            int nextY = currentY + moveY[i];
            if (isSafe(nextX, nextY, room, dimension) && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                queue[rear++] = (Cell){nextX, nextY};
            }
        }
    }

    // αν δεν γινεται
    printf("0\n");
    return false;
}

int main() {
    int dimension, startX, startY, targetX, targetY;
    int room[MAX_DIMENSION][MAX_DIMENSION];

   
    scanf("%d %d %d %d %d", &dimension, &startX, &startY, &targetX, &targetY);

    // scanning
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            scanf("%d", &room[i][j]);
        }
    }

    
    findPath(room, dimension, startX, startY, targetX, targetY);

    return 0;
}
