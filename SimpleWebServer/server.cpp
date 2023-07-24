#include <microhttpd.h>
#include <cstring>
#include <cstdio>

int request_handler(void *cls, struct MHD_Connection *connection,
                    const char *url, const char *method,
                    const char *version, const char *upload_data,
                    size_t *upload_data_size, void **con_cls) {
    const char *page = "<html><body><h1>Hello, World!</h1></body></html>";
    struct MHD_Response *response;
    int ret;
    response = MHD_create_response_from_buffer(strlen(page), (void*)page, MHD_RESPMEM_PERSISTENT);
    if (!response)
        return MHD_NO;
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int main() {
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, 8080, nullptr, nullptr,
                              &request_handler, nullptr, MHD_OPTION_END);
    if (!daemon)
        return 1;
    getchar(); 
    MHD_stop_daemon(daemon);

    return 0;
}