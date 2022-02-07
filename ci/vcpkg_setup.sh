git clone https://github.com/Microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh

~/vcpkg/vcpkg install \
    folly \
    fmt \
    range-v3 \
    benchmark \
    gtest \
    boost
