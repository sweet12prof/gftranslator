lbi     $1  56      
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
k_loop:   ld_s $4 -1($1)    
ld_s    $5 -4($1)          
setmvtype 0               
mv_s    $6 $2             
and_s   $6 $3             
bne     $6 notmultipleof4
J multipleof4
notmultipleof4: xor_s $4 $5  
sto_s $4 0($1)              
addi $2 1                           
addi $1 4                  
lbi $7 44                   
xor_s $7 $2                  
beq $7 endA                 
J k_loop                      
endA: J AES               
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
beq $7 AES                 
J k_loop 
AES: lbi $1 56                  
lbi $2 -24                
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
setsrtype 3 
sr_v $2 $11
sr_v $11 $0 
sr_v $2 $10
sr_v $10 $0
sr_v $2 $9  
sr_v $9 $0   
sr_v $2 $8   
sr_v $8 $0   
sr_v $12 $11 
sr_v $11 $0 
sr_v $12 $10
sr_v $10 $0
sr_v $12 $9
sr_v $9 $0 
sr_v $12 $8
sr_v $8 $0 
sr_v $13 $11 
sr_v $11 $0 
sr_v $13 $10
sr_v $10 $0
sr_v $13 $9
sr_v $9 $0 
sr_v $13 $8
sr_v $8 $0 
sr_v $14 $11 
sr_v $11 $0 
sr_v $14 $10
sr_v $10 $0
sr_v $14 $9
sr_v $9 $0 
sr_v $14 $8
sr_v $8 $0 
addi $1 16                  
xor_v $4 $14                                   
xor_v $5 $13                  
xor_v $6 $12                
xor_v $7 $2   
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
        setsrtype 3 
        sr_v $2 $12 
        sr_v $12 $0 
        sr_v $2 $11
        sr_v $11 $0
        sr_v $2 $10
        sr_v $10 $0 
        sr_v $2 $9
        sr_v $9 $0 
        sr_v $1 $12 
        sr_v $12 $0 
        sr_v $1 $11
        sr_v $11 $0
        sr_v $1 $10
        sr_v $10 $0 
        sr_v $1 $9
        sr_v $9 $0 
        sr_v $8 $12 
        sr_v $12 $0 
        sr_v $8 $11
        sr_v $11 $0
        sr_v $8 $10
        sr_v $10 $0 
        sr_v $8 $9
        sr_v $9 $0 
        sr_v $13 $12 
        sr_v $12 $0 
        sr_v $13 $11
        sr_v $11 $0
        sr_v $13 $10
        sr_v $10 $0 
        sr_v $13 $9
        sr_v $9 $0 
        xor_v $4 $13              
        xor_v $5 $8           
        xor_v $6 $1        
        xor_v $7 $2                   
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