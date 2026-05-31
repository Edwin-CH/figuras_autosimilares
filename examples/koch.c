#include "../turtlec.h"  
#include <math.h>

void koch(Turtle *t, int length, int count);
void snowFlakes(Turtle *t, int length, int count);

int main(void){
  TurtleApp *app = turtleAppCreate(800, 640, "Koch_Snowflakes");

  if(app == NULL)
    return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtlePenUp(t);
  turtleGoTo(t, 150.0f, 200.0f);
  turtlePenDown(t);

  turtleSetColor(t, 140, 240, 255);
  turtleSetSpeed(t, 5.0f);
  //koch(t, 150, 4);
  snowFlakes(t, 200, 3);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

void koch(Turtle *t, int length, int count){
  if (count == 0){
    turtleForward(t, length);
    return;
  }
  length /= 4.0;
  koch(t, length, count - 1);
  turtleLeft(t, 60.0);
  koch(t, length, count - 1);
  turtleRight(t, 120.0);
  koch(t, length, count - 1);
  turtleLeft(t, 60.0);
  koch(t, length, count - 1);
}

void snowFlakes(Turtle *t, int length, int count){
  for (int i = 0; i < 3; i++){
    koch(t, length, count);
    turtleRight(t, 120.0);
  }
}

