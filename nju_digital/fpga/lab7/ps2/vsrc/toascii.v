module toascii(
  input [7:0]in,
  output [7:0]out
);
  reg [7:0]ram[255:0];
  integer i;
  initial begin
    for(i = 0; i < 256; i = i + 1) begin
		  ram[i] = 0;
		end
    $readmemh("./vsrc/memfile.txt", ram);
  end
  assign out = ram[in];
endmodule


