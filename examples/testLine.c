#include "../turtlec.h"
#include <math.h>

void splitline(Turtle *t, int length, int count);
void koch(Turtle *t, int length, int count);
void snowFlakes(Turtle *t, int length, int count);

void drawTriangle(Turtle *t, int length);
void sierpinski(Turtle *t, int length, int depth);

void fractalTree(Turtle *t, int length, int depth);
void levy(Turtle *t, int length, int depth);

int main(void){
  TurtleApp *app = turtleAppCreate(800, 640, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 150.0f, 200.0f);
  turtlePenDown(t);

  turtleSetColor(t, 140, 240, 255);
  turtleSetSpeed(t, 5.0f);
  //turtleForward(t, 300.0f);
  //splitline(t, 150, 1);
  //snowFlakes(t, 200, 3);
  //sierpinski(t, 100, 1);
  //fractalTree(t, 100, 9);
  levy(t, 150, 7);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

void splitline (Turtle *t, int length, int count){
  if (count == 0) {
    turtleForward(t, length);
    return;
  }
  splitline(t, length / 2.0, count - 1);
  turtleLeft(t, 60.0);
  splitline(t, length / 2.0, count - 1);
  turtleRight(t, 60.0);
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

void drawTriangle(Turtle *t, int length) {
    for (int i = 0; i < 3; i++) {
        turtleForward(t, length);
        turtleLeft(t, 120.0);
    }
}

void sierpinski(Turtle *t, int length, int depth) {
    if (depth == 0) {
        drawTriangle(t, length);
        return;
    }
    length /= 2.0;

    sierpinski(t, length, depth - 1);

    turtleForward(t, length);
    sierpinski(t, length, depth - 1);

    turtleLeft(t, 60.0);
    turtleForward(t, length);
    turtleRight(t, 60.0);
    sierpinski(t, length, depth - 1);

    turtleRight(t, 60.0);
    turtleBackward(t, length);
    turtleLeft(t, 60.0);
    sierpinski(t, length, depth - 1);
    turtleRight(t, 120.0);
    turtleForward(t, length);
}

void fractalTree(Turtle *t, int length, int depth){
  if (depth == 0 || length < 5)
    return;
  if (depth > 5)
    turtleSetColor(t, 120, 70, 20);
  else
    turtleSetColor(t, 0, 200, 0);
  turtleForward(t, length);
  turtleLeft(t, 20);
  fractalTree(t, length * 0.8, depth - 1);
  turtleRight(t, 40);
  fractalTree(t, length * 0.8, depth - 1);
  turtleLeft(t, 20);
  turtleBackward(t, length);
}

void levy(Turtle *t, int length, int depth){
  if (depth == 0){
    turtleForward(t, length);
    return;
  }

  length /= sqrt(2);
  turtleLeft(t, 45);
  levy(t, length, depth - 1);
  turtleRight(t, 90);
  levy(t, length, depth - 1);
  turtleLeft(t, 45);
}

