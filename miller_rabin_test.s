	.file	"miller_rabin_test.c"
	.text
	.p2align 4,,15
	.globl	powermod
	.type	powermod, @function
powermod:
.LFB41:
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
.LFE41:
	.size	powermod, .-powermod
	.p2align 4,,15
	.globl	miller_rabin
	.type	miller_rabin, @function
miller_rabin:
.LFB42:
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
	movq	%rdi, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	testb	$1, %r13b
	movq	%r13, (%rsp)
	jne	.L24
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L13:
	shrq	(%rsp)
	addl	$1, %r12d
	movq	(%rsp), %rax
	testb	$1, %al
	je	.L13
	leal	-1(%r12), %eax
	movl	%eax, 12(%rsp)
.L12:
	movq	%rsi, %r15
	movq	(%r15), %r12
	cmpq	%r12, %rbx
	je	.L27
	.p2align 4,,10
	.p2align 3
.L40:
	testq	%r12, %r12
	je	.L27
	movq	(%rsp), %r14
	movl	$1, %ebp
	jmp	.L22
	.p2align 4,,10
	.p2align 3
.L15:
	movq	%r12, %rsi
	movq	%r12, %rdi
	movq	%rbx, %rdx
	call	mulmod@PLT
	shrq	%r14
	movq	%rax, %r12
	je	.L38
.L22:
	testb	$1, %r14b
	je	.L15
	movq	%rbp, %rdi
	movq	%rbx, %rdx
	movq	%r12, %rsi
	call	mulmod@PLT
	movq	%rax, %rbp
	jmp	.L15
	.p2align 4,,10
	.p2align 3
.L38:
	xorl	%edx, %edx
	movq	%rbp, %rax
	divq	%rbx
	cmpq	%rdx, %r13
	movq	%rdx, %rdi
	je	.L18
	cmpq	$1, %rdx
	je	.L18
	movl	12(%rsp), %eax
	testl	%eax, %eax
	jle	.L21
	xorl	%ebp, %ebp
	jmp	.L19
	.p2align 4,,10
	.p2align 3
.L39:
	addl	$1, %ebp
	cmpl	12(%rsp), %ebp
	je	.L21
.L19:
	movq	%rdi, %rsi
	movq	%rbx, %rdx
	call	mulmod@PLT
	cmpq	%rax, %r13
	movq	%rax, %rdi
	jne	.L39
	.p2align 4,,10
	.p2align 3
.L18:
	addq	$8, %r15
	movq	(%r15), %r12
	cmpq	%r12, %rbx
	jne	.L40
.L27:
	addq	$24, %rsp
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
.L21:
	.cfi_restore_state
	addq	$24, %rsp
	.cfi_remember_state
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
.L24:
	.cfi_restore_state
	movl	$-1, 12(%rsp)
	jmp	.L12
	.cfi_endproc
.LFE42:
	.size	miller_rabin, .-miller_rabin
	.p2align 4,,15
	.globl	is_prime
	.type	is_prime, @function
is_prime:
.LFB43:
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
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$280, %rsp
	.cfi_def_cfa_offset 336
	movdqa	.LC0(%rip), %xmm0
	movq	%fs:40, %rax
	movq	%rax, 264(%rsp)
	xorl	%eax, %eax
	movaps	%xmm0, (%rsp)
	cmpq	$5, %rdi
	movaps	%xmm0, 32(%rsp)
	movdqa	.LC2(%rip), %xmm0
	movaps	%xmm0, 48(%rsp)
	movdqa	.LC3(%rip), %xmm0
	movdqa	.LC1(%rip), %xmm1
	movaps	%xmm0, 64(%rsp)
	movaps	%xmm1, 16(%rsp)
	movdqa	.LC4(%rip), %xmm0
	movaps	%xmm0, 80(%rsp)
	ja	.L42
	movl	$1, %edx
	movl	%edi, %ecx
	movl	$1, %eax
	salq	%cl, %rdx
	testb	$44, %dl
	jne	.L41
	xorl	%eax, %eax
	andl	$18, %edx
	jne	.L41
.L42:
	movq	%rbx, %rax
	movabsq	$-8608480567731124087, %rdx
	movq	%rbx, %rcx
	mulq	%rdx
	shrq	$4, %rdx
	movq	%rdx, %rax
	salq	$4, %rax
	subq	%rdx, %rax
	addq	%rax, %rax
	subq	%rax, %rcx
	movl	$1, %eax
	salq	%cl, %rax
	movq	%rax, %rdx
	xorl	%eax, %eax
	testl	$545925250, %edx
	jne	.L55
.L41:
	movq	264(%rsp), %rsi
	xorq	%fs:40, %rsi
	jne	.L56
	addq	$280, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
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
.L55:
	.cfi_restore_state
	movabsq	$4759123140, %rax
	movq	%rsp, %rsi
	cmpq	%rax, %rbx
	jbe	.L44
	movabsq	$341550071728320, %rax
	leaq	32(%rsp), %rsi
	cmpq	%rax, %rbx
	jbe	.L44
	leaq	96(%rsp), %r14
	leaq	-2(%rbx), %r13
	leaq	160(%r14), %r12
	movq	%r14, %rbp
	.p2align 4,,10
	.p2align 3
.L45:
	call	rand@PLT
	movl	%eax, %r15d
	addq	$8, %rbp
	call	rand@PLT
	movslq	%r15d, %rsi
	movslq	%eax, %rdi
	movq	%r13, %rdx
	call	mulmod@PLT
	addq	$1, %rax
	movq	%rax, -8(%rbp)
	cmpq	%rbp, %r12
	jne	.L45
	movq	$0, 256(%rsp)
	movq	%r14, %rsi
.L44:
	movq	%rbx, %rdi
	call	miller_rabin
	jmp	.L41
.L56:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE43:
	.size	is_prime, .-is_prime
	.p2align 4,,15
	.globl	next_prime
	.type	next_prime, @function
next_prime:
.LFB44:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	leaq	1(%rdi), %rbx
	jmp	.L59
	.p2align 4,,10
	.p2align 3
.L62:
	addq	$1, %rbx
.L59:
	movq	%rbx, %rdi
	call	is_prime
	testl	%eax, %eax
	je	.L62
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE44:
	.size	next_prime, .-next_prime
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC5:
	.string	"____test of IS_PRIME___"
.LC6:
	.string	"%ld "
.LC7:
	.string	"\n%ld\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB45:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movl	$10, %edx
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rsi, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	movq	8(%rsi), %rdi
	xorl	%esi, %esi
	call	strtol@PLT
	movq	16(%rbp), %rdi
	xorl	%esi, %esi
	movl	$10, %edx
	movq	%rax, %rbx
	call	strtol@PLT
	movq	24(%rbp), %rdi
	xorl	%esi, %esi
	movl	$10, %edx
	movq	%rax, %r12
	call	strtol@PLT
	xorl	%edi, %edi
	movq	%rax, %rbp
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	cmpq	%r12, %rbx
	jnb	.L70
	testl	%ebp, %ebp
	movl	$0, %ebp
	jne	.L71
	.p2align 4,,10
	.p2align 3
.L67:
	movq	%rbx, %rdi
	call	is_prime
	cmpl	$1, %eax
	sbbq	$-1, %rbp
	addq	$1, %rbx
	cmpq	%rbx, %r12
	jne	.L67
.L64:
	leaq	.LC7(%rip), %rsi
	movq	%rbp, %rdx
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L71:
	.cfi_restore_state
	leaq	.LC6(%rip), %r13
	.p2align 4,,10
	.p2align 3
.L65:
	movq	%rbx, %rdi
	call	is_prime
	testl	%eax, %eax
	je	.L69
	movq	%rbx, %rdx
	movq	%r13, %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	addq	$1, %rbp
	call	__printf_chk@PLT
.L69:
	addq	$1, %rbx
	cmpq	%rbx, %r12
	jne	.L65
	jmp	.L64
.L70:
	xorl	%ebp, %ebp
	jmp	.L64
	.cfi_endproc
.LFE45:
	.size	main, .-main
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.quad	2
	.quad	3
	.align 16
.LC1:
	.quad	61
	.quad	0
	.align 16
.LC2:
	.quad	5
	.quad	7
	.align 16
.LC3:
	.quad	11
	.quad	13
	.align 16
.LC4:
	.quad	17
	.quad	0
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
