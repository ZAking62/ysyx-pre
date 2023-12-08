module top(
	input clk,
	input en,
	input areset,
	output [6:0]h1, h2	
);
	reg clk_1s = 0;
	integer count_clk = 0;
	reg [3:0]q1, q2;
	initial begin
		q1 = 4'd0;
		q2 = 4'd0;
	end
	always@(posedge clk) begin
		if(count_clk == 24999999)begin
			count_clk <= 0;
			clk_1s <= ~clk_1s;
		end
		else count_clk <= count_clk + 1;
	end

	always@(posedge clk_1s or posedge areset) begin
		if(areset)begin
			q1 <= 4'd0;
			q2 <= 4'd0;
		end
		else begin
			if(en)begin
				if(q2 == 4'd9 && q1 == 4'd9)begin
					q2 <= 4'd0;
					q1 <= 4'd0;
				end
				else if(q2 != 4'd9 && q1 == 4'd9)begin
					q2 <= q2 + 4'd1;
					q1 <= 4'd0;
				end
				else q1 <= q1 + 4'd1;
			end
			else begin
				q2 <= q2;
				q1 <= q1;
			end
		end
	end
	bcd7seg i0(.b(q1), .h(h1));
	bcd7seg i1(.b(q2), .h(h2));

endmodule
