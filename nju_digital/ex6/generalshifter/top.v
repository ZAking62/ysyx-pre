module top (
    input clk,
    input [7:0]din,
    input [2:0]op,
    output reg [7:0]dout8,
    output reg dout1
);
    reg [7:0]temp = 8'b0;
    always@(posedge clk)begin
        case(op)
            3'b000: temp <= 8'b0;
            3'b001: temp <= din;
            3'b010: temp <= {1'b0, temp[7:1]};
            3'b011: temp <= {temp[6:0], 1'b0};
            3'b100: temp <= {temp[7], temp[7:1]};
			3'b101: begin
				dout8 <= temp;
			   	dout1 <= temp[7];
			end
            3'b110: temp <= {temp[0], temp[7:1]};
            3'b111: temp <= {temp[6:0], temp[7]};
            default:temp <= temp;
        endcase
    end

endmodule
