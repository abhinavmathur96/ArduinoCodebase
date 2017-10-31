module micro(cout,result,ctrl);
output reg cout;
output reg [3:0]result;
input [8:0]ctrl;
reg [3:0]r1,r2,r3,r4;
reg [1:0]s1,s2,d;
reg [2:0]op;
reg [3:0]var1;
reg [3:0]var2;
reg [3:0]var3;
reg [3:0]temp1;
reg [3:0]temp2;
reg [3:0]temp3;


initial begin // this is the initialzed data in these registers
r1=4'b1100;
r2=4'b0101;
r3=4'b0110;
r4=4'b0011;

end

always@(ctrl) begin
s1=ctrl[8:7];
s2=ctrl[6:5];
d=ctrl[4:3];
op=ctrl[2:0];

case(s1) 
2'b00: temp1=r1;
2'b01: temp1=r2;
2'b10: temp1=r3;
2'b11: temp1=r4;
endcase

case(s2)
2'b00: temp2=r1;
2'b01: temp2=r2;
2'b10: temp2=r3;
2'b11: temp2=r4;
endcase

case(op)
3'b101:begin 
{cout,temp3}=temp1+temp2;
result=temp3;
end
3'b010:begin
temp3=temp2-temp1;
result=temp3;
end
3'b111: begin 
{cout,temp3}=temp2+1;
result=temp3;

//default: $display("wrong operation code");
end
endcase
end
endmodule
 
module tb_micro;
reg [8:0]ctrl;
wire cout;
wire [3:0]result;
micro  m1(cout,result,ctrl);
initial begin
$monitor("%t ctrl=%b result=%b carry=%b",$time,ctrl,result,cout);
#10 ctrl=9'b1000_01101;
#10 ctrl=9'b0011_10111;
#10 ctrl =9'b1111_10000;

end

endmodule
