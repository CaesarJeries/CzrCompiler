.data
zeroDivErrStr: .asciiz "Error division by zero\n"
str0: .asciiz "\n"
str1: .asciiz "\n"
str2: .asciiz "\n"
str3: .asciiz "\n"
str4: .asciiz "\n"


.text
.globl zeroDivErr
.ent zeroDivErr
zeroDivErr:
la $a0, zeroDivErrStr
li $v0, 4
syscall
li $v0, 10
syscall
.end zeroDivErr



.globl printi
.ent printi
printi:
lw $a0,0($sp)
li $v0,1
syscall
jr $ra
.end printi



.globl print
.ent print
print:
lw $a0,0($sp)
li $v0,4
syscall
jr $ra
.end print



.globl skipSum
.ent skipSum
skipSum:
subu $fp, $sp, 4 # set current frame pointer
lw $s7, 8($fp) # load variable n. reg = $s7
li $s6, 0 # write 0 to register $s6
beq $s7, $s6, label_36
j label_43
label_36:
li $s5, 0 # write 0 to register $s5
move $v0, $s5 # store return value
j label_150
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
label_43:
lw $s4, 4($fp) # load variable shouldSkip. reg = $s4
bne $s4, $zero, label_47
j label_96
label_47:
lw $s3, 4($fp) # load variable shouldSkip. reg = $s3
xor $s3, $s3, 1
bne $s3, $zero, label_52
j label_52
label_52:
lw $s1, 8($fp) # load variable n. reg = $s1
li $s0, 1 # write 1 to register $s0
subu $s1, $s1, $s0
# save registers
subu $sp, $sp, 12
sw $s4, 0($sp)
sw $s2, 4($sp)
sw $s1, 8($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 8
sw $s2, 0($sp)
sw $s1, 4($sp)
# end - push function arguments
jal skipSum
# pop function arguments
addu $sp, $sp, 8
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s1, 8($sp)
lw $s2, 4($sp)
lw $s4, 0($sp)
addu $sp, $sp, 12
# end - restore registers
move $t9, $v0 # store return value of: skipSum
label_89:
move $v0, $t9 # store return value
j label_150
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
j label_146
label_96:
lw $t8, 8($fp) # load variable n. reg = $t8
lw $t7, 4($fp) # load variable shouldSkip. reg = $t7
xor $t7, $t7, 1
bne $t7, $zero, label_102
j label_102
label_102:
lw $t5, 8($fp) # load variable n. reg = $t5
li $t4, 1 # write 1 to register $t4
subu $t5, $t5, $t4
# save registers
subu $sp, $sp, 20
sw $s1, 0($sp)
sw $s2, 4($sp)
sw $t8, 8($sp)
sw $t6, 12($sp)
sw $t5, 16($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 8
sw $t6, 0($sp)
sw $t5, 4($sp)
# end - push function arguments
jal skipSum
# pop function arguments
addu $sp, $sp, 8
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t5, 16($sp)
lw $t6, 12($sp)
lw $t8, 8($sp)
lw $s2, 4($sp)
lw $s1, 0($sp)
addu $sp, $sp, 20
# end - restore registers
move $t3, $v0 # store return value of: skipSum
addu $t8, $t8, $t3
move $v0, $t8 # store return value
j label_150
label_146:
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
label_150:
addu $sp, $fp, 4 # pop function locals
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
jr $ra # return
.end skipSum



.globl main
.ent main
main:
subu $fp, $sp, 4 # set current frame pointer
li $s7, 1 # write 1 to register $s7
j label_164
label_164:
li $s6, 10 # write 10 to register $s6
# save registers
subu $sp, $sp, 8
sw $s7, 0($sp)
sw $s6, 4($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 8
sw $s7, 0($sp)
sw $s6, 4($sp)
# end - push function arguments
jal skipSum
# pop function arguments
addu $sp, $sp, 8
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s6, 4($sp)
lw $s7, 0($sp)
addu $sp, $sp, 8
# end - restore registers
move $s5, $v0 # store return value of: skipSum
# save registers
subu $sp, $sp, 12
sw $s6, 0($sp)
sw $s7, 4($sp)
sw $s5, 8($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $s5, 0($sp)
# end - push function arguments
jal printi
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s5, 8($sp)
lw $s7, 4($sp)
lw $s6, 0($sp)
addu $sp, $sp, 12
# end - restore registers
la $s4, str0
# save registers
subu $sp, $sp, 16
sw $s5, 0($sp)
sw $s7, 4($sp)
sw $s6, 8($sp)
sw $s4, 12($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $s4, 0($sp)
# end - push function arguments
jal print
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s4, 12($sp)
lw $s6, 8($sp)
lw $s7, 4($sp)
lw $s5, 0($sp)
addu $sp, $sp, 16
# end - restore registers
li $s3, 0 # write 0 to register $s3
j label_264
label_264:
li $s2, 40 # write 40 to register $s2
# save registers
subu $sp, $sp, 24
sw $s4, 0($sp)
sw $s6, 4($sp)
sw $s7, 8($sp)
sw $s5, 12($sp)
sw $s3, 16($sp)
sw $s2, 20($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 8
sw $s3, 0($sp)
sw $s2, 4($sp)
# end - push function arguments
jal skipSum
# pop function arguments
addu $sp, $sp, 8
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s2, 20($sp)
lw $s3, 16($sp)
lw $s5, 12($sp)
lw $s7, 8($sp)
lw $s6, 4($sp)
lw $s4, 0($sp)
addu $sp, $sp, 24
# end - restore registers
move $s1, $v0 # store return value of: skipSum
# save registers
subu $sp, $sp, 28
sw $s2, 0($sp)
sw $s3, 4($sp)
sw $s5, 8($sp)
sw $s7, 12($sp)
sw $s6, 16($sp)
sw $s4, 20($sp)
sw $s1, 24($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $s1, 0($sp)
# end - push function arguments
jal printi
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s1, 24($sp)
lw $s4, 20($sp)
lw $s6, 16($sp)
lw $s7, 12($sp)
lw $s5, 8($sp)
lw $s3, 4($sp)
lw $s2, 0($sp)
addu $sp, $sp, 28
# end - restore registers
la $s0, str1
# save registers
subu $sp, $sp, 32
sw $s1, 0($sp)
sw $s4, 4($sp)
sw $s6, 8($sp)
sw $s7, 12($sp)
sw $s5, 16($sp)
sw $s3, 20($sp)
sw $s2, 24($sp)
sw $s0, 28($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $s0, 0($sp)
# end - push function arguments
jal print
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s0, 28($sp)
lw $s2, 24($sp)
lw $s3, 20($sp)
lw $s5, 16($sp)
lw $s7, 12($sp)
lw $s6, 8($sp)
lw $s4, 4($sp)
lw $s1, 0($sp)
addu $sp, $sp, 32
# end - restore registers
li $t9, 1 # write 1 to register $t9
j label_388
label_388:
li $t8, 2 # write 2 to register $t8
# save registers
subu $sp, $sp, 40
sw $s0, 0($sp)
sw $s2, 4($sp)
sw $s3, 8($sp)
sw $s5, 12($sp)
sw $s7, 16($sp)
sw $s6, 20($sp)
sw $s4, 24($sp)
sw $s1, 28($sp)
sw $t9, 32($sp)
sw $t8, 36($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 8
sw $t9, 0($sp)
sw $t8, 4($sp)
# end - push function arguments
jal skipSum
# pop function arguments
addu $sp, $sp, 8
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t8, 36($sp)
lw $t9, 32($sp)
lw $s1, 28($sp)
lw $s4, 24($sp)
lw $s6, 20($sp)
lw $s7, 16($sp)
lw $s5, 12($sp)
lw $s3, 8($sp)
lw $s2, 4($sp)
lw $s0, 0($sp)
addu $sp, $sp, 40
# end - restore registers
move $t7, $v0 # store return value of: skipSum
# save registers
subu $sp, $sp, 44
sw $t8, 0($sp)
sw $t9, 4($sp)
sw $s1, 8($sp)
sw $s4, 12($sp)
sw $s6, 16($sp)
sw $s7, 20($sp)
sw $s5, 24($sp)
sw $s3, 28($sp)
sw $s2, 32($sp)
sw $s0, 36($sp)
sw $t7, 40($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $t7, 0($sp)
# end - push function arguments
jal printi
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t7, 40($sp)
lw $s0, 36($sp)
lw $s2, 32($sp)
lw $s3, 28($sp)
lw $s5, 24($sp)
lw $s7, 20($sp)
lw $s6, 16($sp)
lw $s4, 12($sp)
lw $s1, 8($sp)
lw $t9, 4($sp)
lw $t8, 0($sp)
addu $sp, $sp, 44
# end - restore registers
la $t6, str2
# save registers
subu $sp, $sp, 48
sw $t7, 0($sp)
sw $s0, 4($sp)
sw $s2, 8($sp)
sw $s3, 12($sp)
sw $s5, 16($sp)
sw $s7, 20($sp)
sw $s6, 24($sp)
sw $s4, 28($sp)
sw $s1, 32($sp)
sw $t9, 36($sp)
sw $t8, 40($sp)
sw $t6, 44($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $t6, 0($sp)
# end - push function arguments
jal print
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t6, 44($sp)
lw $t8, 40($sp)
lw $t9, 36($sp)
lw $s1, 32($sp)
lw $s4, 28($sp)
lw $s6, 24($sp)
lw $s7, 20($sp)
lw $s5, 16($sp)
lw $s3, 12($sp)
lw $s2, 8($sp)
lw $s0, 4($sp)
lw $t7, 0($sp)
addu $sp, $sp, 48
# end - restore registers
li $t5, 1 # write 1 to register $t5
j label_536
label_536:
li $t4, 0 # write 0 to register $t4
# save registers
subu $sp, $sp, 56
sw $t6, 0($sp)
sw $t8, 4($sp)
sw $t9, 8($sp)
sw $s1, 12($sp)
sw $s4, 16($sp)
sw $s6, 20($sp)
sw $s7, 24($sp)
sw $s5, 28($sp)
sw $s3, 32($sp)
sw $s2, 36($sp)
sw $s0, 40($sp)
sw $t7, 44($sp)
sw $t5, 48($sp)
sw $t4, 52($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 8
sw $t5, 0($sp)
sw $t4, 4($sp)
# end - push function arguments
jal skipSum
# pop function arguments
addu $sp, $sp, 8
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t4, 52($sp)
lw $t5, 48($sp)
lw $t7, 44($sp)
lw $s0, 40($sp)
lw $s2, 36($sp)
lw $s3, 32($sp)
lw $s5, 28($sp)
lw $s7, 24($sp)
lw $s6, 20($sp)
lw $s4, 16($sp)
lw $s1, 12($sp)
lw $t9, 8($sp)
lw $t8, 4($sp)
lw $t6, 0($sp)
addu $sp, $sp, 56
# end - restore registers
move $t3, $v0 # store return value of: skipSum
# save registers
subu $sp, $sp, 60
sw $t4, 0($sp)
sw $t5, 4($sp)
sw $t7, 8($sp)
sw $s0, 12($sp)
sw $s2, 16($sp)
sw $s3, 20($sp)
sw $s5, 24($sp)
sw $s7, 28($sp)
sw $s6, 32($sp)
sw $s4, 36($sp)
sw $s1, 40($sp)
sw $t9, 44($sp)
sw $t8, 48($sp)
sw $t6, 52($sp)
sw $t3, 56($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $t3, 0($sp)
# end - push function arguments
jal printi
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t3, 56($sp)
lw $t6, 52($sp)
lw $t8, 48($sp)
lw $t9, 44($sp)
lw $s1, 40($sp)
lw $s4, 36($sp)
lw $s6, 32($sp)
lw $s7, 28($sp)
lw $s5, 24($sp)
lw $s3, 20($sp)
lw $s2, 16($sp)
lw $s0, 12($sp)
lw $t7, 8($sp)
lw $t5, 4($sp)
lw $t4, 0($sp)
addu $sp, $sp, 60
# end - restore registers
la $t2, str3
# save registers
subu $sp, $sp, 64
sw $t3, 0($sp)
sw $t6, 4($sp)
sw $t8, 8($sp)
sw $t9, 12($sp)
sw $s1, 16($sp)
sw $s4, 20($sp)
sw $s6, 24($sp)
sw $s7, 28($sp)
sw $s5, 32($sp)
sw $s3, 36($sp)
sw $s2, 40($sp)
sw $s0, 44($sp)
sw $t7, 48($sp)
sw $t5, 52($sp)
sw $t4, 56($sp)
sw $t2, 60($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $t2, 0($sp)
# end - push function arguments
jal print
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t2, 60($sp)
lw $t4, 56($sp)
lw $t5, 52($sp)
lw $t7, 48($sp)
lw $s0, 44($sp)
lw $s2, 40($sp)
lw $s3, 36($sp)
lw $s5, 32($sp)
lw $s7, 28($sp)
lw $s6, 24($sp)
lw $s4, 20($sp)
lw $s1, 16($sp)
lw $t9, 12($sp)
lw $t8, 8($sp)
lw $t6, 4($sp)
lw $t3, 0($sp)
addu $sp, $sp, 64
# end - restore registers
li $t1, 0 # write 0 to register $t1
j label_708
label_708:
li $t0, 0 # write 0 to register $t0
# save registers
subu $sp, $sp, 72
sw $t2, 0($sp)
sw $t4, 4($sp)
sw $t5, 8($sp)
sw $t7, 12($sp)
sw $s0, 16($sp)
sw $s2, 20($sp)
sw $s3, 24($sp)
sw $s5, 28($sp)
sw $s7, 32($sp)
sw $s6, 36($sp)
sw $s4, 40($sp)
sw $s1, 44($sp)
sw $t9, 48($sp)
sw $t8, 52($sp)
sw $t6, 56($sp)
sw $t3, 60($sp)
sw $t1, 64($sp)
sw $t0, 68($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 8
sw $t1, 0($sp)
sw $t0, 4($sp)
# end - push function arguments
jal skipSum
# pop function arguments
addu $sp, $sp, 8
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t0, 68($sp)
lw $t1, 64($sp)
lw $t3, 60($sp)
lw $t6, 56($sp)
lw $t8, 52($sp)
lw $t9, 48($sp)
lw $s1, 44($sp)
lw $s4, 40($sp)
lw $s6, 36($sp)
lw $s7, 32($sp)
lw $s5, 28($sp)
lw $s3, 24($sp)
lw $s2, 20($sp)
lw $s0, 16($sp)
lw $t7, 12($sp)
lw $t5, 8($sp)
lw $t4, 4($sp)
lw $t2, 0($sp)
addu $sp, $sp, 72
# end - restore registers
move $s7, $v0 # store return value of: skipSum
# save registers
subu $sp, $sp, 4
sw $s7, 0($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $s7, 0($sp)
# end - push function arguments
jal printi
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s7, 0($sp)
addu $sp, $sp, 4
# end - restore registers
la $s6, str4
# save registers
subu $sp, $sp, 8
sw $s7, 0($sp)
sw $s6, 4($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $s6, 0($sp)
# end - push function arguments
jal print
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s6, 4($sp)
lw $s7, 0($sp)
addu $sp, $sp, 8
# end - restore registers
label_830:
addu $sp, $fp, 4 # pop function locals
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
li $v0, 10
syscall
.end main





# RegPool: on exit, pool contains 18 free registers
