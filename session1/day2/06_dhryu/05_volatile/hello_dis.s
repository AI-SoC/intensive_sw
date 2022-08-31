
hello:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 9a 2f 00 00    	pushq  0x2f9a(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 9b 2f 00 00 	bnd jmpq *0x2f9b(%rip)        # 3fc8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop

Disassembly of section .plt.got:

0000000000001040 <__cxa_finalize@plt>:
    1040:	f3 0f 1e fa          	endbr64 
    1044:	f2 ff 25 ad 2f 00 00 	bnd jmpq *0x2fad(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    104b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001050 <__printf_chk@plt>:
    1050:	f3 0f 1e fa          	endbr64 
    1054:	f2 ff 25 75 2f 00 00 	bnd jmpq *0x2f75(%rip)        # 3fd0 <__printf_chk@GLIBC_2.3.4>
    105b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001060 <main>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	48 83 ec 18          	sub    $0x18,%rsp
    1068:	48 8d 35 95 0f 00 00 	lea    0xf95(%rip),%rsi        # 2004 <_IO_stdin_used+0x4>
    106f:	bf 01 00 00 00       	mov    $0x1,%edi
    1074:	31 c0                	xor    %eax,%eax
    1076:	c7 44 24 0c 03 00 00 	movl   $0x3,0xc(%rsp)
    107d:	00 
    107e:	8b 54 24 0c          	mov    0xc(%rsp),%edx
    1082:	83 c2 07             	add    $0 x7,%edx
    1085:	e8 c6 ff ff ff       	callq  1050 <__printf_chk@plt>
    108a:	31 c0                	xor    %eax,%eax
    108c:	48 83 c4 18          	add    $0x18,%rsp
    1090:	c3                   	retq   
    1091:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    1098:	00 00 00 
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010a0 <_start>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	31 ed                	xor    %ebp,%ebp
    10a6:	49 89 d1             	mov    %rdx,%r9
    10a9:	5e                   	pop    %rsi
    10aa:	48 89 e2             	mov    %rsp,%rdx
    10ad:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10b1:	50                   	push   %rax
    10b2:	54                   	push   %rsp
    10b3:	4c 8d 05 56 01 00 00 	lea    0x156(%rip),%r8        # 1210 <__libc_csu_fini>
    10ba:	48 8d 0d df 00 00 00 	lea    0xdf(%rip),%rcx        # 11a0 <__libc_csu_init>
    10c1:	48 8d 3d 98 ff ff ff 	lea    -0x68(%rip),%rdi        # 1060 <main>
    10c8:	ff 15 12 2f 00 00    	callq  *0x2f12(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    10ce:	f4                   	hlt    
    10cf:	90                   	nop

00000000000010d0 <deregister_tm_clones>:
    10d0:	48 8d 3d 39 2f 00 00 	lea    0x2f39(%rip),%rdi        # 4010 <__TMC_END__>
    10d7:	48 8d 05 32 2f 00 00 	lea    0x2f32(%rip),%rax        # 4010 <__TMC_END__>
    10de:	48 39 f8             	cmp    %rdi,%rax
    10e1:	74 15                	je     10f8 <deregister_tm_clones+0x28>
    10e3:	48 8b 05 ee 2e 00 00 	mov    0x2eee(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    10ea:	48 85 c0             	test   %rax,%rax
    10ed:	74 09                	je     10f8 <deregister_tm_clones+0x28>
    10ef:	ff e0                	jmpq   *%rax
    10f1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10f8:	c3                   	retq   
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <register_tm_clones>:
    1100:	48 8d 3d 09 2f 00 00 	lea    0x2f09(%rip),%rdi        # 4010 <__TMC_END__>
    1107:	48 8d 35 02 2f 00 00 	lea    0x2f02(%rip),%rsi        # 4010 <__TMC_END__>
    110e:	48 29 fe             	sub    %rdi,%rsi
    1111:	48 89 f0             	mov    %rsi,%rax
    1114:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1118:	48 c1 f8 03          	sar    $0x3,%rax
    111c:	48 01 c6             	add    %rax,%rsi
    111f:	48 d1 fe             	sar    %rsi
    1122:	74 14                	je     1138 <register_tm_clones+0x38>
    1124:	48 8b 05 c5 2e 00 00 	mov    0x2ec5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    112b:	48 85 c0             	test   %rax,%rax
    112e:	74 08                	je     1138 <register_tm_clones+0x38>
    1130:	ff e0                	jmpq   *%rax
    1132:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1138:	c3                   	retq   
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <__do_global_dtors_aux>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	80 3d c5 2e 00 00 00 	cmpb   $0x0,0x2ec5(%rip)        # 4010 <__TMC_END__>
    114b:	75 2b                	jne    1178 <__do_global_dtors_aux+0x38>
    114d:	55                   	push   %rbp
    114e:	48 83 3d a2 2e 00 00 	cmpq   $0x0,0x2ea2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1155:	00 
    1156:	48 89 e5             	mov    %rsp,%rbp
    1159:	74 0c                	je     1167 <__do_global_dtors_aux+0x27>
    115b:	48 8b 3d a6 2e 00 00 	mov    0x2ea6(%rip),%rdi        # 4008 <__dso_handle>
    1162:	e8 d9 fe ff ff       	callq  1040 <__cxa_finalize@plt>
    1167:	e8 64 ff ff ff       	callq  10d0 <deregister_tm_clones>
    116c:	c6 05 9d 2e 00 00 01 	movb   $0x1,0x2e9d(%rip)        # 4010 <__TMC_END__>
    1173:	5d                   	pop    %rbp
    1174:	c3                   	retq   
    1175:	0f 1f 00             	nopl   (%rax)
    1178:	c3                   	retq   
    1179:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001180 <frame_dummy>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	e9 77 ff ff ff       	jmpq   1100 <register_tm_clones>
    1189:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001190 <ADC_EOC_CHECK>:
    1190:	f3 0f 1e fa          	endbr64 
    1194:	b8 01 00 00 00       	mov    $0x1,%eax
    1199:	c3                   	retq   
    119a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000011a0 <__libc_csu_init>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	41 57                	push   %r15
    11a6:	4c 8d 3d 0b 2c 00 00 	lea    0x2c0b(%rip),%r15        # 3db8 <__frame_dummy_init_array_entry>
    11ad:	41 56                	push   %r14
    11af:	49 89 d6             	mov    %rdx,%r14
    11b2:	41 55                	push   %r13
    11b4:	49 89 f5             	mov    %rsi,%r13
    11b7:	41 54                	push   %r12
    11b9:	41 89 fc             	mov    %edi,%r12d
    11bc:	55                   	push   %rbp
    11bd:	48 8d 2d fc 2b 00 00 	lea    0x2bfc(%rip),%rbp        # 3dc0 <__do_global_dtors_aux_fini_array_entry>
    11c4:	53                   	push   %rbx
    11c5:	4c 29 fd             	sub    %r15,%rbp
    11c8:	48 83 ec 08          	sub    $0x8,%rsp
    11cc:	e8 2f fe ff ff       	callq  1000 <_init>
    11d1:	48 c1 fd 03          	sar    $0x3,%rbp
    11d5:	74 1f                	je     11f6 <__libc_csu_init+0x56>
    11d7:	31 db                	xor    %ebx,%ebx
    11d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    11e0:	4c 89 f2             	mov    %r14,%rdx
    11e3:	4c 89 ee             	mov    %r13,%rsi
    11e6:	44 89 e7             	mov    %r12d,%edi
    11e9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    11ed:	48 83 c3 01          	add    $0x1,%rbx
    11f1:	48 39 dd             	cmp    %rbx,%rbp
    11f4:	75 ea                	jne    11e0 <__libc_csu_init+0x40>
    11f6:	48 83 c4 08          	add    $0x8,%rsp
    11fa:	5b                   	pop    %rbx
    11fb:	5d                   	pop    %rbp
    11fc:	41 5c                	pop    %r12
    11fe:	41 5d                	pop    %r13
    1200:	41 5e                	pop    %r14
    1202:	41 5f                	pop    %r15
    1204:	c3                   	retq   
    1205:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    120c:	00 00 00 00 

0000000000001210 <__libc_csu_fini>:
    1210:	f3 0f 1e fa          	endbr64 
    1214:	c3                   	retq   

Disassembly of section .fini:

0000000000001218 <_fini>:
    1218:	f3 0f 1e fa          	endbr64 
    121c:	48 83 ec 08          	sub    $0x8,%rsp
    1220:	48 83 c4 08          	add    $0x8,%rsp
    1224:	c3                   	retq   
