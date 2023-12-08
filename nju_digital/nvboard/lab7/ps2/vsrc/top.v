module top(clk, reset, ps2_clk, ps2_data, seg0, seg1, seg2, seg3, seg4, seg5);
  input clk, reset, ps2_clk, ps2_data;
  output [6:0]seg0, seg1, seg2, seg3, seg4, seg5;
  reg overflow, ready;
  reg nextdata_n;

  reg [7:0]data, kbd_data, ascii_data, count_data;

  //读数据
  always@(posedge ps2_clk)begin
    if(ready)begin
		if(data == 8'hf0) kbd_data <= 0;
		else begin
		  kbd_data <= data;
		  nextdata_n <= 0; 
		end
    end
	else begin
	  nextdata_n <= 1; 
    end
  end

  //写数据
  ps2_keyboard p0(
    .clk(clk), 
    .clrn(reset), 
    .ps2_clk(ps2_clk), 
    .ps2_data(ps2_data),
    .data(data),
    .ready(ready),
    .nextdata_n(nextdata_n),
    .overflow(overflow),
	.count_data(count_data)
  );
  //toascii
  toascii to(.in(kbd_data), .out(ascii_data));
  //键码
  bcd7seg i0(.b(kbd_data[3:0]), .h(seg0));
  bcd7seg i1(.b(kbd_data[7:4]), .h(seg1));
  //对应的ASCII码
  bcd7seg i2(.b(ascii_data[3:0]), .h(seg2));
  bcd7seg i3(.b(ascii_data[7:4]), .h(seg3));
  //按键的总次数
  bcd7seg i4(.b(count_data[3:0]), .h(seg4));
  bcd7seg i5(.b(count_data[7:4]), .h(seg5));
endmodule

