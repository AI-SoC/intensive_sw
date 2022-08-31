
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
    1093:	4c 8d 05 16 03 00 00 	lea    0x316(%rip),%r8        # 13b0 <__libc_csu_fini>
    109a:	48 8d 0d 9f 02 00 00 	lea    0x29f(%rip),%rcx        # 1340 <__libc_csu_init>
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
    1267:	0f b6 45 e5          	movzbl -0x1b(%rbp),%eax
    126b:	0f b6 c0             	movzbl %al,%eax
    126e:	89 c6                	mov    %eax,%esi
    1270:	48 8d 3d b9 0d 00 00 	lea    0xdb9(%rip),%rdi        # 2030 <_IO_stdin_used+0x30>
    1277:	b8 00 00 00 00       	mov    $0x0,%eax
    127c:	e8 ef fd ff ff       	callq  1070 <printf@plt>
    1281:	be 01 00 00 00       	mov    $0x1,%esi
    1286:	48 8d 3d c3 0d 00 00 	lea    0xdc3(%rip),%rdi        # 2050 <_IO_stdin_used+0x50>
    128d:	b8 00 00 00 00       	mov    $0x0,%eax
    1292:	e8 d9 fd ff ff       	callq  1070 <printf@plt>
    1297:	c6 45 e3 0b          	movb   $0xb,-0x1d(%rbp)
    129b:	80 4d e3 80          	orb    $0x80,-0x1d(%rbp)
    129f:	0f b6 45 e3          	movzbl -0x1d(%rbp),%eax
    12a3:	89 c6                	mov    %eax,%esi
    12a5:	48 8d 3d c4 0d 00 00 	lea    0xdc4(%rip),%rdi        # 2070 <_IO_stdin_used+0x70>
    12ac:	b8 00 00 00 00       	mov    $0x0,%eax
    12b1:	e8 ba fd ff ff       	callq  1070 <printf@plt>
    12b6:	be 02 00 00 00       	mov    $0x2,%esi
    12bb:	48 8d 3d bb 0d 00 00 	lea    0xdbb(%rip),%rdi        # 207d <_IO_stdin_used+0x7d>
    12c2:	b8 00 00 00 00       	mov    $0x0,%eax
    12c7:	e8 a4 fd ff ff       	callq  1070 <printf@plt>
    12cc:	66 c7 45 f6 05 f0    	movw   $0xf005,-0xa(%rbp)
    12d2:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    12d6:	0f b6 d0             	movzbl %al,%edx
    12d9:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    12dd:	0f b6 c0             	movzbl %al,%eax
    12e0:	89 c6                	mov    %eax,%esi
    12e2:	48 8d 3d ad 0d 00 00 	lea    0xdad(%rip),%rdi        # 2096 <_IO_stdin_used+0x96>
    12e9:	b8 00 00 00 00       	mov    $0x0,%eax
    12ee:	e8 7d fd ff ff       	callq  1070 <printf@plt>
    12f3:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    12f7:	83 c8 08             	or     $0x8,%eax
    12fa:	88 45 f6             	mov    %al,-0xa(%rbp)
    12fd:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    1301:	0f b6 d0             	movzbl %al,%edx
    1304:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    1308:	0f b6 c0             	movzbl %al,%eax
    130b:	89 c6                	mov    %eax,%esi
    130d:	48 8d 3d 82 0d 00 00 	lea    0xd82(%rip),%rdi        # 2096 <_IO_stdin_used+0x96>
    1314:	b8 00 00 00 00       	mov    $0x0,%eax
    1319:	e8 52 fd ff ff       	callq  1070 <printf@plt>
    131e:	90                   	nop
    131f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1323:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    132a:	00 00 
    132c:	74 05                	je     1333 <main+0x167>
    132e:	e8 2d fd ff ff       	callq  1060 <__stack_chk_fail@plt>
    1333:	c9                   	leaveq 
    1334:	c3                   	retq   
    1335:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    133c:	00 00 00 
    133f:	90                   	nop

0000000000001340 <__libc_csu_init>:
    1340:	f3 0f 1e fa          	endbr64 
    1344:	41 57                	push   %r15
    1346:	4c 8d 3d 63 2a 00 00 	lea    0x2a63(%rip),%r15        # 3db0 <__frame_dummy_init_array_entry>
    134d:	41 56                	push   %r14
    134f:	49 89 d6             	mov    %rdx,%r14
    1352:	41 55                	push   %r13
    1354:	49 89 f5             	mov    %rsi,%r13
    1357:	41 54                	push   %r12
    1359:	41 89 fc             	mov    %edi,%r12d
    135c:	55                   	push   %rbp
    135d:	48 8d 2d 54 2a 00 00 	lea    0x2a54(%rip),%rbp        # 3db8 <__do_global_dtors_aux_fini_array_entry>
    1364:	53                   	push   %rbx
    1365:	4c 29 fd             	sub    %r15,%rbp
    1368:	48 83 ec 08          	sub    $0x8,%rsp
    136c:	e8 8f fc ff ff       	callq  1000 <_init>
    1371:	48 c1 fd 03          	sar    $0x3,%rbp
    1375:	74 1f                	je     1396 <__libc_csu_init+0x56>
    1377:	31 db                	xor    %ebx,%ebx
    1379:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1380:	4c 89 f2             	mov    %r14,%rdx
    1383:	4c 89 ee             	mov    %r13,%rsi
    1386:	44 89 e7             	mov    %r12d,%edi
    1389:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    138d:	48 83 c3 01          	add    $0x1,%rbx
    1391:	48 39 dd             	cmp    %rbx,%rbp
    1394:	75 ea                	jne    1380 <__libc_csu_init+0x40>
    1396:	48 83 c4 08          	add    $0x8,%rsp
    139a:	5b                   	pop    %rbx
    139b:	5d                   	pop    %rbp
    139c:	41 5c                	pop    %r12
    139e:	41 5d                	pop    %r13
    13a0:	41 5e                	pop    %r14
    13a2:	41 5f                	pop    %r15
    13a4:	c3                   	retq   
    13a5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    13ac:	00 00 00 00 

00000000000013b0 <__libc_csu_fini>:
    13b0:	f3 0f 1e fa          	endbr64 
    13b4:	c3                   	retq   

Disassembly of section .fini:

00000000000013b8 <_fini>:
    13b8:	f3 0f 1e fa          	endbr64 
    13bc:	48 83 ec 08          	sub    $0x8,%rsp
    13c0:	48 83 c4 08          	add    $0x8,%rsp
    13c4:	c3                   	retq   
