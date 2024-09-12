#ifndef _ROC_SOCKETOPERATION_H_
#define _ROC_SOCKETOPERATION_H_

#include <cstdint>
#include <string_view>
#include <sys/types.h>
#include <netinet/in.h>


namespace roc {
namespace net {
namespace socket {

// define socket fd
#ifdef __linux__
using SOCKET = int;
#endif

int  connect(SOCKET sockfd, const struct sockaddr* addr);
void bindOrDie(SOCKET sockfd, const struct sockaddr* addr);
void listenOrDie(SOCKET sockfd);
int  accept(SOCKET sockfd, struct sockaddr_in6* addr);
ssize_t read(SOCKET sockfd, void *buf, size_t count);
ssize_t readv(SOCKET sockfd, const struct iovec *iov, int iovcnt);
ssize_t write(SOCKET sockfd, const void *buf, size_t count);
void close(SOCKET sockfd);
void shutdownWrite(SOCKET sockfd);

std::string_view toIpPort(const struct sockaddr* addr);
std::string_view toIp(const struct sockaddr* addr);

void fromIpPort(std::string_view ip, uint16_t port,
                struct sockaddr_in* addr);
void fromIpPort(std::string_view ip, uint16_t port,
                struct sockaddr_in6* addr);

int getSocketError(SOCKET sockfd);

const struct sockaddr* sockaddr_cast(const struct sockaddr_in* addr);
const struct sockaddr* sockaddr_cast(const struct sockaddr_in6* addr);
struct sockaddr* sockaddr_cast(struct sockaddr_in6* addr);
const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr* addr);
const struct sockaddr_in6* sockaddr_in6_cast(const struct sockaddr* addr);

struct sockaddr_in6 getLocalAddr(SOCKET sockfd);
struct sockaddr_in6 getPeerAddr(SOCKET sockfd);
bool isSelfConnect(SOCKET sockfd);

} // namespace socket
} // namespace net
} // namespace roc

#endif // _ROC_SOCKETOPERATION_H_