FROM ubuntu:20.04
COPY ci/pkg_install.sh /build/pkg_install.sh
RUN bash /build/pkg_install.sh
