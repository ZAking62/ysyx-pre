#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/Vtop.h" //1 

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vtop* top;   //2

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vtop;   //3
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("dump.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();

  //4
  top->op = 0;	top->in_x = -8; top->in_y = 7;	step_and_dump_wave();
				top->in_x = -8; top->in_y = -7;	step_and_dump_wave();
				top->in_x = 3; top->in_y = 7;	step_and_dump_wave();
				top->in_x = 1; top->in_y = 3;	step_and_dump_wave();
				top->in_x = -1; top->in_y = -1;	step_and_dump_wave();

  top->op = 1;	top->in_x = -8; top->in_y = 7;	step_and_dump_wave();
				top->in_x = -8; top->in_y = -7;	step_and_dump_wave();
				top->in_x = 3; top->in_y = 7;	step_and_dump_wave();
				top->in_x = 7; top->in_y = 3;	step_and_dump_wave();
				top->in_x = -1; top->in_y = -1;	step_and_dump_wave();
				
   top->op = 2;	top->in_x = -8; top->in_y = 7;	step_and_dump_wave();
				top->in_x = 1; top->in_y = 3;	step_and_dump_wave();
				top->in_x = -1; top->in_y = -1;	step_and_dump_wave();

   top->op = 3;	top->in_x = -8; top->in_y = 7;	step_and_dump_wave();
				top->in_x = -8; top->in_y = -7;	step_and_dump_wave();
				top->in_x = 3; top->in_y = 7;	step_and_dump_wave();
				top->in_x = 1; top->in_y = 3;	step_and_dump_wave();
				top->in_x = -1; top->in_y = -1;	step_and_dump_wave();
   top->op = 4;	top->in_x = -8; top->in_y = 7;	step_and_dump_wave();
				top->in_x = -8; top->in_y = -7;	step_and_dump_wave();
				top->in_x = 3; top->in_y = 7;	step_and_dump_wave();
				top->in_x = 1; top->in_y = 3;	step_and_dump_wave();
				top->in_x = -1; top->in_y = -1;	step_and_dump_wave();
   top->op = 5;	top->in_x = -8; top->in_y = 7;	step_and_dump_wave();
				top->in_x = -8; top->in_y = -7;	step_and_dump_wave();
				top->in_x = 3; top->in_y = 7;	step_and_dump_wave();
				top->in_x = 1; top->in_y = 3;	step_and_dump_wave();
				top->in_x = -1; top->in_y = -1;	step_and_dump_wave();
   top->op = 6;	top->in_x = -8; top->in_y = 7;	step_and_dump_wave();
				top->in_x = 6; top->in_y = -7;	step_and_dump_wave();
				top->in_x = -3; top->in_y = -7;	step_and_dump_wave();
				top->in_x = 1; top->in_y = 3;	step_and_dump_wave();
				top->in_x = 1; top->in_y = 1;	step_and_dump_wave();
   top->op = 7;	top->in_x = -8; top->in_y = 7;	step_and_dump_wave();
				top->in_x = 3; top->in_y = 7;	step_and_dump_wave();
				top->in_x = 1; top->in_y = 1;	step_and_dump_wave();
				top->in_x = -1; top->in_y = -1;	step_and_dump_wave();
  sim_exit();
}
