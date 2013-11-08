
set(PROVIDER_NAME NFSShare)
set(LIBRARY_NAME cmpi${PROVIDER_NAME})
set(MOF nfs.mof)

set(provider_SRCS
     export.c
     export.h
    )
konkretcmpi_generate(${MOF}
                     CIM_PROVIDERS
                     CIM_HEADERS
 		     CIM_CLASSES
)

add_library(${LIBRARY_NAME} SHARED
            ${tutorial_SRCS}
            ${CIM_PROVIDERS}
            ${CIM_HEADERS}
            )

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMPI_INCLUDE_DIR}
    ${KONKRETCMPI_INCLUDE_DIR}
)
#add_library (export.h)
#add_library (export.c)
target_link_libraries(${LIBRARY_NAME} ${KONKRETCMPI_LIBRARIES})

# Create registration file
cim_registration(${PROVIDER_NAME} ${LIBRARY_NAME} ${MOF} "")

install(TARGETS ${LIBRARY_NAME} DESTINATION /usr/lib${LIB_SUFFIX}/cmpi/)
