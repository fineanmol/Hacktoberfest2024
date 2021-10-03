// Simple 4-bit I/O RAM implementation

module RAM(clk,we,addr,in,q);

    input clk, we;
    input [4:0] addr;
    input [3:0] in;

    output [3:0] q;
    reg [3:0] ram[31:0];
    reg [3:0] q;

    always @(clk)
    begin
        if (we)
            ram[addr] <= in;
        else
            q <= ram[addr];
    end

endmodule

module stimulus;

    reg we, clk;
    reg [4:0] addr;
    reg [3:0] in;
    wire [3:0] out;

    RAM rm(clk,we,addr,in,out);
    
    initial 
    begin
        clk = 0;
        we = 0;
        in = 0;
        #10 we=1'b1;

        #10 addr=5'b00001;in=4'b0001;
        $display("address = %b, input = %b",addr,in);
        #10 addr=5'b00010;in=4'b0010;
        $display("address = %b, input = %b",addr,in);

        #10 addr=5'b00011;in=4'b0011;
        $display("address = %b, input = %b",addr,in);

        #10 addr=5'b00100;in=4'b0100;
        $display("address = %b, input = %b",addr,in);

        #10 addr=5'b00101;in=4'b0101;
        $display("address = %b, input = %b",addr,in);

        #10 addr=5'bxxxxx;in=4'bxxxx;
        $display("address = %b, input = %b",addr,in);

        #10 we=1'b0;

        #10 addr=5'b00001;
        $display("address = %b",addr);

        #10 addr=5'b00010;
        $display("address = %b",addr);

        #10 addr=5'b00011;
        $display("address = %b",addr);

        #10 addr=5'b00100;
        $display("address = %b",addr);

        #10 addr=5'b00101;
        $display("address = %b",addr);
    end
    always #10 clk = ~clk;
    initial #150 $finish;
endmodule
