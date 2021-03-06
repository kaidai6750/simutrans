/*
 * This file is part of the Simutrans project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef DESCRIPTOR_WRITER_IMAGE_WRITER_H
#define DESCRIPTOR_WRITER_IMAGE_WRITER_H


#include <string>
#include <stdio.h>
#include "obj_writer.h"
#include "../objversion.h"


class obj_node_t;
struct dimension;


class image_writer_t : public obj_writer_t {
	private:
		static image_writer_t the_instance;

		static std::string last_img_file;
		static unsigned char* block;
		static unsigned width;
		static unsigned height;
		static int img_size;	// default 64

		image_writer_t() { register_writer(false); }

		static uint32 block_getpix(int x, int y);

	public:
		static void dump_special_histogramm();

		static image_writer_t* instance() { return &the_instance; }

		static void set_img_size(int _img_size) { img_size = _img_size; }

		virtual obj_type get_type() const { return obj_image; }
		virtual const char* get_type_name() const { return "image"; }

		void write_obj(FILE* fp, obj_node_t& parent, std::string imagekey, uint32 index);

	private:
		bool block_load(const char* fname);

		/**
		 * Encodes an image into a sprite data structure, considers
		 * special colors.
		 */
		static uint16* encode_image(int x, int y, dimension* dim, int* len);
};

#endif
