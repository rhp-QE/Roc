#ifndef _ROC_TYPES_H_
#define _ROC_TYPES_H_

#include <cstddef>
#include <cstring>

namespace roc {

inline void memZero(void *ptr, std::size_t size) {
    std::memset(ptr, 0, size);
}

}

#endif // _ROC_TYPES_H_