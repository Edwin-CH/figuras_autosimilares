#include "../turtlec.h"  
#include <math.h>

void fractalTree(Turtle *t, int length, int depth);

int main(void){
  TurtleApp *app = turtleAppCreate(800, 640, "Fractaltree");

  if(app == NULL)
    return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtlePenUp(t);
  turtleGoTo(t, 150.0f, 200.0f);
  turtlePenDown(t);

  turtleSetColor(t, 140, 240, 255);
  turtleSetSpeed(t, 5.0f);
  fractalTree(t, 100, 5);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

void fractalTree(Turtle *t, int length, int depth){
  if (depth == 0 || length < 5)
    return;

  if (depth == 1)
    turtleSetColor(t, 255, 0, 0);
  else if(depth == 2)
    turtleSetColor(t, 255, 0, 180);
  else if(depth == 3)
    turtleSetColor(t, 180, 0, 255);
  else if(depth == 4)
    turtleSetColor(t, 0, 0, 255);
  else if(depth == 5)
    turtleSetColor(t, 0, 255, 254);
  else
    turtleSetColor(t, 0, 255, 0);

  turtleForward(t, length);
  turtleLeft(t, 30);
  fractalTree(t, length * 0.8, depth - 1);
  turtleRight(t, 30);
  fractalTree(t, length * 0.7, depth - 1);
  turtleRight(t, 30);
  fractalTree(t, length * 0.6, depth - 1);

  turtlePenUp(t);

  turtleLeft(t, 30);
  turtleBackward(t, length);

  turtlePenDown(t);

}

