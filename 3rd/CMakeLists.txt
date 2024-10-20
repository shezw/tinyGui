set(THIRD_DIR 3rd)
set(CLIST_DIR ${THIRD_DIR}/clist/src)

set(THIRD_CLIST_HDRS
    ${CLIST_DIR}
    ${CLIST_DIR}/clist.h
)

include_directories(
    ${THIRD_DIR}
    ${CLIST_DIR}
)

set(LIBTINYGUI_THIRD_CLIST_SRCS
    ${CLIST_DIR}/clist.c
    ${CLIST_DIR}/clist_iterator.c
    ${CLIST_DIR}/clist_node.c
)

set(LIBTINYGUI_THIRD_SRCS
    ${LIBTINYGUI_THIRD_CLIST_SRCS}
)
