module top(
    input [7:0]din,
    input [2:0]shamt,
    input al, lr,
    output [7:0]dout
);
    reg [7:0]temp;
    initial temp = din;
    always @(din or shamt or al or lr)begin
        case(lr)
            1'b0:begin
                case(al)
                    //算数右移
                    1'b0:begin
                        temp = shamt[0] ? {din[7], temp[7:1]} : temp;
                        temp = shamt[1] ? {{2{din[7]}}, temp[7:2]} : temp;
                        temp = shamt[2] ? {{4{din[7]}}, temp[7:4]} : temp;

                    end
                    //逻辑右移
                    default:begin
                        temp = shamt[0] ? {1'b0, temp[7:1]} : temp;
                        temp = shamt[1] ? {2'b00, temp[7:2]} : temp;
                        temp = shamt[2] ? {4'b0000, temp[7:4]} : temp;
                    end
                endcase
            end
            //左移
            default:begin
                temp = shamt[0] ? {temp[6:0], 1'b0} : temp;
                temp = shamt[1] ? {temp[5:0], 2'b00} : temp;
                temp = shamt[2] ? {temp[3:0], 4'b0000} : temp;
            end
        endcase
    end
    assign dout = temp;
endmodule
