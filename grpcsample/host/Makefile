# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

# Detect C and C++ compiler options
# if not gcc and g++, default to clang-7
C_COMPILER=$(notdir $(CC))
ifeq ($(C_COMPILER), gcc)
        CXX_COMPILER=$(notdir $(CXX))
        USE_GCC = true
endif

ifeq ($(USE_GCC),)
        CC = clang-7
        CXX = clang++-7
        C_COMPILER=clang
        CXX_COMPILER=clang++
endif

CFLAGS=$(shell pkg-config oehost-$(C_COMPILER) --cflags)
CXXFLAGS=$(shell pkg-config oehost-$(CXX_COMPILER) --cflags)
LDFLAGS=$(shell pkg-config oehost-$(CXX_COMPILER) --libs)

all: build

build:
	@ echo "Compilers used: $(CC), $(CXX)"
	oeedger8r  --search-path ../ ../helloworld.edl --untrusted
	$(CXX) -c  -g $(CXXFLAGS) -I../../openenclave/include -std=c++11 host.cpp hostthreads.cpp pthread_host.c eventfd_host.c socket_host.c inet_host.c netdb_host.c epoll_host.c fcntl_host.c
	$(CC) -c -g $(CFLAGS) helloworld_u.c
	$(CXX) -o helloworldhost hostthreads.o host.o pthread_host.o eventfd_host.o socket_host.o inet_host.o netdb_host.o epoll_host.o fcntl_host.o  helloworld_u.o $(LDFLAGS) -Wl,--no-undefined -L/usr/local/lib -pthread -g

clean:
	rm -f file-encryptorhost fileencryptor_u.* fileencryptor_args.h *.o ../out.decrypted ../out.encrypted

