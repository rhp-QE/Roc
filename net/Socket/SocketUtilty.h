#ifndef _ROC_SOCKETUTILTY_H_
#define _ROC_SOCKETUTILTY_H_

#include <sys/socket.h>

namespace roc {
namespace net {
namespace socketUtil {

int creatNonblockSocket(sa_family_t family);

}// namespace socketUtil
}// namespace net
}// namespace roc

#endif // _ROC_SOCKETUTILTY_H_