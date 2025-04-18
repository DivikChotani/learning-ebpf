# How to load, unload, and attach ebpf programs

## 1. Compile

Compile the BPF program

```bash
clang -target bpf -I/usr/include/$(uname -m)-linux-gnu -g -O2 -c a.bpf.c -o a.bpf.o
```

### Compilation flags explained:
- `clang` - The compiler used for eBPF programs
- `-target bpf` - Specifies to generate BPF object files (not regular object files)
- `-I/usr/include/$(uname -m)-linux-gnu` - Includes architecture-specific headers
- `-g` - Adds debug information
- `-O2` - for certain optimization level (not required)
- `-c` - Compile only 

## 2. Load and Attach the Program

there are Two main options for loading and attaching:

### Option A: Using bpftool

1. **Load the program into the kernel:**
   ```bash
   bpftool prog load a.bpf.o /sys/fs/bpf/a
   ```

2. **Attach the program to a network interface:**
   ```bash
   bpftool net attach xdp name a dev eth0
   ```


### Option B: Using ip link command

Load and attach in a single command:
```bash
ip link set dev eth0 xdp obj a.bpf.o sec xdp
```
   > **Note:** XDP generally allows only one attached program at a time per interface.

## 3. Unload and Detach the Program

Always detach programs before unloading them.

### Option A: Using bpftool

1. **Detach the program:**
   ```bash
   bpftool net detach xdp dev eth0
   ```

2. **Remove from kernel:**
   ```bash
   rm /sys/fs/bpf/a
   ```

### Option B: Using ip link command

1. **Detach the XDP program:**
   ```bash
   ip link set dev eth0 xdp off
   ```

## About XDP (eXpress Data Path)

XDP provides extremely fast packet processing by intercepting packets at the earliest possible point in the network stack, immediately after they arrive at the network interface.