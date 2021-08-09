#ifndef _NGX_QUEUE_H_INCLUDED_ 
#define _NGX_QUEUE_H_INCLUDED_ 

typedef struct ngx_queue_s ngx_queue_t;

struct ngx_queue_s {
	ngx_queue_t* prev;
	ngx_queue_t* next;
};

#define ngx_queue_init(q)	\
	(q)->prev = q;			\
	(q)->next = q

#define ngx_queue_empty(h)	\
	(h == (h)->prev)

#define ngx_queue_insert_head(h, x)	\
	(x)->next = (h)->next;			\
	(x)->next->prev = x;			\
	(x)->prev = h;					\
	(h)->next = x

#define ngx_queue_insert_after ngx_queue_insert_head 

#define ngx_queue_insert_tail(h, x) \
	(x)->prev = (h)->prev;			\
	(x)->prev->next = x;			\
	(x)->next = h;					\
	(h)->prev = x 

#define ngx_queue_head(h) \
	(h)->next

#define ngx_queue_last(h) \
	(h)->prev

#define ngx_queue_sentinel(h) \
	(h) 

#define ngx_queue_next(q) \
	(q)->next 

#define ngx_queue_prev(q) \
	(q)->prev 

#define ngx_queue_remove(x) \
	(x)->next->prev = (x)->prev; \
	(x)->prev->next = (x)->next

#define ngx_queue_data(q, type, link) \
		(type *) ((char *) q - offsetof(type, link)) 

#endif