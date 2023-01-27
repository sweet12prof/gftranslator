sum2: addi $1, 12      
beq $1, sum2           
additp: j sum2          
srs $1, $0             
jr $4, 12               
mvv $2, $1             