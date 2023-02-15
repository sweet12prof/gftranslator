;AES KERNEL STARTS HERE
lbi $1 56                   ;reset $1 to start of expansion keys 
lbi $2 232                  ;$2 now points to starting address of Plaintext
;lbi $sp 508                ;$3 as stack pointer

lbi $9  01
lbi $8  -4
and_s $sp $0 
setsrtype 2
sr $sp $9
sr $sp $8


;get aes plaintext
ld_s $4 0($2)              ;$4 = MEM[0+$2]
ld_s $5 1($2)              ;$5 = MEM[4+$2]
ld_s $6 2($2)              ;$6 = MEM[8+$2]
ld_s $7 3($2)              ;$7 = MEM[12+$2]

;perform initial addRoundKey
ld_s $8  0($1)              ;get first word of first Roundkey
ld_s $9  1($1)              ;get 2ndword
ld_s $10 2($1)              ; get 3 word
ld_s $11 3($1)              ;get word 4

addi $1 16                  ;increment keyPointer to nextRound
xor_s $4 $8                 ;perform addRoundKey(Initial)                  
xor_s $5 $9                 ;perform addRoundKey(Initial)  
xor_s $6 $10                ;perform addRoundKey(Initial)
xor_s $7 $11                ;perform addRoundKey(Initial)


;set iteration count
lbi $8 0                    ;reg8 holds iterationCount
Loop: setfx 27              ;setfx to irreducible polynomial
        dupi_s $9 01        ;$9 to hold operandB of division 
        div $4 $9           ;perform division on rows(inversion) 
        div $5 $9           ;perform division on rows(inversion) 
        div $6 $9           ;perform division on rows(inversion)     
        div $7 $9           ;perform division on rows(inversion) 

        setfx 01            ;set irreducible poly for multiply
        dupi_s $9 31        ;set operandB to Ox1F(31) 
        mul_s $4 $9         ;multiply by 0x1F mod 0x101         
        mul_S $5 $9         ;multiply by 0x1F mod 0x101
        mul_s $6 $9         ;multiply by 0x1F mod 0x101
        mul_s $7 $9         ;multiply by 0x1F mod 0x101

        dupi_s $9 99        ;set affine constant to 0x63(99)
        xor_s $4 $9         ;perform xor with 0x63         
        xor_s $5 $9         ;perform xor with 0x63
        xor_s $6 $9         ;perform xor with 0x63
        xor_s $7 $9         ;perform xor with 0x63 


        setsrtype 0         ;set shift type to aes shift rows top
        sr_s $4 $5          ;perform aes shift rows top on reg4 and reg5
        setsrtype 1         ;set shift type to aes shiftrows bottom
        sr_s $6 $7          ;perform aes shift rows bottom on reg6 and reg7

        addi  $8 1          ;increment iteration counter
        lbi   $10 9         ;load temp reg10 with immediate 9 
        xor_s $10 $8        ; if @ final round $10 = 0 else someother val
        bne $10 MixColumn   ; branch to mixcolumn if not finalRound
        J AddKey            ; Jump to addkey if we are in final Round
    
    
    MixColumn: addi $sp -32  ;reserve space on stack to preserve important registers before procedure call
    sto_s $4 0($sp)          ;pushing regs to stack                    
    sto_s $5 1($sp)          ;pushing regs to stack
    sto_s $6 2($sp)          ;pushing regs to stack
    sto_s $7 3($sp)          ;pushing regs to stack
    sto_s $8 4($sp)          ;pushing regs to stack 
    
    jal Mix1Row              ;First Call to procedure 
    sto_s $4 5($sp)          ;store first immediate word result to stack

    ld_s $4 1($sp)           ;restore procedure inputs in swapped form b4 call              
    ld_s $5 2($sp)           ;restore procedure inputs in swapped form b4 call 
    ld_s $6 3($sp)           ;restore procedure inputs in swapped form b4 call
    ld_s $7 0($sp)           ;restore procedure inputs in swapped form b4 call

    jal Mix1Row              ;second call
    sto_s $4 6($sp)          ;store second intermediate word 
   
    ld_s $4 2($sp)          ;restore procedure inputs in swapped form b4 call
    ld_s $5 3($sp)          ;restore procedure inputs in swapped form b4 call 
    ld_s $6 0($sp)          ;restore procedure inputs in swapped form b4 call
    ld_s $7 1($sp)          ;restore procedure inputs in swapped form b4 call

    jal Mix1Row             ;third call
    sto_s $4 7($sp)         ;store third intermediate word 
    
    
    ld_s $4 3($sp)          ;restore procedure inputs in swapped form b4 call          
    ld_s $5 0($sp)          ;restore procedure inputs in swapped form b4 call 
    ld_s $6 1($sp)          ;restore procedure inputs in swapped form b4 call
    ld_s $7 2($sp)          ;restore procedure inputs in swapped form b4 call
    
    jal Mix1Row             ;Final Call
    sto_s $4 8($sp)         ;store final intermediate word 

    ld_s $4 5($sp)          ;restore intermediate results back into register          
    ld_s $5 6($sp)          ;restore intermediate results back into register
    ld_s $6 7($sp)          ;restore intermediate results back into register
    ld_s $7 8($sp)          ;restore intermediate results back into register
    ld_s $8 4($sp)          ;restore iteration count
    
    addi $sp 32             ;reclaim stack space

AddKey: ld_s $9  0($1)         ;get first word of next Roundkey
        ld_s $10 1($1)         ;get 2ndword
        ld_s $11 2($1)         ;get 3 word
        ld_s $12 3($1)         ;get word 4

        xor_s $4 $9            ;perform add RoundKey           
        xor_s $5 $10           ;perform add RoundKey 
        xor_s $6 $11           ;perform add RoundKey
        xor_s $7 $12           ;perform add RoundKey
        addi  $1 16            ; point $1 to start of next key 
    

        lbi   $10 9            ;Load register 10 with final iteration count value  
        xor_s $10 $8           ;reg10 = 0 if we are at final round other value if otherwise 
        bne $10 notEnd         ;if reg10 != 0 got to not end 
        J END                  ; Jump to end if otherwise 
        notEnd: J Loop         ;Jump back to Loop 
        

Mix1Row: dupi_s $9 03          ;duplicate 03 in reg9
    dupi_s $8 02               ;duplicate 02 in reg8
    mul_s $5 $9                ; mul $5 with dup03
    mul_s $4 $8                ;mul $5 with dupo2

    xor $4 $5                  ;perform xors                   
    xor $4 $6                  ;perform xors 
    xor $4 $7                  ;perform xors  

    jr $15                     ;Jump to return address
   
END: addi $sp -12              ;create space on stack 
sto_s $4 0($sp)                ;push results to stack
sto_s $5 1($sp)                ;push results to stack
sto_s $6 2($sp)                ;push results to stack
sto_s $7 3($sp)                ;push results to stack