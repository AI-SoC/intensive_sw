
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
    1020:	ff 35 92 2f 00 00    	pushq  0x2f92(%rip)        # 3fb8 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 93 2f 00 00 	bnd jmpq *0x2f93(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop

Disassembly of section .plt.got:

0000000000001050 <__cxa_finalize@plt>:
    1050:	f3 0f 1e fa          	endbr64 
    1054:	f2 ff 25 9d 2f 00 00 	bnd jmpq *0x2f9d(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    105b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001060 <puts@plt>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	f2 ff 25 5d 2f 00 00 	bnd jmpq *0x2f5d(%rip)        # 3fc8 <puts@GLIBC_2.2.5>
    106b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001070 <__printf_chk@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 55 2f 00 00 	bnd jmpq *0x2f55(%rip)        # 3fd0 <__printf_chk@GLIBC_2.3.4>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001080 <main>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	48 83 ec 08          	sub    $0x8,%rsp
    1088:	48 8d 3d 75 0f 00 00 	lea    0xf75(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    108f:	e8 cc ff ff ff       	callq  1060 <puts@plt>
    1094:	ba 03 00 00 00       	mov    $0x3,%edx
    1099:	48 8d 35 7f 0f 00 00 	lea    0xf7f(%rip),%rsi        # 201f <_IO_stdin_used+0x1f>
    10a0:	31 c0                	xor    %eax,%eax
    10a2:	bf 01 00 00 00       	mov    $0x1,%edi
    10a7:	e8 c4 ff ff ff       	callq  1070 <__printf_chk@plt>
    10ac:	ba 0a 00 00 00       	mov    $0xa,%edx
    10b1:	48 8d 35 5b 0f 00 00 	lea    0xf5b(%rip),%rsi        # 2013 <_IO_stdin_used+0x13>
    10b8:	31 c0                	xor    %eax,%eax
    10ba:	bf 01 00 00 00       	mov    $0x1,%edi
    10bf:	e8 ac ff ff ff       	callq  1070 <__printf_chk@plt>
    10c4:	31 c0                	xor    %eax,%eax
    10c6:	48 83 c4 08          	add    $0x8,%rsp
    10ca:	c3                   	retq   
    10cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010d0 <_start>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	31 ed                	xor    %ebp,%ebp
    10d6:	49 89 d1             	mov    %rdx,%r9
    10d9:	5e                   	pop    %rsi
    10da:	48 89 e2             	mov    %rsp,%rdx
    10dd:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10e1:	50                   	push   %rax
    10e2:	54                   	push   %rsp
    10e3:	4c 8d 05 56 01 00 00 	lea    0x156(%rip),%r8        # 1240 <__libc_csu_fini>
    10ea:	48 8d 0d df 00 00 00 	lea    0xdf(%rip),%rcx        # 11d0 <__libc_csu_init>
    10f1:	48 8d 3d 88 ff ff ff 	lea    -0x78(%rip),%rdi        # 1080 <main>
    10f8:	ff 15 e2 2e 00 00    	callq  *0x2ee2(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    10fe:	f4                   	hlt    
    10ff:	90                   	nop

0000000000001100 <deregister_tm_clones>:
    1100:	48 8d 3d 09 2f 00 00 	lea    0x2f09(%rip),%rdi        # 4010 <__TMC_END__>
    1107:	48 8d 05 02 2f 00 00 	lea    0x2f02(%rip),%rax        # 4010 <__TMC_END__>
    110e:	48 39 f8             	cmp    %rdi,%rax
    1111:	74 15                	je     1128 <deregister_tm_clones+0x28>
    1113:	48 8b 05 be 2e 00 00 	mov    0x2ebe(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    111a:	48 85 c0             	test   %rax,%rax
    111d:	74 09                	je     1128 <deregister_tm_clones+0x28>
    111f:	ff e0                	jmpq   *%rax
    1121:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1128:	c3                   	retq   
    1129:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001130 <register_tm_clones>:
    1130:	48 8d 3d d9 2e 00 00 	lea    0x2ed9(%rip),%rdi        # 4010 <__TMC_END__>
    1137:	48 8d 35 d2 2e 00 00 	lea    0x2ed2(%rip),%rsi        # 4010 <__TMC_END__>
    113e:	48 29 fe             	sub    %rdi,%rsi
    1141:	48 89 f0             	mov    %rsi,%rax
    1144:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1148:	48 c1 f8 03          	sar    $0x3,%rax
    114c:	48 01 c6             	add    %rax,%rsi
    114f:	48 d1 fe             	sar    %rsi
    1152:	74 14                	je     1168 <register_tm_clones+0x38>
    1154:	48 8b 05 95 2e 00 00 	mov    0x2e95(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    115b:	48 85 c0             	test   %rax,%rax
    115e:	74 08                	je     1168 <register_tm_clones+0x38>
    1160:	ff e0                	jmpq   *%rax
    1162:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1168:	c3                   	retq   
    1169:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001170 <__do_global_dtors_aux>:
    1170:	f3 0f 1e fa          	endbr64 
    1174:	80 3d 95 2e 00 00 00 	cmpb   $0x0,0x2e95(%rip)        # 4010 <__TMC_END__>
    117b:	75 2b                	jne    11a8 <__do_global_dtors_aux+0x38>
    117d:	55                   	push   %rbp
    117e:	48 83 3d 72 2e 00 00 	cmpq   $0x0,0x2e72(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1185:	00 
    1186:	48 89 e5             	mov    %rsp,%rbp
    1189:	74 0c                	je     1197 <__do_global_dtors_aux+0x27>
    118b:	48 8b 3d 76 2e 00 00 	mov    0x2e76(%rip),%rdi        # 4008 <__dso_handle>
    1192:	e8 b9 fe ff ff       	callq  1050 <__cxa_finalize@plt>
    1197:	e8 64 ff ff ff       	callq  1100 <deregister_tm_clones>
    119c:	c6 05 6d 2e 00 00 01 	movb   $0x1,0x2e6d(%rip)        # 4010 <__TMC_END__>
    11a3:	5d                   	pop    %rbp
    11a4:	c3                   	retq   
    11a5:	0f 1f 00             	nopl   (%rax)
    11a8:	c3                   	retq   
    11a9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011b0 <frame_dummy>:
    11b0:	f3 0f 1e fa          	endbr64 
    11b4:	e9 77 ff ff ff       	jmpq   1130 <register_tm_clones>
    11b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011c0 <ADC_EOC_CHECK>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	b8 01 00 00 00       	mov    $0x1,%eax
    11c9:	c3                   	retq   
    11ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000011d0 <__libc_csu_init>:
    11d0:	f3 0f 1e fa          	endbr64 
    11d4:	41 57                	push   %r15
    11d6:	4c 8d 3d d3 2b 00 00 	lea    0x2bd3(%rip),%r15        # 3db0 <__frame_dummy_init_array_entry>
    11dd:	41 56                	push   %r14
    11df:	49 89 d6             	mov    %rdx,%r14
    11e2:	41 55                	push   %r13
    11e4:	49 89 f5             	mov    %rsi,%r13
    11e7:	41 54                	push   %r12
    11e9:	41 89 fc             	mov    %edi,%r12d
    11ec:	55                   	push   %rbp
    11ed:	48 8d 2d c4 2b 00 00 	lea    0x2bc4(%rip),%rbp        # 3db8 <__do_global_dtors_aux_fini_array_entry>
    11f4:	53                   	push   %rbx
    11f5:	4c 29 fd             	sub    %r15,%rbp
    11f8:	48 83 ec 08          	sub    $0x8,%rsp
    11fc:	e8 ff fd ff ff       	callq  1000 <_init>
    1201:	48 c1 fd 03          	sar    $0x3,%rbp
    1205:	74 1f                	je     1226 <__libc_csu_init+0x56>
    1207:	31 db                	xor    %ebx,%ebx
    1209:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1210:	4c 89 f2             	mov    %r14,%rdx
    1213:	4c 89 ee             	mov    %r13,%rsi
    1216:	44 89 e7             	mov    %r12d,%edi
    1219:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    121d:	48 83 c3 01          	add    $0x1,%rbx
    1221:	48 39 dd             	cmp    %rbx,%rbp
    1224:	75 ea                	jne    1210 <__libc_csu_init+0x40>
    1226:	48 83 c4 08          	add    $0x8,%rsp
    122a:	5b                   	pop    %rbx
    122b:	5d                   	pop    %rbp
    122c:	41 5c                	pop    %r12
    122e:	41 5d                	pop    %r13
    1230:	41 5e                	pop    %r14
    1232:	41 5f                	pop    %r15
    1234:	c3                   	retq   
    1235:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    123c:	00 00 00 00 

0000000000001240 <__libc_csu_fini>:
    1240:	f3 0f 1e fa          	endbr64 
    1244:	c3                   	retq   

Disassembly of section .fini:

0000000000001248 <_fini>:
    1248:	f3 0f 1e fa          	endbr64 
    124c:	48 83 ec 08          	sub    $0x8,%rsp
    1250:	48 83 c4 08          	add    $0x8,%rsp
    1254:	c3                   	retq   
