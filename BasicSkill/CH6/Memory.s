	.file	"Memory.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\12\0"
.LC1:
	.ascii "%d %d\12\0"
.LC2:
	.ascii "%d element : %d\11%s\12\0"
.LC3:
	.ascii "%c \0"
.LC4:
	.ascii "%d %d %d %d %d %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$280, %rsp
	.seh_stackalloc	280
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	movl	$40, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$40, %ecx
	call	malloc
	movq	%rax, 120(%rbp)
	cmpq	$0, 120(%rbp)
	je	.L2
	movq	120(%rbp), %rax
	addq	$8, %rax
	movl	$50, (%rax)
	movq	120(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
.L2:
	movq	120(%rbp), %rax
	movl	$400, %edx
	movq	%rax, %rcx
	call	realloc
	movq	%rax, 120(%rbp)
	movq	120(%rbp), %rax
	addq	$120, %rax
	movl	$75, (%rax)
	movq	120(%rbp), %rax
	addq	$120, %rax
	movl	(%rax), %edx
	movq	120(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
	movq	120(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$2, 116(%rbp)
	movabsq	$2338328219631577172, %rax
	movq	%rax, -16(%rbp)
	movabsq	$8386104319403257449, %rax
	movq	%rax, -8(%rbp)
	movl	$7237481, 0(%rbp)
	movl	116(%rbp), %eax
	cltq
	movl	$16, %edx
	movq	%rax, %rcx
	call	calloc
	movq	%rax, 104(%rbp)
	cmpq	$0, 104(%rbp)
	je	.L3
	movl	$0, 140(%rbp)
	jmp	.L4
.L5:
	movl	140(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	104(%rbp), %rax
	addq	%rdx, %rax
	movl	140(%rbp), %edx
	movl	%edx, (%rax)
	movl	140(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	104(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	$20, %ecx
	call	malloc
	movq	%rax, 8(%rbx)
	movl	140(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	104(%rbp), %rax
	addq	%rdx, %rax
	movq	8(%rax), %rcx
	leaq	-16(%rbp), %rax
	movq	%rax, %rdx
	call	strcpy
	movl	140(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	104(%rbp), %rax
	addq	%rdx, %rax
	movq	8(%rax), %rcx
	movl	140(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	104(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	140(%rbp), %eax
	movq	%rcx, %r9
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	addl	$1, 140(%rbp)
.L4:
	movl	140(%rbp), %eax
	cmpl	116(%rbp), %eax
	jl	.L5
.L3:
	movq	$0, 96(%rbp)
	leaq	-48(%rbp), %rax
	movl	$875770417, (%rax)
	movb	$0, 4(%rax)
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	printf
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	addq	$1, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, 96(%rbp)
	leaq	-48(%rbp), %rax
	movq	96(%rbp), %rcx
	movq	%rax, %rdx
	call	strcpy
	movq	96(%rbp), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, -56(%rbp)
	movl	$4, %edx
	movl	$1, %ecx
	call	calloc
	movq	%rax, -64(%rbp)
	movl	$1, -52(%rbp)
	movl	-52(%rbp), %eax
	addl	$5, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	realloc
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	testq	%rax, %rax
	je	.L7
	movl	-52(%rbp), %eax
	addl	$5, %eax
	movl	%eax, -52(%rbp)
	jmp	.L7
.L8:
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movl	$50, (%rax)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-56(%rbp), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
.L7:
	movl	-56(%rbp), %edx
	movl	-52(%rbp), %eax
	cmpl	%eax, %edx
	jl	.L8
	movl	$2, 92(%rbp)
	movl	$5, 88(%rbp)
	movl	92(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, 80(%rbp)
	movl	88(%rbp), %eax
	cltq
	movq	%rax, %rcx
	call	malloc
	movq	%rax, %rdx
	movq	80(%rbp), %rax
	movq	%rdx, (%rax)
	movl	88(%rbp), %eax
	cltq
	movq	80(%rbp), %rdx
	leaq	8(%rdx), %rbx
	movq	%rax, %rcx
	call	malloc
	movq	%rax, (%rbx)
	movq	80(%rbp), %rax
	movq	(%rax), %rax
	movb	$65, (%rax)
	movq	80(%rbp), %rax
	movq	(%rax), %rax
	addq	$1, %rax
	movb	$69, (%rax)
	movq	80(%rbp), %rax
	movq	(%rax), %rax
	addq	$2, %rax
	movb	$73, (%rax)
	movq	80(%rbp), %rax
	movq	(%rax), %rax
	addq	$3, %rax
	movb	$79, (%rax)
	movq	80(%rbp), %rax
	movq	(%rax), %rax
	addq	$4, %rax
	movb	$85, (%rax)
	movq	80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movb	$97, (%rax)
	movq	80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	addq	$1, %rax
	movb	$101, (%rax)
	movq	80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	addq	$2, %rax
	movb	$105, (%rax)
	movq	80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	addq	$3, %rax
	movb	$111, (%rax)
	movq	80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	addq	$4, %rax
	movb	$117, (%rax)
	movl	$0, 136(%rbp)
	jmp	.L9
.L12:
	movl	$0, 132(%rbp)
	jmp	.L10
.L11:
	movl	136(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	80(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	132(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	addl	$1, 132(%rbp)
.L10:
	movl	132(%rbp), %eax
	cmpl	88(%rbp), %eax
	jl	.L11
	movl	$10, %ecx
	call	putchar
	addl	$1, 136(%rbp)
.L9:
	movl	136(%rbp), %eax
	cmpl	92(%rbp), %eax
	jl	.L12
	movq	80(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	free
	movq	80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	free
	movq	80(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$24, %ecx
	call	malloc
	movq	%rax, 72(%rbp)
	movq	72(%rbp), %rax
	addq	$20, %rax
	movl	(%rax), %r8d
	movq	72(%rbp), %rax
	addq	$16, %rax
	movl	(%rax), %ecx
	movq	72(%rbp), %rax
	addq	$12, %rax
	movl	(%rax), %edx
	movq	72(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %r9d
	movq	72(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %r10d
	movq	72(%rbp), %rax
	movl	(%rax), %eax
	movl	%r8d, 48(%rsp)
	movl	%ecx, 40(%rsp)
	movl	%edx, 32(%rsp)
	movl	%r10d, %r8d
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	movq	72(%rbp), %rax
	movl	$1, (%rax)
	movq	72(%rbp), %rax
	addq	$20, %rax
	movl	(%rax), %r8d
	movq	72(%rbp), %rax
	addq	$16, %rax
	movl	(%rax), %ecx
	movq	72(%rbp), %rax
	addq	$12, %rax
	movl	(%rax), %edx
	movq	72(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %r9d
	movq	72(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %r10d
	movq	72(%rbp), %rax
	movl	(%rax), %eax
	movl	%r8d, 48(%rsp)
	movl	%ecx, 40(%rsp)
	movl	%edx, 32(%rsp)
	movl	%r10d, %r8d
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	movq	72(%rbp), %rax
	movl	$24, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	memset
	movq	72(%rbp), %rax
	addq	$20, %rax
	movl	(%rax), %r8d
	movq	72(%rbp), %rax
	addq	$16, %rax
	movl	(%rax), %ecx
	movq	72(%rbp), %rax
	addq	$12, %rax
	movl	(%rax), %edx
	movq	72(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %r9d
	movq	72(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %r10d
	movq	72(%rbp), %rax
	movl	(%rax), %eax
	movl	%r8d, 48(%rsp)
	movl	%ecx, 40(%rsp)
	movl	%edx, 32(%rsp)
	movl	%r10d, %r8d
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	movl	$24, %ecx
	call	malloc
	movq	%rax, 64(%rbp)
	movq	64(%rbp), %rax
	movl	$1, (%rax)
	movq	64(%rbp), %rax
	addq	$4, %rax
	movl	$2, (%rax)
	movq	64(%rbp), %rax
	addq	$8, %rax
	movl	$3, (%rax)
	movq	64(%rbp), %rax
	addq	$12, %rax
	movl	$4, (%rax)
	movq	64(%rbp), %rax
	addq	$16, %rax
	movl	$5, (%rax)
	movq	64(%rbp), %rax
	addq	$20, %rax
	movl	$6, (%rax)
	movq	64(%rbp), %rdx
	movq	72(%rbp), %rax
	movl	$24, %r8d
	movq	%rax, %rcx
	call	memcpy
	movq	72(%rbp), %rax
	addq	$20, %rax
	movl	(%rax), %r8d
	movq	72(%rbp), %rax
	addq	$16, %rax
	movl	(%rax), %ecx
	movq	72(%rbp), %rax
	addq	$12, %rax
	movl	(%rax), %edx
	movq	72(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %r9d
	movq	72(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %r10d
	movq	72(%rbp), %rax
	movl	(%rax), %eax
	movl	%r8d, 48(%rsp)
	movl	%ecx, 40(%rsp)
	movl	%edx, 32(%rsp)
	movl	%r10d, %r8d
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	movq	72(%rbp), %rax
	addq	$4, %rax
	movq	72(%rbp), %rdx
	movl	$20, %r8d
	movq	%rax, %rcx
	call	memcpy
	movq	72(%rbp), %rax
	addq	$20, %rax
	movl	(%rax), %r8d
	movq	72(%rbp), %rax
	addq	$16, %rax
	movl	(%rax), %ecx
	movq	72(%rbp), %rax
	addq	$12, %rax
	movl	(%rax), %edx
	movq	72(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %r9d
	movq	72(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %r10d
	movq	72(%rbp), %rax
	movl	(%rax), %eax
	movl	%r8d, 48(%rsp)
	movl	%ecx, 40(%rsp)
	movl	%edx, 32(%rsp)
	movl	%r10d, %r8d
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	movq	64(%rbp), %rdx
	movq	72(%rbp), %rax
	movl	$24, %r8d
	movq	%rax, %rcx
	call	memcpy
	movq	72(%rbp), %rax
	addq	$4, %rax
	movq	72(%rbp), %rdx
	movl	$20, %r8d
	movq	%rax, %rcx
	call	memmove
	movq	72(%rbp), %rax
	addq	$20, %rax
	movl	(%rax), %r8d
	movq	72(%rbp), %rax
	addq	$16, %rax
	movl	(%rax), %ecx
	movq	72(%rbp), %rax
	addq	$12, %rax
	movl	(%rax), %edx
	movq	72(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %r9d
	movq	72(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %r10d
	movq	72(%rbp), %rax
	movl	(%rax), %eax
	movl	%r8d, 48(%rsp)
	movl	%ecx, 40(%rsp)
	movl	%edx, 32(%rsp)
	movl	%r10d, %r8d
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$280, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	realloc;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	calloc;	.scl	2;	.type	32;	.endef
	.def	strcpy;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
