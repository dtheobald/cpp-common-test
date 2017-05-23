/**
 * @file resolver_utils.h.
 *
 * Copyright (C) Metaswitch Networks 2017
 * If license terms are provided to you in a COPYING file in the root directory
 * of the source code repository by which you are accessing this code, then
 * the license outlined in that COPYING file applies to your use.
 * Otherwise no rights are granted except for those provided to you by
 * Metaswitch Networks in a separate written agreement.
 */

#ifndef RESOLVER_UTILS_H__
#define RESOLVER_UTILS_H__

#include <functional>
#include <algorithm>
#include <string>

using namespace std;

namespace ResolverUtils
{
inline std::string addrinfo_to_string(const AddrInfo& ai)
{
  ostringstream oss;
  char buf[100];
  if (ai.address.af == AF_INET6)
  {
    oss << "[";
  }
  oss << inet_ntop(ai.address.af, &ai.address.addr, buf, sizeof(buf));
  if (ai.address.af == AF_INET6)
  {
    oss << "]";
  }
  oss << ":" << ai.port;
  oss << ";transport=";
  if (ai.transport == IPPROTO_SCTP)
  {
    oss << "SCTP";
  }
  else if (ai.transport == IPPROTO_TCP)
  {
    oss << "TCP";
  }
  else
  {
    oss << "Unknown (" << ai.transport << ")";
  }
  return oss.str();
}

inline DnsRRecord* a(const std::string& name,
                     int ttl,
                     const std::string& address)
{
  struct in_addr addr;
  inet_pton(AF_INET, address.c_str(), &addr);
  return (DnsRRecord*)new DnsARecord(name, ttl, addr);
}

inline DnsRRecord* aaaa(const std::string& name,
                        int ttl,
                        const std::string& address)
{
  struct in6_addr addr;
  inet_pton(AF_INET6, address.c_str(), &addr);
  return (DnsRRecord*)new DnsAAAARecord(name, ttl, addr);
}

inline DnsRRecord* srv(const std::string& name,
                       int ttl,
                       int priority,
                       int weight,
                       int port,
                       const std::string& target)
{
  return (DnsRRecord*)new DnsSrvRecord(name, ttl, priority, weight, port, target);
}

inline DnsRRecord* naptr(const std::string& name,
                         int ttl,
                         int order,
                         int preference,
                         const std::string& flags,
                         const std::string& service,
                         const std::string& regex,
                         const std::string& replacement)
{
  return (DnsRRecord*)new DnsNaptrRecord(name, ttl, order, preference, flags,
                                         service, regex, replacement);
}
}

#endif
