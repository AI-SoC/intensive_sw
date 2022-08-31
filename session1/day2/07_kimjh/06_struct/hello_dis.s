
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
    1093:	4c 8d 05 06 03 00 00 	lea    0x306(%rip),%r8        # 13a0 <__libc_csu_fini>
    109a:	48 8d 0d 8f 02 00 00 	lea    0x28f(%rip),%rcx        # 1330 <__libc_csu_init>
    10a1:	48 8d 3d 1a 01 00 00 	lea    0x11a(%rip),%rdi        # 11c2 <main>
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
    1183:	eb 31                	jmp    11b6 <mem_inspection+0x4d>
    1185:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1188:	48 63 d0             	movslq %eax,%rdx
    118b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    118f:	48 01 d0             	add    %rdx,%rax
    1192:	0f b6 00             	movzbl (%rax),%eax
    1195:	0f b6 d0             	movzbl %al,%edx
    1198:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
    119c:	8b 45 fc             	mov    -0x4(%rbp),%eax
    119f:	89 c6                	mov    %eax,%esi
    11a1:	48 8d 3d 60 0e 00 00 	lea    0xe60(%rip),%rdi        # 2008 <_IO_stdin_used+0x8>
    11a8:	b8 00 00 00 00       	mov    $0x0,%eax
    11ad:	e8 be fe ff ff       	callq  1070 <printf@plt>
    11b2:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
    11b6:	8b 45 fc             	mov    -0x4(%rbp),%eax
    11b9:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
    11bc:	7c c7                	jl     1185 <mem_inspection+0x1c>
    11be:	90                   	nop
    11bf:	90                   	nop
    11c0:	c9                   	leaveq 
    11c1:	c3                   	retq   

00000000000011c2 <main>:
    11c2:	f3 0f 1e fa          	endbr64 
    11c6:	55                   	push   %rbp
    11c7:	48 89 e5             	mov    %rsp,%rbp
    11ca:	48 83 ec 20          	sub    $0x20,%rsp
    11ce:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    11d5:	00 00 
    11d7:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    11db:	31 c0                	xor    %eax,%eax
    11dd:	c6 45 e4 01          	movb   $0x1,-0x1c(%rbp)
    11e1:	c6 45 e5 80          	movb   $0x80,-0x1b(%rbp)
    11e5:	66 c7 45 e6 00 f0    	movw   $0xf000,-0x1a(%rbp)
    11eb:	0f b6 45 e4          	movzbl -0x1c(%rbp),%eax
    11ef:	0f b6 c0             	movzbl %al,%eax
    11f2:	89 c6                	mov    %eax,%esi
    11f4:	48 8d 3d 26 0e 00 00 	lea    0xe26(%rip),%rdi        # 2021 <_IO_stdin_used+0x21>
    11fb:	b8 00 00 00 00       	mov    $0x0,%eax
    1200:	e8 6b fe ff ff       	callq  1070 <printf@plt>
    1205:	0f b6 45 e5          	movzbl -0x1b(%rbp),%eax
    1209:	0f b6 c0             	movzbl %al,%eax
    120c:	89 c6                	mov    %eax,%esi
    120e:	48 8d 3d 0c 0e 00 00 	lea    0xe0c(%rip),%rdi        # 2021 <_IO_stdin_used+0x21>
    1215:	b8 00 00 00 00       	mov    $0x0,%eax
    121a:	e8 51 fe ff ff       	callq  1070 <printf@plt>
    121f:	0f b7 45 e6          	movzwl -0x1a(%rbp),%eax
    1223:	0f b7 c0             	movzwl %ax,%eax
    1226:	89 c6                	mov    %eax,%esi
    1228:	48 8d 3d 02 0e 00 00 	lea    0xe02(%rip),%rdi        # 2031 <_IO_stdin_used+0x31>
    122f:	b8 00 00 00 00       	mov    $0x0,%eax
    1234:	e8 37 fe ff ff       	callq  1070 <printf@plt>
    1239:	48 8d 45 e4          	lea    -0x1c(%rbp),%rax
    123d:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1241:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1245:	be 04 00 00 00       	mov    $0x4,%esi
    124a:	48 89 c7             	mov    %rax,%rdi
    124d:	e8 17 ff ff ff       	callq  1169 <mem_inspection>
    1252:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1256:	48 83 c0 01          	add    $0x1,%rax
    125a:	c6 00 5a             	movb   $0x5a,(%rax)
    125d:	0f b6 45 e5          	movzbl -0x1b(%rbp),%eax
    1261:	0f b6 c0             	movzbl %al,%eax
    1264:	89 c6                	mov    %eax,%esi
    1266:	48 8d 3d b4 0d 00 00 	lea    0xdb4(%rip),%rdi        # 2021 <_IO_stdin_used+0x21>
    126d:	b8 00 00 00 00       	mov    $0x0,%eax
    1272:	e8 f9 fd ff ff       	callq  1070 <printf@plt>
    1277:	be 01 00 00 00       	mov    $0x1,%esi
    127c:	48 8d 3d c5 0d 00 00 	lea    0xdc5(%rip),%rdi        # 2048 <_IO_stdin_used+0x48>
    1283:	b8 00 00 00 00       	mov    $0x0,%eax
    1288:	e8 e3 fd ff ff       	callq  1070 <printf@plt>
    128d:	c6 45 e3 0b          	movb   $0xb,-0x1d(%rbp)
    1291:	80 4d e3 80          	orb    $0x80,-0x1d(%rbp)
    1295:	0f b6 45 e3          	movzbl -0x1d(%rbp),%eax
    1299:	89 c6                	mov    %eax,%esi
    129b:	48 8d 3d d0 0d 00 00 	lea    0xdd0(%rip),%rdi        # 2072 <_IO_stdin_used+0x72>
    12a2:	b8 00 00 00 00       	mov    $0x0,%eax
    12a7:	e8 c4 fd ff ff       	callq  1070 <printf@plt>
    12ac:	be 02 00 00 00       	mov    $0x2,%esi
    12b1:	48 8d 3d c8 0d 00 00 	lea    0xdc8(%rip),%rdi        # 2080 <_IO_stdin_used+0x80>
    12b8:	b8 00 00 00 00       	mov    $0x0,%eax
    12bd:	e8 ae fd ff ff       	callq  1070 <printf@plt>
    12c2:	66 c7 45 f6 05 f0    	movw   $0xf005,-0xa(%rbp)
    12c8:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    12cc:	0f b6 d0             	movzbl %al,%edx
    12cf:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    12d3:	0f b6 c0             	movzbl %al,%eax
    12d6:	89 c6                	mov    %eax,%esi
    12d8:	48 8d 3d ba 0d 00 00 	lea    0xdba(%rip),%rdi        # 2099 <_IO_stdin_used+0x99>
    12df:	b8 00 00 00 00       	mov    $0x0,%eax
    12e4:	e8 87 fd ff ff       	callq  1070 <printf@plt>
    12e9:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    12ed:	83 e0 7f             	and    $0x7f,%eax
    12f0:	88 45 f7             	mov    %al,-0x9(%rbp)
    12f3:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    12f7:	0f b6 d0             	movzbl %al,%edx
    12fa:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    12fe:	0f b6 c0             	movzbl %al,%eax
    1301:	89 c6                	mov    %eax,%esi
    1303:	48 8d 3d 8f 0d 00 00 	lea    0xd8f(%rip),%rdi        # 2099 <_IO_stdin_used+0x99>
    130a:	b8 00 00 00 00       	mov    $0x0,%eax
    130f:	e8 5c fd ff ff       	callq  1070 <printf@plt>
    1314:	90                   	nop
    1315:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1319:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1320:	00 00 
    1322:	74 05                	je     1329 <main+0x167>
    1324:	e8 37 fd ff ff       	callq  1060 <__stack_chk_fail@plt>
    1329:	c9                   	leaveq 
    132a:	c3                   	retq   
    132b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001330 <__libc_csu_init>:
    1330:	f3 0f 1e fa          	endbr64 
    1334:	41 57                	push   %r15
    1336:	4c 8d 3d 73 2a 00 00 	lea    0x2a73(%rip),%r15        # 3db0 <__frame_dummy_init_array_entry>
    133d:	41 56                	push   %r14
    133f:	49 89 d6             	mov    %rdx,%r14
    1342:	41 55                	push   %r13
    1344:	49 89 f5             	mov    %rsi,%r13
    1347:	41 54                	push   %r12
    1349:	41 89 fc             	mov    %edi,%r12d
    134c:	55                   	push   %rbp
    134d:	48 8d 2d 64 2a 00 00 	lea    0x2a64(%rip),%rbp        # 3db8 <__do_global_dtors_aux_fini_array_entry>
    1354:	53                   	push   %rbx
    1355:	4c 29 fd             	sub    %r15,%rbp
    1358:	48 83 ec 08          	sub    $0x8,%rsp
    135c:	e8 9f fc ff ff       	callq  1000 <_init>
    1361:	48 c1 fd 03          	sar    $0x3,%rbp
    1365:	74 1f                	je     1386 <__libc_csu_init+0x56>
    1367:	31 db                	xor    %ebx,%ebx
    1369:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1370:	4c 89 f2             	mov    %r14,%rdx
    1373:	4c 89 ee             	mov    %r13,%rsi
    1376:	44 89 e7             	mov    %r12d,%edi
    1379:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    137d:	48 83 c3 01          	add    $0x1,%rbx
    1381:	48 39 dd             	cmp    %rbx,%rbp
    1384:	75 ea                	jne    1370 <__libc_csu_init+0x40>
    1386:	48 83 c4 08          	add    $0x8,%rsp
    138a:	5b                   	pop    %rbx
    138b:	5d                   	pop    %rbp
    138c:	41 5c                	pop    %r12
    138e:	41 5d                	pop    %r13
    1390:	41 5e                	pop    %r14
    1392:	41 5f                	pop    %r15
    1394:	c3                   	retq   
    1395:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    139c:	00 00 00 00 

00000000000013a0 <__libc_csu_fini>:
    13a0:	f3 0f 1e fa          	endbr64 
    13a4:	c3                   	retq   

Disassembly of section .fini:

00000000000013a8 <_fini>:
    13a8:	f3 0f 1e fa          	endbr64 
    13ac:	48 83 ec 08          	sub    $0x8,%rsp
    13b0:	48 83 c4 08          	add    $0x8,%rsp
    13b4:	c3                   	retq   
