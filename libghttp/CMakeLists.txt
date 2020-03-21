cmake_minimum_required(VERSION 3.8)

# aux_source_directory(. DIR_GHTTP_SCRS)
# add_library(logger ${DIR_GHTTP_SCRS})
set(GHTTP_SCRS
	ghttp.c
	http_base64.c
	http_date.c
	http_hdrs.c
	http_req.c
	http_resp.c
	http_trans.c
	http_uri.c
)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(ghttp ${GHTTP_SCRS})