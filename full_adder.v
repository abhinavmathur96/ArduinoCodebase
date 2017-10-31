module full_adder(cout,s,a,b,cin);
output cout,s;
input a,b,cin;
wire w1,w2,w3;
xor x1(w1,a,b);
and a1(w2,w1,cin);
and a2(w3,a,b);
xor x2(s,w1,cin);
or o1(cout,w2,w3);
endmodule


module tb_full_adder;
wire s, cout;
reg a,b,cin;
full_adder a1(cout,s,a,b,cin);

initial begin
$monitor("time=%d, s=%b,cout=%d,a=%d,b=%d,c=%d,",$time,s,cout,a,b,cin);


#10 a=1'b0; b=1'b0;cin=1'b0;
#10 a=1'b0; b=1'b0;cin=1'b1;
#10 a=1'b0; b=1'b1;cin=1'b0;
#10 a=1'b0; b=1'b1;cin=1'b1;
#10 a=1'b1; b=1'b0;cin=1'b0;
#10 a=1'b1; b=1'b0;cin=1'b1;
#10 a=1'b1; b=1'b1;cin=1'b0;
#10 a=1'b1; b=1'b1;cin=1'b1;

end
endmodule
