
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
    1093:	4c 8d 05 86 02 00 00 	lea    0x286(%rip),%r8        # 1320 <__libc_csu_fini>
    109a:	48 8d 0d 0f 02 00 00 	lea    0x20f(%rip),%rcx        # 12b0 <__libc_csu_init>
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
    11f5:	48 8d 45 e4          	lea    -0x1c(%rbp),%rax
    11f9:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    11fd:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1201:	48 83 c0 01          	add    $0x1,%rax
    1205:	c6 00 5a             	movb   $0x5a,(%rax)
    1208:	c6 45 e3 08          	movb   $0x8,-0x1d(%rbp)
    120c:	80 4d e3 80          	orb    $0x80,-0x1d(%rbp)
    1210:	66 c7 45 f6 05 f0    	movw   $0xf005,-0xa(%rbp)
    1216:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    121a:	0f b6 d0             	movzbl %al,%edx
    121d:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    1221:	0f b6 c0             	movzbl %al,%eax
    1224:	89 c6                	mov    %eax,%esi
    1226:	48 8d 3d f3 0d 00 00 	lea    0xdf3(%rip),%rdi        # 2020 <_IO_stdin_used+0x20>
    122d:	b8 00 00 00 00       	mov    $0x0,%eax
    1232:	e8 39 fe ff ff       	callq  1070 <printf@plt>
    1237:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    123b:	83 e0 7f             	and    $0x7f,%eax
    123e:	88 45 f7             	mov    %al,-0x9(%rbp)
    1241:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    1245:	0f b6 d0             	movzbl %al,%edx
    1248:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    124c:	0f b6 c0             	movzbl %al,%eax
    124f:	89 c6                	mov    %eax,%esi
    1251:	48 8d 3d e0 0d 00 00 	lea    0xde0(%rip),%rdi        # 2038 <_IO_stdin_used+0x38>
    1258:	b8 00 00 00 00       	mov    $0x0,%eax
    125d:	e8 0e fe ff ff       	callq  1070 <printf@plt>
    1262:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    1266:	83 c8 08             	or     $0x8,%eax
    1269:	88 45 f7             	mov    %al,-0x9(%rbp)
    126c:	0f b6 45 f6          	movzbl -0xa(%rbp),%eax
    1270:	0f b6 d0             	movzbl %al,%edx
    1273:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
    1277:	0f b6 c0             	movzbl %al,%eax
    127a:	89 c6                	mov    %eax,%esi
    127c:	48 8d 3d b5 0d 00 00 	lea    0xdb5(%rip),%rdi        # 2038 <_IO_stdin_used+0x38>
    1283:	b8 00 00 00 00       	mov    $0x0,%eax
    1288:	e8 e3 fd ff ff       	callq  1070 <printf@plt>
    128d:	b8 00 00 00 00       	mov    $0x0,%eax
    1292:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    1296:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    129d:	00 00 
    129f:	74 05                	je     12a6 <main+0xda>
    12a1:	e8 ba fd ff ff       	callq  1060 <__stack_chk_fail@plt>
    12a6:	c9                   	leaveq 
    12a7:	c3                   	retq   
    12a8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    12af:	00 

00000000000012b0 <__libc_csu_init>:
    12b0:	f3 0f 1e fa          	endbr64 
    12b4:	41 57                	push   %r15
    12b6:	4c 8d 3d f3 2a 00 00 	lea    0x2af3(%rip),%r15        # 3db0 <__frame_dummy_init_array_entry>
    12bd:	41 56                	push   %r14
    12bf:	49 89 d6             	mov    %rdx,%r14
    12c2:	41 55                	push   %r13
    12c4:	49 89 f5             	mov    %rsi,%r13
    12c7:	41 54                	push   %r12
    12c9:	41 89 fc             	mov    %edi,%r12d
    12cc:	55                   	push   %rbp
    12cd:	48 8d 2d e4 2a 00 00 	lea    0x2ae4(%rip),%rbp        # 3db8 <__do_global_dtors_aux_fini_array_entry>
    12d4:	53                   	push   %rbx
    12d5:	4c 29 fd             	sub    %r15,%rbp
    12d8:	48 83 ec 08          	sub    $0x8,%rsp
    12dc:	e8 1f fd ff ff       	callq  1000 <_init>
    12e1:	48 c1 fd 03          	sar    $0x3,%rbp
    12e5:	74 1f                	je     1306 <__libc_csu_init+0x56>
    12e7:	31 db                	xor    %ebx,%ebx
    12e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    12f0:	4c 89 f2             	mov    %r14,%rdx
    12f3:	4c 89 ee             	mov    %r13,%rsi
    12f6:	44 89 e7             	mov    %r12d,%edi
    12f9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    12fd:	48 83 c3 01          	add    $0x1,%rbx
    1301:	48 39 dd             	cmp    %rbx,%rbp
    1304:	75 ea                	jne    12f0 <__libc_csu_init+0x40>
    1306:	48 83 c4 08          	add    $0x8,%rsp
    130a:	5b                   	pop    %rbx
    130b:	5d                   	pop    %rbp
    130c:	41 5c                	pop    %r12
    130e:	41 5d                	pop    %r13
    1310:	41 5e                	pop    %r14
    1312:	41 5f                	pop    %r15
    1314:	c3                   	retq   
    1315:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    131c:	00 00 00 00 

0000000000001320 <__libc_csu_fini>:
    1320:	f3 0f 1e fa          	endbr64 
    1324:	c3                   	retq   

Disassembly of section .fini:

0000000000001328 <_fini>:
    1328:	f3 0f 1e fa          	endbr64 
    132c:	48 83 ec 08          	sub    $0x8,%rsp
    1330:	48 83 c4 08          	add    $0x8,%rsp
    1334:	c3                   	retq   