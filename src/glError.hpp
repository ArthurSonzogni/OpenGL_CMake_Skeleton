/**
 * glError.hpp
 * Contributors:
 *      * Arthur Sonzogni (author)
 * Licence:
 *      * MIT
 */

#ifndef OPENGL_CMAKE_SKELETON_GLERROR_HPP
#define OPENGL_CMAKE_SKELETON_GLERROR_HPP

// Ask Opengl for errors:
// Result is printed on the standard output
// usage :
//      glCheckError(__FILE__,__LINE__);
void glCheckError(const char* file, unsigned int line);

#endif  // OPENGL_CMAKE_SKELETON_GLERROR_HPP
