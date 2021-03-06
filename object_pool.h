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

#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

typedef struct object_pool_t {
	unsigned int avail_count;
	unsigned int max_size;
	unsigned int item_size;
	void **items;
} object_pool;

#define OBJECT_POOL_INIT(type, size) object_pool_init(size, sizeof(type))
#define OBJECT_POOL_GET(type, pool) (type *) object_pool_get(pool)
#define OBJECT_POOL_RELEASE(obj) object_pool_put(obj)
#define OBJECT_POOL_DESTROY(pool) object_pool_destroy(pool)

object_pool *object_pool_init(unsigned int initial_size, unsigned int item_size);
void object_pool_put(void *obj);
void *object_pool_get(object_pool *pool);
void object_pool_destroy(object_pool *pool);

#ifdef __cplusplus
}
#endif

#endif // OBJECT_POOL_H
