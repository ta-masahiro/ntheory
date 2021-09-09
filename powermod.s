	.file	"powermod.c"
	.text
	.p2align 4,,15
	.globl	powermod
	.type	powermod, @function
powermod:
.LFB0:
	.cfi_startproc
	movq	%rdx, %r8	# n: 	%r8
	movq	$1, %r9		# ans:	%r9
	movq	%rsi, %rcx	# m: 	%rcx
.L4: 
	testq	%rsi, %rsi	#  m == 0 ?
	je	.L3				#  -> loop end

	testb	$1, %cl		# m % 2 == 0
	je	.L2
	movq	%r9, %rax
	mulq	%rdi		# rdx: rax <- apow * ans 
	divq	%r8			# rdx <- (apoq * ans) % n 
	movq	%rdx, %r9	# ans  = (apow * ans) % n

.L2: 
	movq	%rdi, %rax	# 
	mulq	%rdi		# rdx: rax <- apow * apow 
	divq	%r8			# rdx <- (apow * apow) % n 
	movq	%rdx, %rdi	# apow = (apow * apow) % n

	shrq	%rcx		# m /= 2
	jne	.L4				# (m /= 2) != 0 -> .L4
.L3:
	movq	%r9, %rax
	xorl	%edx, %edx
	divq	%r8
	movq	%rdx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	powermod, .-powermod
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
