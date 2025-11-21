# Title: Demo code for CSE 031 Lab 5 
#        This program adds 10 to the value of $t1, stores the result in $s1 and outputs that value.
#	 click on 'Help' to learn more about what each instruction does. You may also hover your
#	 mouse over each instruction line to learn about it.
# Author: Santosh Chandrasekhar

# $t0 = $s0 
# $t1 = $t0 - 7 
# $t2 = $t1 + $t0 
# $t3 = $t2 + 2 
# $t4 = $t3 + $t2 
# $t5 = $t4 - 28 
# $t6 = $t4 - $t5 
# $t7 = $t6 + 12

.data	# Define the program data (static data segment).
num: 	.word 10 # Declare a word (4 bytes) in the static data segment that contains the value 
	         # 10 and label this memory address as 'num' so you may refer to it later.

.text	# Define the program instructions (text segment).
main:	# Label to define the main program. In other words, 'main' is a label assigned to the memory
     	# address where this program begins in the text segment.
	
	lw $t0, num # Load the value at label 'num' into $t0 (this is where 10 is stored).
		    # We will go over how this is actually done in class.
	
	# HOW TO SET THE VALUE OF $t1 BEFORE RUNNING PROGRAM:
	# Build the program, then set $t1 to a some value using the pane on the right 
	# displaying register values. Remember to go to 'Settings' and uncheck the box 
	# 'Values displayed in hexadecimal' if you want to work with decimals. Once this is 
	# done, you may run the program.
	
	add $s1, $t0, $t1 # Register $s1 now holds the sum of $t0 (10) and $t1 (set by you).
	
	addi $a0, $s1, 0 # Load the value $s1 to be printed into $a0 (constants are called 
			 # immediates in MIPS Assembly Language programs). Here we are adding 0
			 # to $s1 and storing the result in $a0.
	
	# Below are two other ways to load the value $s1 into $a0:
	# add $a0, $s1, $zero # The register called $zero always stores 0 and nothing else.
	# move $a0, $s1
	
	li $v0, 1 # Load 1 (service number) into $v0 to indicate printing of an integer.
	syscall # Syscall reads the value in $v0, sees that it is 1, so it expects $a0 to 
		# contain the target VALUE that is then printed. 
		# Click on 'Help' and navigate to Syscalls tab to learn more.

	li $v0, 10 # Load a 10 (service number for halt) into $v0.
	syscall # The program ends because syscall reads the value of 10 in $v0.
