/*
				File:		aglContext.h

				Version:	1.0

				Copyright:	� 1999 by Apple Computer, Inc., all rights reserved.
*/

#ifndef _AGLCONTEXT_H
#define _AGLCONTEXT_H

#include "gliContext.h"
#include "gliDispatch.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
** Opaque declaration for private AGLContext data.
*/
typedef struct __AGLPrivateRec* AGLPrivate;

/*
** AGLContext structure.
*/
struct __AGLContextRec {
	GLIContext			 rend;
	GLIFunctionDispatch	 disp;
	GLIExtensionDispatch exts;
	AGLPrivate			 priv;
};

#ifdef __cplusplus
}
#endif

#endif /* _AGLCONTEXT_H */
