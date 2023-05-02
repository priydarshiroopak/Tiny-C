	.file	"ass6_20CS30042_test6.c"

#	Allocation of function variables and temporaries on the stack:

#	fibNum
#	n: -4
#	t10: -8
#	t11: -12
#	t12: -16
#	t13: -20
#	t14: -24
#	t15: -28
#	t16: -32
#	t17: -36
#	t18: -40
#	t8: -44
#	t9: -48
#	main
#	end: -4
#	ep: -8
#	ff: -12
#	n: -16
#	start: -20
#	t19: -28
#	t20: -32
#	t21: -40
#	t22: -44
#	t23: -52
#	t24: -56
#	t25: -60
#	t26: -68
#	t27: -72
#	t28: -76
#	t29: -84
#	t30: -88
#	t31: -96
#	t32: -100
#	t33: -104
#	t34: -112
#	t35: -116
#	t36: -120
#	t37: -128
#	t38: -132
#	t39: -136
#	t40: -144
#	t41: -148
#	t42: -152
#	t43: -160
#	t44: -164
#	t45: -168
#	t46: -176
#	t47: -180
#	t49: -188
#	t50: -192
#	t51: -200
#	t52: -204
#	t53: -208
#	t54: -216
#	t55: -220
#	t56: -224
#	t57: -228
#	t58: -236
#	t59: -240
#	t60: -244
#	t61: -252
#	t62: -256
#	t63: -260
#	t64: -268
#	t65: -272
#	t66: -276
#	t67: -280
#	t68: -288
#	t69: -292
#	t70: -296
#	printInt
#	n: -4
#	printNums
#	curr: -4
#	t0: -12
#	t1: -20
#	t2: -24
#	t3: -32
#	t4: -36
#	t5: -40
#	t6: -44
#	till: -8
#	printStr
#	s: -8
#	readInt
#	eP: -8

	.section	.rodata
.LC0:
	.string	"\n"
.LC1:
	.string	" "
.LC2:
	.string	"\n#### TEST 6 (Recursive function calls) ####"
.LC3:
	.string	"\nEnter start: "
.LC4:
	.string	"Invalid start\n"
.LC5:
	.string	"Enter end: "
.LC6:
	.string	"Invalid end\n"
.LC7:
	.string	"Invalid range\n"
.LC8:
	.string	"Numbers from "
.LC9:
	.string	" to "
.LC10:
	.string	" are: "
.LC11:
	.string	"\n\nEnter value of n (<40) to find the nth fibonacci number: "
.LC12:
	.string	"Invalid n\n\n"
.LC13:
	.string	"n should be less than 40\n\n"
.LC14:
	.string	"\nfib("
.LC15:
	.string	") = "
.LC16:
	.string	"\n\n"
	.text
	.globl  printNums
	.type   printNums, @function
printNums:
.LFB0:
	.cfi_startproc
	pushq   %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq    %rsp, %rbp
	.cfi_def_cfa_register 6
	subq    $44, %rsp
	movl    %edi, -4(%rbp)
	movl    %esi, -8(%rbp)
	movl    -8(%rbp), %eax
	cmpl    %eax, -4(%rbp)
	jg      .L3
	jmp     .L4
.L3:
	jmp     .LFE0
	jmp     .L4
.L4:
	movl    -4(%rbp), %edi
	call    printInt
	movl    %eax, -12(%rbp)
	movl    -8(%rbp), %eax
	cmpl    %eax, -4(%rbp)
	je      .L5
	jmp     .L6
.L5:
	movq    $.LC0, -20(%rbp)
	movq    -20(%rbp), %rdi
	call    printStr
	movl    %eax, -24(%rbp)
	jmp     .LFE0
.L6:
	movq    $.LC1, -32(%rbp)
	movq    -32(%rbp), %rdi
	call    printStr
	movl    %eax, -36(%rbp)
	movl    $1, -40(%rbp)
	movl    -4(%rbp), %eax
	addl    -40(%rbp), %eax
	movl    %eax, -44(%rbp)
	movl    -8(%rbp), %esi
	movl    -44(%rbp), %edi
	call    printNums
.LFE0:
	movq    %rbp, %rsp
	popq    %rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
	.size   printNums, .-printNums
	.text
	.globl  fibNum
	.type   fibNum, @function
fibNum:
.LFB1:
	.cfi_startproc
	pushq   %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq    %rsp, %rbp
	.cfi_def_cfa_register 6
	subq    $48, %rsp
	movl    %edi, -4(%rbp)
	movl    $0, -44(%rbp)
	movl    -44(%rbp), %eax
	cmpl    %eax, -4(%rbp)
	je      .L7
	jmp     .L8
.L7:
	movl    $0, -48(%rbp)
	movl    -48(%rbp), %eax
	jmp     .LFE1
	jmp     .LFE1
.L8:
	movl    $1, -8(%rbp)
	movl    -8(%rbp), %eax
	cmpl    %eax, -4(%rbp)
	je      .L9
	jmp     .L10
.L9:
	movl    $1, -12(%rbp)
	movl    -12(%rbp), %eax
	jmp     .LFE1
	jmp     .LFE1
.L10:
	movl    $1, -16(%rbp)
	movl    -4(%rbp), %eax
	subl    -16(%rbp), %eax
	movl    %eax, -20(%rbp)
	movl    -20(%rbp), %edi
	call    fibNum
	movl    %eax, -24(%rbp)
	movl    $2, -28(%rbp)
	movl    -4(%rbp), %eax
	subl    -28(%rbp), %eax
	movl    %eax, -32(%rbp)
	movl    -32(%rbp), %edi
	call    fibNum
	movl    %eax, -36(%rbp)
	movl    -24(%rbp), %eax
	addl    -36(%rbp), %eax
	movl    %eax, -40(%rbp)
	movl    -40(%rbp), %eax
.LFE1:
	movq    %rbp, %rsp
	popq    %rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
	.size   fibNum, .-fibNum
	.text
	.globl  main
	.type   main, @function
main:
.LFB2:
	.cfi_startproc
	pushq   %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq    %rsp, %rbp
	.cfi_def_cfa_register 6
	subq    $296, %rsp
	movq    $.LC2, -28(%rbp)
	movq    -28(%rbp), %rdi
	call    printStr
	movl    %eax, -32(%rbp)
	movq    $.LC3, -40(%rbp)
	movq    -40(%rbp), %rdi
	call    printStr
	movl    %eax, -44(%rbp)
	leaq    -20(%rbp), %rax
	movq    %rax, -52(%rbp)
	movq    -52(%rbp), %rdi
	call    readInt
	movl    %eax, -56(%rbp)
	movl    -56(%rbp), %eax
	movl    %eax, -8(%rbp)
	movl    $0, -60(%rbp)
	movl    -60(%rbp), %eax
	cmpl    %eax, -8(%rbp)
	je      .L11
	jmp     .L12
.L11:
	movq    $.LC4, -68(%rbp)
	movq    -68(%rbp), %rdi
	call    printStr
	movl    %eax, -72(%rbp)
	movl    $0, -76(%rbp)
	movl    -76(%rbp), %eax
	jmp     .LFE2
	jmp     .L12
.L12:
	movq    $.LC5, -84(%rbp)
	movq    -84(%rbp), %rdi
	call    printStr
	movl    %eax, -88(%rbp)
	leaq    -4(%rbp), %rax
	movq    %rax, -96(%rbp)
	movq    -96(%rbp), %rdi
	call    readInt
	movl    %eax, -100(%rbp)
	movl    -100(%rbp), %eax
	movl    %eax, -8(%rbp)
	movl    $0, -104(%rbp)
	movl    -104(%rbp), %eax
	cmpl    %eax, -8(%rbp)
	je      .L13
	jmp     .L14
.L13:
	movq    $.LC6, -112(%rbp)
	movq    -112(%rbp), %rdi
	call    printStr
	movl    %eax, -116(%rbp)
	movl    $0, -120(%rbp)
	movl    -120(%rbp), %eax
	jmp     .LFE2
	jmp     .L14
.L14:
	movl    -4(%rbp), %eax
	cmpl    %eax, -20(%rbp)
	jg      .L15
	jmp     .L16
.L15:
	movq    $.LC7, -128(%rbp)
	movq    -128(%rbp), %rdi
	call    printStr
	movl    %eax, -132(%rbp)
	movl    $0, -136(%rbp)
	movl    -136(%rbp), %eax
	jmp     .LFE2
	jmp     .L16
.L16:
	movq    $.LC8, -144(%rbp)
	movq    -144(%rbp), %rdi
	call    printStr
	movl    %eax, -148(%rbp)
	movl    -20(%rbp), %edi
	call    printInt
	movl    %eax, -152(%rbp)
	movq    $.LC9, -160(%rbp)
	movq    -160(%rbp), %rdi
	call    printStr
	movl    %eax, -164(%rbp)
	movl    -4(%rbp), %edi
	call    printInt
	movl    %eax, -168(%rbp)
	movq    $.LC10, -176(%rbp)
	movq    -176(%rbp), %rdi
	call    printStr
	movl    %eax, -180(%rbp)
	movl    -4(%rbp), %esi
	movl    -20(%rbp), %edi
	call    printNums
	movq    $.LC11, -188(%rbp)
	movq    -188(%rbp), %rdi
	call    printStr
	movl    %eax, -192(%rbp)
	leaq    -16(%rbp), %rax
	movq    %rax, -200(%rbp)
	movq    -200(%rbp), %rdi
	call    readInt
	movl    %eax, -204(%rbp)
	movl    -204(%rbp), %eax
	movl    %eax, -8(%rbp)
	movl    $0, -208(%rbp)
	movl    -208(%rbp), %eax
	cmpl    %eax, -8(%rbp)
	je      .L17
	jmp     .L18
.L17:
	movq    $.LC12, -216(%rbp)
	movq    -216(%rbp), %rdi
	call    printStr
	movl    %eax, -220(%rbp)
	movl    $0, -224(%rbp)
	movl    -224(%rbp), %eax
	jmp     .LFE2
	jmp     .L19
.L18:
	movl    $40, -228(%rbp)
	movl    -228(%rbp), %eax
	cmpl    %eax, -16(%rbp)
	jge     .L20
	jmp     .L21
.L20:
	movq    $.LC13, -236(%rbp)
	movq    -236(%rbp), %rdi
	call    printStr
	movl    %eax, -240(%rbp)
	movl    $0, -244(%rbp)
	movl    -244(%rbp), %eax
	jmp     .LFE2
	jmp     .L19
.L21:
	movq    $.LC14, -252(%rbp)
	movq    -252(%rbp), %rdi
	call    printStr
	movl    %eax, -256(%rbp)
	movl    -16(%rbp), %edi
	call    printInt
	movl    %eax, -260(%rbp)
	movq    $.LC15, -268(%rbp)
	movq    -268(%rbp), %rdi
	call    printStr
	movl    %eax, -272(%rbp)
	movl    -16(%rbp), %edi
	call    fibNum
	movl    %eax, -276(%rbp)
	movl    -276(%rbp), %eax
	movl    %eax, -12(%rbp)
	movl    -12(%rbp), %edi
	call    printInt
	movl    %eax, -280(%rbp)
	movq    $.LC16, -288(%rbp)
	movq    -288(%rbp), %rdi
	call    printStr
	movl    %eax, -292(%rbp)
.L19:
	movl    $0, -296(%rbp)
	movl    -296(%rbp), %eax
.LFE2:
	movq    %rbp, %rsp
	popq    %rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
	.size   main, .-main
