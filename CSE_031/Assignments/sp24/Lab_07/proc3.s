# Individual Assignment 1: Create proc3.s FOO BAR
.data
x:	.word 2
y:	.word 4
z:	.word 6
fooStr:	.asciiz "p + q: "
newline: 	.asciiz "\n"

.text
MAIN:	# Intialize x, y, and z integers
	la $t0, x
	lw $s0, 0($t0)		# $s0 = x (2)
	la $t0, y
	lw $s1, 0($t0)		# $s1 = y (4)
	la $t0, z
	lw $s2, 0($t0)		# $s2 = z (6)
	
	# Prepare to call foo(x, y, z)
	addu $a0, $zero, $s0	# Set a0 as input argument m for FOO	
	addu $a1, $zero, $s1	# Set a1 as input argument n for FOO	
	addu $a2, $zero, $s2	# Set a2 as input argument o for FOO
	jal FOO
	
	# Calculate final z value
	addu $t0, $s1, $s0
	addu $t0, $s2, $t0
	addu $t0, $t0, $v0
	
	# Print resulting integer z
	addu $a0, $zero, $t0
	li $v0, 1		 
	syscall	
	j END
	
	
FOO: 	# FOO prologue
	addi $sp, $sp, 24
	sw $ra, 20($sp)		# Save FOO ra
	sw $a0, 16($sp)		# Save FOO arg1
	sw $a1, 12($sp)		# Save FOO arg2
	sw $a2, 8($sp)		# Save FOO arg3
	sw $s1, 4($sp)		# Save x variable
	sw $s0, 0($sp)		# Save y variable
	
	# Prepare to call bar(m + o, n + o, m + n)
	addu $t0, $a0, $a2
	addu $t1, $a1, $a2
	addu $t2, $a0, $a1
	addu $a0, $zero, $t0
	addu $a1, $zero, $t1
	addu $a2, $zero, $t2
	jal BAR
	addu $s0, $zero, $v0	# $s0 = p
	
	# Intermediate epilogue
	lw $a0, 16($sp)		# Restore m
	lw $a1, 12($sp)		# Restore n
	lw $a2, 8($sp)		# Restore o
	
	# Prepare to call bar(m - o, n - m, n + n)
	subu $t0, $a0, $a2
	subu $t1, $a1, $a0
	addu $t2, $a1, $a1
	addu $a0, $zero, $t0
	addu $a1, $zero, $t1
	addu $a2, $zero, $t2
	jal BAR
	addu $s1, $zero, $v0	# $s1 = q

	# Print p + q: {p + q}
	la $a0, fooStr
	li $v0, 4
	syscall
	addu $v1, $s0, $s1
	addu $a0, $zero, $v1
	li $v0, 1		 
	syscall
	li $v0, 4
	la $a0, newline
	syscall

	# FOO epilogue
	lw $s1, 0($sp)		# Restore var y
	lw $s0, 4($sp)		# Restore var x
	lw $ra, 20($sp)		# Restore SUM ra
	addi $sp, $sp, 24
	addu $v0, $zero, $v1
	jr $ra

BAR:	subu $t0, $a1, $a0
	sllv $t0, $t0, $a2
	addu $v0, $zero, $t0
	jr $ra
	
END: