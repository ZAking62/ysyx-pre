#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->clk, BIND_RATE_SCR, BIND_DIR_IN , 1, BTNC);
	nvboard_bind_pin( &top->in, BIND_RATE_SCR, BIND_DIR_IN , 1, SW1);
	nvboard_bind_pin( &top->reset, BIND_RATE_SCR, BIND_DIR_IN , 1, SW0);
	nvboard_bind_pin( &top->out, BIND_RATE_SCR, BIND_DIR_OUT, 1, LD0);
}
