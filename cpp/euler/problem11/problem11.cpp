#include <iostream>
#include <fstream>

void read_file(int grid[20][20], const std::string filename)
{
    std::ifstream infile(filename);
    std::string word;

    int num;
    int i = 0, j = 0;
    while(infile >> word){
        num = stoi(word);
        grid[i][j] = num;

        j++;
        if(j > 19){
            i++;
            j = 0;
        }
    }
    infile.close();
}

int main()
{
    int grid[20][20];
    read_file(grid, "numbers");

    int max = 0;

    for (int i = 3; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            int prod = grid[i][j]*grid[i-1][j]*grid[i-2][j]*grid[i-3][j];
            if (prod > max) {
                max = prod;
            }
        }
    }


    for (int i = 0; i < 17; ++i) {
        for (int j = 0; j < 20; ++j) {
            int prod = grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j];
            if (prod > max) {
                max = prod;
            }
        }
    }

    for (int i = 0; i < 20; ++i) {
        for (int j = 3; j < 20; ++j) {
            int prod = grid[i][j]*grid[i][j-1]*grid[i][j-2]*grid[i][j-3];
            if (prod > max) {
                max = prod;
            }
        }
    }
    
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 17; ++j) {
            int prod = grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
            if (prod > max) {
                max = prod;
            }
        }
    }

    for (int i = 3; i < 20; ++i) {
        for (int j = 3; j < 20; ++j) {
            int prod = grid[i][j]*grid[i-1][j-1]*grid[i-2][j-2]*grid[i-3][j-3];
            if (prod > max) {
                max = prod;
            }
        }
    }

    for (int i = 3; i < 20; ++i) {
        for (int j = 0; j < 17; ++j) {
            int prod = grid[i][j]*grid[i-1][j+1]*grid[i-2][j+2]*grid[i-3][j+3];
            if (prod > max) {
                max = prod;
            }
        }
    }

    for (int i = 0; i < 17; ++i) {
        for (int j = 3; j < 20; ++j) {
            int prod = grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
            if (prod > max) {
                max = prod;
            }
        }
    }

    for (int i = 0; i < 17; ++i) {
        for (int j = 0; j < 17; ++j) {
            int prod = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
            if (prod > max) {
                max = prod;
            }
        }
    }

    std::printf("max: %d\n", max);
    return 0;
}

