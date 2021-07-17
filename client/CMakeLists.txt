project(client)

add_executable(${PROJECT_NAME} "")

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_sources(${PROJECT_NAME} PRIVATE
    Client.h Client.cpp
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    common
    sdbus-c++
    nlohmann_json
)