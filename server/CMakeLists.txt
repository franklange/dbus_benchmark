project(server)

add_executable(${PROJECT_NAME} "")

target_sources(${PROJECT_NAME} PRIVATE
    Server.h Server.cpp
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    sdbus-c++
    pthread
)
