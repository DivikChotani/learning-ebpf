# How to load, unload, and attach eBPF programs

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

There are two main options for loading and attaching:

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

# Debugging and inspecting eBPF tools

After running hello-mapy.py from chapter 2

`bpftool prog show name hello` shows the function which was hello that was loaded in, and corresponding information

```bash
sudo bpftool prog show name hello --pretty
{
    "id": 88,
    "type": "kprobe",
    "name": "hello",
    "tag": "4da1746b346c294f",
    "gpl_compatible": true,
    "loaded_at": 1745012208,
    "uid": 0,
    "orphaned": false,
    "bytes_xlated": 216,
    "jited": true,
    "bytes_jited": 280,
    "bytes_memlock": 4096,
    "map_ids": [18
    ],
    "btf_id": 117
}
```

id: id of ebpf function  
type: type of attachement  
name: name of ebpf function  
tag: unique id  
gpl_compatible: must be true  
loaded at: time of load  
uid: who loaded  
orphaned: false  
bytes_xlated: bytes turned into ebpf code  
bytes_jited: bytes of ebpf jit compiled  
bytes_memlock: bytes reserved for this  
map_ids: maps associated  
btf_id:  

`bpftool map list` 

to see all data structures loaded in by ebpf, sample output

```bash
17: hash  name counter_table  flags 0x0
	key 8B  value 8B  max_entries 10240  memlock 918816B
	btf_id 116
```

And then to view the table and some sample output

```bash
bpftool map dump name counter_table
[{
        "key": 0,
        "value": 1055
    },{
        "key": 996,
        "value": 2
    },{
        "key": 1501,
        "value": 16
    },{
        "key": 1000,
        "value": 52
    },{
        "key": 501,
        "value": 1022
    }
]
```