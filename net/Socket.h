#ifndef _ROC_SOCKET_H_
#define _ROC_SOCKET_H_


#include "base/noncopyable.h"


namespace roc {
namespace socket {

#ifdef __linux__
using SOCKET = int;
#endif


class Socket : public noncopyable {
public:
    Socket(SOCKET sockfd)
        :sockfd_(sockfd)
    {}

    ~Socket() {

    }

    SOCKET fd() {
        return sockfd_;
    }

private:
    SOCKET sockfd_;
};

} // namespace sokcet
} //  namespace roc

#endif // _ROC_SOCKET_H_