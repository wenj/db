cmake_minimum_required(VERSION 3.8)
project(mydb)

set(CMAKE_CXX_STANDARD 11)

set(UTIL_DIR "utils")
set(PF_DIR "pf")
set(RM_DIR "rm")
set(IX_DIR "ix")
set(SMQL_DIR "smql")

set(SOURCE_FILES main.cpp
        ${UTIL_DIR}/statistics.cc
        ${PF_DIR}/pf_buffermgr.cc ${PF_DIR}/pf_error.cc ${PF_DIR}/pf_filehandle.cc ${PF_DIR}/pf_hashtable.cc
            ${PF_DIR}/pf_manager.cc ${PF_DIR}/pf_pagehandle.cc ${PF_DIR}/pf_statistics.cc
        ${RM_DIR}/rm_error.cc ${RM_DIR}/rm_filehandle.cc ${RM_DIR}/rm_filescan.cc ${RM_DIR}/rm_manager.cc
            ${RM_DIR}/rm_record.cc ${RM_DIR}/rm_rid.cc
        ${IX_DIR}/ix_indexhandle.cc ${IX_DIR}/ix_indexscan.cc ${IX_DIR}/ix_manager.cc
        ${SMQL_DIR}/sm_manager.cc
)

add_executable(mydb ${SOURCE_FILES})

include_directories(
        "${UTIL_DIR}"
        "${PF_DIR}"
        "${RM_DIR}"
        "${IX_DIR}"
        "${SMQL_DIR}"
)