file(GLOB_RECURSE SOURCE_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB_RECURSE SOURCE_CPPS    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_HEADERS} ${SOURCE_CPPS})

# Expose file lists to the parent scope so source_group can be called
# from the same directory scope as the target (avoids VS filter issues)
set(SOURCE_HEADERS_CLIENT ${SOURCE_HEADERS} PARENT_SCOPE)
set(SOURCE_CPPS_CLIENT    ${SOURCE_CPPS}    PARENT_SCOPE)
