add_executable (bmc BMC.cpp)
target_link_libraries (bmc ${Z3_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${GMPXX_LIB} ${GMP_LIB})
llvm_config (bmc bitwriter)
install(TARGETS bmc RUNTIME DESTINATION bin)

add_executable (itp BMCItp.cpp)
target_link_libraries (itp ${Z3_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${GMPXX_LIB} ${GMP_LIB})
llvm_config (itp bitwriter)
install(TARGETS itp RUNTIME DESTINATION bin)

add_executable (equiv Equiv.cpp)
target_link_libraries (equiv ${Z3_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${GMPXX_LIB} ${GMP_LIB})
llvm_config (equiv bitwriter)
install(TARGETS equiv RUNTIME DESTINATION bin)

add_executable (houdini Houdini.cpp)
target_link_libraries (houdini ${Z3_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${GMPXX_LIB} ${GMP_LIB})
llvm_config (houdini bitwriter)
install(TARGETS houdini RUNTIME DESTINATION bin)
