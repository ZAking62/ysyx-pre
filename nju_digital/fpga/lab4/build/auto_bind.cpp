#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->areset, BIND_RATE_SCR, BIND_DIR_IN , 1, SW0);
	nvboard_bind_pin( &top->en, BIND_RATE_SCR, BIND_DIR_IN , 1, SW1);
	nvboard_bind_pin( &top->h1, BIND_RATE_SCR, BIND_DIR_OUT, 7, SEG0G, SEG0F, SEG0E, SEG0D, SEG0C, SEG0B, SEG0A);
	nvboard_bind_pin( &top->h2, BIND_RATE_SCR, BIND_DIR_OUT, 7, SEG1G, SEG1F, SEG1E, SEG1D, SEG1C, SEG1B, SEG1A);
	nvboard_bind_pin( &top->clk, BIND_RATE_RT , BIND_DIR_IN , 1, PS2_CLK);
}
