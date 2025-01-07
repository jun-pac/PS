`timescale 1ns / 1ps

module MAC #(

    parameter integer A_BITWIDTH = 8,
    parameter integer B_BITWIDTH = A_BITWIDTH,
    parameter integer OUT_BITWIDTH = 16,
    parameter integer C_BITWIDTH = A_BITWIDTH,
    parameter integer C_EXTEN_BITWIDTH = 2*C_BITWIDTH-1
    
)
(
    
    input                                   CLK,
    input                                   EN,
    input                                   RSTn,
    input [A_BITWIDTH-1:0]                  DATA_A, 
    input [B_BITWIDTH-1:0]                  DATA_B,
    input [C_BITWIDTH-1:0]                  DATA_C,
    output reg [OUT_BITWIDTH-1:0]           MOUT,
    output reg                              DONE
    );

localparam 
    STATE_IDLE = 2'b00, 
    STATE_MULT = 2'b01, 
    STATE_Addx = 2'b10,
    STATE_Done = 2'b11;
    
reg [1:0]                       m_state;
wire [C_EXTEN_BITWIDTH-1:0] data_c_exten;
reg [14:0] mult_result; // To store 15-bit result of multiplication
reg sign_result;        // To store sign bit of the result

// data_c_exten is Extended DATA_C
// Because C is added with A*B, both of C and A*B have same fraction bits (12bit = 2^-12) and better to have same # of bits
// DATA_C's fraction is  6bit(2^-6), So modify it.
assign data_c_exten = {DATA_C[7],1'b0,DATA_C[6:0], 6'b000000};  


// sequential task: updating the state
always @( posedge CLK or negedge RSTn) begin
    //$monitor("At time %0t: m_state=%d, mult_result = %d, sign_result = %d, MOUT = %d, DATA_A=%d, DATA_B=%d, data_c_exten=%d, EN=%b, DONE=%b", $time, m_state,mult_result, sign_result, MOUT,DATA_A,DATA_B,data_c_exten,EN,DONE);

    if(!RSTn) begin
        m_state <= 2'b00;
    end
    else begin
        case(m_state)
            STATE_IDLE: begin
                if(EN) begin
                // TO DO
                    m_state <= STATE_MULT; // If EN is high and DONE != 1, then running state.
                end
            end
            STATE_MULT: begin
                // TO DO
                m_state <= STATE_Addx; // If multiply calculation done, move to add state
            end
            STATE_Addx: begin
                // TO DO
                m_state <= STATE_Done; // If add calculation done, move to done state
            end
            STATE_Done: begin
                // TO DO
                m_state <= STATE_IDLE; // move to idle state
            end
            default:;
           
        endcase
    end
end
                    
// combinational logic: determine the value of the machine's output
always @ (posedge CLK or negedge RSTn) begin
    if(!RSTn) begin
        MOUT <={OUT_BITWIDTH{1'b0}};
        DONE <= 1'b0;
    end

    // implement multiply and adder freely
    // In this module, you can modify everything except input/outputs
    // MOUT = A*B + data_c_exten
    else begin
        case(m_state)
            STATE_IDLE: begin
            // TO DO 
                DONE <= 1'b0;
            end
            
            STATE_MULT: begin
                // TO DO
                mult_result <= DATA_A[6:0] * DATA_B[6:0];
                sign_result <= DATA_A[7] ^ DATA_B[7];
            end
            
            STATE_Addx: begin
            // TO DO
                //$monitor("Add time %0t: sign_result = %b, data_c_exten[15]=%b",$time,sign_result,data_c_exten[15]);
                //MOUT <= {sign_result, mult_result} + data_c_exten; // Do add
                if (sign_result == data_c_exten[14]) begin
                    // Same sign, add magnitudes
                    MOUT[15]<=sign_result;
                    MOUT[14:0]<=mult_result[13:0] + data_c_exten[13:0];
                end 
                else begin
                    // Different signs, subtract the smaller magnitude from the larger one
                    if (mult_result > data_c_exten[13:0]) begin
                        //MOUT <= {sign_result, mult_result - data_c_exten[14:0]};
                        MOUT[15]<=sign_result;
                        MOUT[14:0]<=mult_result[13:0] - data_c_exten[13:0];
                    end 
                    else begin
                        MOUT[15] <= data_c_exten[14];
                        MOUT[14:0]<= data_c_exten[13:0] - mult_result[13:0]; // Use the sign of the larger magnitude
                    end
                end

            end 
            STATE_Done: begin
            // TO DO
                DONE <= 1'b1; // make output 'DONE' flag high.( DONE = 1)
            end
            default:;
       endcase
   end
end
endmodule
