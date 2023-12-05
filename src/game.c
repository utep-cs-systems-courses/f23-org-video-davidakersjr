#include "game.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw.h"
#include "buzzer.h"
//player will be 16 pixels wide (x) 
//move at 0 = left, 1 == right, 2 == none
void gameMain(int sec, int move, int shoot){
  
  
  static int enemyCordsX = 16;
  static int enemyCordsY = 16;
  static int playerX = 64;
  static int enemyDir = 0; //left is 0 right is 1
  
  if (enemyCordsY <= 144){

    if (move == 0){
      playerX -= 16;
      gamePlayer(playerX);
    }
    if (move == 1){
      playerX += 16;
      gamePlayer(playerX);
    }
    gamePlayer(playerX);
    if (shoot){
      if (playerX == enemyCordsX){
	//TEMP THROW GAME WIN
	clearScreen(COLOR_BLUE);
	enemyCordsY = 144;
	
      }
    }
    
    if (sec == 249){
      
      if (enemyCordsX == 112){
	enemyDir = 0;
	enemyCordsY += 16;
      }
      
      if (enemyCordsY == 16){
	enemyDir = 1;
	enemyCordsY += 16;
      }
      if(enemyDir){
	enemyCordsX += 16;
      }
      else{
	enemyCordsY -=16;
      }
           
    }
    gameEnemy(enemyCordsX,enemyCordsY);
  }
  
}
void gamePlayer(int x){
  if (x <= 112 && x >= 0) { //Screen size - player size
    
    drawFillBox(x, 144, COLOR_GREEN, 16);
  }

}
void gameEnemy(int x, int y){
  if(x<=112||x<=16) {
    
    drawFillBox(x,y,COLOR_RED,16);
  }
}
void gameGraphics(){
  clearScreen(COLOR_BLACK);
}
