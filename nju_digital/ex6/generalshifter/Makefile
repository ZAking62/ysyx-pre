VSRCS = $(shell find -name "*.v")
VERILATOR_FLAGS += --cc --exe
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += --build
VERILATOR_FLAGS += --top-module top

all:
	verilator $(VERILATOR_FLAGS) $(VSRCS) sim_main.cpp
	./obj_dir/Vtop
clean:
	rm -rf obj_dir
	rm -f dump.vcd

