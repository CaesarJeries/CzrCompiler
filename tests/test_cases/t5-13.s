.data
zeroDivErrStr: .asciiz "Error division by zero\n"
str0: .asciiz "\n"
str1: .asciiz "\n"


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



.globl getInt
.ent getInt
getInt:
subu $fp, $sp, 4 # set current frame pointer
lw $s7, 4($fp) # load variable arg. reg = $s7
move $v0, $s7 # store return value
j label_35
label_35:
addu $sp, $fp, 4 # pop function locals
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
jr $ra # return
.end getInt



.globl getSwitched
.ent getSwitched
getSwitched:
subu $fp, $sp, 4 # set current frame pointer
lw $s7, 4($fp) # load variable arg. reg = $s7
lw $s6, 4($fp) # load variable arg. reg = $s6
li $s5, 10 # write 10 to register $s5
beqz $s5, zeroDivErr
divu $s6, $s6, $s5
li $s4, 10 # write 10 to register $s4
mul $s6, $s6, $s4
subu $s7, $s7, $s6
# push local variable toSwitch
# push local variable: $s7
subu $sp, $sp, 4
sw $s7, ($sp)
lw $s3, 0($fp) # load variable toSwitch. reg = $s3
j label_96
label_61:
li $s2, 11 # write 11 to register $s2
move $v0, $s2 # store return value
j label_107
# break statement
j label_103
label_67:
li $s1, 12 # write 12 to register $s1
move $v0, $s1 # store return value
j label_107
# break statement
j label_103
label_73:
li $s0, 13 # write 13 to register $s0
move $v0, $s0 # store return value
j label_107
# break statement
j label_103
label_79:
li $t9, 14 # write 14 to register $t9
move $v0, $t9 # store return value
j label_107
# break statement
j label_103
label_85:
li $t8, 15 # write 15 to register $t8
move $v0, $t8 # store return value
j label_107
# break statement
j label_103
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
# Break out of switch statement
j label_103
label_96:
beq $s3, 0, label_61
beq $s3, 1, label_67
beq $s3, 2, label_73
beq $s3, 3, label_79
beq $s3, 4, label_85
# End of switch statement
label_103:
li $t7, 0 # write 0 to register $t7
move $v0, $t7 # store return value
j label_107
label_107:
addu $sp, $fp, 4 # pop function locals
# unwind stack due to exiting a block
# total variables declared in block : 1
addu $sp, $sp, 4
jr $ra # return
.end getSwitched



.globl main
.ent main
main:
subu $fp, $sp, 4 # set current frame pointer
li $s7, 100 # write 100 to register $s7
# push local variable x
# push local variable: $s7
subu $sp, $sp, 4
sw $s7, ($sp)
lw $s6, 0($fp) # load variable x. reg = $s6
lw $s5, 0($fp) # load variable x. reg = $s5
# save registers
subu $sp, $sp, 8
sw $s6, 0($sp)
sw $s5, 4($sp)
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
jal getInt
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s5, 4($sp)
lw $s6, 0($sp)
addu $sp, $sp, 8
# end - restore registers
move $s4, $v0 # store return value of: getInt
mul $s6, $s6, $s4
lw $s3, 0($fp) # load variable x. reg = $s3
# save registers
subu $sp, $sp, 12
sw $s5, 0($sp)
sw $s6, 4($sp)
sw $s3, 8($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $s3, 0($sp)
# end - push function arguments
jal getSwitched
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s3, 8($sp)
lw $s6, 4($sp)
lw $s5, 0($sp)
addu $sp, $sp, 12
# end - restore registers
move $s2, $v0 # store return value of: getSwitched
addu $s6, $s6, $s2
# save registers
subu $sp, $sp, 12
sw $s3, 0($sp)
sw $s6, 4($sp)
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
sw $s6, 0($sp)
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
lw $s6, 4($sp)
lw $s3, 0($sp)
addu $sp, $sp, 12
# end - restore registers
la $s1, str0
# save registers
subu $sp, $sp, 16
sw $s5, 0($sp)
sw $s6, 4($sp)
sw $s3, 8($sp)
sw $s1, 12($sp)
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
lw $s1, 12($sp)
lw $s3, 8($sp)
lw $s6, 4($sp)
lw $s5, 0($sp)
addu $sp, $sp, 16
# end - restore registers
li $s0, 12 # write 12 to register $s0
sw $s0, 0($fp) # update local variable
lw $t9, 0($fp) # load variable x. reg = $t9
lw $t8, 0($fp) # load variable x. reg = $t8
# save registers
subu $sp, $sp, 24
sw $s1, 0($sp)
sw $s3, 4($sp)
sw $s6, 8($sp)
sw $s5, 12($sp)
sw $t9, 16($sp)
sw $t8, 20($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $t8, 0($sp)
# end - push function arguments
jal getInt
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t8, 20($sp)
lw $t9, 16($sp)
lw $s5, 12($sp)
lw $s6, 8($sp)
lw $s3, 4($sp)
lw $s1, 0($sp)
addu $sp, $sp, 24
# end - restore registers
move $t7, $v0 # store return value of: getInt
mul $t9, $t9, $t7
lw $t6, 0($fp) # load variable x. reg = $t6
# save registers
subu $sp, $sp, 28
sw $t8, 0($sp)
sw $t9, 4($sp)
sw $s5, 8($sp)
sw $s6, 12($sp)
sw $s3, 16($sp)
sw $s1, 20($sp)
sw $t6, 24($sp)
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
jal getSwitched
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t6, 24($sp)
lw $s1, 20($sp)
lw $s3, 16($sp)
lw $s6, 12($sp)
lw $s5, 8($sp)
lw $t9, 4($sp)
lw $t8, 0($sp)
addu $sp, $sp, 28
# end - restore registers
move $t5, $v0 # store return value of: getSwitched
addu $t9, $t9, $t5
lw $t4, 0($fp) # load variable x. reg = $t4
li $t3, 1 # write 1 to register $t3
subu $t4, $t4, $t3
# save registers
subu $sp, $sp, 32
sw $t6, 0($sp)
sw $s1, 4($sp)
sw $s3, 8($sp)
sw $s6, 12($sp)
sw $s5, 16($sp)
sw $t9, 20($sp)
sw $t8, 24($sp)
sw $t4, 28($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $t4, 0($sp)
# end - push function arguments
jal getSwitched
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t4, 28($sp)
lw $t8, 24($sp)
lw $t9, 20($sp)
lw $s5, 16($sp)
lw $s6, 12($sp)
lw $s3, 8($sp)
lw $s1, 4($sp)
lw $t6, 0($sp)
addu $sp, $sp, 32
# end - restore registers
move $t2, $v0 # store return value of: getSwitched
li $t1, 2 # write 2 to register $t1
beqz $t1, zeroDivErr
divu $t2, $t2, $t1
subu $t9, $t9, $t2
# save registers
subu $sp, $sp, 32
sw $t4, 0($sp)
sw $t8, 4($sp)
sw $t9, 8($sp)
sw $s5, 12($sp)
sw $s6, 16($sp)
sw $s3, 20($sp)
sw $s1, 24($sp)
sw $t6, 28($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $t9, 0($sp)
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
lw $t6, 28($sp)
lw $s1, 24($sp)
lw $s3, 20($sp)
lw $s6, 16($sp)
lw $s5, 12($sp)
lw $t9, 8($sp)
lw $t8, 4($sp)
lw $t4, 0($sp)
addu $sp, $sp, 32
# end - restore registers
la $t0, str1
# save registers
subu $sp, $sp, 36
sw $t6, 0($sp)
sw $s1, 4($sp)
sw $s3, 8($sp)
sw $s6, 12($sp)
sw $s5, 16($sp)
sw $t9, 20($sp)
sw $t8, 24($sp)
sw $t4, 28($sp)
sw $t0, 32($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 4
sw $t0, 0($sp)
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
lw $t0, 32($sp)
lw $t4, 28($sp)
lw $t8, 24($sp)
lw $t9, 20($sp)
lw $s5, 16($sp)
lw $s6, 12($sp)
lw $s3, 8($sp)
lw $s1, 4($sp)
lw $t6, 0($sp)
addu $sp, $sp, 36
# end - restore registers
label_475:
addu $sp, $fp, 4 # pop function locals
# unwind stack due to exiting a block
# total variables declared in block : 1
addu $sp, $sp, 4
li $v0, 10
syscall
.end main





# RegPool: on exit, pool contains 18 free registers
