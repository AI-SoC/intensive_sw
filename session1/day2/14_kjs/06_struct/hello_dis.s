
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
    10a2:	48 8d 35 75 0f 00 00 	lea    0xf75(%rip),%rsi        # 201e <_IO_stdin_used+0x1e>
    10a9:	c7 44 24 04 01 80 00 	movl   $0xf0008001,0x4(%rsp)
    10b0:	f0 
    10b1:	e8 ba ff ff ff       	callq  1070 <__printf_chk@plt>
    10b6:	0f b6 54 24 04       	movzbl 0x4(%rsp),%edx
    10bb:	48 8d 35 6c 0f 00 00 	lea    0xf6c(%rip),%rsi        # 202e <_IO_stdin_used+0x2e>
    10c2:	31 c0                	xor    %eax,%eax
    10c4:	bf 01 00 00 00       	mov    $0x1,%edi
    10c9:	e8 a2 ff ff ff       	callq  1070 <__printf_chk@plt>
    10ce:	0f b7 54 24 06       	movzwl 0x6(%rsp),%edx
    10d3:	48 8d 35 64 0f 00 00 	lea    0xf64(%rip),%rsi        # 203e <_IO_stdin_used+0x3e>
    10da:	31 c0                	xor    %eax,%eax
    10dc:	bf 01 00 00 00       	mov    $0x1,%edi
    10e1:	e8 8a ff ff ff       	callq  1070 <__printf_chk@plt>
    10e6:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
    10eb:	be 04 00 00 00       	mov    $0x4,%esi
    10f0:	e8 2b 01 00 00       	callq  1220 <mem_inspection>
    10f5:	31 c0                	xor    %eax,%eax
    10f7:	ba 5a 00 00 00       	mov    $0x5a,%edx
    10fc:	48 8d 35 2b 0f 00 00 	lea    0xf2b(%rip),%rsi        # 202e <_IO_stdin_used+0x2e>
    1103:	bf 01 00 00 00       	mov    $0x1,%edi
    1108:	c6 44 24 05 5a       	movb   $0x5a,0x5(%rsp)
    110d:	e8 5e ff ff ff       	callq  1070 <__printf_chk@plt>
    1112:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    1117:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    111e:	00 00 
    1120:	75 05                	jne    1127 <main+0xa7>
    1122:	48 83 c4 18          	add    $0x18,%rsp
    1126:	c3                   	retq   
    1127:	e8 34 ff ff ff       	callq  1060 <__stack_chk_fail@plt>
    112c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001130 <_start>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	31 ed                	xor    %ebp,%ebp
    1136:	49 89 d1             	mov    %rdx,%r9
    1139:	5e                   	pop    %rsi
    113a:	48 89 e2             	mov    %rsp,%rdx
    113d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1141:	50                   	push   %rax
    1142:	54                   	push   %rsp
    1143:	4c 8d 05 b6 01 00 00 	lea    0x1b6(%rip),%r8        # 1300 <__libc_csu_fini>
    114a:	48 8d 0d 3f 01 00 00 	lea    0x13f(%rip),%rcx        # 1290 <__libc_csu_init>
    1151:	48 8d 3d 28 ff ff ff 	lea    -0xd8(%rip),%rdi        # 1080 <main>
    1158:	ff 15 82 2e 00 00    	callq  *0x2e82(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    115e:	f4                   	hlt    
    115f:	90                   	nop

0000000000001160 <deregister_tm_clones>:
    1160:	48 8d 3d a9 2e 00 00 	lea    0x2ea9(%rip),%rdi        # 4010 <__TMC_END__>
    1167:	48 8d 05 a2 2e 00 00 	lea    0x2ea2(%rip),%rax        # 4010 <__TMC_END__>
    116e:	48 39 f8             	cmp    %rdi,%rax
    1171:	74 15                	je     1188 <deregister_tm_clones+0x28>
    1173:	48 8b 05 5e 2e 00 00 	mov    0x2e5e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    117a:	48 85 c0             	test   %rax,%rax
    117d:	74 09                	je     1188 <deregister_tm_clones+0x28>
    117f:	ff e0                	jmpq   *%rax
    1181:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1188:	c3                   	retq   
    1189:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001190 <register_tm_clones>:
    1190:	48 8d 3d 79 2e 00 00 	lea    0x2e79(%rip),%rdi        # 4010 <__TMC_END__>
    1197:	48 8d 35 72 2e 00 00 	lea    0x2e72(%rip),%rsi        # 4010 <__TMC_END__>
    119e:	48 29 fe             	sub    %rdi,%rsi
    11a1:	48 89 f0             	mov    %rsi,%rax
    11a4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    11a8:	48 c1 f8 03          	sar    $0x3,%rax
    11ac:	48 01 c6             	add    %rax,%rsi
    11af:	48 d1 fe             	sar    %rsi
    11b2:	74 14                	je     11c8 <register_tm_clones+0x38>
    11b4:	48 8b 05 35 2e 00 00 	mov    0x2e35(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    11bb:	48 85 c0             	test   %rax,%rax
    11be:	74 08                	je     11c8 <register_tm_clones+0x38>
    11c0:	ff e0                	jmpq   *%rax
    11c2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    11c8:	c3                   	retq   
    11c9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011d0 <__do_global_dtors_aux>:
    11d0:	f3 0f 1e fa          	endbr64 
    11d4:	80 3d 35 2e 00 00 00 	cmpb   $0x0,0x2e35(%rip)        # 4010 <__TMC_END__>
    11db:	75 2b                	jne    1208 <__do_global_dtors_aux+0x38>
    11dd:	55                   	push   %rbp
    11de:	48 83 3d 12 2e 00 00 	cmpq   $0x0,0x2e12(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    11e5:	00 
    11e6:	48 89 e5             	mov    %rsp,%rbp
    11e9:	74 0c                	je     11f7 <__do_global_dtors_aux+0x27>
    11eb:	48 8b 3d 16 2e 00 00 	mov    0x2e16(%rip),%rdi        # 4008 <__dso_handle>
    11f2:	e8 59 fe ff ff       	callq  1050 <__cxa_finalize@plt>
    11f7:	e8 64 ff ff ff       	callq  1160 <deregister_tm_clones>
    11fc:	c6 05 0d 2e 00 00 01 	movb   $0x1,0x2e0d(%rip)        # 4010 <__TMC_END__>
    1203:	5d                   	pop    %rbp
    1204:	c3                   	retq   
    1205:	0f 1f 00             	nopl   (%rax)
    1208:	c3                   	retq   
    1209:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001210 <frame_dummy>:
    1210:	f3 0f 1e fa          	endbr64 
    1214:	e9 77 ff ff ff       	jmpq   1190 <register_tm_clones>
    1219:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001220 <mem_inspection>:
    1220:	f3 0f 1e fa          	endbr64 
    1224:	85 f6                	test   %esi,%esi
    1226:	7e 58                	jle    1280 <mem_inspection+0x60>
    1228:	41 55                	push   %r13
    122a:	4c 8d 2d d3 0d 00 00 	lea    0xdd3(%rip),%r13        # 2004 <_IO_stdin_used+0x4>
    1231:	41 54                	push   %r12
    1233:	41 89 f4             	mov    %esi,%r12d
    1236:	55                   	push   %rbp
    1237:	31 ed                	xor    %ebp,%ebp
    1239:	53                   	push   %rbx
    123a:	48 89 fb             	mov    %rdi,%rbx
    123d:	48 83 ec 08          	sub    $0x8,%rsp
    1241:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1248:	0f b6 0b             	movzbl (%rbx),%ecx
    124b:	49 89 d8             	mov    %rbx,%r8
    124e:	89 ea                	mov    %ebp,%edx
    1250:	4c 89 ee             	mov    %r13,%rsi
    1253:	bf 01 00 00 00       	mov    $0x1,%edi
    1258:	31 c0                	xor    %eax,%eax
    125a:	83 c5 01             	add    $0x1,%ebp
    125d:	48 83 c3 01          	add    $0x1,%rbx
    1261:	e8 0a fe ff ff       	callq  1070 <__printf_chk@plt>
    1266:	41 39 ec             	cmp    %ebp,%r12d
    1269:	75 dd                	jne    1248 <mem_inspection+0x28>
    126b:	48 83 c4 08          	add    $0x8,%rsp
    126f:	5b                   	pop    %rbx
    1270:	5d                   	pop    %rbp
    1271:	41 5c                	pop    %r12
    1273:	41 5d                	pop    %r13
    1275:	c3                   	retq   
    1276:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    127d:	00 00 00 
    1280:	c3                   	retq   
    1281:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    1288:	00 00 00 
    128b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001290 <__libc_csu_init>:
    1290:	f3 0f 1e fa          	endbr64 
    1294:	41 57                	push   %r15
    1296:	4c 8d 3d 13 2b 00 00 	lea    0x2b13(%rip),%r15        # 3db0 <__frame_dummy_init_array_entry>
    129d:	41 56                	push   %r14
    129f:	49 89 d6             	mov    %rdx,%r14
    12a2:	41 55                	push   %r13
    12a4:	49 89 f5             	mov    %rsi,%r13
    12a7:	41 54                	push   %r12
    12a9:	41 89 fc             	mov    %edi,%r12d
    12ac:	55                   	push   %rbp
    12ad:	48 8d 2d 04 2b 00 00 	lea    0x2b04(%rip),%rbp        # 3db8 <__do_global_dtors_aux_fini_array_entry>
    12b4:	53                   	push   %rbx
    12b5:	4c 29 fd             	sub    %r15,%rbp
    12b8:	48 83 ec 08          	sub    $0x8,%rsp
    12bc:	e8 3f fd ff ff       	callq  1000 <_init>
    12c1:	48 c1 fd 03          	sar    $0x3,%rbp
    12c5:	74 1f                	je     12e6 <__libc_csu_init+0x56>
    12c7:	31 db                	xor    %ebx,%ebx
    12c9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    12d0:	4c 89 f2             	mov    %r14,%rdx
    12d3:	4c 89 ee             	mov    %r13,%rsi
    12d6:	44 89 e7             	mov    %r12d,%edi
    12d9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    12dd:	48 83 c3 01          	add    $0x1,%rbx
    12e1:	48 39 dd             	cmp    %rbx,%rbp
    12e4:	75 ea                	jne    12d0 <__libc_csu_init+0x40>
    12e6:	48 83 c4 08          	add    $0x8,%rsp
    12ea:	5b                   	pop    %rbx
    12eb:	5d                   	pop    %rbp
    12ec:	41 5c                	pop    %r12
    12ee:	41 5d                	pop    %r13
    12f0:	41 5e                	pop    %r14
    12f2:	41 5f                	pop    %r15
    12f4:	c3                   	retq   
    12f5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    12fc:	00 00 00 00 

0000000000001300 <__libc_csu_fini>:
    1300:	f3 0f 1e fa          	endbr64 
    1304:	c3                   	retq   

Disassembly of section .fini:

0000000000001308 <_fini>:
    1308:	f3 0f 1e fa          	endbr64 
    130c:	48 83 ec 08          	sub    $0x8,%rsp
    1310:	48 83 c4 08          	add    $0x8,%rsp
    1314:	c3                   	retq   
