
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
    1064:	48 83 ec 08          	sub    $0x8,%rsp
    1068:	ba 0a 00 00 00       	mov    $0xa,%edx
    106d:	bf 01 00 00 00       	mov    $0x1,%edi
    1072:	31 c0                	xor    %eax,%eax
    1074:	48 8d 35 89 0f 00 00 	lea    0xf89(%rip),%rsi        # 2004 <_IO_stdin_used+0x4>
    107b:	e8 d0 ff ff ff       	callq  1050 <__printf_chk@plt>
    1080:	31 c0                	xor    %eax,%eax
    1082:	48 83 c4 08          	add    $0x8,%rsp
    1086:	c3                   	retq   
    1087:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    108e:	00 00 

0000000000001090 <_start>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	31 ed                	xor    %ebp,%ebp
    1096:	49 89 d1             	mov    %rdx,%r9
    1099:	5e                   	pop    %rsi
    109a:	48 89 e2             	mov    %rsp,%rdx
    109d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10a1:	50                   	push   %rax
    10a2:	54                   	push   %rsp
    10a3:	4c 8d 05 56 01 00 00 	lea    0x156(%rip),%r8        # 1200 <__libc_csu_fini>
    10aa:	48 8d 0d df 00 00 00 	lea    0xdf(%rip),%rcx        # 1190 <__libc_csu_init>
    10b1:	48 8d 3d a8 ff ff ff 	lea    -0x58(%rip),%rdi        # 1060 <main>
    10b8:	ff 15 22 2f 00 00    	callq  *0x2f22(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    10be:	f4                   	hlt    
    10bf:	90                   	nop

00000000000010c0 <deregister_tm_clones>:
    10c0:	48 8d 3d 49 2f 00 00 	lea    0x2f49(%rip),%rdi        # 4010 <__TMC_END__>
    10c7:	48 8d 05 42 2f 00 00 	lea    0x2f42(%rip),%rax        # 4010 <__TMC_END__>
    10ce:	48 39 f8             	cmp    %rdi,%rax
    10d1:	74 15                	je     10e8 <deregister_tm_clones+0x28>
    10d3:	48 8b 05 fe 2e 00 00 	mov    0x2efe(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    10da:	48 85 c0             	test   %rax,%rax
    10dd:	74 09                	je     10e8 <deregister_tm_clones+0x28>
    10df:	ff e0                	jmpq   *%rax
    10e1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10e8:	c3                   	retq   
    10e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010f0 <register_tm_clones>:
    10f0:	48 8d 3d 19 2f 00 00 	lea    0x2f19(%rip),%rdi        # 4010 <__TMC_END__>
    10f7:	48 8d 35 12 2f 00 00 	lea    0x2f12(%rip),%rsi        # 4010 <__TMC_END__>
    10fe:	48 29 fe             	sub    %rdi,%rsi
    1101:	48 89 f0             	mov    %rsi,%rax
    1104:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1108:	48 c1 f8 03          	sar    $0x3,%rax
    110c:	48 01 c6             	add    %rax,%rsi
    110f:	48 d1 fe             	sar    %rsi
    1112:	74 14                	je     1128 <register_tm_clones+0x38>
    1114:	48 8b 05 d5 2e 00 00 	mov    0x2ed5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    111b:	48 85 c0             	test   %rax,%rax
    111e:	74 08                	je     1128 <register_tm_clones+0x38>
    1120:	ff e0                	jmpq   *%rax
    1122:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1128:	c3                   	retq   
    1129:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001130 <__do_global_dtors_aux>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	80 3d d5 2e 00 00 00 	cmpb   $0x0,0x2ed5(%rip)        # 4010 <__TMC_END__>
    113b:	75 2b                	jne    1168 <__do_global_dtors_aux+0x38>
    113d:	55                   	push   %rbp
    113e:	48 83 3d b2 2e 00 00 	cmpq   $0x0,0x2eb2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1145:	00 
    1146:	48 89 e5             	mov    %rsp,%rbp
    1149:	74 0c                	je     1157 <__do_global_dtors_aux+0x27>
    114b:	48 8b 3d b6 2e 00 00 	mov    0x2eb6(%rip),%rdi        # 4008 <__dso_handle>
    1152:	e8 e9 fe ff ff       	callq  1040 <__cxa_finalize@plt>
    1157:	e8 64 ff ff ff       	callq  10c0 <deregister_tm_clones>
    115c:	c6 05 ad 2e 00 00 01 	movb   $0x1,0x2ead(%rip)        # 4010 <__TMC_END__>
    1163:	5d                   	pop    %rbp
    1164:	c3                   	retq   
    1165:	0f 1f 00             	nopl   (%rax)
    1168:	c3                   	retq   
    1169:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001170 <frame_dummy>:
    1170:	f3 0f 1e fa          	endbr64 
    1174:	e9 77 ff ff ff       	jmpq   10f0 <register_tm_clones>
    1179:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001180 <ADC_EOC_CHECK>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	b8 01 00 00 00       	mov    $0x1,%eax
    1189:	c3                   	retq   
    118a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001190 <__libc_csu_init>:
    1190:	f3 0f 1e fa          	endbr64 
    1194:	41 57                	push   %r15
    1196:	4c 8d 3d 1b 2c 00 00 	lea    0x2c1b(%rip),%r15        # 3db8 <__frame_dummy_init_array_entry>
    119d:	41 56                	push   %r14
    119f:	49 89 d6             	mov    %rdx,%r14
    11a2:	41 55                	push   %r13
    11a4:	49 89 f5             	mov    %rsi,%r13
    11a7:	41 54                	push   %r12
    11a9:	41 89 fc             	mov    %edi,%r12d
    11ac:	55                   	push   %rbp
    11ad:	48 8d 2d 0c 2c 00 00 	lea    0x2c0c(%rip),%rbp        # 3dc0 <__do_global_dtors_aux_fini_array_entry>
    11b4:	53                   	push   %rbx
    11b5:	4c 29 fd             	sub    %r15,%rbp
    11b8:	48 83 ec 08          	sub    $0x8,%rsp
    11bc:	e8 3f fe ff ff       	callq  1000 <_init>
    11c1:	48 c1 fd 03          	sar    $0x3,%rbp
    11c5:	74 1f                	je     11e6 <__libc_csu_init+0x56>
    11c7:	31 db                	xor    %ebx,%ebx
    11c9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    11d0:	4c 89 f2             	mov    %r14,%rdx
    11d3:	4c 89 ee             	mov    %r13,%rsi
    11d6:	44 89 e7             	mov    %r12d,%edi
    11d9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    11dd:	48 83 c3 01          	add    $0x1,%rbx
    11e1:	48 39 dd             	cmp    %rbx,%rbp
    11e4:	75 ea                	jne    11d0 <__libc_csu_init+0x40>
    11e6:	48 83 c4 08          	add    $0x8,%rsp
    11ea:	5b                   	pop    %rbx
    11eb:	5d                   	pop    %rbp
    11ec:	41 5c                	pop    %r12
    11ee:	41 5d                	pop    %r13
    11f0:	41 5e                	pop    %r14
    11f2:	41 5f                	pop    %r15
    11f4:	c3                   	retq   
    11f5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    11fc:	00 00 00 00 

0000000000001200 <__libc_csu_fini>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	c3                   	retq   

Disassembly of section .fini:

0000000000001208 <_fini>:
    1208:	f3 0f 1e fa          	endbr64 
    120c:	48 83 ec 08          	sub    $0x8,%rsp
    1210:	48 83 c4 08          	add    $0x8,%rsp
    1214:	c3                   	retq   
