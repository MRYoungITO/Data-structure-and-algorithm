#include <Windows.h> 
#include <stdlib.h> 
#include <iostream> 
#include "nginx_queue.h" 
#include <time.h> 

using namespace std;

typedef struct ngx_cached_open_file_s {
	//其它属性省略... 
	int fd;
	ngx_queue_t queue;
}ngx_cached_file_t;	//相当于定义队列中的节点

typedef struct {
	//其它属性省略... 
	ngx_queue_t expire_queue;	//队列的队首, 成为"过期的队列"  (相当于头节点)
	//其它属性省略... 
}ngx_open_file_cache_t;	//所有已打开的缓存文件

int main(void) {
	ngx_open_file_cache_t* cache = new ngx_open_file_cache_t; //定义一个队列(缓存文件cache)
	ngx_queue_t* q;	//可以理解为队列中的的节点 q

	ngx_queue_init(&cache->expire_queue);

	//1. 模拟文件模块，增加打开的文件到缓存中 
	for (int i = 0; i < 10; i++) {
		ngx_cached_file_t* e = new ngx_cached_file_t;
		e->fd = i;
		ngx_queue_insert_head(&cache->expire_queue, &e->queue);
	}

	//遍历队列 
	for (q = cache->expire_queue.next; q != ngx_queue_sentinel(&cache->expire_queue); q = q->next) {
		printf("队列中的元素：%d\n", (ngx_queue_data(q, ngx_cached_file_t, queue))->fd);
	}

	//模拟缓存的文件到期，执行出列操作 
	while (!ngx_queue_empty(&cache->expire_queue)) {
		q = ngx_queue_last(&cache->expire_queue);
		ngx_cached_file_t* cached_file = ngx_queue_data(q, ngx_cached_file_t, queue);
		printf("出队列中的元素：%d\n", cached_file->fd);
		ngx_queue_remove(q);
		delete(cached_file);
	}

	system("pause");
	return 0;
}