#include "lcdutils.h"

#include "lcddraw.h"

#include "draw.h"

void drawBox(int x, int y, char color, int size){
  //This makes a square!!
 
  
  for(int i = -size; i<=size;i++){
    
    drawPixel(x-size,y+i,color);
    drawPixel(x+size,y+i,color);
    drawPixel(x+i,y-size,color);
    drawPixel(x+i,y+size,color);
  //drawPixel (col, row, color)

  }
}

void drawFillBox(int x, int y, u_int color, int size){

  
  for (int i = -size;i<= size;i++){
    for (int j = -size;j <= size;j++){
      drawPixel(x+i,y+j,color);
    }
  }

  

}



