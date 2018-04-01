#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>

#define MAX_ROWS 500000
#define MAX_COLUMNS 100

// Forward declarations
int matrixElementsSum(std::vector<std::vector<int>> matrix);
int matrixElementsSum2(std::vector<std::vector<int>> m);

// Main function
int main(int args, char **arg){

   srand(time(NULL));
   
	std::vector<std::vector<int>> matrix;

   for(int i = 0; i < MAX_ROWS; i++){
      int* row = new int[MAX_COLUMNS];
      for(int j = 0; j < MAX_COLUMNS; j++){
         row[j] = rand() % 10;
      }
      std::vector<int> tmp(row, row + sizeof(row) / sizeof(row[0]));
      matrix.push_back(tmp);
   }
   
   /*for(auto row : matrix){
      for(auto i : row){
         std::cout << i << " ";
      }
      std::cout << '\n';
   }*/
   
   // Measurement
   std::chrono::duration<double, std::milli> d;
   for(int i = 0; i < 20; i++){
      std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
      matrixElementsSum(matrix);
      std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
   
      d += std::chrono::duration<double, std::milli>(t2 - t1);
   }
   std::cout << d.count() / 20 ;
   
   std::cout << '\n';
   
   for(int i = 0; i < 20; i++){
      std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
      matrixElementsSum2(matrix);
      std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
   
      d += std::chrono::duration<double, std::milli>(t2 - t1);
   }
   std::cout << d.count() / 20 ;
   
   return 0;
}

// Imnplement function here
int matrixElementsSum(std::vector<std::vector<int>> matrix) {
    std::vector<bool> unsuitable(matrix.size(), false);
    int cost = 0;
    
    // Iterate trough levels
    for(auto row : matrix){
        // Iterate through columns
        for(int i = 0; i < row.size(); i++){
            if(row[i] == 0){
                unsuitable[i] = true;
            }
            if(!unsuitable[i]){
                cost += row[i];
            }
        }
    }
    return cost;
}

int matrixElementsSum2(std::vector<std::vector<int>> m) {
    int r = 0;
    for (int j=0; j<m[0].size(); j++) for (int i=0;i<m.size();i++) {
        if (m[i][j]==0) break;
        r += m[i][j];
    }
    return r;
}
