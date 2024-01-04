.data
evenSum: .asciiz "\nSum of even numbers is: "
oddSum: .asciiz "\nSum of odd numbers is: "
inputmsg: .asciiz "\nPlease enter a number: "
.text 
main: 
		li 	$v0, 4
		la 	$a0, inputmsg
		syscall 
		li      $v0, 5
		syscall	
		
 		move $t0, $v0
 		
 		beq $t0, $zero, end
 		add $t3, $t0, $zero
 		bgt $t3, $zero, pos
 		blt $t3, $zero, neg
 		
 pos: 
 	beq $t3, 1, odd
 	addi $t3, $t3, -2
	beq $t3, 0, even
	j pos
	
neg:
	beq $t3, -1, odd
	addi $t3, $t3, 2
	beq $t3, 0, even
	j neg
		
even:
 	add $t1, $t1, $t0
 	j main
 
odd:
	add $t2, $t2, $t0
 	j main

end:
	li $v0, 4
 	la $a0, evenSum
	syscall
	li $v0, 1
	la $a0, ($t1)
	syscall
	li $v0, 4
 	la $a0, oddSum
	syscall
	li $v0, 1
 	la $a0, ($t2)
	syscall