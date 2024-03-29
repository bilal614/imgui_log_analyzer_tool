
add_library(${LOG_SCP_WRAPPER_LIB}
    ${LOG_SCP_WRAPPER_DIR}/src/AuthenticationWorkFlow.cxx
    ${LOG_SCP_WRAPPER_DIR}/src/PtyMaster.cxx
    ${LOG_SCP_WRAPPER_DIR}/src/ScpExecutor.cxx
)

target_include_directories(${LOG_SCP_WRAPPER_LIB} PUBLIC 
    ${LOG_SCP_WRAPPER_INCLUDE_DIR}
    ${LOG_EVENT_HANDLING_LIB}
)

target_link_libraries(${LOG_SCP_WRAPPER_LIB} 
    ${LOG_EVENT_HANDLING_LIB}
)