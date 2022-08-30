set -xe

bash ci/docker_build.sh
bash ci/docker_run_0_dep_build.sh
bash ci/docker_run_1_build.sh
bash ci/docker_run_2_run.sh
