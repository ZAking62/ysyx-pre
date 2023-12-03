module top(
    input clk,
    input we,
    input [3:0]addr,
    input [7:0]din,
    output [7:0]out
);
    reg [7:0]ram[15:0];
    initial begin
        $readmemh("./mem1.txt", ram, 0, 15);
    end

    always@(posedge clk)begin
        if(we)
            mem[addr] <= din;
    end    
    assign out = ram[addr];

endmodule
