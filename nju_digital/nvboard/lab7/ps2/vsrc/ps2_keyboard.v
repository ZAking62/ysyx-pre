module ps2_keyboard(clk,clrn,ps2_clk,ps2_data,data,count_data,
                    ready,nextdata_n,overflow);
    input clk,clrn,ps2_clk,ps2_data;
    input nextdata_n;
    output [7:0] data;
	output reg [7:0]count_data;
    output reg ready;
    output reg overflow;     // fifo overflow
    // internal signal, for test
    reg [9:0] buffer;        // ps2_data bits
    reg [7:0] fifo[7:0];     // data fifo
    reg [2:0] w_ptr,r_ptr;   // fifo write and read pointers
    reg [3:0] count;  // count ps2_data bits
    // detect falling edge of ps2_clk
    reg [2:0] ps2_clk_sync;
    //记录ps2_clk的历史信息，并检测时钟的下降沿
    always @(posedge clk) begin
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
    end
    //[2]高,[1]低,下降沿
    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
        if (clrn == 1) begin // reset
            count <= 0; w_ptr <= 0; r_ptr <= 0; overflow <= 0; ready<= 0;
        end
        else begin
            if ( ready ) begin // read to output next data
                //确认读取完毕后将nextdata_n置零一个周期.
                //这时，键盘控制器模块收到确认读取完毕的信号，将读指针前移，准备提供下一数据。
                if(nextdata_n == 1'b0) //read next data
                begin
                    r_ptr <= r_ptr + 3'b1; //读指针移动，56行读出
                    if(w_ptr==(r_ptr+1'b1)) //empty，空队，不能读
                        ready <= 1'b0;
                end
            end
            if (sampling) begin
              //十一位，取buffer入队
              if (count == 4'd10) begin
                if ((buffer[0] == 0) &&  // start bit = 0
                    (ps2_data)       &&  // stop bit = 1
                    (^buffer[9:1])) begin      // odd  parity奇校验
                    fifo[w_ptr] <= buffer[8:1];  // kbd scan code数据入队
					if(buffer[8:1] == 8'hf0) count_data = count_data + 1;
                    w_ptr <= w_ptr+3'b1;  //写指针移动
                    ready <= 1'b1;    //可以读了
                    overflow <= overflow | (r_ptr == (w_ptr + 3'b1)); //计算是否溢出
                end
                count <= 0;     // for next
              end
              //没到十一位，往buffer里写 
              else begin
                buffer[count] <= ps2_data;  // store ps2_data
                count <= count + 3'b1;
              end
            end
        end
    end
    assign data = fifo[r_ptr]; //always set output data

endmodule
