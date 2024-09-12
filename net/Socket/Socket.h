#ifndef _ROC_SOCKET_H_
#define _ROC_SOCKET_H_

#include "base/noncopyable.h"
#include "net/Socket/InetAddress.h"
namespace roc {
namespace net {

class InetAddress;
class Socket : public noncopyable {
public:
    explicit Socket(InetAddress address);

    


private:
    int fd_();
};

}
}

#endif // _ROC_SOCKET_H_