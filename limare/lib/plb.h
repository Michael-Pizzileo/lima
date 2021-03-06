/*
 * Copyright (c) 2011-2012 Luc Verhaegen <libv@codethink.co.uk>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sub license,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*
 * Some helpers to deal with the plb stream, and the plbu and pp plb
 * reference streams.
 */
#ifndef LIMARE_PLB_H
#define LIMARE_PLB_H 1

struct plb {
	int block_size; /* 0x200 */

	int width; /* aligned already */
	int height;

	int shift_w;
	int shift_h;

	/* holds the actual primitives */
	int plb_offset;
	int plb_size; /* 0x200 * (width >> (shift_w - 1)) * (height >> (shift_h - 1))) */

	/* holds the addresses so the plbu knows where to store the primitives */
	int plbu_offset;
	int plbu_size; /* 4 * width * height */

	/* holds the coordinates and addresses of the primitives for the PP */
	int pp_offset;
	int pp_size; /* 16 * (width * height + 1) */

	void *mem_address;
	int mem_physical;
	int mem_size;
};

struct plb *plb_create(struct limare_state *state, unsigned int physical,
		       void *address, int offset, int size);

#endif /* LIMARE_PLB_H */
