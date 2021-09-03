	.file	"powermod.c"
	.text
	.p2align 4,,15
	.globl	powermod
	.type	powermod, @function
powermod:
.LFB0:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movl	$1, %r13d
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %rbp
	movq	%rsi, %rbx
	movq	%rdx, %r12
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	testq	%rsi, %rsi
	jne	.L2
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L4:
	movq	%rbp, %rsi
	movq	%rbp, %rdi
	movq	%r12, %rdx
	call	mulmod@PLT
	shrq	%rbx
	movq	%rax, %rbp
	je	.L3
.L2:
	testb	$1, %bl
	je	.L4
	movq	%r13, %rdi
	movq	%r12, %rdx
	movq	%rbp, %rsi
	call	mulmod@PLT
	movq	%rax, %r13
	jmp	.L4
	.p2align 4,,10
	.p2align 3
.L3:
	movq	%r13, %rax
	xorl	%edx, %edx
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	divq	%r12
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	movq	%rdx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	powermod, .-powermod
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
