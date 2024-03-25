set(THIRD_DIR 3rd)
set(CLIST_DIR ${THIRD_DIR}/clist/src)

set(THIRD_CLIST_HDRS
    ${CLIST_DIR}
    ${CLIST_DIR}/list.h
)

include_directories(
    ${THIRD_DIR}
    ${CLIST_DIR}
)

set(LIBTINYGUI_THIRD_CLIST_SRCS
    ${CLIST_DIR}/list.c
    ${CLIST_DIR}/list_iterator.c
    ${CLIST_DIR}/list_node.c
)

set(LIBTINYGUI_THIRD_SRCS
    ${LIBTINYGUI_THIRD_CLIST_SRCS}
)
