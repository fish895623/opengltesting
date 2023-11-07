#ifdef WIN32
#elif __APPLE__
#elif __linux__
#include <GL/freeglut.h>
#include <spdlog/spdlog.h>
#endif

void init();
void display();
void drawPoints();
void keyboard(unsigned char key, int x, int y);

void drawPoints() {
  spdlog::info("drawPoints");
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(-0.5, 0.0);
  glVertex2f(0.5, 0.0);
  glVertex2f(0.0, 1.0);
  glEnd();
  glFlush();
}

void keyboard(unsigned char key, int x, int y) {
  spdlog::info("keyboard: {}", key);
  switch (key) {
    case 'q':
    case 'Q':
      exit(EXIT_SUCCESS);
      break;
    case 'r':
    case 'R':
      glClearColor(1.0, 0.0, 0.0, 1.0);
      break;
  }
  glutPostRedisplay();
}
void function_keyboard(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_F11: {
      glutFullScreen();
    } break;
  }
}

int main(int argc, char** argv) {
  int mode = GLUT_RGB | GLUT_SINGLE;
  glutInit(&argc, argv);
  glutInitDisplayMode(mode);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(400, 400);
  glutCreateWindow("OpenGL");
  glutSetWindowTitle("");
  glutDisplayFunc(drawPoints);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(function_keyboard);
  glutMainLoop();

  return 1;
}
