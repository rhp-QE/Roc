#include "net/SocketOperation.h"

#include <glog/logging.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <unistd.h>
#include <type_traits>

#include "base/utility/types.h"

namespace roc {
namespace net {
namespace socket {

using namespace::google;

int connect(SOCKET sockfd, const struct sockaddr* addr) {
    return ::connect(sockfd, addr, static_cast<socklen_t>(sizeof(struct sockaddr_in6)));
}

void bindOrDie(SOCKET sockfd, const struct sockaddr* addr) {

}

void listenOrDie(SOCKET sockfd) {

}

int accept(SOCKET sockfd, struct sockaddr_in6* addr) {
    socklen_t addrlen = static_cast<socklen_t>(sizeof *addr);
    SOCKET confd = ::accept4(sockfd, sockaddr_cast(addr), &addrlen, SOCK_NONBLOCK | SOCK_CLOEXEC);
}

ssize_t read(SOCKET sockfd, void *buf, size_t count) {
    return ::read(sockfd, buf, count);
}

ssize_t readv(SOCKET sockfd, const struct iovec *iov, int iovcnt) {
    return ::readv(sockfd, iov, iovcnt);
}

ssize_t write(SOCKET sockfd, const void *buf, size_t count) {
    return ::write(sockfd, buf, count);
}

void close(SOCKET sockfd) {
    ::close(sockfd);
}

void shutdownWrite(SOCKET sockfd) {
    if (::shutdown(sockfd, SHUT_WR) < 0) {
        LOG(INFO)<<"[socket]:"<<"shoutDownWrite"<<std::endl;
    }
}

std::string_view toIpPort(const struct sockaddr* addr) {

}

std::string_view toIp(const struct sockaddr* addr) {

}

void fromIpPort(std::string_view ip, uint16_t port, struct sockaddr_in* addr) {

}

void fromIpPort(std::string_view ip, uint16_t port,
                struct sockaddr_in6* addr) {
}

int getSocketError(SOCKET sockfd) {

}

const struct sockaddr* sockaddr_cast(const struct sockaddr_in6* addr)
{
  return static_cast<const struct sockaddr*>(static_cast<const void*>(addr));
}

struct sockaddr* sockaddr_cast(struct sockaddr_in6* addr)
{
  return static_cast<struct sockaddr*>(static_cast<void*>(addr));
}

const struct sockaddr* sockaddr_cast(const struct sockaddr_in* addr)
{
  return static_cast<const struct sockaddr*>(static_cast<const void*>(addr));
}

const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr* addr)
{
  return static_cast<const struct sockaddr_in*>(static_cast<const void*>(addr));
}

const struct sockaddr_in6* sockaddr_in6_cast(const struct sockaddr* addr)
{
  return static_cast<const struct sockaddr_in6*>(static_cast<const void*>(addr));
}

struct sockaddr_in6 getLocalAddr(SOCKET sockfd) {

}

struct sockaddr_in6 getPeerAddr(SOCKET sockfd) {
    struct sockaddr_in6 peeraddr;
    memZero(&peeraddr, sizeof peeraddr);
    socklen_t addrlen = static_cast<socklen_t>(sizeof peeraddr);
    if (::getpeername(sockfd, sockaddr_cast(&peeraddr), &addrlen) < 0)
    {
        LOG(INFO)<<"[socket]:"<<"getPeerAddr"<<std::endl;
    }
    return peeraddr;
}

bool isSelfConnect(SOCKET sockfd) {

}

} // namespace socket
} // namespace net
} // namespace roc