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

  top->din = 0b10011001;
  top->lr = 0; top->al = 0;
  top->shamt = 0b001;  step_and_dump_wave(); //11001100
  top->shamt = 0b100;  step_and_dump_wave();//11111100
  top->lr = 0; top->al = 1;
  top->shamt = 0b011; step_and_dump_wave();
  top->shamt = 0b001; step_and_dump_wave();
  top->lr = 1; 
  top->shamt = 0b011; step_and_dump_wave();
  top->shamt = 0b001; step_and_dump_wave(); 




  sim_exit();
}
