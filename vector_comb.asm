lbi     $1  104
lbi     $10  56      
lbi     $11 16  
LD_S    $2 0($0)
STO_S   $2 0($1)    
LD_S    $3 1($0)                        
STO_s    $3 1($1)                                        
LD_S    $4 2($0)
STO_S   $4 2($1)                                                            
LD_S    $5 3($0)                                        
STO_S   $5 3($1)                                            
LBI     $2 4    
and_s   $3 $0 
lbi     $3 3    
addi    $1 16  
k_loop: ld_s $4 -1($1)
ld_s $5 -4($1)        
setmvtype 0            
mv_s    $6 $2             
and_s   $6 $3             
bne     $6 notmultipleof4
ld_s $4 -4($1)    
ld_s $5 -3($1)
ld_s $6 -2($1)    
ld_s $7 -1($1)
jal columnMajor 
J multipleof4
notmultipleof4: xor_s $4 $5  
sto_s $4 0($1)              
addi $2 1                           
addi $1 4                  
lbi $7 44                   
xor_s $7 $2                  
beq $7 endA                 
J k_loop                      
endA: ld_s $4 -4($1)    
ld_s $5 -3($1)
ld_s $6 -2($1)    
ld_s $7 -1($1)
jal columnMajor
J AES                
multipleof4: setsrtype 0   
sr_s $0 $4                   
setfx 27                  
dupi_s $7 01
div_s $4  $7                 
setfx 1                 
dupi_s $6 31             
mul_s $4 $6                   
dupi_s $6 99              
xor_s $4 $6                  
ld_s $8 0($11)               
addi $11 4                 
xor_s $4 $8                  
xor_s $4 $5                  
sto_s $4 0($1)              
addi $2 1                  
addi $1 4                   
lbi $7 44                
xor_s $7 $2                  
beq $7 end1                 
J k_loop                      
end1: J AES                    
columnMajor: setsrtype 3
sr_s $9 $7
sr_s $7 $0 
sr_s $9 $6
sr_s $6 $0
sr_s $9 $5
sr_s $5 $0
sr_s $9 $4
sr_s $4 $0
sr_s $12 $7 
sr_s $7 $0 
sr_s $12 $6
sr_s $6 $0
sr_s $12 $5
sr_s $5 $0 
sr_s $12 $4
sr_s $4 $0 
sr_s $13 $7 
sr_s $7 $0 
sr_s $13 $6
sr_s $6 $0
sr_s $13 $5
sr_s $5 $0 
sr_s $13 $4
sr_s $4 $0 
sr_s $14 $7 
sr_s $7 $0 
sr_s $14 $6
sr_s $6 $0
sr_s $14 $5
sr_s $5 $0 
sr_s $14 $4
sr_s $4 $0 
ld_s $4 -1($1)    
ld_s $5 -4($1)                                   
sto_s $13  1($10)            
sto_s $12  2($10)            
sto_s $9   3($10)   
sto_s $14  0($10)  
addi $10 16
jr $15 
AES: lbi $1 24
lbi $2 1
setsrtype 2
sr_s $2 $1
lbi $1 56                                 
lbi $9  01
lbi $8  -4
and_s $3 $0 
setsrtype 2
sr_s $3 $9
sr_s $3 $8
setstride 16
ld_v $4 0($2)           
ld_v $5 1($2)              
ld_v $6 2($2)            
ld_v $7 3($2)
setstride 0
ld_v $8  0($1)               
ld_v $9  1($1)              
ld_v $10 2($1)               
ld_v $11 3($1) 
addi $1 16                  
xor_v $4 $8                                   
xor_v $5 $9                  
xor_v $6 $10                
xor_v $7 $11  
lbi $8 0              
Loop: setfx 27              
        dupi_v $9 01         
        div_v $4 $9            
        div_v $5 $9            
        div_v $6 $9                
        div_v $7 $9            
        setfx 01            
        dupi_v $9 31         
        mul_v $4 $9                  
        mul_v $5 $9         
        mul_v $6 $9         
        mul_v $7 $9         
        dupi_v $9 99        
        xor_v $4 $9                  
        xor_v $5 $9         
        xor_v $6 $9         
        xor_v $7 $9          
        setsrtype 0         
        sr_v $4 $5           
        setsrtype 1         
        sr_v $6 $7          
        addi  $8 1          
        lbi   $10 10          
        xor_s $10 $8        
        bne $10 MixColumn   
        J AddKey               
MixColumn: addi $3 -128
    setstride 16
    sto_v $4 0($3)                         
    sto_v $5 1($3)          
    sto_v $6 2($3)          
    sto_v $7 3($3)    
    setmvtype 0
    mv_s $4 $3
    addi $4 64            
    jal Mix1Row              
    sto_v $4 0($4)          
    ld_v $4 1($3)                         
    ld_v $5 2($3)            
    ld_v $6 3($3)           
    ld_v $7 0($3)           
    jal Mix1Row             
    sto_v $4 1($4)           
    ld_v $4 2($3)          
    ld_v $5 3($3)           
    ld_v $6 0($3)          
    ld_v $7 1($3)          
    jal Mix1Row            
    sto_v $4 2($4)          
    ld_v $4 3($3)                    
    ld_v $5 0($3)           
    ld_v $6 1($3)          
    ld_v $7 2($3)          
    jal Mix1Row            
    setmvtype 0 
    mv_v $7 $4          
    ld_v $4 0($4)                    
    ld_v $5 1($4)          
    ld_v $6 2($4)                           
    addi $3 127
    addi $3 1         
AddKey: setstride 0
        ld_v $9  0($1)  
        ld_v $10 1($1)  
        ld_v $11 2($1)  
        ld_v $12 3($1)  
        xor_v $4 $9             
        xor_v $5 $10           
        xor_v $6 $11        
        xor_v $7 $12                   
        addi  $1 16            
        lbi   $10 10              
        xor_s $10 $8             
        bne $10 notEnd          
        J END                   
        notEnd: J Loop
Mix1Row: setfx 27
        dupi_v $9 03          
        dupi_v $8 02               
        mul_v $5 $9                
        mul_v $4 $8                
        xor_v $4 $5                                     
        xor_v $4 $6                   
        xor_v $4 $7                    
        jr $15                    
END: addi $3 -128  
setstride 16             
sto_v $4 0($3)                
sto_v $5 1($3)                
sto_v $6 2($3)                
sto_v $7 3($3)
END_K: J END_K 