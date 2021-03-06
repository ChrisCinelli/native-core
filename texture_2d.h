/* @license
 * This file is part of the Game Closure SDK.
 *
 * The Game Closure SDK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 
 * The Game Closure SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with the Game Closure SDK.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include "core/types.h"
#include "core/deps/uthash/uthash.h"

#include <time.h> // for last_accessed

struct context_2d_t;

typedef struct texture_2d_t {
	int name;
	int original_name;
	int originalWidth;
	int originalHeight;
	int width;
	int height;
	char *url;
	bool failed;
	UT_hash_handle name_hash;
	UT_hash_handle url_hash;
	bool is_text;
	bool is_canvas;
	struct context_2d_t *ctx;
	time_t last_accessed;
	char *saved_data;
	bool loaded;
	unsigned char *pixel_data;
	int num_channels;
	int scale;
	long assumed_texture_bytes;
	long used_texture_bytes; // Bytes actually used, zero until loaded
	int frame_epoch; // Frame ID to avoid double-counting usage

	struct texture_2d_t *next;
	struct texture_2d_t *prev;
} texture_2d;


#ifdef __cplusplus
extern "C" {
#endif

texture_2d *texture_2d_new_from_url(char *url);
texture_2d *texture_2d_new_from_dimensions(int width, int height);
texture_2d *texture_2d_new_from_data(int width, int height, void *data);
texture_2d *texture_2d_new_from_image(char *url, int name, int width, int height, int original_width, int original_height);
void texture_2d_destroy(texture_2d *tex);

void texture_2d_save(texture_2d *tex);
void texture_2d_reload(texture_2d *tex);

// Load texture from raw image data, returning null on failure to load
unsigned char *texture_2d_load_texture_raw(const char *url, const void *data, unsigned long sz, int *out_channels, int *out_width, int *out_height, int *out_originalWidth, int *out_originalHeight, int *out_scale);

#ifdef __cplusplus
}
#endif

#endif
