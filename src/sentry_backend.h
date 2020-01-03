#ifndef SENTRY_BACKEND_H_INCLUDED
#define SENTRY_BACKEND_H_INCLUDED

#include "sentry_scope.h"
#include <sentry.h>

struct sentry_backend_s;
typedef struct sentry_backend_s {
    void (*startup_func)(struct sentry_backend_s *);
    void (*shutdown_func)(struct sentry_backend_s *);
    void (*free_func)(struct sentry_backend_s *);
    void (*flush_scope_func)(
        struct sentry_backend_s *, const sentry_scope_t *scope);
    void (*add_breadcrumb_func)(
        struct sentry_backend_s *, sentry_value_t breadcrumb);
    void (*user_consent_changed_func)(struct sentry_backend_s *);
    void *data;
} sentry_backend_t;

void sentry__backend_free(sentry_backend_t *backend);

#endif