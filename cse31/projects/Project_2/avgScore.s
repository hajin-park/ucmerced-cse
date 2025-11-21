.data 

orig: .space 100	# In terms of bytes (25 elements * 4 bytes each)
sorted: .space 100

str0: .asciiz "Enter the number of assignments (between 1 and 25): "
str1: .asciiz "Enter score: "
str2: .asciiz "Original scores: "
str3: .asciiz "Sorted scores (in descending order): "
str4: .asciiz "Enter the number of (lowest) scores to drop: "
str5: .asciiz "Average (rounded down) with dropped scores removed: "
newline: .asciiz "\n"
space: .asciiz " "


.text 

# This is the main program.
# It first asks user to enter the number of assignments.
# It then asks user to input the scores, one at a time.
# It then calls selSort to perform selection sort.
# It then calls printArray twice to print out contents of the original and sorted scores.
# It then asks user to enter the number of (lowest) scores to drop.
# It then calls calcSum on the sorted array with the adjusted length (to account for dropped scores).
# It then prints out average score with the specified number of (lowest) scores dropped from the calculation.
main: 
	addi $sp, $sp -4
	sw $ra, 0($sp)
	li $v0, 4 
	la $a0, str0
	syscall 
	li $v0, 5	# Read the number of scores from user
	syscall
	move $s0, $v0	# $s0 = numScores
	move $t0, $0
	la $s1, orig	# $s1 = orig
	la $s2, sorted	# $s2 = sorted
loop_in:
	li $v0, 4
	la $a0, str1 
	syscall 
	sll $t1, $t0, 2
	add $t1, $t1, $s1
	li $v0, 5	# Read elements from user
	syscall
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	bne $t0, $s0, loop_in
	
	move $a0, $s0
	jal selSort	# Call selSort to perform selection sort in original array
	
	li $v0, 4 
	la $a0, str2 
	syscall
	move $a0, $s1	# More efficient than la $a0, orig
	move $a1, $s0
	jal printArray	# Print original scores
	li $v0, 4 
	la $a0, str3 
	syscall 
	move $a0, $s2	# More efficient than la $a0, sorted
	jal printArray	# Print sorted scores
	
	li $v0, 4 
	la $a0, str4 
	syscall 
	li $v0, 5	# Read the number of (lowest) scores to drop
	syscall
	move $a1, $v0
	sub $a1, $s0, $a1	# numScores - drop
	move $a0, $s2
	jal calcSum	# Call calcSum to RECURSIVELY compute the sum of scores that are not dropped
	
	# Your code here to compute average and print it
	divu $v0, $a1
	mflo $t0	
	
	# Print average int rounded down
	li $v0, 4 
	la $a0, str5
	syscall 
	
	li $v0, 1
	move $a0, $t0
	syscall
	
	lw $ra, 0($sp)
	addi $sp, $sp 4
	li $v0, 10 
	syscall
	
	
# printList takes in an array and its size as arguments. 
# It prints all the elements in one line with a newline at the end.
printArray:
	# Your implementation of printList here
	# prologue
	addi $sp, $sp, -16		# reserve space for saved registers and argument
	sw $a0, 12($sp)		# save $a0
	sw $s0, 8($sp)		# save $s0
	sw $s1, 4($sp)		# save $s1
	sw $s2, 0($sp)		# save $s2
	
	# test initial copyArrayLoop condition
	li $s0, 0		# int i = 0
	slt $t0, $s0, $a1	# $t0 = 1 if i < len
	beq $t0, $zero, afterPrint

printLoop:
	lw $a0, 12($sp)		# restore $a0
	sll $t0, $s0, 2		# $t0 = &i
	add $t0, $t0, $a0	# $t0 = &arr[i]
	lw $t0, 0($t0)		# $t0 = arr[i]
	
	# Print array element
	li $v0, 1
	move $a0, $t0
	syscall
	
	# Print space
	li $v0, 4
	la $a0, space
	syscall
	
	# check copyArrayLoop loop condition
	addi $s0, $s0, 1	# i++
	slt $t0, $s0, $a1	# $t0 = 1 if i < len
	bne $t0, $zero, printLoop
	
afterPrint:
	# Print newline
	li $v0, 4
	la $a0, newline
	syscall	
	
	# epilogue
	lw $a0, 12($sp)		# restore $a0
	lw $s0, 8($sp)		# restore $s0
	lw $s1, 4($sp)		# restore $s1
	lw $s2, 0($sp)		# restore $s2
	addi $sp, $sp, 12		# restore stack frame
	jr $ra
	
	
# selSort takes in the number of scores as argument. 
# It performs SELECTION sort in descending order and populates the sorted array
selSort:
	# Your implementation of selSort here
	# prologue
	addi $sp, $sp, -12		# reserve space for saved registers
	sw $s0, 8($sp)		# save $s0 length
	sw $s1, 4($sp)		# save $s1 orig
	sw $s2, 0($sp)		# save $s2 sorted

	# initialize local variables
	li $s0, 0		# int i
	li $s1, 0		# int j
	li $s2, 0		# int temp
	
	# load orig and sorted arrays
	lw $t0, 4($sp)		# $t0 = orig
	lw $t1, 0($sp)		# $t1 = sorted
	
	# test initial copyArrayLoop condition
	slt $t2, $s0, $a0	# $t2 = 1 if i < len
	beq $t2, $zero, afterCopyArray
	
copyArrayLoop:
	# Copy orig into sorted
	sll $t2, $s0, 2		# i
	add $t3, $t2, $t0	# &orig[i]
	add $t4, $t2, $t1	# &sorted[i]
	lw $t3, 0($t3)		# $t4 = orig[i]
	sw $t3, 0($t4)		# sorted[i] = orig[i]
	
	# check copyArrayLoop loop condition
	addi $s0, $s0, 1
	slt $t2, $s0, $a0	# $t2 = 1 if i < len
	bne $t2, $zero, copyArrayLoop
	li $s0, 0		# int i = 0
	
afterCopyArray:
	# test initial swapMaxElementLoop condition
	addi $t2, $a0, -1	# $t2 = len - 1
	slt $t2, $s0, $t2	# $t2 = 1 if i < len - 1
	beq $t2, $zero, endSelSort

swapMaxElementLoop:
	# Swap largest with the first element in sorted[i..len-1]
	addi $s3, $s0, 0	# int maxIndex = i
	addi $s1, $s0, 1	# j = i + 1
	
	# test initial findMaxElementLoop condition
	slt $t2, $s1, $a0	# $t2 = 1 if j < len
	beq $t2, $zero, afterFindMaxElement
	
findMaxElementLoop:
	# Find the max element in sorted[i..len-1]
	sll $t3, $s1, 2		# $t3 = &j
	add $t3, $t3, $t1	# $t3 = &sorted[j]
	sll $t4, $s3, 2		# $t4 = &maxIndex
	add $t4, $t4, $t1	# $t4 = &sorted[maxIndex]
	lw $t3, 0($t3)		# $t3 = sorted[j]
	lw $t4, 0($t4)		# $t4 = sorted[maxIndex]
	slt $t3, $t4, $t3	# $t3 = 0 if sorted[j] > sorted[maxIndex]
	beq $t3, $zero, loopConditional
	addi $s3, $s1, 0	# maxIndex = j;      

loopConditional:
	# check findMaxElementLoop condition
	addi $s1, $s1, 1
	slt $t2, $s1, $a0	# $t2 = 1 if j < len
	bne $t2, $zero, findMaxElementLoop

afterFindMaxElement:
	# swap sorted[maxIndex] and sorted[i]
	sll $t2, $s3, 2		# $t2 = &maxIndex
	add $t2, $t2, $t1	# $t2 = &sorted[maxIndex]
	lw $t3, 0($t2)		# $t3 = sorted[maxIndex]
	move $s2, $t3		# temp = sorted[maxIndex]
	
	sll $t3, $s0, 2		# $t3 = &i
	add $t3, $t3, $t1	# $t3 = &sorted[i]
	lw $t4, 0($t3)		# $t4 = sorted[i]
	sw $t4, 0($t2)		# sorted[maxIndex] = sorted[i]
	
	sw $s2, 0($t3)		# sorted[i] = temp

	# check swapMaxElementLoop condition
	addi $s0, $s0, 1
	addi $t2, $a0, -1	# $t2 = len - 1
	slt $t2, $s0, $t2	# $t2 = 1 if i < len - 1
	bne $t2, $zero, swapMaxElementLoop

endSelSort:
	# epilogue
	lw $s0, 8($sp)		# restore $s0
	lw $s1, 4($sp)		# restore $s1
	lw $s2, 0($sp)		# restore $s2
	addi $sp, $sp, 12	# restore stack frame
	jr $ra
	
	
# calcSum takes in an array and its size as arguments.
# It RECURSIVELY computes and returns the sum of elements in the array.
# Note: you MUST NOT use iterative approach in this function.
calcSum:
	# Your implementation of calcSum here
	#prologue
	addi $sp, $sp, 	-12	# stack frame for 2 arguments, 1 ra
	sw $ra, 8($sp)		# save $ra
	sw $a0, 4($sp)		# save $a1
	sw $a1, 0($sp)		# save $a0
	
	slt $t0, $zero, $a1	# $t0 = 1 if 0 < len
	beq $t0, $zero, lenisZero
	
	# Call calcSum(arr, len - 1)
	addi $a1, $a1, -1
	jal calcSum
	
	# calcSum(arr, len - 1) + arr[len - 1]
	sll $t0, $a1, 2
	add $t0, $t0, $a0
	lw $t0, 0($t0)
	add $v0, $v0, $t0
	j endCalcSum

lenisZero:
	li $v0, 0		# return 0

endCalcSum:
	#epilogue
	lw $ra, 8($sp)		# restore $ra
	lw $a0, 4($sp)		# restore $a1
	lw $a1, 0($sp)		# restore $a0
	addi $sp, $sp, 	12	# restore stack frame
	jr $ra
