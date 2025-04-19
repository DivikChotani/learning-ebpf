# How kprobe Attachment Works

### 1. Program Load via `bpf()`
```c
bpf(BPF_PROG_LOAD, {
  prog_type = BPF_PROG_TYPE_KPROBE,
  insn_cnt = 47,
  insns = 0xe0d822af4000,
  license = "GPL",
  log_level = 0,
  log_size = 0,
  log_buf = NULL,
  kern_version = KERNEL_VERSION(6, 11, 11),
  prog_flags = 0,
  prog_name = "hello",
  prog_ifindex = 0,
  expected_attach_type = BPF_CGROUP_INET_INGRESS,
  prog_btf_fd = 3,
  func_info_rec_size = 8,
  func_info = 0x2022a4c0,
  func_info_cnt = 1,
  line_info_rec_size = 16,
  line_info = 0x1fc5a120,
  line_info_cnt = 20,
  attach_btf_id = 0,
  attach_prog_fd = 0,
  fd_array = NULL
}, 148) = 6
```
- This loads the eBPF program into the kernel and returns file descriptor (fd) `6`.

### 2. Create a Perf Event
```c
perf_event_open({
  type = 0x8 /* PERF_TYPE_??? */,
  size = 0x88 /* PERF_ATTR_SIZE_??? */,
  config = 0,
  sample_period = 1,
  sample_type = 0,
  read_format = 0,
  precise_ip = 0 /* arbitrary skid */
}, -1, 0, -1, PERF_FLAG_FD_CLOEXEC) = 7
```
- This sets up a perf event for syscall #8.
- Perf event subsystem supports various event types like:
  - Software-defined events (e.g., syscall entry)
  - Kprobes (breakpoint-style events)
  - Tracepoints
  - Stack sampling

### 3. Attach BPF Program to Perf Event
```c
ioctl(7, PERF_EVENT_IOC_SET_BPF, 6) = 0
```
- This attaches the eBPF program (fd `6`) to the perf event (fd `7`).

---

# How RAW_TRACEPOINT Attachment Works

### 1. Load Program via `bpf()`
```c
bpf(BPF_PROG_LOAD, {
  prog_type = BPF_PROG_TYPE_RAW_TRACEPOINT,
  insn_cnt = 44,
  insns = 0xf64c5a699000,
  license = "GPL",
  log_level = 0,
  log_size = 0,
  log_buf = NULL,
  kern_version = KERNEL_VERSION(6, 11, 11),
  prog_flags = 0,
  prog_name = "hello",
  prog_ifindex = 0,
  expected_attach_type = BPF_CGROUP_INET_INGRESS,
  prog_btf_fd = 3,
  func_info_rec_size = 8,
  func_info = 0x40ad7280,
  func_info_cnt = 1,
  line_info_rec_size = 16,
  line_info = 0x3f6d7a70,
  line_info_cnt = 20,
  attach_btf_id = 0,
  attach_prog_fd = 0,
  fd_array = NULL
}, 148) = 6
```
- Loads the raw tracepoint program. Returns fd `6`.

### 2. Attach Program Using `BPF_RAW_TRACEPOINT_OPEN`
```c
bpf(BPF_RAW_TRACEPOINT_OPEN, {
  raw_tracepoint = {
    name = "sys_enter",
    prog_fd = 6,
    cookie = 0
  }
}, 24) = 7
```
- Attaches the program to the raw tracepoint `sys_enter`.
- Returns fd `7` which represents the link.

### Notes:
- You can detach the program by closing the attachment fd (7), but the program will remain loaded.
- However, if not attached, it will not have any effect.

