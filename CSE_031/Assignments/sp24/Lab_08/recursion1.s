.data
inputPrompt:	.asciiz "Please enter an integer: "

.text
main:	addi $sp, $sp, -16 # MIPS Calling Convention (4 args minimum)
		
	# display input prompt
	la $a0, inputPrompt
	li $v0, 4
	syscall
	
	# read user input
	li $v0, 5
	syscall
	move $s0, $v0	# set x as a saved local variable
	move $a0, $s0	# prepare first argument in recursion(x)
		
	jal recursion	# Call recursion(x)
	
	# print out returned value
	move $a0, $v0
	li $v0, 1		 
	syscall
	
	j end		# Jump to end of program

recursion: #  MIPS Calling Convention (4 args minimum, 1 saved, 1 $ra, 1 local variable, 1 Padding)
	addi $sp, $sp, -32 
	sw $s0, 16($sp) # Push saved register to stack frame
	sw $ra, 20($sp)	# Push $ra to stack frame
	sw $s1, 24($sp)	# Push local variable to stack frame
	sw $a0, 32($sp) # Push $a0 to caller's Argument stack section

	addi $t0, $a0, 1
	bne $t0, $zero, not_minus_one
	
	# update returned value
	addiu $v0, $zero, 3	# Return 3
	
	j end_recur
		
not_minus_one:
	li $t0, -2
	bgt $a0, $t0, not_lte_negative_two
	bge $a0, $t0, not_lt_negative_two
	
	# update returned value
	addiu $v0, $zero, 2	# Return 2
	
	j end_recur
	
not_lt_negative_two:
	# update returned value
	addiu $v0, $zero, 1	# Return 1
	
	j end_recur

not_lte_negative_two: sw $a0, 4($sp) 	
	# Prepare new input argument, i.e. m - 3
	lw $a0, 32($sp)		# Restore $a0 from caller's Argument stack section
	subiu $a0, $a0, 3	# m - 3
	
	jal recursion		# Call recursion(m - 3)

	addu $s1, $v0, $zero	# recursion(m - 3)	
	lw $a0, 32($sp)		# Restore $a0 (m) from caller's Argument stack section
	addu $s1, $s1, $a0	# + m
		
	# Prepare new input argument, i.e. m - 2
	lw $a0, 32($sp)		# Restore $a0 from caller's Argument stack section
	subiu $a0, $a0, 2	# m - 2
	
	jal recursion	# Call recursion(m - 2)
	
	# update returned value
	addu $v0, $v0, $s1	# recursion(m - 2)
	
	j end_recur
			
end_recur:
	lw $s0, 16($sp)		# Restore $s0 from stack frame
	lw $ra, 20($sp)		# Restore $ra from stack frame
	lw $s1, 24($sp)		# Restore local data $s1 from stack frame
	addi $sp, $sp, 32	# Pop stack frame 
	jr $ra

end:	addi $sp, $sp 16	# Moving stack pointer back (pop the stack frame)
	li $v0, 10 
	syscall
