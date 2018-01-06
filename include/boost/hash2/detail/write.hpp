#ifndef BOOST_HASH2_DETAIL_WRITE_HPP_INCLUDED
#define BOOST_HASH2_DETAIL_WRITE_HPP_INCLUDED

// Copyright 2017, 2018 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.

#include <boost/hash2/byte_type.hpp>
#include <boost/cstdint.hpp>
#include <boost/config.hpp>
#include <cstring>

namespace boost
{
namespace hash2
{
namespace detail
{

BOOST_FORCEINLINE void write32le( byte_type * p, boost::uint32_t v )
{
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386) || defined(_M_IX86)

    std::memcpy( p, &v, sizeof(v) );

#else

    p[0] = static_cast<byte_type>( v & 0xFF );
    p[1] = static_cast<byte_type>( ( v >>  8 ) & 0xFF );
    p[2] = static_cast<byte_type>( ( v >> 16 ) & 0xFF );
    p[3] = static_cast<byte_type>( ( v >> 24 ) & 0xFF );

#endif
}

BOOST_FORCEINLINE void write64le( byte_type * p, boost::uint64_t v )
{
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386) || defined(_M_IX86)

    std::memcpy( p, &v, sizeof(v) );

#else

    p[0] = static_cast<byte_type>( v & 0xFF );
    p[1] = static_cast<byte_type>( ( v >>  8 ) & 0xFF );
    p[2] = static_cast<byte_type>( ( v >> 16 ) & 0xFF );
    p[3] = static_cast<byte_type>( ( v >> 24 ) & 0xFF );
    p[4] = static_cast<byte_type>( ( v >> 32 ) & 0xFF );
    p[5] = static_cast<byte_type>( ( v >> 40 ) & 0xFF );
    p[6] = static_cast<byte_type>( ( v >> 48 ) & 0xFF );
    p[7] = static_cast<byte_type>( ( v >> 56 ) & 0xFF );

#endif
}

BOOST_FORCEINLINE void write32be( byte_type * p, boost::uint32_t v )
{
    p[0] = static_cast<byte_type>( ( v >> 24 ) & 0xFF );
    p[1] = static_cast<byte_type>( ( v >> 16 ) & 0xFF );
    p[2] = static_cast<byte_type>( ( v >>  8 ) & 0xFF );
    p[3] = static_cast<byte_type>( v & 0xFF );
}

BOOST_FORCEINLINE void write64be( byte_type * p, boost::uint64_t v )
{
    p[0] = static_cast<byte_type>( ( v >> 56 ) & 0xFF );
    p[1] = static_cast<byte_type>( ( v >> 48 ) & 0xFF );
    p[2] = static_cast<byte_type>( ( v >> 40 ) & 0xFF );
    p[3] = static_cast<byte_type>( ( v >> 32 ) & 0xFF );
    p[4] = static_cast<byte_type>( ( v >> 24 ) & 0xFF );
    p[5] = static_cast<byte_type>( ( v >> 16 ) & 0xFF );
    p[6] = static_cast<byte_type>( ( v >>  8 ) & 0xFF );
    p[7] = static_cast<byte_type>( v & 0xFF );
}

} // namespace detail
} // namespace hash2
} // namespace boost

#endif // #ifndef BOOST_HASH2_DETAIL_WRITE_HPP_INCLUDED
