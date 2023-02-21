lbi $1 56                  
lbi $2 -24                
lbi $9  01
lbi $8  -4
and_s $3 $0 
setsrtype 2
sr_s $3 $9
sr_s $3 $8
setstride 4
ld_v $4 0($2)
addi $2 16              
ld_v $5 1($2)
addi $2 16                
ld_v $6 2($2)
addi $2 16                
ld_v $7 3($2)