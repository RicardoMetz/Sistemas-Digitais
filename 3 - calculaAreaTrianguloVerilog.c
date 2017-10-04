module area (
	input [9:0] x1,
	input [9:0] y1,
	input [9:0] x2,
	input [9:0] y2,
	input [9:0] x3,
	input [9:0] y3,
	output reg [19:0] area);

    wire signed [19:0] aux = ((x1*y2)+(y1*x3)+(x2*y3)-(y2*x3)-(x1*y3)-(x2*y1));

	always @(aux) begin
        if (aux < 0) area <= -aux;
        else         area <=  aux;
    end


    //wire [19:0] area2;
    //assign area2 = (aux < 0) ? -aux : aux;
endmodule

module testbench;

reg [9:0] x1;
reg [9:0] y1;
reg [9:0] x2;
reg [9:0] y2;
reg [9:0] x3;
reg [9:0] y3;
wire [19:0] area;

area A(x1, y1, x2, y2, x3, y3, area);

integer count;

initial begin
	#2
	count = $fscanf('h8000_0000, "%d", x1);
	count = $fscanf('h8000_0000, "%d", y1);
	count = $fscanf('h8000_0000, "%d", x2);
	count = $fscanf('h8000_0000, "%d", y2);
	count = $fscanf('h8000_0000, "%d", x3);
	count = $fscanf('h8000_0000, "%d", y3);

	#2;
	$display("%d", x1);
	$display("%d", y1);
	$display("%d", x2);
	$display("%d", y2);
	$display("%d", x3);
	$display("%d", y3);
	$display("%d", area);
	#2;

end

endmodule
