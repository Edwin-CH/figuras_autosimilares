#include "../turtlec.h"
#include <math.h>

void levy(Turtle *t, int length, int depth);

int main(void){
  TurtleApp *app = turtleAppCreate(800, 640, "Levy");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 150.0f, 200.0f);
  turtlePenDown(t);

  turtleSetColor(t, 140, 240, 255);
  turtleSetSpeed(t, 5.0f);
  levy(t, 150, 7);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

void levy(Turtle *t, int length, int depth){
  if (depth == 0){
    turtleForward(t, length);
    return;
  }

  if (depth == 1)
    turtleSetColor(t, 255, 0, 0);
  else if(depth == 2)
    turtleSetColor(t, 255, 0, 180);
  else if(depth == 3)
    turtleSetColor(t, 180, 0, 255);
  else if(depth == 4)
    turtleSetColor(t, 0, 0, 255);
  else if(depth == 5)
    turtleSetColor(t, 0, 255, 255);
  else
    turtleSetColor(t, 0, 255, 0);

  length /= sqrt(2);
  turtleLeft(t, 45);
  levy(t, length, depth - 1);
  turtleRight(t, 90);
  levy(t, length, depth - 1);
  turtleLeft(t, 45);
}
