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
loop:   ld_s $4 -1($1)    
ld_s    $5 -4($1)          
setmvtype 0               
mv_s    $6 $2             
and_s   $6 $3             
bne     $6 notmultipleof4
J multipleof4
notmultipleof4: xor_s $4 $5  
LD_s $4 0($1)              
addi $2 1                           
addi $1 4                  
lbi $7 44                   
and_s $7 $2                  
beq $7 end                 
J loop                      
end: J END_2                
multipleof4: setsrtype 1   
sr_s $0 $4                   
setfx 0x1b                  
dupi_s $7 01
div_s $4  $7                 
setfx 0x01                 
dupi_s $6 0x1F             
mul_s $4 $6                   
dupi_s $6 0x63              
xor_s $4 $6                  
ld_s $8 0($11)               
addi $11 4                 
xor_s $4 $8                  
xor_s $4 $5                  
ld_s $4 0($1)              
addi $2 1                  
addi $1 4                   
lbi $7 44                   
and_s $7 $2                  
beq $7 end1                 
J loop                      
end1: J END_2                  
END_2: J  END_2               