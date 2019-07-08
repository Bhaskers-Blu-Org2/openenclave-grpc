#!/usr/bin/env bash

# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

##==============================================================================
#function trap_handler()
#{
#    echo "ERROR LINE# ${1} : ${2}"
#    exit "${1}"
#}

#trap 'trap_handler ${LINENO} $?' ERR
echo "1"
cd openenclave
git am ../0001-openenclaeve-for-grpc.patch

echo "2"
cd ../grpc
git am ../0001-Get-GRPC-to-build.patch

echo "3"
cd third_party/zlib
git am ../../../0001-zlib-CMakeLists.txt.patch

echo "4"
cd ../protobuf
git am ../../../0001-Add-ability-to-build-libprotobuf_oe_enclave.patch

echo "5"
cd ../boringssl
git am ../../../0001-Change-boringssl-s-cmake-lib-to-crypto2-since-crypto.patch

