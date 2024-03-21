.data
evenSum: 	.word 0
oddSum: 	.word 0
newline: 	.asciiz "\n"
inputPrompt:	.asciiz "Please enter a number: "
evenOutput:	.asciiz "Sum of even numbers is: "
oddOutput:	.asciiz "Sum of odd numbers is: "

.text
main:	li $t0, 1	
While:	beq $t0, $zero, PrintResults

	# Load prompt into $a0
	la $a0, inputPrompt
	
	# Print prompt in $a0
	li $v0, 4
	syscall
	
	# Get user input
	li $v0, 5
	syscall
	move $t0, $v0
	add $t1, $zero, $t0
	
	# Check if input is negative or positive
	slt $t4, $t1, $zero
	bne $t4, $zero, checkEvenOddNeg
	j checkEvenOddPos

checkEvenOddPos:
	subi $t1, $t1, 2
	
	# Input is even
	beq $t1, $zero, addEven
	
	# Input is odd
	slt $t4, $t1, $zero
	bne $t4, $zero, addOdd
	
	j checkEvenOddPos
	
checkEvenOddNeg	:
	addi $t1, $t1, 2
	
	# Input is even
	beq $t1, $zero, addEven
	
	# Input is odd
	slt $t4, $zero, $t1
	bne $t4, $zero, addOdd
	
	j checkEvenOddNeg

addEven:# Add input to evenSum
	la $t2, evenSum
	lw $t3, 0($t2)
	add $t3, $t3, $t0
	sw $t3, 0($t2)
	j While
	
addOdd:	# Add input to oddSumt
	la $t2, oddSum
	lw $t3, 0($t2)
	add $t3, $t3, $t0
	sw $t3, 0($t2)
	j While

PrintResults:
	li $v0, 4
	la $a0, newline
	syscall
	
	# Print even sum
	la $a0, evenOutput
	syscall
	li $v0, 1
	lw $a0, evenSum
	syscall
	li $v0, 4
	la $a0, newline
	syscall
	
	# Print odd sum
	la $a0, oddOutput
	syscall
	li $v0, 1
	lw $a0, oddSum
	syscall

	j After

After:  # Quit the program
	li $v0, 10		
	syscall