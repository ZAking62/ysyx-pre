module top(
    input clk,
    input[7:0] din,
    output[6:0] dout1, dout0
);
    reg [7:0]dout = din;
	reg [7:0]temp = din;
    integer i = 0;
    always@(posedge clk or din)begin
		if(din == temp)begin
          if(dout == 8'b0) dout <= din; 
          else begin
              if(i == 255) dout <= din;
              else begin
                  dout <= {dout[4]^dout[3]^dout[2]^dout[1] ,dout[7:1]};
                  i = i + 1;
              end
          end
	    end
		else begin
			dout <= din;
			temp <= din;
		end
    end
    bcd7seg i1(.b(dout[7:4]), .h(dout1));
    bcd7seg i0(.b(dout[3:0]), .h(dout0));
endmodule
