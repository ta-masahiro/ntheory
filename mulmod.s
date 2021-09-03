	.file	"mulmod.c"
	.text
	#.p2align 4,,15
	.p2align 8,,15
	.globl	mulmod
	.type	mulmod, @function
mulmod:
.LFB0:
	.cfi_startproc
	movq	%rdi, %rax
	movq	%rdx, %rcx
	#xorl	%edx, %edx
	mulq	%rsi
	divq	%rcx
	movq	%rdx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	mulmod, .-mulmod
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
