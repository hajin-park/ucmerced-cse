        .data
str1: .asciiz "Less than\n"
str2: .asciiz "Greater than or equal to\n"

	.text
	# TPS 1 part 6
	addi $s0, $zero, 25
	
	li $v0, 5	#read value from user
	syscall
	move $s1, $v0	

	# TPS 1 part 7
	slt $t0, $s1, $s0
	
	# TPS 1 part 8
	bne $t0, $zero, LESS
	
	# TPS 1 part 9
	j GREQ

LESS:	li $v0, 4 
	la $a0, str1 
	syscall 	
	j END

GREQ:	li $v0, 4 
	la $a0, str2 
	syscall 	
	j END
			
END:	li $v0, 10		
	syscall

