.data
zeroDivErrStr: .asciiz "Error division by zero\n"
str0: .asciiz "zero"
str1: .asciiz "one"
str2: .asciiz "two"
str3: .asciiz "practically infinity"
str4: .asciiz "c"
str5: .asciiz "not c"
str6: .asciiz "\n"
str7: .asciiz "\n"


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



.globl switchMe
.ent switchMe
switchMe:
subu $fp, $sp, 4 # set current frame pointer
lw $s7, 4($fp) # load variable x. reg = $s7
j label_156
label_34:
la $s6, str0
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
j label_196
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
# break statement
j label_161
label_71:
la $s5, str1
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
lw $s5, 8($sp)
lw $s7, 4($sp)
lw $s6, 0($sp)
addu $sp, $sp, 12
# end - restore registers
j label_196
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
# break statement
j label_161
label_110:
la $s4, str2
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
j label_196
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
# break statement
j label_161
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
# Break out of switch statement
j label_161
label_156:
beq $s7, 0, label_34
beq $s7, 1, label_71
beq $s7, 2, label_110
# End of switch statement
label_161:
la $s3, str3
# save registers
subu $sp, $sp, 16
sw $s4, 0($sp)
sw $s6, 4($sp)
sw $s5, 8($sp)
sw $s3, 12($sp)
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
lw $s3, 12($sp)
lw $s5, 8($sp)
lw $s6, 4($sp)
lw $s4, 0($sp)
addu $sp, $sp, 16
# end - restore registers
label_196:
addu $sp, $fp, 4 # pop function locals
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
jr $ra # return
.end switchMe



.globl do
.ent do
do:
subu $fp, $sp, 4 # set current frame pointer
lw $s7, 4($fp) # load variable c. reg = $s7
bne $s7, $zero, label_211
j label_245
label_211:
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
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
label_245:
li $s5, 10 # write 10 to register $s5
# push local variable i
# push local variable: $s5
subu $sp, $sp, 4
sw $s5, ($sp)
label_251:
lw $s4, 4($fp) # load variable c. reg = $s4
bne $s4, $zero, label_255
j label_305
label_255:
lw $s3, 0($fp) # load variable i. reg = $s3
li $s2, 5 # write 5 to register $s2
bgt $s3, $s2, label_260
j label_305
label_260:
lw $s1, 0($fp) # load variable i. reg = $s1
# save registers
subu $sp, $sp, 20
sw $s6, 0($sp)
sw $s4, 4($sp)
sw $s3, 8($sp)
sw $s2, 12($sp)
sw $s1, 16($sp)
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
lw $s1, 16($sp)
lw $s2, 12($sp)
lw $s3, 8($sp)
lw $s4, 4($sp)
lw $s6, 0($sp)
addu $sp, $sp, 20
# end - restore registers
lw $s0, 0($fp) # load variable i. reg = $s0
li $t9, 2 # write 2 to register $t9
subu $s0, $s0, $t9
sw $s0, 0($fp) # update local variable
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
j label_251
label_305:
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
lw $t8, 4($fp) # load variable c. reg = $t8
xor $t8, $t8, 1
bne $t8, $zero, label_313
j label_351
label_313:
la $t7, str5
# save registers
subu $sp, $sp, 16
sw $s1, 0($sp)
sw $s6, 4($sp)
sw $t8, 8($sp)
sw $t7, 12($sp)
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
lw $t7, 12($sp)
lw $t8, 8($sp)
lw $s6, 4($sp)
lw $s1, 0($sp)
addu $sp, $sp, 16
# end - restore registers
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
label_351:
la $t6, str6
# save registers
subu $sp, $sp, 16
sw $t7, 0($sp)
sw $s6, 4($sp)
sw $s1, 8($sp)
sw $t6, 12($sp)
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
lw $t6, 12($sp)
lw $s1, 8($sp)
lw $s6, 4($sp)
lw $t7, 0($sp)
addu $sp, $sp, 16
# end - restore registers
label_386:
addu $sp, $fp, 4 # pop function locals
# unwind stack due to exiting a block
# total variables declared in block : 1
addu $sp, $sp, 4
jr $ra # return
.end do



.globl main
.ent main
main:
subu $fp, $sp, 4 # set current frame pointer
li $s7, 0 # write 0 to register $s7
# push local variable i
# push local variable: $s7
subu $sp, $sp, 4
sw $s7, ($sp)
label_403:
lw $s6, 0($fp) # load variable i. reg = $s6
li $s5, 4 # write 4 to register $s5
blt $s6, $s5, label_408
j label_484
label_408:
lw $s4, 0($fp) # load variable i. reg = $s4
# save registers
subu $sp, $sp, 12
sw $s6, 0($sp)
sw $s5, 4($sp)
sw $s4, 8($sp)
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
jal switchMe
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s4, 8($sp)
lw $s5, 4($sp)
lw $s6, 0($sp)
addu $sp, $sp, 12
# end - restore registers
la $s3, str7
# save registers
subu $sp, $sp, 16
sw $s4, 0($sp)
sw $s5, 4($sp)
sw $s6, 8($sp)
sw $s3, 12($sp)
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
lw $s3, 12($sp)
lw $s6, 8($sp)
lw $s5, 4($sp)
lw $s4, 0($sp)
addu $sp, $sp, 16
# end - restore registers
lw $s2, 0($fp) # load variable i. reg = $s2
li $s1, 1 # write 1 to register $s1
addu $s2, $s2, $s1
and $s2, $s2, 255
sw $s2, 0($fp) # update local variable
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
j label_403
label_484:
# unwind stack due to exiting a block
# total variables declared in block : 0
addu $sp, $sp, 0
li $s0, 1 # write 1 to register $s0
j label_490
label_490:
# save registers
subu $sp, $sp, 8
sw $s3, 0($sp)
sw $s4, 4($sp)
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
jal do
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s4, 4($sp)
lw $s3, 0($sp)
addu $sp, $sp, 8
# end - restore registers
li $t9, 0 # write 0 to register $t9
j label_522
label_522:
# save registers
subu $sp, $sp, 8
sw $s4, 0($sp)
sw $s3, 4($sp)
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
jal do
# pop function arguments
addu $sp, $sp, 4
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s3, 4($sp)
lw $s4, 0($sp)
addu $sp, $sp, 8
# end - restore registers
lw $t8, 0($fp) # load variable i. reg = $t8
li $t7, 4 # write 4 to register $t7
blt $t8, $t7, label_556
j label_559
label_556:
addu $t6, $zero, 1
j label_561
label_559:
addu $t6, $zero, 0
label_561:
# save registers
subu $sp, $sp, 12
sw $s3, 0($sp)
sw $s4, 4($sp)
sw $t6, 8($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 12
sw $t6, 0($sp)
sw $t8, 4($sp)
sw $t7, 8($sp)
# end - push function arguments
jal do
# pop function arguments
addu $sp, $sp, 12
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t6, 8($sp)
lw $s4, 4($sp)
lw $s3, 0($sp)
addu $sp, $sp, 12
# end - restore registers
lw $t5, 0($fp) # load variable i. reg = $t5
li $t4, 4 # write 4 to register $t4
bgt $t5, $t4, label_599
j label_602
label_599:
addu $t3, $zero, 1
j label_604
label_602:
addu $t3, $zero, 0
label_604:
# save registers
subu $sp, $sp, 16
sw $t6, 0($sp)
sw $s4, 4($sp)
sw $s3, 8($sp)
sw $t3, 12($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 12
sw $t3, 0($sp)
sw $t5, 4($sp)
sw $t4, 8($sp)
# end - push function arguments
jal do
# pop function arguments
addu $sp, $sp, 12
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $t3, 12($sp)
lw $s3, 8($sp)
lw $s4, 4($sp)
lw $t6, 0($sp)
addu $sp, $sp, 16
# end - restore registers
lw $t2, 0($fp) # load variable i. reg = $t2
li $t1, 4 # write 4 to register $t1
bgt $t2, $t1, label_649
j label_644
label_644:
lw $t0, 0($fp) # load variable i. reg = $t0
li $s7, 4 # write 4 to register $s7
beq $t0, $s7, label_649
j label_652
label_649:
addu $s1, $zero, 1
j label_654
label_652:
addu $s1, $zero, 0
label_654:
# save registers
subu $sp, $sp, 20
sw $t3, 0($sp)
sw $s3, 4($sp)
sw $s4, 8($sp)
sw $t6, 12($sp)
sw $s1, 16($sp)
# end - save registers
# push frame pointer
subu $sp, $sp, 4
sw $fp, ($sp)
# push return address
subu $sp, $sp, 4
sw $ra, ($sp)
# push function arguments
subu $sp, $sp, 20
sw $s1, 0($sp)
sw $t2, 4($sp)
sw $t1, 8($sp)
sw $t0, 12($sp)
sw $s7, 16($sp)
# end - push function arguments
jal do
# pop function arguments
addu $sp, $sp, 20
# pop return address
lw $ra, 0($sp)
addu $sp, $sp, 4
# pop frame pointer
lw $fp, 0($sp)
addu $sp, $sp, 4
# restore registers
lw $s1, 16($sp)
lw $t6, 12($sp)
lw $s4, 8($sp)
lw $s3, 4($sp)
lw $t3, 0($sp)
addu $sp, $sp, 20
# end - restore registers
label_694:
addu $sp, $fp, 4 # pop function locals
# unwind stack due to exiting a block
# total variables declared in block : 1
addu $sp, $sp, 4
li $v0, 10
syscall
.end main





# RegPool: on exit, pool contains 18 free registers
