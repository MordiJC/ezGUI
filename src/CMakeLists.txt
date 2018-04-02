

add_library(ezGUI STATIC
    util/linked_list.c
    context.c
)

target_include_directories(ezGUI
    PUBLIC
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(ezGUI
    PUBLIC
        c_std_99
        c_function_prototypes
        c_restrict
)