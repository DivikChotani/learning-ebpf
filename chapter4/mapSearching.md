# Understanding `bpftool map dump` with strace

## Command
```bash
sudo strace -e bpf bpftool map dump name config
```

## Output and Analysis

```
--- SIGCHLD {si_signo=SIGCHLD, si_code=CLD_EXITED, si_pid=11448, si_uid=0, si_status=0, si_utime=0, si_stime=0} ---
--- SIGCHLD {si_signo=SIGCHLD, si_code=CLD_EXITED, si_pid=11449, si_uid=0, si_status=0, si_utime=0, si_stime=0} ---
bpf(BPF_MAP_GET_NEXT_ID, {start_id=0, next_id=0 => 14, open_flags=0}, 12) = 0
bpf(BPF_MAP_GET_FD_BY_ID, {map_id=14, next_id=0, open_flags=0}, 12) = 3
bpf(BPF_OBJ_GET_INFO_BY_FD, {info={bpf_fd=3, info_len=88, info=0xffffdc8e0f00}}, 16) = 0
bpf(BPF_MAP_GET_NEXT_ID, {start_id=14, next_id=0 => 15, open_flags=0}, 12) = 0
bpf(BPF_MAP_GET_FD_BY_ID, {map_id=15, next_id=0, open_flags=0}, 12) = 3
bpf(BPF_OBJ_GET_INFO_BY_FD, {info={bpf_fd=3, info_len=88, info=0xffffdc8e0f00}}, 16) = 0
bpf(BPF_MAP_GET_NEXT_ID, {start_id=15, next_id=0 => 18, open_flags=0}, 12) = 0
bpf(BPF_MAP_GET_FD_BY_ID, {map_id=18, next_id=0, open_flags=0}, 12) = 4
bpf(BPF_OBJ_GET_INFO_BY_FD, {info={bpf_fd=4, info_len=88, info=0xffffdc8e0f00}}, 16) = 0
bpf(BPF_MAP_GET_NEXT_ID, {start_id=18, next_id=0 => 19, open_flags=0}, 12) = 0
bpf(BPF_MAP_GET_FD_BY_ID, {map_id=19, next_id=0, open_flags=0}, 12) = 4
bpf(BPF_OBJ_GET_INFO_BY_FD, {info={bpf_fd=4, info_len=88, info=0xffffdc8e0f00}}, 16) = 0
bpf(BPF_MAP_GET_NEXT_ID, {start_id=19, next_id=0, open_flags=0}, 12) = -1 ENOENT (No such file or directory)
bpf(BPF_OBJ_GET_INFO_BY_FD, {info={bpf_fd=3, info_len=88, info=0xffffdc8e1090}}, 16) = 0
bpf(BPF_OBJ_GET_INFO_BY_FD, {info={bpf_fd=4, info_len=88, info=0xffffdc8e1090}}, 16) = 0
bpf(BPF_OBJ_GET_INFO_BY_FD, {info={bpf_fd=3, info_len=88, info=0xffffdc8e1038}}, 16) = 0
bpf(BPF_BTF_GET_FD_BY_ID, {btf_id=97}, 12) = 5
bpf(BPF_OBJ_GET_INFO_BY_FD, {info={bpf_fd=5, info_len=32, info=0xffffdc8e0ef8}}, 16) = 0
[{
        "id": 15,
        "type": "hash",
        "name": "config",
        "flags": 0,
bpf(BPF_MAP_GET_NEXT_KEY, {map_fd=3, key=NULL, next_key=0xac04b96746f0}, 24) = 0
bpf(BPF_MAP_LOOKUP_ELEM, {map_fd=3, key=0xac04b96746f0, value=0xac04b9674710, flags=BPF_ANY}, 32) = 0
        "elements": [{
                "key": 501,
                "value": {
                    "message": "Hi user 501!"
                }
bpf(BPF_MAP_GET_NEXT_KEY, {map_fd=3, key=0xac04b96746f0, next_key=0xac04b96746f0}, 24) = 0
bpf(BPF_MAP_LOOKUP_ELEM, {map_fd=3, key=0xac04b96746f0, value=0xac04b9674710, flags=BPF_ANY}, 32) = 0
            },{
                "key": 0,
                "value": {
                    "message": "Hey root!"
                }
bpf(BPF_MAP_GET_NEXT_KEY, {map_fd=3, key=0xac04b96746f0, next_key=0xac04b96746f0}, 24) = -1 ENOENT (No such file or directory)
            }
        ]
bpf(BPF_OBJ_GET_INFO_BY_FD, {info={bpf_fd=4, info_len=88, info=0xffffdc8e1038}}, 16) = 0
bpf(BPF_BTF_GET_FD_BY_ID, {btf_id=99}, 12) = 3
bpf(BPF_OBJ_GET_INFO_BY_FD, {info={bpf_fd=3, info_len=32, info=0xffffdc8e0ef8}}, 16) = 0
    },{
        "id": 19,
        "type": "hash",
        "name": "config",
        "flags": 0,
bpf(BPF_MAP_GET_NEXT_KEY, {map_fd=4, key=NULL, next_key=0xac04b9674710}, 24) = 0
bpf(BPF_MAP_LOOKUP_ELEM, {map_fd=4, key=0xac04b9674710, value=0xac04b96746f0, flags=BPF_ANY}, 32) = 0
        "elements": [{
                "key": 501,
                "value": {
                    "message": "Hi user 501!"
                }
bpf(BPF_MAP_GET_NEXT_KEY, {map_fd=4, key=0xac04b9674710, next_key=0xac04b9674710}, 24) = 0
bpf(BPF_MAP_LOOKUP_ELEM, {map_fd=4, key=0xac04b9674710, value=0xac04b96746f0, flags=BPF_ANY}, 32) = 0
            },{
                "key": 0,
                "value": {
                    "message": "Hey root!"
                }
bpf(BPF_MAP_GET_NEXT_KEY, {map_fd=4, key=0xac04b9674710, next_key=0xac04b9674710}, 24) = -1 ENOENT (No such file or directory)
            }
        ]
    }
]
+++ exited with 0 +++
```

## Key System Calls Explained

### BPF_MAP_GET_NEXT_ID
Gets the id of the first map available. Used to iterate through all maps in the system.

### BPF_MAP_GET_FD_BY_ID
Given the map id, this will return a file descriptor (fd) from which to interact with the map.

### BPF_OBJ_GET_INFO_BY_FD
This will return the info of the map. Since we asked to print out all maps named "config", it finds maps with that name and returns their details.

### BPF_MAP_GET_NEXT_KEY and BPF_MAP_LOOKUP_ELEM
These are used to get the key and value pairs stored in the map. The operation:
1. Gets the next key in the map
2. Looks up the element value using that key
3. Continues until no more keys are found (ENOENT error)

## Map Contents

The system found two maps named "config", with:

1. First map (id: 15):
   - Contains key-value pairs where keys are user IDs and values are greeting messages
   - Entry for user 501: "Hi user 501!"
   - Entry for user 0 (root): "Hey root!"

2. Second map (id: 19):
   - Contains identical data to the first map


# Updating a bpf map from the terminal 

sudo bpftool map list
14: perf_event_array  name output  flags 0x0
	key 4B  value 4B  max_entries 4  memlock 296B
15: hash  name config  flags 0x0
	key 4B  value 13B  max_entries 10240  memlock 1000768B
	btf_id 97
sudo  bpftool map dump name config
[{
        "key": 501,
        "value": {
            "message": "Hi user 501!"
        }
    },{
        "key": 0,
        "value": {
            "message": "Hey root!"
        }
    }
]

Previous output
12112 0 bpftool Hey root!
12113 0 bpftool Hey root!
12111 0 bpftool Hey root!

sudo bpftool map update id 15 \
    key   hex 00 00 00 00        \
    value hex 48 65 6c 6c 6f 20 52 75 6c 65 72 21 00 (Hello Ruler)

New Output
12114 0 lima-guestagent Hello Ruler!
12115 0 lima-guestagent Hello Ruler!
12116 0 lima-guestagent Hello Ruler!
