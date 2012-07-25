/**************************************************************************
 *
 * Copyright 2011 Jose Fonseca
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 **************************************************************************/

#ifndef _GLRETRACE_HPP_
#define _GLRETRACE_HPP_

#include "glws.hpp"
#include "retrace.hpp"


namespace glretrace {


extern bool insideList;
extern bool insideGlBeginEnd;


extern glws::Drawable *currentDrawable;
extern glws::Context *currentContext;

glws::Drawable *
createDrawable(glws::Profile profile);

glws::Drawable *
createDrawable(void);

glws::Context *
createContext(glws::Context *shareContext, glws::Profile profile);

glws::Context *
createContext(glws::Context *shareContext = 0);

bool
makeCurrent(trace::Call &call, glws::Drawable *drawable, glws::Context *context);


void
checkGlError(trace::Call &call);

extern const retrace::Entry gl_callbacks[];
extern const retrace::Entry cgl_callbacks[];
extern const retrace::Entry glx_callbacks[];
extern const retrace::Entry wgl_callbacks[];
extern const retrace::Entry egl_callbacks[];

void frame_start();
void frame_complete(trace::Call &call);

void updateDrawable(int width, int height);

void flushQueries();
void beginProfile(trace::Call &call);
void endProfile(trace::Call &call);

void setActiveProgram(GLuint program);
} /* namespace glretrace */

GLuint retrace_unmap_program(GLuint val);

#endif /* _GLRETRACE_HPP_ */
