/*
				File:		gliDispatch.h

				Version:	1.0

				Copyright:	� 1999-2000 by Apple Computer, Inc., all rights
	 reserved.
*/

#ifndef _GLIDISPATCH_H
#define _GLIDISPATCH_H

#include "gl.h"

#include "gliContext.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
** GL extension dispatch table type
*/
typedef struct __GLIExtensionDispatchRec {
	GLint ext_count; /* 38 */
	void (*blend_color_EXT)(GLIContext ctx, GLclampf red, GLclampf green,
							GLclampf blue, GLclampf alpha);
	void (*blend_equation_EXT)(GLIContext ctx, GLenum mode);

	void (*lock_arrays_EXT)(GLIContext ctx, GLint first, GLsizei count);
	void (*unlock_arrays_EXT)(GLIContext ctx);

	void (*client_active_texture_ARB)(GLIContext ctx, GLenum target);
	void (*active_texture_ARB)(GLIContext ctx, GLenum target);
	void (*multi_tex_coord1d_ARB)(GLIContext ctx, GLenum target, GLdouble s);
	void (*multi_tex_coord1dv_ARB)(GLIContext ctx, GLenum target,
								   const GLdouble* v);
	void (*multi_tex_coord1f_ARB)(GLIContext ctx, GLenum target, GLfloat s);
	void (*multi_tex_coord1fv_ARB)(GLIContext ctx, GLenum target,
								   const GLfloat* v);
	void (*multi_tex_coord1i_ARB)(GLIContext ctx, GLenum target, GLint s);
	void (*multi_tex_coord1iv_ARB)(GLIContext ctx, GLenum target,
								   const GLint* v);
	void (*multi_tex_coord1s_ARB)(GLIContext ctx, GLenum target, GLshort s);
	void (*multi_tex_coord1sv_ARB)(GLIContext ctx, GLenum target,
								   const GLshort* v);
	void (*multi_tex_coord2d_ARB)(GLIContext ctx, GLenum target, GLdouble s,
								  GLdouble t);
	void (*multi_tex_coord2dv_ARB)(GLIContext ctx, GLenum target,
								   const GLdouble* v);
	void (*multi_tex_coord2f_ARB)(GLIContext ctx, GLenum target, GLfloat s,
								  GLfloat t);
	void (*multi_tex_coord2fv_ARB)(GLIContext ctx, GLenum target,
								   const GLfloat* v);
	void (*multi_tex_coord2i_ARB)(GLIContext ctx, GLenum target, GLint s,
								  GLint t);
	void (*multi_tex_coord2iv_ARB)(GLIContext ctx, GLenum target,
								   const GLint* v);
	void (*multi_tex_coord2s_ARB)(GLIContext ctx, GLenum target, GLshort s,
								  GLshort t);
	void (*multi_tex_coord2sv_ARB)(GLIContext ctx, GLenum target,
								   const GLshort* v);
	void (*multi_tex_coord3d_ARB)(GLIContext ctx, GLenum target, GLdouble s,
								  GLdouble t, GLdouble r);
	void (*multi_tex_coord3dv_ARB)(GLIContext ctx, GLenum target,
								   const GLdouble* v);
	void (*multi_tex_coord3f_ARB)(GLIContext ctx, GLenum target, GLfloat s,
								  GLfloat t, GLfloat r);
	void (*multi_tex_coord3fv_ARB)(GLIContext ctx, GLenum target,
								   const GLfloat* v);
	void (*multi_tex_coord3i_ARB)(GLIContext ctx, GLenum target, GLint s,
								  GLint t, GLint r);
	void (*multi_tex_coord3iv_ARB)(GLIContext ctx, GLenum target,
								   const GLint* v);
	void (*multi_tex_coord3s_ARB)(GLIContext ctx, GLenum target, GLshort s,
								  GLshort t, GLshort r);
	void (*multi_tex_coord3sv_ARB)(GLIContext ctx, GLenum target,
								   const GLshort* v);
	void (*multi_tex_coord4d_ARB)(GLIContext ctx, GLenum target, GLdouble s,
								  GLdouble t, GLdouble r, GLdouble q);
	void (*multi_tex_coord4dv_ARB)(GLIContext ctx, GLenum target,
								   const GLdouble* v);
	void (*multi_tex_coord4f_ARB)(GLIContext ctx, GLenum target, GLfloat s,
								  GLfloat t, GLfloat r, GLfloat q);
	void (*multi_tex_coord4fv_ARB)(GLIContext ctx, GLenum target,
								   const GLfloat* v);
	void (*multi_tex_coord4i_ARB)(GLIContext ctx, GLenum target, GLint s,
								  GLint t, GLint r, GLint q);
	void (*multi_tex_coord4iv_ARB)(GLIContext ctx, GLenum target,
								   const GLint* v);
	void (*multi_tex_coord4s_ARB)(GLIContext ctx, GLenum target, GLshort s,
								  GLshort t, GLshort r, GLshort q);
	void (*multi_tex_coord4sv_ARB)(GLIContext ctx, GLenum target,
								   const GLshort* v);

	void (*load_transpose_matrixd_ARB)(GLIContext ctx, const GLdouble* m);
	void (*load_transpose_matrixf_ARB)(GLIContext ctx, const GLfloat* m);
	void (*mult_transpose_matrixd_ARB)(GLIContext ctx, const GLdouble* m);
	void (*mult_transpose_matrixf_ARB)(GLIContext ctx, const GLfloat* m);

	void (*compressed_tex_image3D_ARB)(GLIContext ctx, GLenum target,
									   GLint level, GLenum internalformat,
									   GLsizei width, GLsizei height,
									   GLsizei depth, GLint border,
									   GLsizei imageSize, const GLvoid* data);
	void (*compressed_tex_image2D_ARB)(GLIContext ctx, GLenum target,
									   GLint level, GLenum internalformat,
									   GLsizei width, GLsizei height,
									   GLint border, GLsizei imageSize,
									   const GLvoid* data);
	void (*compressed_tex_image1D_ARB)(GLIContext ctx, GLenum target,
									   GLint level, GLenum internalformat,
									   GLsizei width, GLint border,
									   GLsizei imageSize, const GLvoid* data);
	void (*compressed_tex_sub_image3D_ARB)(
		GLIContext ctx, GLenum target, GLint level, GLint xoffset,
		GLint yoffset, GLint zoffset, GLsizei width, GLsizei height,
		GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
	void (*compressed_tex_sub_image2D_ARB)(GLIContext ctx, GLenum target,
										   GLint level, GLint xoffset,
										   GLint yoffset, GLsizei width,
										   GLsizei height, GLenum format,
										   GLsizei		 imageSize,
										   const GLvoid* data);
	void (*compressed_tex_sub_image1D_ARB)(GLIContext ctx, GLenum target,
										   GLint level, GLint xoffset,
										   GLsizei width, GLenum format,
										   GLsizei		 imageSize,
										   const GLvoid* data);
	void (*get_compressed_tex_image_ARB)(GLIContext ctx, GLenum target,
										 GLint level, void* img);

	void (*secondaryColor3b_EXT)(GLIContext ctx, GLbyte red, GLbyte green,
								 GLbyte blue);
	void (*secondaryColor3bv_EXT)(GLIContext ctx, const GLbyte* v);
	void (*secondaryColor3d_EXT)(GLIContext ctx, GLdouble red, GLdouble green,
								 GLdouble blue);
	void (*secondary_color3dv_EXT)(GLIContext ctx, const GLdouble* v);
	void (*secondary_color3f_EXT)(GLIContext ctx, GLfloat red, GLfloat green,
								  GLfloat blue);
	void (*secondary_color3fv_EXT)(GLIContext ctx, const GLfloat* v);
	void (*secondary_color3i_EXT)(GLIContext ctx, GLint red, GLint green,
								  GLint blue);
	void (*secondary_color3iv_EXT)(GLIContext ctx, const GLint* v);
	void (*secondary_color3s_EXT)(GLIContext ctx, GLshort red, GLshort green,
								  GLshort blue);
	void (*secondary_color3sv_EXT)(GLIContext ctx, const GLshort* v);
	void (*secondary_color3ub_EXT)(GLIContext ctx, GLubyte red, GLubyte green,
								   GLubyte blue);
	void (*secondary_color3ubv_EXT)(GLIContext ctx, const GLubyte* v);
	void (*secondary_color3ui_EXT)(GLIContext ctx, GLuint red, GLuint green,
								   GLuint blue);
	void (*secondary_color3uiv_EXT)(GLIContext ctx, const GLuint* v);
	void (*secondary_color3us_EXT)(GLIContext ctx, GLushort red, GLushort green,
								   GLushort blue);
	void (*secondary_color3usv_EXT)(GLIContext ctx, const GLushort* v);
	void (*secondary_color_pointer_EXT)(GLIContext ctx, GLint size, GLenum type,
										GLsizei stride, GLvoid* pointer);

	void (*blend_color)(GLIContext ctx, GLclampf red, GLclampf green,
						GLclampf blue, GLclampf alpha);
	void (*blend_equation)(GLIContext ctx, GLenum mode);
	void (*draw_range_elements)(GLIContext ctx, GLenum mode, GLuint start,
								GLuint end, GLsizei count, GLenum type,
								const GLvoid* indices);
	void (*color_table)(GLIContext ctx, GLenum target, GLenum internalformat,
						GLsizei width, GLenum format, GLenum type,
						const GLvoid* table);
	void (*color_table_parameterfv)(GLIContext ctx, GLenum target, GLenum pname,
									const GLfloat* params);
	void (*color_table_parameteriv)(GLIContext ctx, GLenum target, GLenum pname,
									const GLint* params);
	void (*copy_color_table)(GLIContext ctx, GLenum target,
							 GLenum internalformat, GLint x, GLint y,
							 GLsizei width);
	void (*get_color_table)(GLIContext ctx, GLenum target, GLenum format,
							GLenum type, GLvoid* table);
	void (*get_color_table_parameterfv)(GLIContext ctx, GLenum target,
										GLenum pname, GLfloat* params);
	void (*get_color_table_parameteriv)(GLIContext ctx, GLenum target,
										GLenum pname, GLint* params);
	void (*color_sub_table)(GLIContext ctx, GLenum target, GLsizei start,
							GLsizei count, GLenum format, GLenum type,
							const GLvoid* data);
	void (*copy_color_sub_table)(GLIContext ctx, GLenum target, GLsizei start,
								 GLint x, GLint y, GLsizei width);
	void (*convolution_filter1D)(GLIContext ctx, GLenum target,
								 GLenum internalformat, GLsizei width,
								 GLenum format, GLenum type,
								 const GLvoid* image);
	void (*convolution_filter2D)(GLIContext ctx, GLenum target,
								 GLenum internalformat, GLsizei width,
								 GLsizei height, GLenum format, GLenum type,
								 const GLvoid* image);
	void (*convolution_parameterf)(GLIContext ctx, GLenum target, GLenum pname,
								   GLfloat params);
	void (*convolution_parameterfv)(GLIContext ctx, GLenum target, GLenum pname,
									const GLfloat* params);
	void (*convolution_parameteri)(GLIContext ctx, GLenum target, GLenum pname,
								   GLint params);
	void (*convolution_parameteriv)(GLIContext ctx, GLenum target, GLenum pname,
									const GLint* params);
	void (*copy_convolution_filter1D)(GLIContext ctx, GLenum target,
									  GLenum internalformat, GLint x, GLint y,
									  GLsizei width);
	void (*copy_convolution_filter2D)(GLIContext ctx, GLenum target,
									  GLenum internalformat, GLint x, GLint y,
									  GLsizei width, GLsizei height);
	void (*get_convolution_filter)(GLIContext ctx, GLenum target, GLenum format,
								   GLenum type, GLvoid* image);
	void (*get_convolution_parameterfv)(GLIContext ctx, GLenum target,
										GLenum pname, GLfloat* params);
	void (*get_convolution_parameteriv)(GLIContext ctx, GLenum target,
										GLenum pname, GLint* params);
	void (*get_separable_filter)(GLIContext ctx, GLenum target, GLenum format,
								 GLenum type, GLvoid* row, GLvoid* column,
								 GLvoid* span);
	void (*separable_filter2D)(GLIContext ctx, GLenum target,
							   GLenum internalformat, GLsizei width,
							   GLsizei height, GLenum format, GLenum type,
							   const GLvoid* row, const GLvoid* column);
	void (*get_histogram)(GLIContext ctx, GLenum target, GLboolean reset,
						  GLenum format, GLenum type, GLvoid* values);
	void (*get_histogram_parameterfv)(GLIContext ctx, GLenum target,
									  GLenum pname, GLfloat* params);
	void (*get_histogram_parameteriv)(GLIContext ctx, GLenum target,
									  GLenum pname, GLint* params);
	void (*get_minmax)(GLIContext ctx, GLenum target, GLboolean reset,
					   GLenum format, GLenum type, GLvoid* values);
	void (*get_minmax_parameterfv)(GLIContext ctx, GLenum target, GLenum pname,
								   GLfloat* params);
	void (*get_minmax_parameteriv)(GLIContext ctx, GLenum target, GLenum pname,
								   GLint* params);
	void (*histogram)(GLIContext ctx, GLenum target, GLsizei width,
					  GLenum internalformat, GLboolean sink);
	void (*minmax)(GLIContext ctx, GLenum target, GLenum internalformat,
				   GLboolean sink);
	void (*reset_histogram)(GLIContext ctx, GLenum target);
	void (*reset_minmax)(GLIContext ctx, GLenum target);
	void (*tex_image3D)(GLIContext ctx, GLenum target, GLint level,
						GLint internalformat, GLsizei width, GLsizei height,
						GLsizei depth, GLint border, GLenum format, GLenum type,
						const GLvoid* pixels);
	void (*tex_sub_image3D)(GLIContext ctx, GLenum target, GLint level,
							GLint xoffset, GLint yoffset, GLint zoffset,
							GLsizei width, GLsizei height, GLsizei depth,
							GLenum format, GLenum type, const GLvoid* pixels);
	void (*copy_tex_sub_image3D)(GLIContext ctx, GLenum target, GLint level,
								 GLint xoffset, GLint yoffset, GLint zoffset,
								 GLint x, GLint y, GLsizei width,
								 GLsizei height);
} GLIExtensionDispatch;

/*
** GL function dispatch table type
*/
typedef struct __GLIFunctionDispatchRec {
	void (*accum)(GLIContext ctx, GLenum op, GLfloat value);
	void (*alpha_func)(GLIContext ctx, GLenum func, GLclampf ref);
	GLboolean (*are_textures_resident)(GLIContext ctx, GLsizei n,
									   const GLuint* textures,
									   GLboolean*	 residences);
	void (*array_element)(GLIContext ctx, GLint i);
	void (*begin)(GLIContext ctx, GLenum mode);
	void (*bind_texture)(GLIContext ctx, GLenum target, GLuint texture);
	void (*bitmap)(GLIContext ctx, GLsizei width, GLsizei height, GLfloat xorig,
				   GLfloat yorig, GLfloat xmove, GLfloat ymove,
				   const GLubyte* bitmap);
	void (*blend_func)(GLIContext ctx, GLenum sfactor, GLenum dfactor);
	void (*call_list)(GLIContext ctx, GLuint list);
	void (*call_lists)(GLIContext ctx, GLsizei n, GLenum type,
					   const GLvoid* lists);
	void (*clear)(GLIContext ctx, GLbitfield mask);
	void (*clear_accum)(GLIContext ctx, GLfloat red, GLfloat green,
						GLfloat blue, GLfloat alpha);
	void (*clear_color)(GLIContext ctx, GLclampf red, GLclampf green,
						GLclampf blue, GLclampf alpha);
	void (*clear_depth)(GLIContext ctx, GLclampd depth);
	void (*clear_index)(GLIContext ctx, GLfloat c);
	void (*clear_stencil)(GLIContext ctx, GLint s);
	void (*clip_plane)(GLIContext ctx, GLenum plane, const GLdouble* equation);
	void (*color3b)(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue);
	void (*color3bv)(GLIContext ctx, const GLbyte* v);
	void (*color3d)(GLIContext ctx, GLdouble red, GLdouble green,
					GLdouble blue);
	void (*color3dv)(GLIContext ctx, const GLdouble* v);
	void (*color3f)(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue);
	void (*color3fv)(GLIContext ctx, const GLfloat* v);
	void (*color3i)(GLIContext ctx, GLint red, GLint green, GLint blue);
	void (*color3iv)(GLIContext ctx, const GLint* v);
	void (*color3s)(GLIContext ctx, GLshort red, GLshort green, GLshort blue);
	void (*color3sv)(GLIContext ctx, const GLshort* v);
	void (*color3ub)(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue);
	void (*color3ubv)(GLIContext ctx, const GLubyte* v);
	void (*color3ui)(GLIContext ctx, GLuint red, GLuint green, GLuint blue);
	void (*color3uiv)(GLIContext ctx, const GLuint* v);
	void (*color3us)(GLIContext ctx, GLushort red, GLushort green,
					 GLushort blue);
	void (*color3usv)(GLIContext ctx, const GLushort* v);
	void (*color4b)(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue,
					GLbyte alpha);
	void (*color4bv)(GLIContext ctx, const GLbyte* v);
	void (*color4d)(GLIContext ctx, GLdouble red, GLdouble green, GLdouble blue,
					GLdouble alpha);
	void (*color4dv)(GLIContext ctx, const GLdouble* v);
	void (*color4f)(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue,
					GLfloat alpha);
	void (*color4fv)(GLIContext ctx, const GLfloat* v);
	void (*color4i)(GLIContext ctx, GLint red, GLint green, GLint blue,
					GLint alpha);
	void (*color4iv)(GLIContext ctx, const GLint* v);
	void (*color4s)(GLIContext ctx, GLshort red, GLshort green, GLshort blue,
					GLshort alpha);
	void (*color4sv)(GLIContext ctx, const GLshort* v);
	void (*color4ub)(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue,
					 GLubyte alpha);
	void (*color4ubv)(GLIContext ctx, const GLubyte* v);
	void (*color4ui)(GLIContext ctx, GLuint red, GLuint green, GLuint blue,
					 GLuint alpha);
	void (*color4uiv)(GLIContext ctx, const GLuint* v);
	void (*color4us)(GLIContext ctx, GLushort red, GLushort green,
					 GLushort blue, GLushort alpha);
	void (*color4usv)(GLIContext ctx, const GLushort* v);
	void (*color_mask)(GLIContext ctx, GLboolean red, GLboolean green,
					   GLboolean blue, GLboolean alpha);
	void (*color_material)(GLIContext ctx, GLenum face, GLenum mode);
	void (*color_pointer)(GLIContext ctx, GLint size, GLenum type,
						  GLsizei stride, const GLvoid* pointer);
	void (*copy_pixels)(GLIContext ctx, GLint x, GLint y, GLsizei width,
						GLsizei height, GLenum type);
	void (*copy_tex_image1D)(GLIContext ctx, GLenum target, GLint level,
							 GLenum internalFormat, GLint x, GLint y,
							 GLsizei width, GLint border);
	void (*copy_tex_image2D)(GLIContext ctx, GLenum target, GLint level,
							 GLenum internalFormat, GLint x, GLint y,
							 GLsizei width, GLsizei height, GLint border);
	void (*copy_tex_sub_image1D)(GLIContext ctx, GLenum target, GLint level,
								 GLint xoffset, GLint x, GLint y,
								 GLsizei width);
	void (*copy_tex_sub_image2D)(GLIContext ctx, GLenum target, GLint level,
								 GLint xoffset, GLint yoffset, GLint x, GLint y,
								 GLsizei width, GLsizei height);
	void (*cull_face)(GLIContext ctx, GLenum mode);
	void (*delete_lists)(GLIContext ctx, GLuint list, GLsizei range);
	void (*delete_textures)(GLIContext ctx, GLsizei n, const GLuint* textures);
	void (*depth_func)(GLIContext ctx, GLenum func);
	void (*depth_mask)(GLIContext ctx, GLboolean flag);
	void (*depth_range)(GLIContext ctx, GLclampd zNear, GLclampd zFar);
	void (*disable)(GLIContext ctx, GLenum cap);
	void (*disable_client_state)(GLIContext ctx, GLenum array);
	void (*draw_arrays)(GLIContext ctx, GLenum mode, GLint first,
						GLsizei count);
	void (*draw_buffer)(GLIContext ctx, GLenum mode);
	void (*draw_elements)(GLIContext ctx, GLenum mode, GLsizei count,
						  GLenum type, const GLvoid* indices);
	void (*draw_pixels)(GLIContext ctx, GLsizei width, GLsizei height,
						GLenum format, GLenum type, const GLvoid* pixels);
	void (*edge_flag)(GLIContext ctx, GLboolean flag);
	void (*edge_flag_pointer)(GLIContext ctx, GLsizei stride,
							  const GLvoid* pointer);
	void (*edge_flagv)(GLIContext ctx, const GLboolean* flag);
	void (*enable)(GLIContext ctx, GLenum cap);
	void (*enable_client_state)(GLIContext ctx, GLenum array);
	void (*end)(GLIContext ctx);
	void (*end_list)(GLIContext ctx);
	void (*eval_coord1d)(GLIContext ctx, GLdouble u);
	void (*eval_coord1dv)(GLIContext ctx, const GLdouble* u);
	void (*eval_coord1f)(GLIContext ctx, GLfloat u);
	void (*eval_coord1fv)(GLIContext ctx, const GLfloat* u);
	void (*eval_coord2d)(GLIContext ctx, GLdouble u, GLdouble v);
	void (*eval_coord2dv)(GLIContext ctx, const GLdouble* u);
	void (*eval_coord2f)(GLIContext ctx, GLfloat u, GLfloat v);
	void (*eval_coord2fv)(GLIContext ctx, const GLfloat* u);
	void (*eval_mesh1)(GLIContext ctx, GLenum mode, GLint i1, GLint i2);
	void (*eval_mesh2)(GLIContext ctx, GLenum mode, GLint i1, GLint i2,
					   GLint j1, GLint j2);
	void (*eval_point1)(GLIContext ctx, GLint i);
	void (*eval_point2)(GLIContext ctx, GLint i, GLint j);
	void (*feedback_buffer)(GLIContext ctx, GLsizei size, GLenum type,
							GLfloat* buffer);
	void (*finish)(GLIContext ctx);
	void (*flush)(GLIContext ctx);
	void (*fogf)(GLIContext ctx, GLenum pname, GLfloat param);
	void (*fogfv)(GLIContext ctx, GLenum pname, const GLfloat* params);
	void (*fogi)(GLIContext ctx, GLenum pname, GLint param);
	void (*fogiv)(GLIContext ctx, GLenum pname, const GLint* params);
	void (*front_face)(GLIContext ctx, GLenum mode);
	void (*frustum)(GLIContext ctx, GLdouble left, GLdouble right,
					GLdouble bottom, GLdouble top, GLdouble zNear,
					GLdouble zFar);
	GLuint (*gen_lists)(GLIContext ctx, GLsizei range);
	void (*gen_textures)(GLIContext ctx, GLsizei n, GLuint* textures);
	void (*get_booleanv)(GLIContext ctx, GLenum pname, GLboolean* params);
	void (*get_clip_plane)(GLIContext ctx, GLenum plane, GLdouble* equation);
	void (*get_doublev)(GLIContext ctx, GLenum pname, GLdouble* params);
	GLenum (*get_error)(GLIContext ctx);
	void (*get_floatv)(GLIContext ctx, GLenum pname, GLfloat* params);
	void (*get_integerv)(GLIContext ctx, GLenum pname, GLint* params);
	void (*get_lightfv)(GLIContext ctx, GLenum light, GLenum pname,
						GLfloat* params);
	void (*get_lightiv)(GLIContext ctx, GLenum light, GLenum pname,
						GLint* params);
	void (*get_mapdv)(GLIContext ctx, GLenum target, GLenum query, GLdouble* v);
	void (*get_mapfv)(GLIContext ctx, GLenum target, GLenum query, GLfloat* v);
	void (*get_mapiv)(GLIContext ctx, GLenum target, GLenum query, GLint* v);
	void (*get_materialfv)(GLIContext ctx, GLenum face, GLenum pname,
						   GLfloat* params);
	void (*get_materialiv)(GLIContext ctx, GLenum face, GLenum pname,
						   GLint* params);
	void (*get_pixel_mapfv)(GLIContext ctx, GLenum map, GLfloat* values);
	void (*get_pixel_mapuiv)(GLIContext ctx, GLenum map, GLuint* values);
	void (*get_pixel_mapusv)(GLIContext ctx, GLenum map, GLushort* values);
	void (*get_pointerv)(GLIContext ctx, GLenum pname, GLvoid** params);
	void (*get_polygon_stipple)(GLIContext ctx, GLubyte* mask);
	const GLubyte* (*get_string)(GLIContext ctx, GLenum name);
	void (*get_tex_envfv)(GLIContext ctx, GLenum target, GLenum pname,
						  GLfloat* params);
	void (*get_tex_enviv)(GLIContext ctx, GLenum target, GLenum pname,
						  GLint* params);
	void (*get_tex_gendv)(GLIContext ctx, GLenum coord, GLenum pname,
						  GLdouble* params);
	void (*get_tex_genfv)(GLIContext ctx, GLenum coord, GLenum pname,
						  GLfloat* params);
	void (*get_tex_geniv)(GLIContext ctx, GLenum coord, GLenum pname,
						  GLint* params);
	void (*get_tex_image)(GLIContext ctx, GLenum target, GLint level,
						  GLenum format, GLenum type, GLvoid* pixels);
	void (*get_tex_level_parameterfv)(GLIContext ctx, GLenum target,
									  GLint level, GLenum pname,
									  GLfloat* params);
	void (*get_tex_level_parameteriv)(GLIContext ctx, GLenum target,
									  GLint level, GLenum pname, GLint* params);
	void (*get_tex_parameterfv)(GLIContext ctx, GLenum target, GLenum pname,
								GLfloat* params);
	void (*get_tex_parameteriv)(GLIContext ctx, GLenum target, GLenum pname,
								GLint* params);
	void (*hint)(GLIContext ctx, GLenum target, GLenum mode);
	void (*index_mask)(GLIContext ctx, GLuint mask);
	void (*index_pointer)(GLIContext ctx, GLenum type, GLsizei stride,
						  const GLvoid* pointer);
	void (*indexd)(GLIContext ctx, GLdouble c);
	void (*indexdv)(GLIContext ctx, const GLdouble* c);
	void (*indexf)(GLIContext ctx, GLfloat c);
	void (*indexfv)(GLIContext ctx, const GLfloat* c);
	void (*indexi)(GLIContext ctx, GLint c);
	void (*indexiv)(GLIContext ctx, const GLint* c);
	void (*indexs)(GLIContext ctx, GLshort c);
	void (*indexsv)(GLIContext ctx, const GLshort* c);
	void (*indexub)(GLIContext ctx, GLubyte c);
	void (*indexubv)(GLIContext ctx, const GLubyte* c);
	void (*init_names)(GLIContext ctx);
	void (*interleaved_arrays)(GLIContext ctx, GLenum format, GLsizei stride,
							   const GLvoid* pointer);
	GLboolean (*is_enabled)(GLIContext ctx, GLenum cap);
	GLboolean (*is_list)(GLIContext ctx, GLuint list);
	GLboolean (*is_texture)(GLIContext ctx, GLuint texture);
	void (*light_modelf)(GLIContext ctx, GLenum pname, GLfloat param);
	void (*light_modelfv)(GLIContext ctx, GLenum pname, const GLfloat* params);
	void (*light_modeli)(GLIContext ctx, GLenum pname, GLint param);
	void (*light_modeliv)(GLIContext ctx, GLenum pname, const GLint* params);
	void (*lightf)(GLIContext ctx, GLenum light, GLenum pname, GLfloat param);
	void (*lightfv)(GLIContext ctx, GLenum light, GLenum pname,
					const GLfloat* params);
	void (*lighti)(GLIContext ctx, GLenum light, GLenum pname, GLint param);
	void (*lightiv)(GLIContext ctx, GLenum light, GLenum pname,
					const GLint* params);
	void (*line_stipple)(GLIContext ctx, GLint factor, GLushort pattern);
	void (*line_width)(GLIContext ctx, GLfloat width);
	void (*list_base)(GLIContext ctx, GLuint base);
	void (*load_identity)(GLIContext ctx);
	void (*load_matrixd)(GLIContext ctx, const GLdouble* m);
	void (*load_matrixf)(GLIContext ctx, const GLfloat* m);
	void (*load_name)(GLIContext ctx, GLuint name);
	void (*logic_op)(GLIContext ctx, GLenum opcode);
	void (*map1d)(GLIContext ctx, GLenum target, GLdouble u1, GLdouble u2,
				  GLint stride, GLint order, const GLdouble* points);
	void (*map1f)(GLIContext ctx, GLenum target, GLfloat u1, GLfloat u2,
				  GLint stride, GLint order, const GLfloat* points);
	void (*map2d)(GLIContext ctx, GLenum target, GLdouble u1, GLdouble u2,
				  GLint ustride, GLint uorder, GLdouble v1, GLdouble v2,
				  GLint vstride, GLint vorder, const GLdouble* points);
	void (*map2f)(GLIContext ctx, GLenum target, GLfloat u1, GLfloat u2,
				  GLint ustride, GLint uorder, GLfloat v1, GLfloat v2,
				  GLint vstride, GLint vorder, const GLfloat* points);
	void (*map_grid1d)(GLIContext ctx, GLint un, GLdouble u1, GLdouble u2);
	void (*map_grid1f)(GLIContext ctx, GLint un, GLfloat u1, GLfloat u2);
	void (*map_grid2d)(GLIContext ctx, GLint un, GLdouble u1, GLdouble u2,
					   GLint vn, GLdouble v1, GLdouble v2);
	void (*map_grid2f)(GLIContext ctx, GLint un, GLfloat u1, GLfloat u2,
					   GLint vn, GLfloat v1, GLfloat v2);
	void (*materialf)(GLIContext ctx, GLenum face, GLenum pname, GLfloat param);
	void (*materialfv)(GLIContext ctx, GLenum face, GLenum pname,
					   const GLfloat* params);
	void (*materiali)(GLIContext ctx, GLenum face, GLenum pname, GLint param);
	void (*materialiv)(GLIContext ctx, GLenum face, GLenum pname,
					   const GLint* params);
	void (*matrix_mode)(GLIContext ctx, GLenum mode);
	void (*mult_matrixd)(GLIContext ctx, const GLdouble* m);
	void (*mult_matrixf)(GLIContext ctx, const GLfloat* m);
	void (*new_list)(GLIContext ctx, GLuint list, GLenum mode);
	void (*normal3b)(GLIContext ctx, GLbyte nx, GLbyte ny, GLbyte nz);
	void (*normal3bv)(GLIContext ctx, const GLbyte* v);
	void (*normal3d)(GLIContext ctx, GLdouble nx, GLdouble ny, GLdouble nz);
	void (*normal3dv)(GLIContext ctx, const GLdouble* v);
	void (*normal3f)(GLIContext ctx, GLfloat nx, GLfloat ny, GLfloat nz);
	void (*normal3fv)(GLIContext ctx, const GLfloat* v);
	void (*normal3i)(GLIContext ctx, GLint nx, GLint ny, GLint nz);
	void (*normal3iv)(GLIContext ctx, const GLint* v);
	void (*normal3s)(GLIContext ctx, GLshort nx, GLshort ny, GLshort nz);
	void (*normal3sv)(GLIContext ctx, const GLshort* v);
	void (*normal_pointer)(GLIContext ctx, GLenum type, GLsizei stride,
						   const GLvoid* pointer);
	void (*ortho)(GLIContext ctx, GLdouble left, GLdouble right,
				  GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	void (*pass_through)(GLIContext ctx, GLfloat token);
	void (*pixel_mapfv)(GLIContext ctx, GLenum map, GLsizei mapsize,
						const GLfloat* values);
	void (*pixel_mapuiv)(GLIContext ctx, GLenum map, GLsizei mapsize,
						 const GLuint* values);
	void (*pixel_mapusv)(GLIContext ctx, GLenum map, GLsizei mapsize,
						 const GLushort* values);
	void (*pixel_storef)(GLIContext ctx, GLenum pname, GLfloat param);
	void (*pixel_storei)(GLIContext ctx, GLenum pname, GLint param);
	void (*pixel_transferf)(GLIContext ctx, GLenum pname, GLfloat param);
	void (*pixel_transferi)(GLIContext ctx, GLenum pname, GLint param);
	void (*pixel_zoom)(GLIContext ctx, GLfloat xfactor, GLfloat yfactor);
	void (*point_size)(GLIContext ctx, GLfloat size);
	void (*polygon_mode)(GLIContext ctx, GLenum face, GLenum mode);
	void (*polygon_offset)(GLIContext ctx, GLfloat factor, GLfloat units);
	void (*polygon_stipple)(GLIContext ctx, const GLubyte* mask);
	void (*pop_attrib)(GLIContext ctx);
	void (*pop_client_attrib)(GLIContext ctx);
	void (*pop_matrix)(GLIContext ctx);
	void (*pop_name)(GLIContext ctx);
	void (*prioritize_textures)(GLIContext ctx, GLsizei n,
								const GLuint*	textures,
								const GLclampf* priorities);
	void (*push_attrib)(GLIContext ctx, GLbitfield mask);
	void (*push_client_attrib)(GLIContext ctx, GLbitfield mask);
	void (*push_matrix)(GLIContext ctx);
	void (*push_name)(GLIContext ctx, GLuint name);
	void (*raster_pos2d)(GLIContext ctx, GLdouble x, GLdouble y);
	void (*raster_pos2dv)(GLIContext ctx, const GLdouble* v);
	void (*raster_pos2f)(GLIContext ctx, GLfloat x, GLfloat y);
	void (*raster_pos2fv)(GLIContext ctx, const GLfloat* v);
	void (*raster_pos2i)(GLIContext ctx, GLint x, GLint y);
	void (*raster_pos2iv)(GLIContext ctx, const GLint* v);
	void (*raster_pos2s)(GLIContext ctx, GLshort x, GLshort y);
	void (*raster_pos2sv)(GLIContext ctx, const GLshort* v);
	void (*raster_pos3d)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z);
	void (*raster_pos3dv)(GLIContext ctx, const GLdouble* v);
	void (*raster_pos3f)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z);
	void (*raster_pos3fv)(GLIContext ctx, const GLfloat* v);
	void (*raster_pos3i)(GLIContext ctx, GLint x, GLint y, GLint z);
	void (*raster_pos3iv)(GLIContext ctx, const GLint* v);
	void (*raster_pos3s)(GLIContext ctx, GLshort x, GLshort y, GLshort z);
	void (*raster_pos3sv)(GLIContext ctx, const GLshort* v);
	void (*raster_pos4d)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z,
						 GLdouble w);
	void (*raster_pos4dv)(GLIContext ctx, const GLdouble* v);
	void (*raster_pos4f)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z,
						 GLfloat w);
	void (*raster_pos4fv)(GLIContext ctx, const GLfloat* v);
	void (*raster_pos4i)(GLIContext ctx, GLint x, GLint y, GLint z, GLint w);
	void (*raster_pos4iv)(GLIContext ctx, const GLint* v);
	void (*raster_pos4s)(GLIContext ctx, GLshort x, GLshort y, GLshort z,
						 GLshort w);
	void (*raster_pos4sv)(GLIContext ctx, const GLshort* v);
	void (*read_buffer)(GLIContext ctx, GLenum mode);
	void (*read_pixels)(GLIContext ctx, GLint x, GLint y, GLsizei width,
						GLsizei height, GLenum format, GLenum type,
						GLvoid* pixels);
	void (*rectd)(GLIContext ctx, GLdouble x1, GLdouble y1, GLdouble x2,
				  GLdouble y2);
	void (*rectdv)(GLIContext ctx, const GLdouble* v1, const GLdouble* v2);
	void (*rectf)(GLIContext ctx, GLfloat x1, GLfloat y1, GLfloat x2,
				  GLfloat y2);
	void (*rectfv)(GLIContext ctx, const GLfloat* v1, const GLfloat* v2);
	void (*recti)(GLIContext ctx, GLint x1, GLint y1, GLint x2, GLint y2);
	void (*rectiv)(GLIContext ctx, const GLint* v1, const GLint* v2);
	void (*rects)(GLIContext ctx, GLshort x1, GLshort y1, GLshort x2,
				  GLshort y2);
	void (*rectsv)(GLIContext ctx, const GLshort* v1, const GLshort* v2);
	GLint (*render_mode)(GLIContext ctx, GLenum mode);
	void (*rotated)(GLIContext ctx, GLdouble angle, GLdouble x, GLdouble y,
					GLdouble z);
	void (*rotatef)(GLIContext ctx, GLfloat angle, GLfloat x, GLfloat y,
					GLfloat z);
	void (*scaled)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z);
	void (*scalef)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z);
	void (*scissor)(GLIContext ctx, GLint x, GLint y, GLsizei width,
					GLsizei height);
	void (*select_buffer)(GLIContext ctx, GLsizei size, GLuint* buffer);
	void (*shade_model)(GLIContext ctx, GLenum mode);
	void (*stencil_func)(GLIContext ctx, GLenum func, GLint ref, GLuint mask);
	void (*stencil_mask)(GLIContext ctx, GLuint mask);
	void (*stencil_op)(GLIContext ctx, GLenum fail, GLenum zfail, GLenum zpass);
	void (*tex_coord1d)(GLIContext ctx, GLdouble s);
	void (*tex_coord1dv)(GLIContext ctx, const GLdouble* v);
	void (*tex_coord1f)(GLIContext ctx, GLfloat s);
	void (*tex_coord1fv)(GLIContext ctx, const GLfloat* v);
	void (*tex_coord1i)(GLIContext ctx, GLint s);
	void (*tex_coord1iv)(GLIContext ctx, const GLint* v);
	void (*tex_coord1s)(GLIContext ctx, GLshort s);
	void (*tex_coord1sv)(GLIContext ctx, const GLshort* v);
	void (*tex_coord2d)(GLIContext ctx, GLdouble s, GLdouble t);
	void (*tex_coord2dv)(GLIContext ctx, const GLdouble* v);
	void (*tex_coord2f)(GLIContext ctx, GLfloat s, GLfloat t);
	void (*tex_coord2fv)(GLIContext ctx, const GLfloat* v);
	void (*tex_coord2i)(GLIContext ctx, GLint s, GLint t);
	void (*tex_coord2iv)(GLIContext ctx, const GLint* v);
	void (*tex_coord2s)(GLIContext ctx, GLshort s, GLshort t);
	void (*tex_coord2sv)(GLIContext ctx, const GLshort* v);
	void (*tex_coord3d)(GLIContext ctx, GLdouble s, GLdouble t, GLdouble r);
	void (*tex_coord3dv)(GLIContext ctx, const GLdouble* v);
	void (*tex_coord3f)(GLIContext ctx, GLfloat s, GLfloat t, GLfloat r);
	void (*tex_coord3fv)(GLIContext ctx, const GLfloat* v);
	void (*tex_coord3i)(GLIContext ctx, GLint s, GLint t, GLint r);
	void (*tex_coord3iv)(GLIContext ctx, const GLint* v);
	void (*tex_coord3s)(GLIContext ctx, GLshort s, GLshort t, GLshort r);
	void (*tex_coord3sv)(GLIContext ctx, const GLshort* v);
	void (*tex_coord4d)(GLIContext ctx, GLdouble s, GLdouble t, GLdouble r,
						GLdouble q);
	void (*tex_coord4dv)(GLIContext ctx, const GLdouble* v);
	void (*tex_coord4f)(GLIContext ctx, GLfloat s, GLfloat t, GLfloat r,
						GLfloat q);
	void (*tex_coord4fv)(GLIContext ctx, const GLfloat* v);
	void (*tex_coord4i)(GLIContext ctx, GLint s, GLint t, GLint r, GLint q);
	void (*tex_coord4iv)(GLIContext ctx, const GLint* v);
	void (*tex_coord4s)(GLIContext ctx, GLshort s, GLshort t, GLshort r,
						GLshort q);
	void (*tex_coord4sv)(GLIContext ctx, const GLshort* v);
	void (*tex_coord_pointer)(GLIContext ctx, GLint size, GLenum type,
							  GLsizei stride, const GLvoid* pointer);
	void (*tex_envf)(GLIContext ctx, GLenum target, GLenum pname,
					 GLfloat param);
	void (*tex_envfv)(GLIContext ctx, GLenum target, GLenum pname,
					  const GLfloat* params);
	void (*tex_envi)(GLIContext ctx, GLenum target, GLenum pname, GLint param);
	void (*tex_enviv)(GLIContext ctx, GLenum target, GLenum pname,
					  const GLint* params);
	void (*tex_gend)(GLIContext ctx, GLenum coord, GLenum pname,
					 GLdouble param);
	void (*tex_gendv)(GLIContext ctx, GLenum coord, GLenum pname,
					  const GLdouble* params);
	void (*tex_genf)(GLIContext ctx, GLenum coord, GLenum pname, GLfloat param);
	void (*tex_genfv)(GLIContext ctx, GLenum coord, GLenum pname,
					  const GLfloat* params);
	void (*tex_geni)(GLIContext ctx, GLenum coord, GLenum pname, GLint param);
	void (*tex_geniv)(GLIContext ctx, GLenum coord, GLenum pname,
					  const GLint* params);
	void (*tex_image1D)(GLIContext ctx, GLenum target, GLint level,
						GLint internalformat, GLsizei width, GLint border,
						GLenum format, GLenum type, const GLvoid* pixels);
	void (*tex_image2D)(GLIContext ctx, GLenum target, GLint level,
						GLint internalformat, GLsizei width, GLsizei height,
						GLint border, GLenum format, GLenum type,
						const GLvoid* pixels);
	void (*tex_parameterf)(GLIContext ctx, GLenum target, GLenum pname,
						   GLfloat param);
	void (*tex_parameterfv)(GLIContext ctx, GLenum target, GLenum pname,
							const GLfloat* params);
	void (*tex_parameteri)(GLIContext ctx, GLenum target, GLenum pname,
						   GLint param);
	void (*tex_parameteriv)(GLIContext ctx, GLenum target, GLenum pname,
							const GLint* params);
	void (*tex_sub_image1D)(GLIContext ctx, GLenum target, GLint level,
							GLint xoffset, GLsizei width, GLenum format,
							GLenum type, const GLvoid* pixels);
	void (*tex_sub_image2D)(GLIContext ctx, GLenum target, GLint level,
							GLint xoffset, GLint yoffset, GLsizei width,
							GLsizei height, GLenum format, GLenum type,
							const GLvoid* pixels);
	void (*translated)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z);
	void (*translatef)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z);
	void (*vertex2d)(GLIContext ctx, GLdouble x, GLdouble y);
	void (*vertex2dv)(GLIContext ctx, const GLdouble* v);
	void (*vertex2f)(GLIContext ctx, GLfloat x, GLfloat y);
	void (*vertex2fv)(GLIContext ctx, const GLfloat* v);
	void (*vertex2i)(GLIContext ctx, GLint x, GLint y);
	void (*vertex2iv)(GLIContext ctx, const GLint* v);
	void (*vertex2s)(GLIContext ctx, GLshort x, GLshort y);
	void (*vertex2sv)(GLIContext ctx, const GLshort* v);
	void (*vertex3d)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z);
	void (*vertex3dv)(GLIContext ctx, const GLdouble* v);
	void (*vertex3f)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z);
	void (*vertex3fv)(GLIContext ctx, const GLfloat* v);
	void (*vertex3i)(GLIContext ctx, GLint x, GLint y, GLint z);
	void (*vertex3iv)(GLIContext ctx, const GLint* v);
	void (*vertex3s)(GLIContext ctx, GLshort x, GLshort y, GLshort z);
	void (*vertex3sv)(GLIContext ctx, const GLshort* v);
	void (*vertex4d)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z,
					 GLdouble w);
	void (*vertex4dv)(GLIContext ctx, const GLdouble* v);
	void (*vertex4f)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z,
					 GLfloat w);
	void (*vertex4fv)(GLIContext ctx, const GLfloat* v);
	void (*vertex4i)(GLIContext ctx, GLint x, GLint y, GLint z, GLint w);
	void (*vertex4iv)(GLIContext ctx, const GLint* v);
	void (*vertex4s)(GLIContext ctx, GLshort x, GLshort y, GLshort z,
					 GLshort w);
	void (*vertex4sv)(GLIContext ctx, const GLshort* v);
	void (*vertex_pointer)(GLIContext ctx, GLint size, GLenum type,
						   GLsizei stride, const GLvoid* pointer);
	void (*viewport)(GLIContext ctx, GLint x, GLint y, GLsizei width,
					 GLsizei height);
} GLIFunctionDispatch;

#ifdef __cplusplus
}
#endif

#endif /* _GLIDISPATCH_H */
