
/*
This sketch was modified from the open-source ESS-Adapter found here: https://github.com/hallcristobal/ESS-Adapter
 */
#include "Nintendo.h"
CGamecubeController controller(2); //sets D2 on arduino to read data from controller
CGamecubeConsole console(3);       //sets D3 on arduino to write data to console
Gamecube_Report_t gcc_send;
Gamecube_Report_t gcc_last;
Gamecube_Report_t gcc;

unsigned char input_counter = 0;
char send_buffer[65];
// The following 2 arrays are the actual remap, replace them with whatever mapping you choose. By default it is my 'no dead zone' mapping on Y, and my 'slight dead zone' mapping on X.
// Please make sure there are exactly 128 numbers in each array.
uint8_t new_map_y[128] = {15, 16, 17, 18, 19, 20, 21, 22, 23, 23, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 31, 32, 32, 32, 33, 33, 33, 34, 34, 34, 35, 35, 35, 36, 36, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 55, 56, 56, 56, 57, 57, 57, 58, 58, 58, 58, 58, 59, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 65, 66, 66, 67, 67, 68, 68, 68, 69, 69, 69, 69, 69, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70};
uint8_t new_map_x[128] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 31, 32, 32, 32, 33, 33, 33, 34, 34, 34, 35, 35, 35, 36, 36, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 55, 56, 56, 56, 57, 57, 57, 58, 58, 58, 58, 58, 59, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 65, 66, 66, 67, 67, 68, 68, 68, 69, 69, 69, 69, 69, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70};
void setup() {
}

int8_t remap_x(int8_t in) {
	uint8_t tmp = abs(in);
  tmp = new_map_x[tmp];
	return in > 0 ? tmp : tmp * -1;
}

int8_t remap_y(int8_t in) {
  uint8_t tmp = abs(in);
  tmp = new_map_y[tmp];
  return in > 0 ? tmp : tmp * -1;
}

void modify_inputs() {
	int8_t ax = gcc.xAxis - 127; 
	int8_t ay = gcc.yAxis - 127;

	ax = remap_x(ax);
	ay = remap_y(ay);

	gcc.xAxis = ax + 127;
	gcc.yAxis = ay + 127;
}

void loop()
{
	noInterrupts();
	controller.read();
	gcc = controller.getReport();
	modify_inputs();
  // The following 2 if statments map analog L and R presses to digital presses. To increase or decrease sensitivity change the 100's to something else. The range is 0-255.
  if (gcc.left > 100) {
    gcc.l = 1;
  }
  if (gcc.right > 100) {
    gcc.r = 1;
  }
	console.write(gcc);
	interrupts();
}
