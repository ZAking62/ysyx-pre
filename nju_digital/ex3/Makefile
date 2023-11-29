VSRCS = $(shell find -name "*.v")
VERILATOR_FLAGS += --cc --exe
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += --build

all:
	verilator $(VERILATOR_FLAGS) $(VSRCS) sim_main.cpp
clean:
	rm -r obj_dir

