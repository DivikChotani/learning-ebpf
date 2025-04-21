Experiment with bpftool btf dump map and bpftool btf dump prog to see the
BTF information associated with maps and programs, respectively. Remember
that you can specify individual maps and programs in more than one way.

You can use 

$ sudo bpftool btf dump map name output
Error: can't get BTF object by id (0): No such file or directory
Error: get btf by id (0): No such file or directory

Why this didn't work: outpu is a perf buffer that doesnt have a btf format

sudo bpftool btf dump map name my_config
[12] TYPEDEF 'u32' type_id=13
[16] STRUCT 'user_msg_t' size=12 vlen=1
	'message' type_id=18 bits_offset=0


$ sudo bpftool btf dump prog name hello
[1] PTR '(anon)' type_id=3
[2] INT 'int' size=4 bits_offset=0 nr_bits=32 encoding=SIGNED
[3] ARRAY '(anon)' type_id=2 index_type_id=4 nr_elems=4
[4] INT '__ARRAY_SIZE_TYPE__' size=4 bits_offset=0 nr_bits=32 encoding=(none)
[5] STRUCT '(anon)' size=24 vlen=3
	'type' type_id=1 bits_offset=0
	'key_size' type_id=1 bits_offset=64
	'value_size' type_id=1 bits_offset=128
[6] VAR 'output' type_id=5, linkage=global
[7] PTR '(anon)' type_id=8
[8] ARRAY '(anon)' type_id=2 index_type_id=4 nr_elems=1
[9] PTR '(anon)' type_id=10
[10] ARRAY '(anon)' type_id=2 index_type_id=4 nr_elems=10240
[11] PTR '(anon)' type_id=12
[12] TYPEDEF 'u32' type_id=13
[13] TYPEDEF '__u32' type_id=14
[14] INT 'unsigned int' size=4 bits_offset=0 nr_bits=32 encoding=(none)
[15] PTR '(anon)' type_id=16
[16] STRUCT 'user_msg_t' size=12 vlen=1
	'message' type_id=18 bits_offset=0
[17] INT 'char' size=1 bits_offset=0 nr_bits=8 encoding=SIGNED
[18] ARRAY '(anon)' type_id=17 index_type_id=4 nr_elems=12
[19] STRUCT '(anon)' size=32 vlen=4
	'type' type_id=7 bits_offset=0
	'max_entries' type_id=9 bits_offset=64
	'key' type_id=11 bits_offset=128
	'value' type_id=15 bits_offset=192
[20] VAR 'my_config' type_id=19, linkage=global
[21] PTR '(anon)' type_id=22
[22] STRUCT 'pt_regs' size=336 vlen=9
	'(anon)' type_id=23 bits_offset=0
	'orig_x0' type_id=29 bits_offset=2176
	'syscallno' type_id=31 bits_offset=2240
	'unused2' type_id=12 bits_offset=2272
	'sdei_ttbr1' type_id=29 bits_offset=2304
	'pmr_save' type_id=29 bits_offset=2368
	'stackframe' type_id=33 bits_offset=2432
	'lockdep_hardirqs' type_id=29 bits_offset=2560
	'exit_rcu' type_id=29 bits_offset=2624
[23] UNION '(anon)' size=272 vlen=2
	'user_regs' type_id=24 bits_offset=0
	'(anon)' type_id=28 bits_offset=0
[24] STRUCT 'user_pt_regs' size=272 vlen=4
	'regs' type_id=27 bits_offset=0
	'sp' type_id=25 bits_offset=1984
	'pc' type_id=25 bits_offset=2048
	'pstate' type_id=25 bits_offset=2112
[25] TYPEDEF '__u64' type_id=26
[26] INT 'unsigned long long' size=8 bits_offset=0 nr_bits=64 encoding=(none)
[27] ARRAY '(anon)' type_id=25 index_type_id=4 nr_elems=31
[28] STRUCT '(anon)' size=272 vlen=4
	'regs' type_id=30 bits_offset=0
	'sp' type_id=29 bits_offset=1984
	'pc' type_id=29 bits_offset=2048
	'pstate' type_id=29 bits_offset=2112
[29] TYPEDEF 'u64' type_id=25
[30] ARRAY '(anon)' type_id=29 index_type_id=4 nr_elems=31
[31] TYPEDEF 's32' type_id=32
[32] TYPEDEF '__s32' type_id=2
[33] ARRAY '(anon)' type_id=29 index_type_id=4 nr_elems=2
[34] FUNC_PROTO '(anon)' ret_type_id=2 vlen=1
	'ctx' type_id=21
[35] FUNC 'hello' type_id=34 linkage=global
[36] STRUCT 'pt_regs___arm64' size=8 vlen=1
	'orig_x0' type_id=37 bits_offset=0
[37] INT 'unsigned long' size=8 bits_offset=0 nr_bits=64 encoding=(none)
[38] VAR 'message' type_id=18, linkage=global
[39] INT '_Bool' size=1 bits_offset=0 nr_bits=8 encoding=BOOL
[40] VAR 'LINUX_HAS_SYSCALL_WRAPPER' type_id=39, linkage=global
[41] ARRAY '(anon)' type_id=17 index_type_id=4 nr_elems=13
[42] VAR 'LICENSE' type_id=41, linkage=global
[43] DATASEC '.data' size=12 vlen=1
	type_id=38 offset=0 size=12 (VAR 'message')
[44] DATASEC '.kconfig' size=1 vlen=1
	type_id=40 offset=0 size=1 (VAR 'LINUX_HAS_SYSCALL_WRAPPER')
[45] DATASEC '.maps' size=56 vlen=2
	type_id=6 offset=0 size=24 (VAR 'output')
	type_id=20 offset=24 size=32 (VAR 'my_config')
[46] DATASEC 'license' size=13 vlen=1
	type_id=42 offset=0 size=13 (VAR 'LICENSE')