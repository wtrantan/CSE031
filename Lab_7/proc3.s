.data
str: .asciiz "p + q: "
str1: .asciiz "\n "

.text

MAIN:		
		add $s0, $zero, 1
		add $s1, $zero, 2
		add $s2, $zero, 3
		li $v0, 4
		la $a0, str
		syscall 
		
		jal foo
		move $t4, $a0

		move $a0, $t4
		add $a0, $s0, $s1
		add $a1, $s2, $v0	
		add $v0, $a0, $a1
		move $a0, $v0
		
		li $v0, 1
		syscall 
		move $v0, $a0
		j END
		
foo: 		
		addi $sp, $sp, 12
		sw $ra, 0($sp)
		sw $s0, 4($sp)
		sw $s1, 8($sp)
		
		add $a0, $s0, $s2
		add $a1, $s1, $s2
		add $a2, $s0, $s1
		jal bar
		move $t3, $v0 
		
		sub $a0, $s0, $s2
		sub $a1, $s1, $s0
		add $a2, $s1, $s1
		jal bar
		move $t1, $v0 
		
		add $v0, $t3, $t1
		move $a0, $v0
		li $v0, 1
		syscall
		move $v0, $a0
		
		move $a1, $v0
		li $v0, 4
		la $a0, str1
		syscall 
		move $v0, $a1
		
		lw $ra, 0($sp)
		lw $s0, 4($sp)
		lw $s1, 8($sp)
		addi $sp, $sp, -12
		jr $ra		
		
bar:
    		# a0 = a, a1 = b, a2 = c
    		sub $t0, $a1, $a0    # b - a
		sllv $v0, $t0, $a2   # (b - a) << c
    		jr $ra
		
END:
