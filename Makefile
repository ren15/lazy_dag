.PHONY: $(MAKECMDGOALS)

export REPO_DIR=${PWD}
export BUILD_DIR=${REPO_DIR}/cxx/cmake-build-debug
export SOURCE_DIR=${REPO_DIR}/cxx
export CMAKE_PREFIX_DIR=${REPO_DIR}/cmake_prefix

help:
	echo "Check Makefile"

configure:
	bash ci/setup_cmake_projects.sh

build:
	cmake --build ${BUILD_DIR} -j
	
run: 
	${BUILD_DIR}/bin/dag_range
	${BUILD_DIR}/bin/ranges_impl_1
bench:
	${BUILD_DIR}/bin/mathop_bench
	${BUILD_DIR}/bin/dag_bench
	${BUILD_DIR}/bin/ranges_impl_bench

git_clone_AAD:
	git clone https://github.com/asavine/CompFinance.git

clean:
	rm -rf ${BUILD_DIR}