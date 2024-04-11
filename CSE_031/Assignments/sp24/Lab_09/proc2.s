        .data
str1: .asciiz "Greater than\n"
str2: .asciiz "Less than or equal to\n"

	.text
	
	addi $s0, $zero, -15
	
	li $v0, 5	#read value from user
	syscall
	move $s1, $v0	

	# Individual assignment part 2
	slt $t0, $s0, $s1
	
	# Individual assignment part 3
	beq $t0, $zero, LEEQ
	
	# Individual assignment part 4
	j GRT

GRT:	li $v0, 4 
	la $a0, str1 
	syscall 	
	j END

LEEQ:	li $v0, 4 
	la $a0, str2 
	syscall 	
	j END
			
END:	li $v0, 10		
	syscall

