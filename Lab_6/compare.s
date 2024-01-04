        .data
n:      .word 25
str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to\n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"


        .text
main: 		lw	$t1, n
		li      $v0, 5
		syscall	
		add 	$s1, $v0, $zero
		lw 	$s2, n
 		move $t0, $v0
 		
 		slt  $t1,$s2,$s1      # checks if $s1 > $s2
		bne  $t1,$zero, great
		slt  $t1,$s1,$s2 # if $s0 >  $s1, goes to label1
		beq  $s1,$s2, lessequal
		
		slt  $t1,$s1,$s2      # checks if $s2 > $s1
		bne  $t1,$zero, less 
		slt  $t1,$s2,$s1    # if $s0 >  $s1, goes to label1
		beq  $s1,$s2, greatequal   # if $s0 == $s2, goes to label2 
		
		
great: 		la $a0, str3
		j end

greatequal: 	la $a0, str4
		j end
		
less: 		la $a0, str1
		j end
		
lessequal: 	la $a0, str2
		j end


end:	li      $v0, 4
	syscall
	
