# setup main project
cd ${REPO_DIR}
cmake -E make_directory ${BUILD_DIR}

conan install ${SOURCE_DIR} --build=missing -if=${BUILD_DIR} 

cmake -S ${SOURCE_DIR} -B ${BUILD_DIR} \
	-DCMAKE_CXX_COMPILER=g++ \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_DIR} \
	-G Ninja

ln -f -s ${BUILD_DIR}/compile_commands.json \
	${SOURCE_DIR}/compile_commands.json