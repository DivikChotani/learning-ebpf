/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED BY BPFTOOL! */
#ifndef __HELLO_TRACEPOINT_BPF_SKEL_H__
#define __HELLO_TRACEPOINT_BPF_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

#define BPF_SKEL_SUPPORTS_MAP_AUTO_ATTACH 1

struct hello_tracepoint_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *output;
		struct bpf_map *data;
	} maps;
	struct {
		struct bpf_program *kprobe_exec;
	} progs;
	struct {
		struct bpf_link *kprobe_exec;
	} links;
	struct hello_tracepoint_bpf__data {
		int c;
	} *data;

#ifdef __cplusplus
	static inline struct hello_tracepoint_bpf *open(const struct bpf_object_open_opts *opts = nullptr);
	static inline struct hello_tracepoint_bpf *open_and_load();
	static inline int load(struct hello_tracepoint_bpf *skel);
	static inline int attach(struct hello_tracepoint_bpf *skel);
	static inline void detach(struct hello_tracepoint_bpf *skel);
	static inline void destroy(struct hello_tracepoint_bpf *skel);
	static inline const void *elf_bytes(size_t *sz);
#endif /* __cplusplus */
};

static void
hello_tracepoint_bpf__destroy(struct hello_tracepoint_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
hello_tracepoint_bpf__create_skeleton(struct hello_tracepoint_bpf *obj);

static inline struct hello_tracepoint_bpf *
hello_tracepoint_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct hello_tracepoint_bpf *obj;
	int err;

	obj = (struct hello_tracepoint_bpf *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = hello_tracepoint_bpf__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	hello_tracepoint_bpf__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct hello_tracepoint_bpf *
hello_tracepoint_bpf__open(void)
{
	return hello_tracepoint_bpf__open_opts(NULL);
}

static inline int
hello_tracepoint_bpf__load(struct hello_tracepoint_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct hello_tracepoint_bpf *
hello_tracepoint_bpf__open_and_load(void)
{
	struct hello_tracepoint_bpf *obj;
	int err;

	obj = hello_tracepoint_bpf__open();
	if (!obj)
		return NULL;
	err = hello_tracepoint_bpf__load(obj);
	if (err) {
		hello_tracepoint_bpf__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
hello_tracepoint_bpf__attach(struct hello_tracepoint_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
hello_tracepoint_bpf__detach(struct hello_tracepoint_bpf *obj)
{
	bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *hello_tracepoint_bpf__elf_bytes(size_t *sz);

static inline int
hello_tracepoint_bpf__create_skeleton(struct hello_tracepoint_bpf *obj)
{
	struct bpf_object_skeleton *s;
	struct bpf_map_skeleton *map __attribute__((unused));
	int err;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)	{
		err = -ENOMEM;
		goto err;
	}

	s->sz = sizeof(*s);
	s->name = "hello_tracepoint_bpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = 24;
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt,
			sizeof(*s->maps) > 24 ? sizeof(*s->maps) : 24);
	if (!s->maps) {
		err = -ENOMEM;
		goto err;
	}

	map = (struct bpf_map_skeleton *)((char *)s->maps + 0 * s->map_skel_sz);
	map->name = "output";
	map->map = &obj->maps.output;

	map = (struct bpf_map_skeleton *)((char *)s->maps + 1 * s->map_skel_sz);
	map->name = "hello_tr.data";
	map->map = &obj->maps.data;
	map->mmaped = (void **)&obj->data;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs) {
		err = -ENOMEM;
		goto err;
	}

	s->progs[0].name = "kprobe_exec";
	s->progs[0].prog = &obj->progs.kprobe_exec;
	s->progs[0].link = &obj->links.kprobe_exec;

	s->data = hello_tracepoint_bpf__elf_bytes(&s->data_sz);

	obj->skeleton = s;
	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return err;
}

static inline const void *hello_tracepoint_bpf__elf_bytes(size_t *sz)
{
	static const char data[] __attribute__((__aligned__(8))) = "\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xb8\x05\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0e\0\
\x01\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x23\0\0\0\0\0\0\x07\x03\0\0\x01\
\0\0\0\x63\x32\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x03\0\0\xff\
\xff\xff\xff\0\0\0\0\0\0\0\0\x18\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x05\0\0\
\x04\0\0\0\x85\0\0\0\x19\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x44\x75\x61\x6c\x20\x42\
\x53\x44\x2f\x47\x50\x4c\0\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x40\x01\0\0\
\x40\x01\0\0\x39\x01\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\
\0\0\x20\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x04\0\0\0\x05\0\
\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\x03\0\0\x04\x18\0\0\0\x19\0\0\0\x01\
\0\0\0\0\0\0\0\x1e\0\0\0\x01\0\0\0\x40\0\0\0\x27\0\0\0\x01\0\0\0\x80\0\0\0\x32\
\0\0\0\0\0\0\x0e\x05\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\
\x0d\x02\0\0\0\x39\0\0\0\x07\0\0\0\x3d\0\0\0\x01\0\0\x0c\x08\0\0\0\x16\x01\0\0\
\0\0\0\x0e\x02\0\0\0\x01\0\0\0\x18\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\
\0\0\0\0\0\x03\0\0\0\0\x0b\0\0\0\x04\0\0\0\x0d\0\0\0\x1d\x01\0\0\0\0\0\x0e\x0c\
\0\0\0\x01\0\0\0\x25\x01\0\0\x01\0\0\x0f\0\0\0\0\x0a\0\0\0\0\0\0\0\x04\0\0\0\
\x2b\x01\0\0\x01\0\0\x0f\0\0\0\0\x06\0\0\0\0\0\0\0\x18\0\0\0\x31\x01\0\0\x01\0\
\0\x0f\0\0\0\0\x0d\0\0\0\0\0\0\0\x0d\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\
\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x74\x79\x70\x65\0\
\x6b\x65\x79\x5f\x73\x69\x7a\x65\0\x76\x61\x6c\x75\x65\x5f\x73\x69\x7a\x65\0\
\x6f\x75\x74\x70\x75\x74\0\x63\x74\x78\0\x6b\x70\x72\x6f\x62\x65\x5f\x65\x78\
\x65\x63\0\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x63\x61\x6c\
\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x5f\x65\x78\x65\x63\x76\x65\0\
\x2f\x68\x6f\x6d\x65\x2f\x64\x69\x76\x69\x6b\x63\x68\x6f\x74\x61\x6e\x69\x2e\
\x6c\x69\x6e\x75\x78\x2f\x6c\x65\x61\x72\x6e\x69\x6e\x67\x2d\x65\x62\x70\x66\
\x2f\x63\x68\x61\x70\x74\x65\x72\x36\x2f\x68\x65\x6c\x6c\x6f\x2d\x74\x72\x61\
\x63\x65\x70\x6f\x69\x6e\x74\x2e\x62\x70\x66\x2e\x63\0\x20\x20\x20\x63\x2b\x2b\
\x3b\x20\0\x20\x20\x20\x62\x70\x66\x5f\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\x74\
\x5f\x6f\x75\x74\x70\x75\x74\x28\x63\x74\x78\x2c\x20\x26\x6f\x75\x74\x70\x75\
\x74\x2c\x20\x42\x50\x46\x5f\x46\x5f\x43\x55\x52\x52\x45\x4e\x54\x5f\x43\x50\
\x55\x2c\x20\x20\x26\x63\x2c\x20\x73\x69\x7a\x65\x6f\x66\x28\x63\x29\x29\x3b\0\
\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x30\x3b\0\x63\0\x63\x68\x61\x72\0\x4c\
\x49\x43\x45\x4e\x53\x45\0\x2e\x64\x61\x74\x61\0\x2e\x6d\x61\x70\x73\0\x6c\x69\
\x63\x65\x6e\x73\x65\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\
\0\x3c\0\0\0\x50\0\0\0\0\0\0\0\x08\0\0\0\x49\0\0\0\x01\0\0\0\0\0\0\0\x09\0\0\0\
\x10\0\0\0\x49\0\0\0\x03\0\0\0\0\0\0\0\x6e\0\0\0\xb5\0\0\0\x05\x44\0\0\x28\0\0\
\0\x6e\0\0\0\xbe\0\0\0\x04\x48\0\0\x68\0\0\0\x6e\0\0\0\x09\x01\0\0\x04\x4c\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x78\0\0\0\
\0\0\0\0\x6a\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x14\0\0\0\x11\
\0\x06\0\0\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x8b\0\0\0\x11\0\x07\0\0\0\0\0\0\0\0\
\0\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x28\0\0\0\0\0\0\0\x01\
\0\0\0\x04\0\0\0\x48\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\x01\0\0\0\0\0\0\x04\
\0\0\0\x03\0\0\0\x38\x01\0\0\0\0\0\0\x04\0\0\0\x04\0\0\0\x50\x01\0\0\0\0\0\0\
\x04\0\0\0\x05\0\0\0\x2c\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x40\0\0\0\0\0\0\0\
\x04\0\0\0\x01\0\0\0\x50\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x60\0\0\0\0\0\0\0\
\x04\0\0\0\x01\0\0\0\x0b\x0c\x0d\x0e\0\x2e\x74\x65\x78\x74\0\x2e\x72\x65\x6c\
\x2e\x42\x54\x46\x2e\x65\x78\x74\0\x6f\x75\x74\x70\x75\x74\0\x2e\x6d\x61\x70\
\x73\0\x2e\x6c\x6c\x76\x6d\x5f\x61\x64\x64\x72\x73\x69\x67\0\x2e\x72\x65\x6c\
\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\
\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x5f\x65\x78\x65\x63\x76\x65\0\x6c\x69\
\x63\x65\x6e\x73\x65\0\x6b\x70\x72\x6f\x62\x65\x5f\x65\x78\x65\x63\0\x2e\x73\
\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x64\x61\x74\x61\0\x2e\
\x72\x65\x6c\x2e\x42\x54\x46\0\x4c\x49\x43\x45\x4e\x53\x45\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6c\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x24\x05\0\0\0\0\0\0\x93\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x01\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x33\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x78\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2f\0\0\0\x09\0\
\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\x04\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\
\x0d\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x7c\0\0\0\x01\0\0\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1b\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\xc0\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xd8\0\0\0\0\0\0\0\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x86\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\0\0\0\0\0\0\
\0\x91\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x82\0\
\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb0\x04\0\0\0\0\0\0\x30\0\0\0\
\0\0\0\0\x0d\0\0\0\x08\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x0b\0\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x7c\x03\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x07\0\0\0\x09\0\0\0\x40\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\xe0\x04\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x0d\0\0\0\x0a\0\
\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x21\0\0\0\x03\x4c\xff\x6f\0\0\0\x80\0\
\0\0\0\0\0\0\0\0\0\0\0\x20\x05\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x74\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xf0\x03\0\0\0\0\0\0\x90\0\0\0\0\0\0\0\x01\0\0\0\x02\0\0\0\x08\0\0\0\0\
\0\0\0\x18\0\0\0\0\0\0\0";

	*sz = sizeof(data) - 1;
	return (const void *)data;
}

#ifdef __cplusplus
struct hello_tracepoint_bpf *hello_tracepoint_bpf::open(const struct bpf_object_open_opts *opts) { return hello_tracepoint_bpf__open_opts(opts); }
struct hello_tracepoint_bpf *hello_tracepoint_bpf::open_and_load() { return hello_tracepoint_bpf__open_and_load(); }
int hello_tracepoint_bpf::load(struct hello_tracepoint_bpf *skel) { return hello_tracepoint_bpf__load(skel); }
int hello_tracepoint_bpf::attach(struct hello_tracepoint_bpf *skel) { return hello_tracepoint_bpf__attach(skel); }
void hello_tracepoint_bpf::detach(struct hello_tracepoint_bpf *skel) { hello_tracepoint_bpf__detach(skel); }
void hello_tracepoint_bpf::destroy(struct hello_tracepoint_bpf *skel) { hello_tracepoint_bpf__destroy(skel); }
const void *hello_tracepoint_bpf::elf_bytes(size_t *sz) { return hello_tracepoint_bpf__elf_bytes(sz); }
#endif /* __cplusplus */

__attribute__((unused)) static void
hello_tracepoint_bpf__assert(struct hello_tracepoint_bpf *s __attribute__((unused)))
{
#ifdef __cplusplus
#define _Static_assert static_assert
#endif
	_Static_assert(sizeof(s->data->c) == 4, "unexpected size of 'c'");
#ifdef __cplusplus
#undef _Static_assert
#endif
}

#endif /* __HELLO_TRACEPOINT_BPF_SKEL_H__ */
