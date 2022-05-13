FROM ubuntu:20.04
COPY ci/pkg_install.sh /build/pkg_install.sh
ENV CI=${CI}
ARG USER UID_i GID_i CI_i
RUN bash /build/pkg_install.sh
# RUN mkdir -p /home/$USER/.conan/ && chown -R $UID_i:$GID_i /home/$USER && echo "User $USER with UID $UID_i and GID $GID_i"
