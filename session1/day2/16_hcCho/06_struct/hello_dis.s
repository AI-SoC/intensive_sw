
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
    10a9:	c7 04 24 01 80 00 f0 	movl   $0xf0008001,(%rsp)
    10b0:	e8 bb ff ff ff       	callq  1070 <__printf_chk@plt>
    10b5:	0f b6 54 24 01       	movzbl 0x1(%rsp),%edx
    10ba:	48 8d 35 6c 0f 00 00 	lea    0xf6c(%rip),%rsi        # 202d <_IO_stdin_used+0x2d>
    10c1:	31 c0                	xor    %eax,%eax
    10c3:	bf 01 00 00 00       	mov    $0x1,%edi
    10c8:	e8 a3 ff ff ff       	callq  1070 <__printf_chk@plt>
    10cd:	0f b7 54 24 02       	movzwl 0x2(%rsp),%edx
    10d2:	48 8d 35 64 0f 00 00 	lea    0xf64(%rip),%rsi        # 203d <_IO_stdin_used+0x3d>
    10d9:	31 c0                	xor    %eax,%eax
    10db:	bf 01 00 00 00       	mov    $0x1,%edi
    10e0:	e8 8b ff ff ff       	callq  1070 <__printf_chk@plt>
    10e5:	48 89 e7             	mov    %rsp,%rdi
    10e8:	be 04 00 00 00       	mov    $0x4,%esi
    10ed:	e8 9e 01 00 00       	callq  1290 <mem_insepction>
    10f2:	ba 5a 00 00 00       	mov    $0x5a,%edx
    10f7:	48 8d 35 2f 0f 00 00 	lea    0xf2f(%rip),%rsi        # 202d <_IO_stdin_used+0x2d>
    10fe:	31 c0                	xor    %eax,%eax
    1100:	bf 01 00 00 00       	mov    $0x1,%edi
    1105:	c6 44 24 01 5a       	movb   $0x5a,0x1(%rsp)
    110a:	e8 61 ff ff ff       	callq  1070 <__printf_chk@plt>
    110f:	ba 01 00 00 00       	mov    $0x1,%edx
    1114:	48 8d 35 32 0f 00 00 	lea    0xf32(%rip),%rsi        # 204d <_IO_stdin_used+0x4d>
    111b:	31 c0                	xor    %eax,%eax
    111d:	bf 01 00 00 00       	mov    $0x1,%edi
    1122:	e8 49 ff ff ff       	callq  1070 <__printf_chk@plt>
    1127:	ba 8b 00 00 00       	mov    $0x8b,%edx
    112c:	48 8d 35 37 0f 00 00 	lea    0xf37(%rip),%rsi        # 206a <_IO_stdin_used+0x6a>
    1133:	31 c0                	xor    %eax,%eax
    1135:	bf 01 00 00 00       	mov    $0x1,%edi
    113a:	e8 31 ff ff ff       	callq  1070 <__printf_chk@plt>
    113f:	b8 85 f0 ff ff       	mov    $0xfffff085,%eax
    1144:	ba 04 00 00 00       	mov    $0x4,%edx
    1149:	48 8d 35 40 0f 00 00 	lea    0xf40(%rip),%rsi        # 2090 <_IO_stdin_used+0x90>
    1150:	66 89 44 24 04       	mov    %ax,0x4(%rsp)
    1155:	bf 01 00 00 00       	mov    $0x1,%edi
    115a:	31 c0                	xor    %eax,%eax
    115c:	e8 0f ff ff ff       	callq  1070 <__printf_chk@plt>
    1161:	0f b6 4c 24 04       	movzbl 0x4(%rsp),%ecx
    1166:	31 c0                	xor    %eax,%eax
    1168:	ba f0 00 00 00       	mov    $0xf0,%edx
    116d:	48 8d 35 01 0f 00 00 	lea    0xf01(%rip),%rsi        # 2075 <_IO_stdin_used+0x75>
    1174:	bf 01 00 00 00       	mov    $0x1,%edi
    1179:	e8 f2 fe ff ff       	callq  1070 <__printf_chk@plt>
    117e:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    1183:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    118a:	00 00 
    118c:	75 05                	jne    1193 <main+0x113>
    118e:	48 83 c4 18          	add    $0x18,%rsp
    1192:	c3                   	retq   
    1193:	e8 c8 fe ff ff       	callq  1060 <__stack_chk_fail@plt>
    1198:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    119f:	00 

00000000000011a0 <_start>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	31 ed                	xor    %ebp,%ebp
    11a6:	49 89 d1             	mov    %rdx,%r9
    11a9:	5e                   	pop    %rsi
    11aa:	48 89 e2             	mov    %rsp,%rdx
    11ad:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    11b1:	50                   	push   %rax
    11b2:	54                   	push   %rsp
    11b3:	4c 8d 05 b6 01 00 00 	lea    0x1b6(%rip),%r8        # 1370 <__libc_csu_fini>
    11ba:	48 8d 0d 3f 01 00 00 	lea    0x13f(%rip),%rcx        # 1300 <__libc_csu_init>
    11c1:	48 8d 3d b8 fe ff ff 	lea    -0x148(%rip),%rdi        # 1080 <main>
    11c8:	ff 15 12 2e 00 00    	callq  *0x2e12(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    11ce:	f4                   	hlt    
    11cf:	90                   	nop

00000000000011d0 <deregister_tm_clones>:
    11d0:	48 8d 3d 39 2e 00 00 	lea    0x2e39(%rip),%rdi        # 4010 <__TMC_END__>
    11d7:	48 8d 05 32 2e 00 00 	lea    0x2e32(%rip),%rax        # 4010 <__TMC_END__>
    11de:	48 39 f8             	cmp    %rdi,%rax
    11e1:	74 15                	je     11f8 <deregister_tm_clones+0x28>
    11e3:	48 8b 05 ee 2d 00 00 	mov    0x2dee(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    11ea:	48 85 c0             	test   %rax,%rax
    11ed:	74 09                	je     11f8 <deregister_tm_clones+0x28>
    11ef:	ff e0                	jmpq   *%rax
    11f1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    11f8:	c3                   	retq   
    11f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001200 <register_tm_clones>:
    1200:	48 8d 3d 09 2e 00 00 	lea    0x2e09(%rip),%rdi        # 4010 <__TMC_END__>
    1207:	48 8d 35 02 2e 00 00 	lea    0x2e02(%rip),%rsi        # 4010 <__TMC_END__>
    120e:	48 29 fe             	sub    %rdi,%rsi
    1211:	48 89 f0             	mov    %rsi,%rax
    1214:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1218:	48 c1 f8 03          	sar    $0x3,%rax
    121c:	48 01 c6             	add    %rax,%rsi
    121f:	48 d1 fe             	sar    %rsi
    1222:	74 14                	je     1238 <register_tm_clones+0x38>
    1224:	48 8b 05 c5 2d 00 00 	mov    0x2dc5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    122b:	48 85 c0             	test   %rax,%rax
    122e:	74 08                	je     1238 <register_tm_clones+0x38>
    1230:	ff e0                	jmpq   *%rax
    1232:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1238:	c3                   	retq   
    1239:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001240 <__do_global_dtors_aux>:
    1240:	f3 0f 1e fa          	endbr64 
    1244:	80 3d c5 2d 00 00 00 	cmpb   $0x0,0x2dc5(%rip)        # 4010 <__TMC_END__>
    124b:	75 2b                	jne    1278 <__do_global_dtors_aux+0x38>
    124d:	55                   	push   %rbp
    124e:	48 83 3d a2 2d 00 00 	cmpq   $0x0,0x2da2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1255:	00 
    1256:	48 89 e5             	mov    %rsp,%rbp
    1259:	74 0c                	je     1267 <__do_global_dtors_aux+0x27>
    125b:	48 8b 3d a6 2d 00 00 	mov    0x2da6(%rip),%rdi        # 4008 <__dso_handle>
    1262:	e8 e9 fd ff ff       	callq  1050 <__cxa_finalize@plt>
    1267:	e8 64 ff ff ff       	callq  11d0 <deregister_tm_clones>
    126c:	c6 05 9d 2d 00 00 01 	movb   $0x1,0x2d9d(%rip)        # 4010 <__TMC_END__>
    1273:	5d                   	pop    %rbp
    1274:	c3                   	retq   
    1275:	0f 1f 00             	nopl   (%rax)
    1278:	c3                   	retq   
    1279:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001280 <frame_dummy>:
    1280:	f3 0f 1e fa          	endbr64 
    1284:	e9 77 ff ff ff       	jmpq   1200 <register_tm_clones>
    1289:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001290 <mem_insepction>:
    1290:	f3 0f 1e fa          	endbr64 
    1294:	85 f6                	test   %esi,%esi
    1296:	7e 58                	jle    12f0 <mem_insepction+0x60>
    1298:	41 55                	push   %r13
    129a:	4c 8d 2d 63 0d 00 00 	lea    0xd63(%rip),%r13        # 2004 <_IO_stdin_used+0x4>
    12a1:	41 54                	push   %r12
    12a3:	41 89 f4             	mov    %esi,%r12d
    12a6:	55                   	push   %rbp
    12a7:	31 ed                	xor    %ebp,%ebp
    12a9:	53                   	push   %rbx
    12aa:	48 89 fb             	mov    %rdi,%rbx
    12ad:	48 83 ec 08          	sub    $0x8,%rsp
    12b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    12b8:	0f b6 0b             	movzbl (%rbx),%ecx
    12bb:	49 89 d8             	mov    %rbx,%r8
    12be:	89 ea                	mov    %ebp,%edx
    12c0:	4c 89 ee             	mov    %r13,%rsi
    12c3:	bf 01 00 00 00       	mov    $0x1,%edi
    12c8:	31 c0                	xor    %eax,%eax
    12ca:	83 c5 01             	add    $0x1,%ebp
    12cd:	48 83 c3 01          	add    $0x1,%rbx
    12d1:	e8 9a fd ff ff       	callq  1070 <__printf_chk@plt>
    12d6:	41 39 ec             	cmp    %ebp,%r12d
    12d9:	75 dd                	jne    12b8 <mem_insepction+0x28>
    12db:	48 83 c4 08          	add    $0x8,%rsp
    12df:	5b                   	pop    %rbx
    12e0:	5d                   	pop    %rbp
    12e1:	41 5c                	pop    %r12
    12e3:	41 5d                	pop    %r13
    12e5:	c3                   	retq   
    12e6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    12ed:	00 00 00 
    12f0:	c3                   	retq   
    12f1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    12f8:	00 00 00 
    12fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001300 <__libc_csu_init>:
    1300:	f3 0f 1e fa          	endbr64 
    1304:	41 57                	push   %r15
    1306:	4c 8d 3d a3 2a 00 00 	lea    0x2aa3(%rip),%r15        # 3db0 <__frame_dummy_init_array_entry>
    130d:	41 56                	push   %r14
    130f:	49 89 d6             	mov    %rdx,%r14
    1312:	41 55                	push   %r13
    1314:	49 89 f5             	mov    %rsi,%r13
    1317:	41 54                	push   %r12
    1319:	41 89 fc             	mov    %edi,%r12d
    131c:	55                   	push   %rbp
    131d:	48 8d 2d 94 2a 00 00 	lea    0x2a94(%rip),%rbp        # 3db8 <__do_global_dtors_aux_fini_array_entry>
    1324:	53                   	push   %rbx
    1325:	4c 29 fd             	sub    %r15,%rbp
    1328:	48 83 ec 08          	sub    $0x8,%rsp
    132c:	e8 cf fc ff ff       	callq  1000 <_init>
    1331:	48 c1 fd 03          	sar    $0x3,%rbp
    1335:	74 1f                	je     1356 <__libc_csu_init+0x56>
    1337:	31 db                	xor    %ebx,%ebx
    1339:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1340:	4c 89 f2             	mov    %r14,%rdx
    1343:	4c 89 ee             	mov    %r13,%rsi
    1346:	44 89 e7             	mov    %r12d,%edi
    1349:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    134d:	48 83 c3 01          	add    $0x1,%rbx
    1351:	48 39 dd             	cmp    %rbx,%rbp
    1354:	75 ea                	jne    1340 <__libc_csu_init+0x40>
    1356:	48 83 c4 08          	add    $0x8,%rsp
    135a:	5b                   	pop    %rbx
    135b:	5d                   	pop    %rbp
    135c:	41 5c                	pop    %r12
    135e:	41 5d                	pop    %r13
    1360:	41 5e                	pop    %r14
    1362:	41 5f                	pop    %r15
    1364:	c3                   	retq   
    1365:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    136c:	00 00 00 00 

0000000000001370 <__libc_csu_fini>:
    1370:	f3 0f 1e fa          	endbr64 
    1374:	c3                   	retq   

Disassembly of section .fini:

0000000000001378 <_fini>:
    1378:	f3 0f 1e fa          	endbr64 
    137c:	48 83 ec 08          	sub    $0x8,%rsp
    1380:	48 83 c4 08          	add    $0x8,%rsp
    1384:	c3                   	retq   
