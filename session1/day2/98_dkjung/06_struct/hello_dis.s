
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

0000000000001060 <__stack_chk_fail@plt>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	f2 ff 25 5d 2f 00 00 	bnd jmpq *0x2f5d(%rip)        # 3fc8 <__stack_chk_fail@GLIBC_2.4>
    106b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001070 <printf@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 55 2f 00 00 	bnd jmpq *0x2f55(%rip)        # 3fd0 <printf@GLIBC_2.2.5>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001080 <_start>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	31 ed                	xor    %ebp,%ebp
    1086:	49 89 d1             	mov    %rdx,%r9
    1089:	5e                   	pop    %rsi
    108a:	48 89 e2             	mov    %rsp,%rdx
    108d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1091:	50                   	push   %rax
    1092:	54                   	push   %rsp
    1093:	4c 8d 05 36 03 00 00 	lea    0x336(%rip),%r8        # 13d0 <__libc_csu_fini>
    109a:	48 8d 0d bf 02 00 00 	lea    0x2bf(%rip),%rcx        # 1360 <__libc_csu_init>
    10a1:	48 8d 3d 24 01 00 00 	lea    0x124(%rip),%rdi        # 11cc <main>
    10a8:	ff 15 32 2f 00 00    	callq  *0x2f32(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    10ae:	f4                   	hlt    
    10af:	90                   	nop

00000000000010b0 <deregister_tm_clones>:
    10b0:	48 8d 3d 59 2f 00 00 	lea    0x2f59(%rip),%rdi        # 4010 <__TMC_END__>
    10b7:	48 8d 05 52 2f 00 00 	lea    0x2f52(%rip),%rax        # 4010 <__TMC_END__>
    10be:	48 39 f8             	cmp    %rdi,%rax
    10c1:	74 15                	je     10d8 <deregister_tm_clones+0x28>
    10c3:	48 8b 05 0e 2f 00 00 	mov    0x2f0e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    10ca:	48 85 c0             	test   %rax,%rax
    10cd:	74 09                	je     10d8 <deregister_tm_clones+0x28>
    10cf:	ff e0                	jmpq   *%rax
    10d1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10d8:	c3                   	retq   
    10d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010e0 <register_tm_clones>:
    10e0:	48 8d 3d 29 2f 00 00 	lea    0x2f29(%rip),%rdi        # 4010 <__TMC_END__>
    10e7:	48 8d 35 22 2f 00 00 	lea    0x2f22(%rip),%rsi        # 4010 <__TMC_END__>
    10ee:	48 29 fe             	sub    %rdi,%rsi
    10f1:	48 89 f0             	mov    %rsi,%rax
    10f4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10f8:	48 c1 f8 03          	sar    $0x3,%rax
    10fc:	48 01 c6             	add    %rax,%rsi
    10ff:	48 d1 fe             	sar    %rsi
    1102:	74 14                	je     1118 <register_tm_clones+0x38>
    1104:	48 8b 05 e5 2e 00 00 	mov    0x2ee5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    110b:	48 85 c0             	test   %rax,%rax
    110e:	74 08                	je     1118 <register_tm_clones+0x38>
    1110:	ff e0                	jmpq   *%rax
    1112:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1118:	c3                   	retq   
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <__do_global_dtors_aux>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	80 3d e5 2e 00 00 00 	cmpb   $0x0,0x2ee5(%rip)        # 4010 <__TMC_END__>
    112b:	75 2b                	jne    1158 <__do_global_dtors_aux+0x38>
    112d:	55                   	push   %rbp
    112e:	48 83 3d c2 2e 00 00 	cmpq   $0x0,0x2ec2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1135:	00 
    1136:	48 89 e5             	mov    %rsp,%rbp
    1139:	74 0c                	je     1147 <__do_global_dtors_aux+0x27>
    113b:	48 8b 3d c6 2e 00 00 	mov    0x2ec6(%rip),%rdi        # 4008 <__dso_handle>
    1142:	e8 09 ff ff ff       	callq  1050 <__cxa_finalize@plt>
    1147:	e8 64 ff ff ff       	callq  10b0 <deregister_tm_clones>
    114c:	c6 05 bd 2e 00 00 01 	movb   $0x1,0x2ebd(%rip)        # 4010 <__TMC_END__>
    1153:	5d                   	pop    %rbp
    1154:	c3                   	retq   
    1155:	0f 1f 00             	nopl   (%rax)
    1158:	c3                   	retq   
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <frame_dummy>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	e9 77 ff ff ff       	jmpq   10e0 <register_tm_clones>

0000000000001169 <mem_inspection>:
    1169:	f3 0f 1e fa          	endbr64 
    116d:	55                   	push   %rbp
    116e:	48 89 e5             	mov    %rsp,%rbp
    1171:	48 83 ec 20          	sub    $0x20,%rsp
    1175:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1179:	89 75 e4             	mov    %esi,-0x1c(%rbp)
    117c:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    1183:	eb 3b                	jmp    11c0 <mem_inspection+0x57>
    1185:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1188:	48 63 d0             	movslq %eax,%rdx
    118b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    118f:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    1193:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1196:	48 63 d0             	movslq %eax,%rdx
    1199:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    119d:	48 01 d0             	add    %rdx,%rax
    11a0:	0f b6 00             	movzbl (%rax),%eax
    11a3:	0f b6 d0             	movzbl %al,%edx
    11a6:	8b 45 fc             	mov    -0x4(%rbp),%eax
    11a9:	89 c6                	mov    %eax,%esi
    11ab:	48 8d 3d 56 0e 00 00 	lea    0xe56(%rip),%rdi        # 2008 <_IO_stdin_used+0x8>
    11b2:	b8 00 00 00 00       	mov    $0x0,%eax
    11b7:	e8 b4 fe ff ff       	callq  1070 <printf@plt>
    11bc:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
    11c0:	8b 45 fc             	mov    -0x4(%rbp),%eax
    11c3:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
    11c6:	7c bd                	jl     1185 <mem_inspection+0x1c>
    11c8:	90                   	nop
    11c9:	90                   	nop
    11ca:	c9                   	leaveq 
    11cb:	c3                   	retq   

00000000000011cc <main>:
    11cc:	f3 0f 1e fa          	endbr64 
    11d0:	55                   	push   %rbp
    11d1:	48 89 e5             	mov    %rsp,%rbp
    11d4:	48 83 ec 20          	sub    $0x20,%rsp
    11d8:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    11df:	00 00 
    11e1:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    11e5:	31 c0                	xor    %eax,%eax
    11e7:	c6 45 e4 01          	movb   $0x1,-0x1c(%rbp)
    11eb:	c6 45 e5 80          	movb   $0x80,-0x1b(%rbp)
    11ef:	66 c7 45 e6 00 f0    	movw   $0xf000,-0x1a(%rbp)
    11f5:	0f b6 45 e4          	movzbl -0x1c(%rbp),%eax
    11f9:	0f b6 c0             	movzbl %al,%eax
    11fc:	89 c6                	mov    %eax,%esi
    11fe:	48 8d 3d 1c 0e 00 00 	lea    0xe1c(%rip),%rdi        # 2021 <_IO_stdin_used+0x21>
    1205:	b8 00 00 00 00       	mov    $0x0,%eax
    120a:	e8 61 fe ff ff       	callq  1070 <printf@plt>
    120f:	0f b6 45 e5          	movzbl -0x1b(%rbp),%eax
    1213:	0f b6 c0             	movzbl %al,%eax
    1216:	89 c6                	mov    %eax,%esi
    1218:	48 8d 3d 11 0e 00 00 	lea    0xe11(%rip),%rdi        # 2030 <_IO_stdin_used+0x30>
    121f:	b8 00 00 00 00       	mov    $0x0,%eax
    1224:	e8 47 fe ff ff       	callq  1070 <printf@plt>
    1229:	0f b7 45 e6          	movzwl -0x1a(%rbp),%eax
    122d:	0f b7 c0             	movzwl %ax,%eax
    1230:	89 c6                	mov    %eax,%esi
    1232:	48 8d 3d 06 0e 00 00 	lea    0xe06(%rip),%rdi        # 203f <_IO_stdin_used+0x3f>
    1239:	b8 00 00 00 00       	mov    $0x0,%eax
    123e:	e8 2d fe ff ff       	callq  1070 <printf@plt>
    1243:	48 8d 45 e4          	lea    -0x1c(%rbp),%rax
    1247:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    124b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    124f:	be 04 00 00 00       	mov    $0x4,%esi
    1254:	48 89 c7             	mov    %rax,%rdi
    1257:	e8 0d ff ff ff       	callq  1169 <mem_inspection>
    125c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1260:	48 83 c0 01          	add    $0x1,%rax
    1264:	c6 00 5a             	movb   $0x5a,(%rax)
    1267:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    126b:	be 04 00 00 00       	mov    $0x4,%esi
    1270:	48 89 c7             	mov    %rax,%rdi
    1273:	e8 f1 fe ff ff       	callq  1169 <mem_inspection>
    1278:	be 01 00 00 00       	mov    $0x1,%esi
    127d:	48 8d 3d cc 0d 00 00 	lea    0xdcc(%rip),%rdi        # 2050 <_IO_stdin_used+0x50>
    1284:	b8 00 00 00 00       	mov    $0x0,%eax
    1289:	e8 e2 fd ff ff       	callq  1070 <printf@plt>
    128e:	c6 45 e3 0b          	movb   $0xb,-0x1d(%rbp)
    1292:	80 4d e3 80          	orb    $0x80,-0x1d(%rbp)
    1296:	0f b6 45 e3          	movzbl -0x1d(%rbp),%eax
    129a:	89 c6                	mov    %eax,%esi
    129c:	48 8d 3d d7 0d 00 00 	lea    0xdd7(%rip),%rdi        # 207a <_IO_stdin_used+0x7a>
    12a3:	b8 00 00 00 00       	mov    $0x0,%eax
    12a8:	e8 c3 fd ff ff       	callq  1070 <printf@plt>
    12ad:	be 02 00 00 00       	mov    $0x2,%esi
    12b2:	48 8d 3d cf 0d 00 00 	lea    0xdcf(%rip),%rdi        # 2088 <_IO_stdin_used+0x88>
    12b9:	b8 00 00 00 00       	mov    $0x0,%eax
    12be:	e8 ad fd ff ff       	callq  1070 <printf@plt>
    12c3:	66 c7 45 f6 05 f0    	movw   $0xf005,-0xa(%rbp)
    12c9:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    12cd:	0f b6 d0             	movzbl %al,%edx
    12d0:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    12d4:	0f b6 c0             	movzbl %al,%eax
    12d7:	89 c6                	mov    %eax,%esi
    12d9:	48 8d 3d cb 0d 00 00 	lea    0xdcb(%rip),%rdi        # 20ab <_IO_stdin_used+0xab>
    12e0:	b8 00 00 00 00       	mov    $0x0,%eax
    12e5:	e8 86 fd ff ff       	callq  1070 <printf@plt>
    12ea:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    12ee:	83 e0 7f             	and    $0x7f,%eax
    12f1:	88 45 f7             	mov    %al,-0x9(%rbp)
    12f4:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    12f8:	0f b6 d0             	movzbl %al,%edx
    12fb:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    12ff:	0f b6 c0             	movzbl %al,%eax
    1302:	89 c6                	mov    %eax,%esi
    1304:	48 8d 3d a0 0d 00 00 	lea    0xda0(%rip),%rdi        # 20ab <_IO_stdin_used+0xab>
    130b:	b8 00 00 00 00       	mov    $0x0,%eax
    1310:	e8 5b fd ff ff       	callq  1070 <printf@plt>
    1315:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    1319:	83 c8 40             	or     $0x40,%eax
    131c:	88 45 f6             	mov    %al,-0xa(%rbp)
    131f:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    1323:	0f b6 d0             	movzbl %al,%edx
    1326:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    132a:	0f b6 c0             	movzbl %al,%eax
    132d:	89 c6                	mov    %eax,%esi
    132f:	48 8d 3d 75 0d 00 00 	lea    0xd75(%rip),%rdi        # 20ab <_IO_stdin_used+0xab>
    1336:	b8 00 00 00 00       	mov    $0x0,%eax
    133b:	e8 30 fd ff ff       	callq  1070 <printf@plt>
    1340:	b8 00 00 00 00       	mov    $0x0,%eax
    1345:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    1349:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    1350:	00 00 
    1352:	74 05                	je     1359 <main+0x18d>
    1354:	e8 07 fd ff ff       	callq  1060 <__stack_chk_fail@plt>
    1359:	c9                   	leaveq 
    135a:	c3                   	retq   
    135b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001360 <__libc_csu_init>:
    1360:	f3 0f 1e fa          	endbr64 
    1364:	41 57                	push   %r15
    1366:	4c 8d 3d 43 2a 00 00 	lea    0x2a43(%rip),%r15        # 3db0 <__frame_dummy_init_array_entry>
    136d:	41 56                	push   %r14
    136f:	49 89 d6             	mov    %rdx,%r14
    1372:	41 55                	push   %r13
    1374:	49 89 f5             	mov    %rsi,%r13
    1377:	41 54                	push   %r12
    1379:	41 89 fc             	mov    %edi,%r12d
    137c:	55                   	push   %rbp
    137d:	48 8d 2d 34 2a 00 00 	lea    0x2a34(%rip),%rbp        # 3db8 <__do_global_dtors_aux_fini_array_entry>
    1384:	53                   	push   %rbx
    1385:	4c 29 fd             	sub    %r15,%rbp
    1388:	48 83 ec 08          	sub    $0x8,%rsp
    138c:	e8 6f fc ff ff       	callq  1000 <_init>
    1391:	48 c1 fd 03          	sar    $0x3,%rbp
    1395:	74 1f                	je     13b6 <__libc_csu_init+0x56>
    1397:	31 db                	xor    %ebx,%ebx
    1399:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    13a0:	4c 89 f2             	mov    %r14,%rdx
    13a3:	4c 89 ee             	mov    %r13,%rsi
    13a6:	44 89 e7             	mov    %r12d,%edi
    13a9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    13ad:	48 83 c3 01          	add    $0x1,%rbx
    13b1:	48 39 dd             	cmp    %rbx,%rbp
    13b4:	75 ea                	jne    13a0 <__libc_csu_init+0x40>
    13b6:	48 83 c4 08          	add    $0x8,%rsp
    13ba:	5b                   	pop    %rbx
    13bb:	5d                   	pop    %rbp
    13bc:	41 5c                	pop    %r12
    13be:	41 5d                	pop    %r13
    13c0:	41 5e                	pop    %r14
    13c2:	41 5f                	pop    %r15
    13c4:	c3                   	retq   
    13c5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    13cc:	00 00 00 00 

00000000000013d0 <__libc_csu_fini>:
    13d0:	f3 0f 1e fa          	endbr64 
    13d4:	c3                   	retq   

Disassembly of section .fini:

00000000000013d8 <_fini>:
    13d8:	f3 0f 1e fa          	endbr64 
    13dc:	48 83 ec 08          	sub    $0x8,%rsp
    13e0:	48 83 c4 08          	add    $0x8,%rsp
    13e4:	c3                   	retq   
