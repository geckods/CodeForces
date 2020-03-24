	.file	"c.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	":("
	.text
	.globl	main
	.type	main, @function
main:
.LFB3609:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3609
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$280, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %r15
	movl	$0, %edi
.LEHB0:
	call	_ZNSt8ios_base15sync_with_stdioEb
	movl	$0, %esi
	movl	$_ZSt3cin+16, %edi
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE3tieEPSo
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
.LEHE0:
	leaq	-204(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
.LEHB1:
	call	_ZNSirsERi
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	-204(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	%rdx, -160(%rbp)
	movq	%rdx, %rax
	addq	$1, %rax
	movq	%rax, %r13
	movl	$0, %r14d
	movq	%rdx, %rax
	addq	$1, %rax
	movq	%rax, -224(%rbp)
	movq	$0, -216(%rbp)
	movq	%rdx, %rax
	addq	$1, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -152(%rbp)
	movl	-204(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	%rdx, -144(%rbp)
	movq	%rdx, %rax
	addq	$1, %rax
	movq	%rax, -240(%rbp)
	movq	$0, -232(%rbp)
	movq	%rdx, %rax
	addq	$1, %rax
	movq	%rax, -256(%rbp)
	movq	$0, -248(%rbp)
	movq	%rdx, %rax
	addq	$1, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ecx
	movl	$0, %edx
	divq	%rcx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -136(%rbp)
	movl	-204(%rbp), %eax
	subl	$1, %eax
	movslq	%eax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$40, %al
	je	.L2
	movl	-204(%rbp), %eax
	subl	$2, %eax
	movslq	%eax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$40, %al
	je	.L2
	leaq	-96(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$41, %al
	je	.L2
	leaq	-96(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$41, %al
	jne	.L3
.L2:
	movl	$1, %eax
	jmp	.L4
.L3:
	movl	$0, %eax
.L4:
	testb	%al, %al
	je	.L5
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$0, %r12d
	movl	$0, %ebx
	jmp	.L6
.L5:
	movl	$0, -200(%rbp)
	movl	$2, -196(%rbp)
.L10:
	movl	-204(%rbp), %eax
	subl	$2, %eax
	cmpl	-196(%rbp), %eax
	jle	.L7
	movl	-196(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$40, %al
	sete	%al
	testb	%al, %al
	je	.L8
	addl	$1, -200(%rbp)
	jmp	.L9
.L8:
	movl	-196(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$41, %al
	sete	%al
	testb	%al, %al
	je	.L9
	subl	$1, -200(%rbp)
.L9:
	movq	-152(%rbp), %rax
	movl	-196(%rbp), %edx
	movslq	%edx, %rdx
	movl	-200(%rbp), %ecx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -196(%rbp)
	jmp	.L10
.L7:
	movl	$0, -200(%rbp)
	movl	-204(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -192(%rbp)
.L14:
	cmpl	$1, -192(%rbp)
	jle	.L11
	movl	-192(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$40, %al
	sete	%al
	testb	%al, %al
	je	.L12
	addl	$1, -200(%rbp)
	jmp	.L13
.L12:
	movl	-192(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$41, %al
	sete	%al
	testb	%al, %al
	je	.L13
	subl	$1, -200(%rbp)
.L13:
	movq	-136(%rbp), %rax
	movl	-192(%rbp), %edx
	movslq	%edx, %rdx
	movl	-200(%rbp), %ecx
	movl	%ecx, (%rax,%rdx,4)
	subl	$1, -192(%rbp)
	jmp	.L14
.L11:
	movl	$0, -188(%rbp)
	movl	$0, -184(%rbp)
	movl	$2, -180(%rbp)
.L19:
	movl	-204(%rbp), %eax
	subl	$2, %eax
	cmpl	-180(%rbp), %eax
	jle	.L15
	movl	-180(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$40, %al
	sete	%al
	testb	%al, %al
	je	.L16
	addl	$1, -188(%rbp)
.L16:
	movl	-180(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$41, %al
	sete	%al
	testb	%al, %al
	je	.L17
	subl	$1, -188(%rbp)
.L17:
	movl	-180(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$63, %al
	sete	%al
	testb	%al, %al
	je	.L18
	addl	$1, -184(%rbp)
.L18:
	addl	$1, -180(%rbp)
	jmp	.L19
.L15:
	movl	-188(%rbp), %eax
	cltd
	movl	%edx, %eax
	xorl	-188(%rbp), %eax
	subl	%edx, %eax
	cmpl	-184(%rbp), %eax
	jle	.L20
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$0, %r12d
	movl	$0, %ebx
	jmp	.L6
.L20:
	movl	-204(%rbp), %eax
	cltq
	subq	$1, %rax
	movq	%rax, -128(%rbp)
	movq	%rax, %rdx
	addq	$1, %rdx
	movq	%rdx, -272(%rbp)
	movq	$0, -264(%rbp)
	movq	%rax, %rdx
	addq	$1, %rdx
	movq	%rdx, -288(%rbp)
	movq	$0, -280(%rbp)
	addq	$1, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -120(%rbp)
	movl	$0, -176(%rbp)
	movl	-204(%rbp), %eax
	subl	$3, %eax
	movl	%eax, -172(%rbp)
.L24:
	cmpl	$1, -172(%rbp)
	jle	.L21
	movl	-172(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$41, %al
	sete	%al
	testb	%al, %al
	je	.L22
	addl	$1, -176(%rbp)
	jmp	.L23
.L22:
	cmpl	$0, -176(%rbp)
	jle	.L23
	subl	$1, -176(%rbp)
.L23:
	movq	-120(%rbp), %rax
	movl	-172(%rbp), %edx
	movslq	%edx, %rdx
	movl	-176(%rbp), %ecx
	movl	%ecx, (%rax,%rdx,4)
	subl	$1, -172(%rbp)
	jmp	.L24
.L21:
	movl	-204(%rbp), %eax
	addl	$1, %eax
	cltq
	subq	$1, %rax
	movq	%rax, -112(%rbp)
	movq	%rax, %rdx
	addq	$1, %rdx
	movq	%rdx, -304(%rbp)
	movq	$0, -296(%rbp)
	movq	%rax, %rdx
	addq	$1, %rdx
	movq	%rdx, -320(%rbp)
	movq	$0, -312(%rbp)
	leaq	1(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ecx
	movl	$0, %edx
	divq	%rcx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$0, %rax
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rax
	movb	$40, (%rax)
	movq	-104(%rbp), %rax
	movb	$40, 1(%rax)
	movl	-204(%rbp), %eax
	subl	$1, %eax
	movq	-104(%rbp), %rdx
	cltq
	movb	$41, (%rdx,%rax)
	movl	-204(%rbp), %eax
	subl	$2, %eax
	movq	-104(%rbp), %rdx
	cltq
	movb	$41, (%rdx,%rax)
	movl	$0, -168(%rbp)
	movl	$2, -164(%rbp)
.L30:
	movl	-204(%rbp), %eax
	subl	$2, %eax
	cmpl	-164(%rbp), %eax
	jle	.L25
	movl	-168(%rbp), %eax
	leal	1(%rax), %ecx
	movq	-120(%rbp), %rax
	movl	-164(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	cmpl	$-1, %eax
	jge	.L26
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$0, %r12d
	movl	$0, %ebx
	jmp	.L6
.L26:
	movq	-120(%rbp), %rax
	movl	-164(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movl	-168(%rbp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	$-2, %eax
	jne	.L27
	movq	-104(%rbp), %rdx
	movl	-164(%rbp), %eax
	cltq
	movb	$40, (%rdx,%rax)
	addl	$1, -168(%rbp)
	jmp	.L28
.L27:
	movl	-168(%rbp), %edx
	movl	-188(%rbp), %eax
	addl	%edx, %eax
	testl	%eax, %eax
	jg	.L29
	movq	-104(%rbp), %rdx
	movl	-164(%rbp), %eax
	cltq
	movb	$40, (%rdx,%rax)
	addl	$1, -168(%rbp)
	jmp	.L28
.L29:
	movq	-104(%rbp), %rdx
	movl	-164(%rbp), %eax
	cltq
	movb	$41, (%rdx,%rax)
	subl	$1, -168(%rbp)
.L28:
	addl	$1, -164(%rbp)
	jmp	.L30
.L25:
	movl	-168(%rbp), %edx
	movl	-188(%rbp), %eax
	addl	%edx, %eax
	testl	%eax, %eax
	je	.L31
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$0, %r12d
	movl	$0, %ebx
	jmp	.L6
.L31:
	movl	-204(%rbp), %eax
	movq	-104(%rbp), %rdx
	cltq
	movb	$0, (%rdx,%rax)
	movq	-104(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.LEHE1:
	movl	$1, %ebx
.L6:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
.LEHB2:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.LEHE2:
	cmpl	$1, %ebx
	je	.L43
	movl	$0, %eax
	jmp	.L35
.L43:
	nop
	movl	$1, %eax
.L35:
	movq	%r15, %rsp
	cmpl	$1, %eax
	jne	.L36
	movl	$0, %r12d
.L36:
	movl	%r12d, %eax
	movq	-56(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L39
	jmp	.L42
.L40:
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
.L42:
	call	__stack_chk_fail
.L39:
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3609:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA3609:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3609-.LLSDACSB3609
.LLSDACSB3609:
	.uleb128 .LEHB0-.LFB3609
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB3609
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L40-.LFB3609
	.uleb128 0
	.uleb128 .LEHB2-.LFB3609
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB3609
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE3609:
	.text
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB3678:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L46
	cmpl	$65535, -8(%rbp)
	jne	.L46
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L46:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3678:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB3679:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3679:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
