#pragma once

#include <stdexcept>
#include <string>

#define NEVER_INLINE  __attribute__((noinline))
#define ALWAYS_INLINE __attribute__((always_inline))
#define UNUSED __attribute__((unused))

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

#define MICROSCOPES_DCHECK(expr, msg) \
  do { \
    if (unlikely(!(expr))) \
      throw ::std::runtime_error(msg); \
  } while (0)


#define _STRINGIFY(x) #x

/**
 * __LINE__ comes from the preprocessor as an int.
 * Stringify hack comes from:
 * http://www.decompile.com/cpp/faq/file_and_line_error_string.htm
 */
#define _LINEHACK(x) _STRINGIFY(x)

#define _SOURCE_INFO \
  (::std::string(__PRETTY_FUNCTION__) + \
   ::std::string(" (" __FILE__ ":" _LINEHACK(__LINE__) ")"))

#define MICROSCOPES_NOT_REACHABLE() \
  do { \
    throw ::std::runtime_error( \
      ::std::string("Should not be reached: ") + \
      ::std::string(_SOURCE_INFO)); \
  } while (0)
