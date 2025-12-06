#include <iostream>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

// Directions
const int DX[4] = {1, -1, 0, 0};
const int DY[4] = {0, 0, 1, -1};

// Maze cell structure
struct Cell {
    bool visited = false;
    bool walls[4] = {true, true, true, true}; // right, left, down, up
};

int main() {
    int width = 40;        // number of cells horizontally
    int height = 40;       // number of cells vertically
    int cell_size = 10;    // pixels per cell in output image
    vector<vector<Cell>> maze(height, vector<Cell>(width));

    random_device rd;
    mt19937 rng(rd());

    // Recursive DFS using an explicit stack
    vector<pair<int,int>> stack;
    stack.push_back({0, 0});
    maze[0][0].visited = true;

    while (!stack.empty()) {
        auto [x, y] = stack.back();

        // Collect unvisited neighbors
        vector<int> neighbors;
        for (int d = 0; d < 4; d++) {
            int nx = x + DX[d];
            int ny = y + DY[d];
            if (nx >= 0 && nx < width && ny >= 0 && ny < height && !maze[ny][nx].visited) {
                neighbors.push_back(d);
            }
        }

        if (neighbors.empty()) {
            stack.pop_back();
            continue;
        }

        // Choose random neighbor
        int d = neighbors[rng() % neighbors.size()];
        int nx = x + DX[d];
        int ny = y + DY[d];

        // Knock down walls between current and neighbor
        maze[y][x].walls[d] = false;
        maze[ny][nx].walls[d ^ 1] = false; // opposite wall

        maze[ny][nx].visited = true;
        stack.push_back({nx, ny});
    }

    // Create output image (PPM)
    int img_w = width * cell_size;
    int img_h = height * cell_size;

    ofstream out("maze.ppm");
    out << "P3\n" << img_w << " " << img_h << "\n255\n";

    // Render maze
    for (int j = 0; j < img_h; j++) {
        for (int i = 0; i < img_w; i++) {
            int cx = i / cell_size;
            int cy = j / cell_size;

            int px = i % cell_size;
            int py = j % cell_size;

            bool is_wall = false;

            // Top wall
            if (py == 0 && maze[cy][cx].walls[3]) is_wall = true;
            // Bottom wall
            if (py == cell_size - 1 && maze[cy][cx].walls[2]) is_wall = true;
            // Left wall
            if (px == 0 && maze[cy][cx].walls[1]) is_wall = true;
            // Right wall
            if (px == cell_size - 1 && maze[cy][cx].walls[0]) is_wall = true;

            if (is_wall)
                out << "0 0 0 ";
            else
                out << "255 255 255 ";
        }
        out << "\n";
    }

    out.close();
    cout << "Maze generated → maze.ppm" << endl;
    return 0;
}
