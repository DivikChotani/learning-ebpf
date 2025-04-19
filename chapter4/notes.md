# Using strace to Track BPF System Calls

You can use strace to track all the BPF system calls made when loading and running an eBPF program:

```bash
strace -e bpf python3 ./hello-buffer-config.py
```

Example output:
```
bpf(BPF_PROG_LOAD, {prog_type=BPF_PROG_TYPE_SOCKET_FILTER, insn_cnt=2, insns=0xffffdc2f4e30, license="GPL", log_level=0, log_size=0, log_buf=NULL, kern_version=KERNEL_VERSION(0, 0, 0), prog_flags=0, prog_name="", prog_ifindex=0, expected_attach_type=BPF_CGROUP_INET_INGRESS, prog_btf_fd=0, func_info_rec_size=0, func_info=NULL, func_info_cnt=0, line_info_rec_size=0, line_info=NULL, line_info_cnt=0, attach_btf_id=0, attach_prog_fd=0}, 116) = 3

bpf(BPF_BTF_LOAD, {btf="\237\353\1\0\30\0\0\0\0\0\0\0\374\4\0\0\374\4\0\0\340\3\0\0\1\0\0\0\0\0\0\10"..., btf_log_buf=NULL, btf_size=2292, btf_log_size=0, btf_log_level=0}, 40) = 3

bpf(BPF_PROG_LOAD, {prog_type=BPF_PROG_TYPE_SOCKET_FILTER, insn_cnt=2, insns=0xffffdc2f4ae0, license="GPL", log_level=0, log_size=0, log_buf=NULL, kern_version=KERNEL_VERSION(0, 0, 0), prog_flags=0, prog_name="libbpf_nametest"}, 64) = 4

bpf(BPF_MAP_CREATE, {map_type=BPF_MAP_TYPE_PERF_EVENT_ARRAY, key_size=4, value_size=4, max_entries=4, map_flags=0, inner_map_fd=0, map_name="output", map_ifindex=0, btf_fd=0, btf_key_type_id=0, btf_value_type_id=0, btf_vmlinux_value_type_id=0, map_extra=0}, 80) = 4

bpf(BPF_MAP_CREATE, {map_type=BPF_MAP_TYPE_HASH, key_size=4, value_size=13, max_entries=10240, map_flags=0, inner_map_fd=0, map_name="config", map_ifindex=0, btf_fd=3, btf_key_type_id=1, btf_value_type_id=4, btf_vmlinux_value_type_id=0, map_extra=0}, 80) = 5

bpf(BPF_PROG_LOAD, {prog_type=BPF_PROG_TYPE_KPROBE, insn_cnt=47, insns=0xe3dab6b3e000, license="GPL", log_level=0, log_size=0, log_buf=NULL, kern_version=KERNEL_VERSION(6, 11, 11), prog_flags=0, prog_name="hello", prog_ifindex=0, expected_attach_type=BPF_CGROUP_INET_INGRESS, prog_btf_fd=3, func_info_rec_size=8, func_info=0x2ac97f40, func_info_cnt=1, line_info_rec_size=16, line_info=0x2a2ffbf0, line_info_cnt=20, attach_btf_id=0, attach_prog_fd=0, fd_array=NULL}, 148) = 6
```

## Key BPF System Calls:

### BPF_PROG_LOAD
Loads a program into the kernel and returns a file descriptor (fd) which can be used to access it.
- `insn_cnt`: Number of BPF instructions


### BPF_BTF_LOAD
Loads the BTF (BPF Type Format) object into the kernel.
- BTF is used to 'lint' BPF program loads
- Validates and documents the code

### BPF_MAP_CREATE
Creates a BPF map data structure, which can be:
- Stack
- Queue
- Ring buffer
- Hash map
- And many other types

# Examining eBPF Program Instructions

You can also check the lines of instructions using:

```bash
bpftool prog dump xlated id 72
```

## Example output:

```
int hello(void * ctx):
 ; int hello(void *ctx) {
   0: (bf) r6 = r1
   1: (b7) r1 = 0
 ; struct data_t data = {};  
   2: (63) *(u32 *)(r10 -8) = r1
   3: (63) *(u32 *)(r10 -12) = r1
   4: (63) *(u32 *)(r10 -16) = r1
   5: (63) *(u32 *)(r10 -20) = r1
   6: (63) *(u32 *)(r10 -24) = r1
   7: (63) *(u32 *)(r10 -28) = r1
   8: (63) *(u32 *)(r10 -4) = r1
   9: (b7) r1 = 6581362
 ; char message[12] = "Hello World";
  10: (63) *(u32 *)(r10 -40) = r1
  11: (18) r1 = 0x6f57206f6c6c6548
  13: (7b) *(u64 *)(r10 -48) = r1
 ; data.pid = bpf_get_current_pid_tgid() >> 32;
  14: (85) call bpf_get_current_pid_tgid#293440
 ; data.pid = bpf_get_current_pid_tgid() >> 32;
  15: (77) r0 >>= 32
 ; data.pid = bpf_get_current_pid_tgid() >> 32;
  16: (63) *(u32 *)(r10 -36) = r0
 ; data.uid = bpf_get_current_uid_gid() & 0xFFFFFFFF;
  17: (85) call bpf_get_current_uid_gid#293888
 ; data.uid = bpf_get_current_uid_gid() & 0xFFFFFFFF;
  18: (63) *(u32 *)(r10 -32) = r0
 ; struct data_t data = {};
  19: (bf) r1 = r10
  20: (07) r1 += -28
 ; bpf_get_current_comm(&data.command, sizeof(data.command));
  21: (b7) r2 = 16
  22: (85) call bpf_get_current_comm#294048
 ; p = bpf_map_lookup_elem((void *)bpf_pseudo_fd(1, -1), &data.uid);
  23: (18) r1 = map[id:13]
 ; data.uid = bpf_get_current_uid_gid() & 0xFFFFFFFF;
  25: (bf) r2 = r10
  26: (07) r2 += -32
 ; p = bpf_map_lookup_elem((void *)bpf_pseudo_fd(1, -1), &data.uid);
  27: (85) call __htab_map_lookup_elem#354352
  28: (15) if r0 == 0x0 goto pc+1
  29: (07) r0 += 56
  30: (bf) r3 = r10
 ;  
  31: (07) r3 += -48
  32: (15) if r0 == 0x0 goto pc+1
  33: (bf) r3 = r0
 ; struct data_t data = {};
  34: (bf) r1 = r10
  35: (07) r1 += -12
 ;  
  36: (b7) r2 = 12
  37: (85) call bpf_probe_read_kernel#-133384
 ; bpf_perf_event_output(ctx, (void *)bpf_pseudo_fd(1, -2), CUR_CPU_IDENTIFIER, &data, sizeof(data));
  38: (18) r2 = map[id:12]
  40: (bf) r4 = r10
 ; struct data_t data = {};
  41: (07) r4 += -36
 ; bpf_perf_event_output(ctx, (void *)bpf_pseudo_fd(1, -2), CUR_CPU_IDENTIFIER, &data, sizeof(data));
  42: (bf) r1 = r6
  43: (18) r3 = 0xffffffff
  45: (b7) r5 = 36
  46: (85) call bpf_perf_event_output#-123528
 ; return 0;
  47: (b7) r0 = 0
  48: (95) exit
```