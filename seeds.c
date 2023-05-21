#include <stdio.h>
#include <unistd.h>
#include <raylib.h>
#define FPS 15
#define MAPSIZE 150
#define SCREENH 1080
#define SCREENW 1080

Color GRUVGREY = {29, 32, 33, 255};

int map[MAPSIZE][MAPSIZE] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0}
};

void populateMap(int map[MAPSIZE][MAPSIZE]){
  for (int i = 0; i < MAPSIZE; i++){
    for (int j = 0; j < MAPSIZE; j++){
      if (map[i][j] != 1 && map[i][j] != 0)
	map[i][j] = 0;
    }
  }
}

int neighborMap[MAPSIZE][MAPSIZE] = {
  {0}
  
};

void resetMap(int map[MAPSIZE][MAPSIZE]){
  for (int row = 0; row < MAPSIZE; row++){
    for (int col = 0; col < MAPSIZE; col++){
      map[row][col] = 0;
    } 
  }
}

void drawMap(int map[MAPSIZE][MAPSIZE]){
  int tileSize = SCREENH/MAPSIZE;
  for (int row = 0; row < MAPSIZE; row++){
    for (int col = 0; col < MAPSIZE; col++){
      Color color = GRUVGREY;
      if (map[row][col] == 1)
	color = RAYWHITE;
      if (map[row][col] == 2)
	color = GRAY;
      DrawRectangle((col*tileSize), (row*tileSize), tileSize-1, tileSize-1, color);
    }
  }
}

int step(int map[MAPSIZE][MAPSIZE]){
  for (int row = 1; row < MAPSIZE-1; row++){
    for (int col = 1; col < MAPSIZE-1; col++){
      int neighbors = 0;

      if (map[row-1][col-1] == 1)
	neighbors++;
      if (map[row-1][col] == 1)
	neighbors++;
      if (map[row-1][col+1] == 1)
	neighbors++;
      if (map[row][col-1] == 1)
	neighbors++;
      if (map[row][col+1] == 1)
	neighbors++;
      if (map[row+1][col-1] == 1)
	neighbors++;
      if (map[row+1][col] == 1)
	neighbors++;
      if (map[row+1][col+1] == 1)
	neighbors++;
      neighborMap[row][col] = neighbors;
    } 
  }
  
  for (int row = 0; row < MAPSIZE; row++){
    for (int col = 0; col < MAPSIZE; col++){
      if (neighborMap[row][col] == 2 && map[row][col] == 0){
	map[row][col] = 1;
      } else {
	map[row][col] = 0;
      } 
    }
  }
  resetMap(neighborMap);
}
int main(){
  populateMap(map);
  populateMap(neighborMap);
  InitWindow(SCREENW, SCREENH, "CELLULAR AUTOMATA");
  SetTargetFPS(FPS);
  while (!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);
    step(map);
    drawMap(map);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
