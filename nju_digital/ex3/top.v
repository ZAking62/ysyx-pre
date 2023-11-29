module top(
	input [2:0] op,
	input [3:0] in_x, in_y,
	output reg [3:0] out_s,
	output reg overflow, out_c, zero
);
	reg [3:0] t_add_y = ( 4'b1111^in_y );  
	always @(*)
	begin
		case(op)
			3'b000:
			begin
				{out_c, out_s} = in_x + in_y;
				zero = ~(| out_s);
				overflow = (in_x[3] == in_y[3]) && (out_s[3] != in_x[3]);
			end
			3'b001:
			begin
				{out_c, out_s} = in_x + t_add_y + 1'b1;
				zero = ~(| out_s);
				overflow = (in_x[3] == t_add_y[3]) && (out_s[3] != in_x[3]);
			end
			3'b010:
			begin
				out_s = ~in_x;
				zero = ~(| out_s);
				out_c = 0;
				overflow = 0;
			end
			3'b011:
			begin
				out_s = in_x & in_y;
				zero = ~(| out_s);
				out_c = 0;
				overflow = 0;
			end
			3'b100:
			begin
				out_s = in_x | in_y;
				zero = ~(| out_s);
				out_c = 0;
				overflow = 0;
			end
			3'b101:
			begin
				out_s = in_x ^ in_y;
				zero = ~(| out_s);
				out_c = 0;
				overflow = 0;
			end
			3'b110:
			begin
				if (in_x[3] == 1 && in_y[3] == 0)
					out_s = 1;
				else if (in_x[3] == 0 && in_y[3] == 1)
					out_s = 0;
				else
					out_s = in_x < in_y ? 1 : 0;
				zero = out_s == 0 ? 1 : 0;
				out_c = 0;
				overflow = 0;
			end
			default:
			begin
				if (in_x == in_y)
					out_s = 1;
				else
					out_s = 0;
				zero = out_s == 0 ? 1 : 0;
				out_c = 0;
				overflow = 0;
			end
		endcase
	end

	endmodule

