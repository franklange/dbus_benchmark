project(common)

add_library(${PROJECT_NAME} "")

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_sources(${PROJECT_NAME} PRIVATE
    include/common/DBusConfig.h
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)