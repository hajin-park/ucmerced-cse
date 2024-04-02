.data
x:	.word 5
y:	.word 10
m:	.word 15
b:	.word 2

.text
MAIN:	# Initialize x and y integers
	la $t0, x
	lw $s0, 0($t0)		# s0 = x
	la $t0, y
	lw $s1, 0($t0)		# s1 = y
	
	# Prepare to call sum(x)
	addu $a0, $zero, $s0	# Set a0 as input argument for SUM
	jal SUM
	
	# Calculate final y value
	addu $t0, $s1, $s0
	addu $s1, $t0, $v0
	
	# Print resulting integer y
	addiu $a0, $s1, 0 
	li $v0, 1		 
	syscall	
	j END
		
SUM: 	# SUM prologue
	subi $sp, $sp, 12
	sw $ra, 8($sp)		# Save SUM ra
	sw $s0, 4($sp)		# Save var x
	sw $a0, 0($sp)		# Save SUM arg1
	
	# Prepare to call sub(m + n)
	la $t0, m
	lw $s0, 0($t0)		# s0 = m
	addu $a0, $s0, $a0	# Update a0 as new argument for SUB
	jal SUB
	
	# SUM epilogue
	lw $a0, 0($sp)		# Restore SUM arg1
	lw $s0, 4($sp)		# Restore var x
	lw $ra, 8($sp)		# Restore SUM ra
	addi $sp, $sp, 12
	addu $v0, $a0, $v0
	jr $ra	
		
SUB:	# SUB prologue
	la $t0, b
	addiu $sp, $sp -4
	sw $s0, 0($sp)		# Backup s0 from SUM
	lw $s0, 0($t0)		# s0 = b
	subu $v0, $a0, $s0
	
	# SUB epilogue
	lw $s0, 0($sp)		# Restore s0 from SUM
	addiu $sp, $sp 4
	jr $ra

END:
