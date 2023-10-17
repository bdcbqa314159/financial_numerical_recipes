set(LIBRARY_SOURCES
    credit1.cpp
)

set(LIBRARY_HEADERS
    credit1.hpp
)

set(LIBRARY_INCLUDES
    "./"
)

add_library(${LIBRARY_CREDIT} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})

target_include_directories(${LIBRARY_CREDIT} PUBLIC
    ${LIBRARY_INCLUDES})

target_link_libraries(${LIBRARY_CREDIT} PUBLIC
                        ${LIBRARY_RANDOM})
