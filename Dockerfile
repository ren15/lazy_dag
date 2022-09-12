FROM ubuntu:22.04
COPY ci/pkg_install.sh /build/pkg_install.sh
RUN bash /build/pkg_install.sh
