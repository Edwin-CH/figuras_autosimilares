#include "../turtlec.h"

void koch(Turtle *, int, int);
void snowflake(Turtle *, int, int);

int main(void){
  TurtleApp *app = turtleAppCreate(800, 800, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 100.0f, 100.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 250, 0);
  turtleSetSpeed(t, 5.0f);
  // turtleForward(t, 300.0f);
  snowflake(t, 200, 3);	

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

void koch(Turtle *t, int len, int count){
	if (count == 0){
		turtleForward(t, len);
		return ;
	}
	koch(t, len / 3.0, count - 1);
	turtleLeft(t, 60.0);
	koch(t, len / 3.0, count -1);
	turtleRight(t, 120.0);
	koch(t, len / 3.0, count - 1);
	turtleLeft(t, 60.0);
	koch(t, len / 3.0, count - 1);
	turtleRight(t, 150.0);
}

void snowflake(Turtle *t, int len, int count){
	koch(t, len, count);
	turtleRight(t, 120.0); 
	koch(t, len, count);
	turtleRight(t, 120.0);
	koch(t, len, count);
}


