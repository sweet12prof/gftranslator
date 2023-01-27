sum2: addi $1, 12      
beq $1, sum2           
additp: j sum2          
sr_s $1, $0             
jr $4, 12               
mv_v $2, $1 
beq $4 pick
pick: dupis $5 $20
setfx  $27            
setsrtype $1
bne_dec $15 pick
andv $1 $7