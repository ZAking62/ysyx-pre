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

void single_cycle() {
  top->clk = 0; step_and_dump_wave();
  top->clk = 1; step_and_dump_wave();
}


int main() {
  sim_init();

  //4
  top->din = 0b11000110;
  top->op = 0b000; 
  single_cycle(); //00000000
  top->op = 0b001;
  single_cycle(); //11000110
  top->op = 0b010;
  single_cycle(); //01100011
  single_cycle(); //00110001
  top->op = 0b011;
  single_cycle(); //01100010
  single_cycle(); //11000100
  top->op = 0b100;
  single_cycle(); //11100010
  top->op = 0b101;
  single_cycle(); 
  top->op = 0b110;
  single_cycle(); //01110001
  top->op = 0b111; 
  single_cycle(); //11100010
  single_cycle(); //11000101
  top->op = 0b101;
  single_cycle();



  sim_exit();
}
