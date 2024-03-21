.data
n:	.word 25
str1: 	.asciiz "Less than\n"
str2: 	.asciiz "Less than or equal to\n"
str3: 	.asciiz "Greater than\n"
str4: 	.asciiz "Greater than or equal to\n"

.text
main:	# Read the user input and save it in $s0
	li $v0, 5
	syscall
	move $s0, $v0
	
	# Load the integer stored in n and save it in $t0
	la $t0, n
	lw $t0, 0($t0)
	
	# Compare if user input is less than n
	#slt $t1, $s0, $t0
	#bne $t1, $zero, PrintLT
	
	# Compare if user input is greater than n
	#slt $t1, $t0, $s0
	#bne $t1, $zero, PrintGT	
	
	# Compare if user input is less than or equal to n
	slt $t1, $t0, $s0
	beq $t1, $zero, PrintLTE	
	
	# Compare if user input is geater than or equal to n
	slt $t1, $s0, $t0
	beq $t1, $zero, PrintGTE	
	
PrintLT:
	li $v0, 4
	la $a0, str1
	syscall
	j After

PrintGT:
	li $v0, 4
	la $a0, str3
	syscall
	j After
	
PrintLTE:
	li $v0, 4
	la $a0, str2
	syscall
	j After
	
PrintGTE:
	li $v0, 4
	la $a0, str4
	syscall
	j After
	
After:  # Quit the program
	li $v0, 10		
	syscall
	