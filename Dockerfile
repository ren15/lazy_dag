FROM ubuntu:20.04
ARG USER UID_i GID_i GITHUB_ACTIONS
COPY ci/pkg_install.sh /build/pkg_install.sh
RUN bash /build/pkg_install.sh
