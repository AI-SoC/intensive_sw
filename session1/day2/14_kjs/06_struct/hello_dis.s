
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
    1084:	48 83 ec 18          	sub    $0x18,%rsp
    1088:	ba 01 00 00 00       	mov    $0x1,%edx
    108d:	bf 01 00 00 00       	mov    $0x1,%edi
    1092:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1099:	00 00 
    109b:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    10a0:	31 c0                	xor    %eax,%eax
    10a2:	48 8d 35 74 0f 00 00 	lea    0xf74(%rip),%rsi        # 201d <_IO_stdin_used+0x1d>
    10a9:	c7 44 24 04 01 80 00 	movl   $0xf0008001,0x4(%rsp)
    10b0:	f0 
    10b1:	e8 ba ff ff ff       	callq  1070 <__printf_chk@plt>
    10b6:	0f b6 54 24 05       	movzbl 0x5(%rsp),%edx
    10bb:	48 8d 35 6a 0f 00 00 	lea    0xf6a(%rip),%rsi        # 202c <_IO_stdin_used+0x2c>
    10c2:	31 c0                	xor    %eax,%eax
    10c4:	bf 01 00 00 00       	mov    $0x1,%edi
    10c9:	e8 a2 ff ff ff       	callq  1070 <__printf_chk@plt>
    10ce:	0f b7 54 24 06       	movzwl 0x6(%rsp),%edx
    10d3:	48 8d 35 61 0f 00 00 	lea    0xf61(%rip),%rsi        # 203b <_IO_stdin_used+0x3b>
    10da:	31 c0                	xor    %eax,%eax
    10dc:	bf 01 00 00 00       	mov    $0x1,%edi
    10e1:	e8 8a ff ff ff       	callq  1070 <__printf_chk@plt>
    10e6:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
    10eb:	be 04 00 00 00       	mov    $0x4,%esi
    10f0:	e8 ab 01 00 00       	callq  12a0 <mem_inspection>
    10f5:	ba 5a 00 00 00       	mov    $0x5a,%edx
    10fa:	48 8d 35 2b 0f 00 00 	lea    0xf2b(%rip),%rsi        # 202c <_IO_stdin_used+0x2c>
    1101:	31 c0                	xor    %eax,%eax
    1103:	bf 01 00 00 00       	mov    $0x1,%edi
    1108:	c6 44 24 05 5a       	movb   $0x5a,0x5(%rsp)
    110d:	e8 5e ff ff ff       	callq  1070 <__printf_chk@plt>
    1112:	ba 01 00 00 00       	mov    $0x1,%edx
    1117:	48 8d 35 6a 0f 00 00 	lea    0xf6a(%rip),%rsi        # 2088 <_IO_stdin_used+0x88>
    111e:	31 c0                	xor    %eax,%eax
    1120:	bf 01 00 00 00       	mov    $0x1,%edi
    1125:	e8 46 ff ff ff       	callq  1070 <__printf_chk@plt>
    112a:	ba 80 00 00 00       	mov    $0x80,%edx
    112f:	48 8d 35 13 0f 00 00 	lea    0xf13(%rip),%rsi        # 2049 <_IO_stdin_used+0x49>
    1136:	31 c0                	xor    %eax,%eax
    1138:	bf 01 00 00 00       	mov    $0x1,%edi
    113d:	e8 2e ff ff ff       	callq  1070 <__printf_chk@plt>
    1142:	ba 02 00 00 00       	mov    $0x2,%edx
    1147:	48 8d 35 08 0f 00 00 	lea    0xf08(%rip),%rsi        # 2056 <_IO_stdin_used+0x56>
    114e:	31 c0                	xor    %eax,%eax
    1150:	bf 01 00 00 00       	mov    $0x1,%edi
    1155:	e8 16 ff ff ff       	callq  1070 <__printf_chk@plt>
    115a:	b9 05 00 00 00       	mov    $0x5,%ecx
    115f:	ba f0 00 00 00       	mov    $0xf0,%edx
    1164:	31 c0                	xor    %eax,%eax
    1166:	48 8d 35 04 0f 00 00 	lea    0xf04(%rip),%rsi        # 2071 <_IO_stdin_used+0x71>
    116d:	bf 01 00 00 00       	mov    $0x1,%edi
    1172:	e8 f9 fe ff ff       	callq  1070 <__printf_chk@plt>
    1177:	31 c0                	xor    %eax,%eax
    1179:	b9 05 00 00 00       	mov    $0x5,%ecx
    117e:	ba 70 00 00 00       	mov    $0x70,%edx
    1183:	48 8d 35 e7 0e 00 00 	lea    0xee7(%rip),%rsi        # 2071 <_IO_stdin_used+0x71>
    118a:	bf 01 00 00 00       	mov    $0x1,%edi
    118f:	e8 dc fe ff ff       	callq  1070 <__printf_chk@plt>
    1194:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    1199:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    11a0:	00 00 
    11a2:	75 05                	jne    11a9 <main+0x129>
    11a4:	48 83 c4 18          	add    $0x18,%rsp
    11a8:	c3                   	retq   
    11a9:	e8 b2 fe ff ff       	callq  1060 <__stack_chk_fail@plt>
    11ae:	66 90                	xchg   %ax,%ax

00000000000011b0 <_start>:
    11b0:	f3 0f 1e fa          	endbr64 
    11b4:	31 ed                	xor    %ebp,%ebp
    11b6:	49 89 d1             	mov    %rdx,%r9
    11b9:	5e                   	pop    %rsi
    11ba:	48 89 e2             	mov    %rsp,%rdx
    11bd:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    11c1:	50                   	push   %rax
    11c2:	54                   	push   %rsp
    11c3:	4c 8d 05 b6 01 00 00 	lea    0x1b6(%rip),%r8        # 1380 <__libc_csu_fini>
    11ca:	48 8d 0d 3f 01 00 00 	lea    0x13f(%rip),%rcx        # 1310 <__libc_csu_init>
    11d1:	48 8d 3d a8 fe ff ff 	lea    -0x158(%rip),%rdi        # 1080 <main>
    11d8:	ff 15 02 2e 00 00    	callq  *0x2e02(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    11de:	f4                   	hlt    
    11df:	90                   	nop

00000000000011e0 <deregister_tm_clones>:
    11e0:	48 8d 3d 29 2e 00 00 	lea    0x2e29(%rip),%rdi        # 4010 <__TMC_END__>
    11e7:	48 8d 05 22 2e 00 00 	lea    0x2e22(%rip),%rax        # 4010 <__TMC_END__>
    11ee:	48 39 f8             	cmp    %rdi,%rax
    11f1:	74 15                	je     1208 <deregister_tm_clones+0x28>
    11f3:	48 8b 05 de 2d 00 00 	mov    0x2dde(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    11fa:	48 85 c0             	test   %rax,%rax
    11fd:	74 09                	je     1208 <deregister_tm_clones+0x28>
    11ff:	ff e0                	jmpq   *%rax
    1201:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1208:	c3                   	retq   
    1209:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001210 <register_tm_clones>:
    1210:	48 8d 3d f9 2d 00 00 	lea    0x2df9(%rip),%rdi        # 4010 <__TMC_END__>
    1217:	48 8d 35 f2 2d 00 00 	lea    0x2df2(%rip),%rsi        # 4010 <__TMC_END__>
    121e:	48 29 fe             	sub    %rdi,%rsi
    1221:	48 89 f0             	mov    %rsi,%rax
    1224:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1228:	48 c1 f8 03          	sar    $0x3,%rax
    122c:	48 01 c6             	add    %rax,%rsi
    122f:	48 d1 fe             	sar    %rsi
    1232:	74 14                	je     1248 <register_tm_clones+0x38>
    1234:	48 8b 05 b5 2d 00 00 	mov    0x2db5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    123b:	48 85 c0             	test   %rax,%rax
    123e:	74 08                	je     1248 <register_tm_clones+0x38>
    1240:	ff e0                	jmpq   *%rax
    1242:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1248:	c3                   	retq   
    1249:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001250 <__do_global_dtors_aux>:
    1250:	f3 0f 1e fa          	endbr64 
    1254:	80 3d b5 2d 00 00 00 	cmpb   $0x0,0x2db5(%rip)        # 4010 <__TMC_END__>
    125b:	75 2b                	jne    1288 <__do_global_dtors_aux+0x38>
    125d:	55                   	push   %rbp
    125e:	48 83 3d 92 2d 00 00 	cmpq   $0x0,0x2d92(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1265:	00 
    1266:	48 89 e5             	mov    %rsp,%rbp
    1269:	74 0c                	je     1277 <__do_global_dtors_aux+0x27>
    126b:	48 8b 3d 96 2d 00 00 	mov    0x2d96(%rip),%rdi        # 4008 <__dso_handle>
    1272:	e8 d9 fd ff ff       	callq  1050 <__cxa_finalize@plt>
    1277:	e8 64 ff ff ff       	callq  11e0 <deregister_tm_clones>
    127c:	c6 05 8d 2d 00 00 01 	movb   $0x1,0x2d8d(%rip)        # 4010 <__TMC_END__>
    1283:	5d                   	pop    %rbp
    1284:	c3                   	retq   
    1285:	0f 1f 00             	nopl   (%rax)
    1288:	c3                   	retq   
    1289:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001290 <frame_dummy>:
    1290:	f3 0f 1e fa          	endbr64 
    1294:	e9 77 ff ff ff       	jmpq   1210 <register_tm_clones>
    1299:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012a0 <mem_inspection>:
    12a0:	f3 0f 1e fa          	endbr64 
    12a4:	85 f6                	test   %esi,%esi
    12a6:	7e 58                	jle    1300 <mem_inspection+0x60>
    12a8:	41 55                	push   %r13
    12aa:	4c 8d 2d 53 0d 00 00 	lea    0xd53(%rip),%r13        # 2004 <_IO_stdin_used+0x4>
    12b1:	41 54                	push   %r12
    12b3:	41 89 f4             	mov    %esi,%r12d
    12b6:	55                   	push   %rbp
    12b7:	31 ed                	xor    %ebp,%ebp
    12b9:	53                   	push   %rbx
    12ba:	48 89 fb             	mov    %rdi,%rbx
    12bd:	48 83 ec 08          	sub    $0x8,%rsp
    12c1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    12c8:	0f b6 0b             	movzbl (%rbx),%ecx
    12cb:	49 89 d8             	mov    %rbx,%r8
    12ce:	89 ea                	mov    %ebp,%edx
    12d0:	4c 89 ee             	mov    %r13,%rsi
    12d3:	bf 01 00 00 00       	mov    $0x1,%edi
    12d8:	31 c0                	xor    %eax,%eax
    12da:	83 c5 01             	add    $0x1,%ebp
    12dd:	48 83 c3 01          	add    $0x1,%rbx
    12e1:	e8 8a fd ff ff       	callq  1070 <__printf_chk@plt>
    12e6:	41 39 ec             	cmp    %ebp,%r12d
    12e9:	75 dd                	jne    12c8 <mem_inspection+0x28>
    12eb:	48 83 c4 08          	add    $0x8,%rsp
    12ef:	5b                   	pop    %rbx
    12f0:	5d                   	pop    %rbp
    12f1:	41 5c                	pop    %r12
    12f3:	41 5d                	pop    %r13
    12f5:	c3                   	retq   
    12f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    12fd:	00 00 00 
    1300:	c3                   	retq   
    1301:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    1308:	00 00 00 
    130b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001310 <__libc_csu_init>:
    1310:	f3 0f 1e fa          	endbr64 
    1314:	41 57                	push   %r15
    1316:	4c 8d 3d 93 2a 00 00 	lea    0x2a93(%rip),%r15        # 3db0 <__frame_dummy_init_array_entry>
    131d:	41 56                	push   %r14
    131f:	49 89 d6             	mov    %rdx,%r14
    1322:	41 55                	push   %r13
    1324:	49 89 f5             	mov    %rsi,%r13
    1327:	41 54                	push   %r12
    1329:	41 89 fc             	mov    %edi,%r12d
    132c:	55                   	push   %rbp
    132d:	48 8d 2d 84 2a 00 00 	lea    0x2a84(%rip),%rbp        # 3db8 <__do_global_dtors_aux_fini_array_entry>
    1334:	53                   	push   %rbx
    1335:	4c 29 fd             	sub    %r15,%rbp
    1338:	48 83 ec 08          	sub    $0x8,%rsp
    133c:	e8 bf fc ff ff       	callq  1000 <_init>
    1341:	48 c1 fd 03          	sar    $0x3,%rbp
    1345:	74 1f                	je     1366 <__libc_csu_init+0x56>
    1347:	31 db                	xor    %ebx,%ebx
    1349:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1350:	4c 89 f2             	mov    %r14,%rdx
    1353:	4c 89 ee             	mov    %r13,%rsi
    1356:	44 89 e7             	mov    %r12d,%edi
    1359:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    135d:	48 83 c3 01          	add    $0x1,%rbx
    1361:	48 39 dd             	cmp    %rbx,%rbp
    1364:	75 ea                	jne    1350 <__libc_csu_init+0x40>
    1366:	48 83 c4 08          	add    $0x8,%rsp
    136a:	5b                   	pop    %rbx
    136b:	5d                   	pop    %rbp
    136c:	41 5c                	pop    %r12
    136e:	41 5d                	pop    %r13
    1370:	41 5e                	pop    %r14
    1372:	41 5f                	pop    %r15
    1374:	c3                   	retq   
    1375:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    137c:	00 00 00 00 

0000000000001380 <__libc_csu_fini>:
    1380:	f3 0f 1e fa          	endbr64 
    1384:	c3                   	retq   

Disassembly of section .fini:

0000000000001388 <_fini>:
    1388:	f3 0f 1e fa          	endbr64 
    138c:	48 83 ec 08          	sub    $0x8,%rsp
    1390:	48 83 c4 08          	add    $0x8,%rsp
    1394:	c3                   	retq   
