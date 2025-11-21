.data

# TPS 2 #3 (input prompt to be displayed)
inputPrompt:		.asciiz "Please enter an integer: "
returnOnePrompt:	.asciiz "Returning 1\n"
returnThreePrompt:	.asciiz "Returning 3\n"

.text
main: 	#Moving stack pointer to make room for storing local variables (push the stack frame)
	addi $sp, $sp, -16 # !!! updated -4 to -16 to fit the MIPS Calling Convention (4 args minimum)
	move $s1, $sp # !!! I have no idea why this was given to us, maybe implementing a frame pointer idk..........
		
	# TPS 2 #3 (display input prompt)
	la $a0, inputPrompt
	li $v0, 4
	syscall
	
	# TPS 2 #4 (read user input)
	li $v0, 5
	syscall
	move $s0, $v0	# !!! set x as a saved local variable
	move $a0, $s0	# prepare first argument in recursion(x)
		
	jal recursion	# Call recursion(x)
	
	# TPS 2 #6 (print out returned value)
	move $a0, $v0
	li $v0, 1		 
	syscall
	
	j end		# Jump to end of program


# Implementing recursion
recursion: addi $sp, $sp, -32 # !!! updated -4 to -32 to fit the MIPS Calling Convention (4 args minimum, 1 saved, 1 $ra, 1 local variable, 1 Padding)

	# TPS 2 #7
	sw $s0, 16($sp) # Push saved register to stack frame
	sw $ra, 20($sp)	# Push $ra to stack frame
	sw $s1, 24($sp)	# Push local variable to stack frame
	sw $a0, 32($sp) # Push $a0 to caller's Argument stack section

	addi $t0, $a0, 1
	bne $t0, $zero, not_minus_one
	
	# TPS 2 #8 (update returned value)
	la $a0, returnOnePrompt
	li $v0, 4
	syscall
	addiu $v0, $zero, 1	# Return 1
	
	j end_recur
		
not_minus_one:	bne $a0, $zero, not_zero
	# TPS 2 #9 (update returned value)
	la $a0, returnThreePrompt
	li $v0, 4
	syscall
	addiu $v0, $zero, 3	# Return 3
	
	j end_recur

not_zero: sw $a0, 4($sp) 	
	# TPS 2 #11 (Prepare new input argument, i.e. m - 2)
	lw $a0, 32($sp)		# Restore $a0 from caller's Argument stack section
	subiu $a0, $a0, 2	# m - 1
	
	jal recursion		# Call recursion(m - 2)
	
	# TPS 2 #12 
	addu $s1, $v0, $zero	# recursion(m - 2)
		
	# TPS 2 #13 (Prepare new input argument, i.e. m - 1)
	lw $a0, 32($sp)		# Restore $a0 from caller's Argument stack section
	subiu $a0, $a0, 1	# m - 1
	
	jal recursion	# Call recursion(m - 1)
	
	# TPS 2 #14 (update returned value)
	addu $v0, $v0, $s1	# recursion(m - 1)
	
	j end_recur
		

# End of recursion function	
end_recur: # TPS 2 #15
	lw $s0, 16($sp)		# Restore $s0 from stack frame
	lw $ra, 20($sp)		# Restore $ra from stack frame
	lw $s1, 24($sp)		# Restore local data $s1 from stack frame
	addi $sp, $sp, 32	# Pop stack frame 
	jr $ra

# Terminating the program
end:	addi $sp, $sp 16	# Moving stack pointer back (pop the stack frame) # !!! updated 4 to 16 to fit the MIPS Calling Convention (4 arg)
	li $v0, 10 
	syscall
