	.file	"batt_update.c"
	.text
	.globl	batt_update
	.type	batt_update, @function
batt_update:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movw	$0, -12(%rbp)
	movb	$0, -9(%rbp)
	movb	$0, -10(%rbp)
	leaq	-12(%rbp), %rax
	movq	%rax, %rdi
	call	set_batt_from_ports
	cmpl	$1, %eax
	je	.L2
	movl	-12(%rbp), %eax
	leaq	BATT_DISPLAY_PORT(%rip), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	set_display_from_batt
	movl	$0, %eax
	jmp	.L4
.L2:
	movl	$1, %eax
.L4:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	batt_update, .-batt_update
	.globl	set_batt_from_ports
	.type	set_batt_from_ports, @function
set_batt_from_ports:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movzwl	BATT_VOLTAGE_PORT(%rip), %eax
	testw	%ax, %ax
	js	.L7
	movzwl	BATT_VOLTAGE_PORT(%rip), %eax
	sarw	%ax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movw	%dx, (%rax)
	movq	-8(%rbp), %rax
	movzwl	(%rax), %eax
	cmpw	$2999, %ax
	jg	.L8
	movq	-8(%rbp), %rax
	movb	$0, 2(%rax)
	jmp	.L9
.L8:
	movq	-8(%rbp), %rax
	movzwl	(%rax), %eax
	cwtl
	subl	$3000, %eax
	sarl	$3, %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movb	%dl, 2(%rax)
.L9:
	movq	-8(%rbp), %rax
	movzbl	2(%rax), %eax
	cmpb	$100, %al
	jle	.L10
	movq	-8(%rbp), %rax
	movb	$100, 2(%rax)
.L10:
	movzbl	BATT_STATUS_PORT(%rip), %eax
	movzbl	%al, %eax
	andl	$16, %eax
	testl	%eax, %eax
	je	.L11
	movl	$1, %edx
	jmp	.L12
.L11:
	movl	$2, %edx
.L12:
	movq	-8(%rbp), %rax
	movb	%dl, 3(%rax)
	movl	$0, %eax
	jmp	.L13
.L7:
	movl	$1, %eax
.L13:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	set_batt_from_ports, .-set_batt_from_ports
	.globl	set_display_from_batt
	.type	set_display_from_batt, @function
set_display_from_batt:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movl	%edi, -116(%rbp)
	movq	%rsi, -128(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$100, -108(%rbp)
	movq	-128(%rbp), %rax
	movl	$0, (%rax)
	movl	$63, -48(%rbp)
	movl	$6, -44(%rbp)
	movl	$91, -40(%rbp)
	movl	$79, -36(%rbp)
	movl	$102, -32(%rbp)
	movl	$109, -28(%rbp)
	movl	$125, -24(%rbp)
	movl	$7, -20(%rbp)
	movl	$127, -16(%rbp)
	movl	$111, -12(%rbp)
	movl	$5, -80(%rbp)
	movl	$30, -76(%rbp)
	movl	$50, -72(%rbp)
	movl	$70, -68(%rbp)
	movl	$90, -64(%rbp)
	movl	$0, -104(%rbp)
	jmp	.L15
.L17:
	movq	-128(%rbp), %rax
	movl	(%rax), %edx
	movl	-104(%rbp), %eax
	addl	$24, %eax
	movl	$1, %esi
	movl	%eax, %ecx
	sall	%cl, %esi
	movl	%esi, %eax
	orl	%eax, %edx
	movq	-128(%rbp), %rax
	movl	%edx, (%rax)
	addl	$1, -104(%rbp)
.L15:
	cmpl	$4, -104(%rbp)
	jg	.L16
	movzbl	-114(%rbp), %eax
	movsbl	%al, %edx
	movl	-104(%rbp), %eax
	cltq
	movl	-80(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jge	.L17
.L16:
	movzbl	-113(%rbp), %eax
	cmpb	$2, %al
	jne	.L18
	movzwl	-116(%rbp), %eax
	cwtl
	movl	%eax, -100(%rbp)
	movl	-100(%rbp), %ecx
	movslq	%ecx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	sarl	$2, %eax
	movl	%ecx, %esi
	sarl	$31, %esi
	subl	%esi, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	cmpl	$4, %edx
	jle	.L19
	addl	$10, -100(%rbp)
.L19:
	movl	-100(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$2, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, -100(%rbp)
	movl	$14, -96(%rbp)
	jmp	.L20
.L21:
	movq	-128(%rbp), %rax
	movl	(%rax), %esi
	movl	-100(%rbp), %eax
	cltd
	idivl	-108(%rbp)
	cltq
	movl	-48(%rbp,%rax,4), %edx
	movl	-96(%rbp), %eax
	addl	$3, %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	orl	%eax, %esi
	movl	%esi, %edx
	movq	-128(%rbp), %rax
	movl	%edx, (%rax)
	movl	-100(%rbp), %eax
	cltd
	idivl	-108(%rbp)
	movl	%edx, -100(%rbp)
	movl	-108(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$2, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, -108(%rbp)
	subl	$7, -96(%rbp)
.L20:
	cmpl	$0, -96(%rbp)
	jns	.L21
	movq	-128(%rbp), %rax
	movl	(%rax), %eax
	orl	$6, %eax
	movl	%eax, %edx
	movq	-128(%rbp), %rax
	movl	%edx, (%rax)
	jmp	.L22
.L18:
	movzbl	-114(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, -92(%rbp)
	movl	$0, -88(%rbp)
	movl	$14, -84(%rbp)
	jmp	.L23
.L26:
	cmpl	$0, -108(%rbp)
	jle	.L24
	movl	-92(%rbp), %eax
	cltd
	idivl	-108(%rbp)
	testl	%eax, %eax
	jne	.L25
	cmpl	$1, -88(%rbp)
	jne	.L24
.L25:
	movq	-128(%rbp), %rax
	movl	(%rax), %esi
	movl	-92(%rbp), %eax
	cltd
	idivl	-108(%rbp)
	cltq
	movl	-48(%rbp,%rax,4), %edx
	movl	-84(%rbp), %eax
	addl	$3, %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	orl	%eax, %esi
	movl	%esi, %edx
	movq	-128(%rbp), %rax
	movl	%edx, (%rax)
	movl	-92(%rbp), %eax
	cltd
	idivl	-108(%rbp)
	movl	%edx, -92(%rbp)
	movl	$1, -88(%rbp)
.L24:
	movl	-108(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$2, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, -108(%rbp)
	subl	$7, -84(%rbp)
.L23:
	cmpl	$0, -84(%rbp)
	jns	.L26
	cmpl	$0, -88(%rbp)
	jne	.L27
	movq	-128(%rbp), %rax
	movl	(%rax), %edx
	movl	-48(%rbp), %eax
	sall	$3, %eax
	orl	%eax, %edx
	movq	-128(%rbp), %rax
	movl	%edx, (%rax)
.L27:
	movq	-128(%rbp), %rax
	movl	(%rax), %eax
	orl	$1, %eax
	movl	%eax, %edx
	movq	-128(%rbp), %rax
	movl	%edx, (%rax)
.L22:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L29
	call	__stack_chk_fail@PLT
.L29:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	set_display_from_batt, .-set_display_from_batt
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
