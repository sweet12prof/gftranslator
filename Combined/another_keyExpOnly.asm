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
loop: ld_s $4 -1($1)
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
beq $7 end                 
J loop                      
end: ld_s $4 -4($1)    
ld_s $5 -3($1)
ld_s $6 -2($1)    
ld_s $7 -1($1)
jal columnMajor
J END_2                
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
J loop                      
end1: J END_2                  
END_2: J  END_2       
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