	.file	"miller_rabin.c"
	.text
	.p2align 4,,15
	.globl	miller_rabin
	.type	miller_rabin, @function
miller_rabin:
.LFB0:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	leaq	-1(%rdi), %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	$-1, %ebp
	movq	%rdi, %rbx
	movq	%r13, %r12
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	testb	$1, %r13b
	jne	.L2
	xorl	%ebp, %ebp
	.p2align 4,,10
	.p2align 3
.L3:
	shrq	%r12
	addl	$1, %ebp
	testb	$1, %r12b
	je	.L3
	subl	$1, %ebp
.L2:
	movq	%rsi, %r14
	movq	(%r14), %rdi
	testq	%rdi, %rdi
	je	.L13
	.p2align 4,,10
	.p2align 3
.L26:
	cmpq	%rdi, %rbx
	je	.L13
	movq	%rbx, %rdx
	movq	%r12, %rsi
	call	powermod@PLT
	cmpq	$1, %rax
	je	.L5
	cmpq	%rax, %r13
	je	.L5
	testl	%ebp, %ebp
	jle	.L8
	xorl	%r15d, %r15d
	jmp	.L6
	.p2align 4,,10
	.p2align 3
.L25:
	addl	$1, %r15d
	cmpl	%ebp, %r15d
	je	.L8
.L6:
	movq	%rbx, %rdx
	movq	%rax, %rsi
	movq	%rax, %rdi
	call	mulmod@PLT
	cmpq	%rax, %r13
	jne	.L25
	.p2align 4,,10
	.p2align 3
.L5:
	addq	$8, %r14
	movq	(%r14), %rdi
	testq	%rdi, %rdi
	jne	.L26
.L13:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movl	$1, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L8:
	.cfi_restore_state
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	miller_rabin, .-miller_rabin
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
