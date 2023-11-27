module encode83(x,en,y,s,h);
  input  [7:0] x;
  input  en;
  output reg [3:0]y;
  output reg s;
  output [6:0]h;
  integer i;
  always @(x or en) begin
    if (en) begin
      y = 0;
	  s = 0;
      for( i = 0; i <= 7; i = i+1)
          if(x[i] == 1)  y = i[3:0];
	  if (y != 4'b0)
		  s = 1;
    end
	else begin
	  y = 0;
	  s = 0;
	end
  end
  bcd7seg seg0(.b(y), .h(h));
  endmodule




