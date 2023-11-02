#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/Vtop.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

VerilatedContext* contextp = NULL;
Vtop* top = NULL;

void sim_init(){
  contextp = new VerilatedContext;
  top = new Vtop;
}

void sim_exit(){

}

int main(int argc, char** argv){

	sim_init();
	int count = 0;
	scanf("%d", &count);
	while (count--) {
	  int a = rand() & 1;
	  int b = rand() & 1;
	  top->a = a;
	  top->b = b;
	  top->eval();
	  printf("a = %d, b = %d, f = %d\n", a, b, top->f);
	  assert(top->f == (a ^ b));
	}
	sim_exit();
}

