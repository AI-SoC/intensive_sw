
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

0000000000001070 <__printf_chk@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 55 2f 00 00 	bnd jmpq *0x2f55(%rip)        # 3fd0 <__printf_chk@GLIBC_2.3.4>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001080 <main>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	41 54                	push   %r12
    1086:	ba 01 00 00 00       	mov    $0x1,%edx
    108b:	bf 01 00 00 00       	mov    $0x1,%edi
    1090:	48 8d 35 86 0f 00 00 	lea    0xf86(%rip),%rsi        # 201d <_IO_stdin_used+0x1d>
    1097:	41 bc 70 00 00 00    	mov    $0x70,%r12d
    109d:	48 83 ec 10          	sub    $0x10,%rsp
    10a1:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    10a8:	00 00 
    10aa:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    10af:	31 c0                	xor    %eax,%eax
    10b1:	c7 44 24 04 01 80 00 	movl   $0xf0008001,0x4(%rsp)
    10b8:	f0 
    10b9:	e8 b2 ff ff ff       	callq  1070 <__printf_chk@plt>
    10be:	0f b6 54 24 05       	movzbl 0x5(%rsp),%edx
    10c3:	48 8d 35 63 0f 00 00 	lea    0xf63(%rip),%rsi        # 202d <_IO_stdin_used+0x2d>
    10ca:	31 c0                	xor    %eax,%eax
    10cc:	bf 01 00 00 00       	mov    $0x1,%edi
    10d1:	e8 9a ff ff ff       	callq  1070 <__printf_chk@plt>
    10d6:	0f b7 54 24 06       	movzwl 0x6(%rsp),%edx
    10db:	48 8d 35 5b 0f 00 00 	lea    0xf5b(%rip),%rsi        # 203d <_IO_stdin_used+0x3d>
    10e2:	31 c0                	xor    %eax,%eax
    10e4:	bf 01 00 00 00       	mov    $0x1,%edi
    10e9:	e8 82 ff ff ff       	callq  1070 <__printf_chk@plt>
    10ee:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
    10f3:	be 04 00 00 00       	mov    $0x4,%esi
    10f8:	e8 d3 01 00 00       	callq  12d0 <mem_inspection>
    10fd:	ba 5a 00 00 00       	mov    $0x5a,%edx
    1102:	48 8d 35 43 0f 00 00 	lea    0xf43(%rip),%rsi        # 204c <_IO_stdin_used+0x4c>
    1109:	31 c0                	xor    %eax,%eax
    110b:	bf 01 00 00 00       	mov    $0x1,%edi
    1110:	c6 44 24 05 5a       	movb   $0x5a,0x5(%rsp)
    1115:	e8 56 ff ff ff       	callq  1070 <__printf_chk@plt>
    111a:	ba 01 00 00 00       	mov    $0x1,%edx
    111f:	48 8d 35 72 0f 00 00 	lea    0xf72(%rip),%rsi        # 2098 <_IO_stdin_used+0x98>
    1126:	31 c0                	xor    %eax,%eax
    1128:	bf 01 00 00 00       	mov    $0x1,%edi
    112d:	e8 3e ff ff ff       	callq  1070 <__printf_chk@plt>
    1132:	ba 8b 00 00 00       	mov    $0x8b,%edx
    1137:	48 8d 35 1d 0f 00 00 	lea    0xf1d(%rip),%rsi        # 205b <_IO_stdin_used+0x5b>
    113e:	31 c0                	xor    %eax,%eax
    1140:	bf 01 00 00 00       	mov    $0x1,%edi
    1145:	e8 26 ff ff ff       	callq  1070 <__printf_chk@plt>
    114a:	ba 02 00 00 00       	mov    $0x2,%edx
    114f:	48 8d 35 12 0f 00 00 	lea    0xf12(%rip),%rsi        # 2068 <_IO_stdin_used+0x68>
    1156:	31 c0                	xor    %eax,%eax
    1158:	bf 01 00 00 00       	mov    $0x1,%edi
    115d:	e8 0e ff ff ff       	callq  1070 <__printf_chk@plt>
    1162:	b9 05 00 00 00       	mov    $0x5,%ecx
    1167:	ba f0 00 00 00       	mov    $0xf0,%edx
    116c:	31 c0                	xor    %eax,%eax
    116e:	48 8d 35 0c 0f 00 00 	lea    0xf0c(%rip),%rsi        # 2081 <_IO_stdin_used+0x81>
    1175:	bf 01 00 00 00       	mov    $0x1,%edi
    117a:	e8 f1 fe ff ff       	callq  1070 <__printf_chk@plt>
    117f:	b9 05 00 00 00       	mov    $0x5,%ecx
    1184:	44 89 e2             	mov    %r12d,%edx
    1187:	31 c0                	xor    %eax,%eax
    1189:	48 8d 35 f1 0e 00 00 	lea    0xef1(%rip),%rsi        # 2081 <_IO_stdin_used+0x81>
    1190:	bf 01 00 00 00       	mov    $0x1,%edi
    1195:	e8 d6 fe ff ff       	callq  1070 <__printf_chk@plt>
    119a:	31 c0                	xor    %eax,%eax
    119c:	b9 0d 00 00 00       	mov    $0xd,%ecx
    11a1:	44 89 e2             	mov    %r12d,%edx
    11a4:	48 8d 35 d6 0e 00 00 	lea    0xed6(%rip),%rsi        # 2081 <_IO_stdin_used+0x81>
    11ab:	bf 01 00 00 00       	mov    $0x1,%edi
    11b0:	e8 bb fe ff ff       	callq  1070 <__printf_chk@plt>
    11b5:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    11ba:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    11c1:	00 00 
    11c3:	75 07                	jne    11cc <main+0x14c>
    11c5:	48 83 c4 10          	add    $0x10,%rsp
    11c9:	41 5c                	pop    %r12
    11cb:	c3                   	retq   
    11cc:	e8 8f fe ff ff       	callq  1060 <__stack_chk_fail@plt>
    11d1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    11d8:	00 00 00 
    11db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011e0 <_start>:
    11e0:	f3 0f 1e fa          	endbr64 
    11e4:	31 ed                	xor    %ebp,%ebp
    11e6:	49 89 d1             	mov    %rdx,%r9
    11e9:	5e                   	pop    %rsi
    11ea:	48 89 e2             	mov    %rsp,%rdx
    11ed:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    11f1:	50                   	push   %rax
    11f2:	54                   	push   %rsp
    11f3:	4c 8d 05 b6 01 00 00 	lea    0x1b6(%rip),%r8        # 13b0 <__libc_csu_fini>
    11fa:	48 8d 0d 3f 01 00 00 	lea    0x13f(%rip),%rcx        # 1340 <__libc_csu_init>
    1201:	48 8d 3d 78 fe ff ff 	lea    -0x188(%rip),%rdi        # 1080 <main>
    1208:	ff 15 d2 2d 00 00    	callq  *0x2dd2(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    120e:	f4                   	hlt    
    120f:	90                   	nop

0000000000001210 <deregister_tm_clones>:
    1210:	48 8d 3d f9 2d 00 00 	lea    0x2df9(%rip),%rdi        # 4010 <__TMC_END__>
    1217:	48 8d 05 f2 2d 00 00 	lea    0x2df2(%rip),%rax        # 4010 <__TMC_END__>
    121e:	48 39 f8             	cmp    %rdi,%rax
    1221:	74 15                	je     1238 <deregister_tm_clones+0x28>
    1223:	48 8b 05 ae 2d 00 00 	mov    0x2dae(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    122a:	48 85 c0             	test   %rax,%rax
    122d:	74 09                	je     1238 <deregister_tm_clones+0x28>
    122f:	ff e0                	jmpq   *%rax
    1231:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1238:	c3                   	retq   
    1239:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001240 <register_tm_clones>:
    1240:	48 8d 3d c9 2d 00 00 	lea    0x2dc9(%rip),%rdi        # 4010 <__TMC_END__>
    1247:	48 8d 35 c2 2d 00 00 	lea    0x2dc2(%rip),%rsi        # 4010 <__TMC_END__>
    124e:	48 29 fe             	sub    %rdi,%rsi
    1251:	48 89 f0             	mov    %rsi,%rax
    1254:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1258:	48 c1 f8 03          	sar    $0x3,%rax
    125c:	48 01 c6             	add    %rax,%rsi
    125f:	48 d1 fe             	sar    %rsi
    1262:	74 14                	je     1278 <register_tm_clones+0x38>
    1264:	48 8b 05 85 2d 00 00 	mov    0x2d85(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    126b:	48 85 c0             	test   %rax,%rax
    126e:	74 08                	je     1278 <register_tm_clones+0x38>
    1270:	ff e0                	jmpq   *%rax
    1272:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1278:	c3                   	retq   
    1279:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001280 <__do_global_dtors_aux>:
    1280:	f3 0f 1e fa          	endbr64 
    1284:	80 3d 85 2d 00 00 00 	cmpb   $0x0,0x2d85(%rip)        # 4010 <__TMC_END__>
    128b:	75 2b                	jne    12b8 <__do_global_dtors_aux+0x38>
    128d:	55                   	push   %rbp
    128e:	48 83 3d 62 2d 00 00 	cmpq   $0x0,0x2d62(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1295:	00 
    1296:	48 89 e5             	mov    %rsp,%rbp
    1299:	74 0c                	je     12a7 <__do_global_dtors_aux+0x27>
    129b:	48 8b 3d 66 2d 00 00 	mov    0x2d66(%rip),%rdi        # 4008 <__dso_handle>
    12a2:	e8 a9 fd ff ff       	callq  1050 <__cxa_finalize@plt>
    12a7:	e8 64 ff ff ff       	callq  1210 <deregister_tm_clones>
    12ac:	c6 05 5d 2d 00 00 01 	movb   $0x1,0x2d5d(%rip)        # 4010 <__TMC_END__>
    12b3:	5d                   	pop    %rbp
    12b4:	c3                   	retq   
    12b5:	0f 1f 00             	nopl   (%rax)
    12b8:	c3                   	retq   
    12b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012c0 <frame_dummy>:
    12c0:	f3 0f 1e fa          	endbr64 
    12c4:	e9 77 ff ff ff       	jmpq   1240 <register_tm_clones>
    12c9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012d0 <mem_inspection>:
    12d0:	f3 0f 1e fa          	endbr64 
    12d4:	85 f6                	test   %esi,%esi
    12d6:	7e 58                	jle    1330 <mem_inspection+0x60>
    12d8:	41 55                	push   %r13
    12da:	4c 8d 2d 23 0d 00 00 	lea    0xd23(%rip),%r13        # 2004 <_IO_stdin_used+0x4>
    12e1:	41 54                	push   %r12
    12e3:	41 89 f4             	mov    %esi,%r12d
    12e6:	55                   	push   %rbp
    12e7:	31 ed                	xor    %ebp,%ebp
    12e9:	53                   	push   %rbx
    12ea:	48 89 fb             	mov    %rdi,%rbx
    12ed:	48 83 ec 08          	sub    $0x8,%rsp
    12f1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    12f8:	0f b6 0b             	movzbl (%rbx),%ecx
    12fb:	49 89 d8             	mov    %rbx,%r8
    12fe:	89 ea                	mov    %ebp,%edx
    1300:	4c 89 ee             	mov    %r13,%rsi
    1303:	bf 01 00 00 00       	mov    $0x1,%edi
    1308:	31 c0                	xor    %eax,%eax
    130a:	83 c5 01             	add    $0x1,%ebp
    130d:	48 83 c3 01          	add    $0x1,%rbx
    1311:	e8 5a fd ff ff       	callq  1070 <__printf_chk@plt>
    1316:	41 39 ec             	cmp    %ebp,%r12d
    1319:	75 dd                	jne    12f8 <mem_inspection+0x28>
    131b:	48 83 c4 08          	add    $0x8,%rsp
    131f:	5b                   	pop    %rbx
    1320:	5d                   	pop    %rbp
    1321:	41 5c                	pop    %r12
    1323:	41 5d                	pop    %r13
    1325:	c3                   	retq   
    1326:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    132d:	00 00 00 
    1330:	c3                   	retq   
    1331:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    1338:	00 00 00 
    133b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

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
