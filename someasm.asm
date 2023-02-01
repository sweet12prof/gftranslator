ld_s  $1 1($0)
ld_s  $2 2($0)
ld_s  $3 3($0)
ld_s  $4 4($0)
ld_s  $5 5($0)
xor_s $1, $5
ld_s  $5 6($0)
xor_s $2, $5
ld_s  $5 7($0)
xor_s $3, $5
ld_s  $5 8($0)
xor_s $4, $5
start:  setfx 0x11b
dupis $5 0x01
div_s $1, $5
div_s $2, $5
div_s $3, $5
div_s $4, $5 
dupis $5 0x1F
setfx 0x101 
mul_s $1 $5
mul_s $2 $5
mul_s $3 $5
mul_s $4 $5
dupis $5 0x63
xor_s $1 $5
xor_s $2 $5 
xor_s $3 $5
xor_s $4 $5 
sr_s $1, $2  
sr_s $3, $4 
mvs $10, $12 
addi $12, -1 
bne_dec $12, notAddKey 
J addkey
notAddKey: addi $14, -12 
setstride 4
jal MixFor1row
sto_s $7 0($14)
mvs $1, $2
mvs $2, $3
mvs $4, $3
jal MixFor1row
sto_s $7 1($14)
mvs $1, $2
mvs $2, $3
mvs $4, $3
jal MixFor1row
sto_s $7 2($14)
mvs $1, $2
mvs $2, $3
mvs $4, $3
jal MixFor1row
sto_s $7 3($14)
ld_s $1, 0($14)
ld_s $2, 1($14)
ld_s $3, 2($14)
ld_s $4, 3($14)
addi $14, 12 

addkey: ld_s  $5 0($11)
xor_s $1, $5
ld_s  $5 1($11)
xor_s $2, $5
ld_s  $5 2($11)
xor_s $3, $5
ld_s  $5 3($11)
xor_s $4, $5
addi $11, 4 
beq_dec $10, MixFor1row
J   start




MixFor1row: addi $14, -12 
sto_s   $1, 0($14)
sto_s   $2, 1($14)
sto_s   $3, 2($14)
sto_s   $4, 3($14)		
dupi_s   $5 0x02
dupi_s   $6 0x03
mul_s   $1, $5
mul_s   $2, $6
xor_s   $1 $2
xor_s   $1 $3
xor_s   $1 $3 
mv_s    $1 $7
ld_s    $1 0($14)
ld_s    $2 1($14)
ld_s    $3 2($14)
ld_s    $4 3($14)
addi    $14, 12
jr      $15