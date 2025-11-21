        .data
#n:      	.word 13
inputPrompt:	.asciiz "Please enter a number: "

        .text
main: 	add     $t0, $0, $zero
	addi    $t1, $zero, 1
	#la      $t3, n
	#lw      $t3, 0($t3)
	
	# Load prompt into $a0
	la $a0, inputPrompt
	
	# Print prompt in $a0
	li $v0, 4
	syscall
	
	# Get user input
	li $v0, 5
	syscall
	move $t3, $v0
		
fib: 	beq     $t3, $0, finish
	add     $t2,$t1,$t0
	move    $t0, $t1
	move    $t1, $t2
	subi    $t3, $t3, 1
	j       fib
		
finish: addi    $a0, $t0, 0
	li      $v0, 1		
	syscall			
	li      $v0, 10		
	syscall			

