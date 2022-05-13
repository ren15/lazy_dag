FROM ubuntu:20.04
COPY ci/pkg_install.sh /build/pkg_install.sh
ENV CI=${CI}
RUN bash /build/pkg_install.sh
ARG USER UID_i GID_i CI_i
# RUN mkdir -p /home/$USER/.conan/ && chown -R $UID_i:$GID_i /home/$USER && echo "User $USER with UID $UID_i and GID $GID_i"
