	.file	"f5_5.c"
	.section	.rodata
.LC0:
	.string	"output error"
.LC1:
	.string	"input error"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4096, %rsp
	jmp	.L2
.L3:
	movq	stdout(%rip), %rdx
	leaq	-4096(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	cmpl	$-1, %eax
	jne	.L2
	movl	$.LC0, %edi
	movl	$0, %eax
	call	err_sys
.L2:
	movq	stdin(%rip), %rdx
	leaq	-4096(%rbp), %rax
	movl	$4096, %esi
	movq	%rax, %rdi
	call	fgets
	testq	%rax, %rax
	jne	.L3
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	ferror
	testl	%eax, %eax
	je	.L4
	movl	$.LC1, %edi
	movl	$0, %eax
	call	err_sys
.L4:
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
