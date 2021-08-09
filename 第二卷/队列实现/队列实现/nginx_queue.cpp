#include <Windows.h> 
#include <stdlib.h> 
#include <iostream> 
#include "nginx_queue.h" 
#include <time.h> 

using namespace std;

typedef struct ngx_cached_open_file_s {
	//��������ʡ��... 
	int fd;
	ngx_queue_t queue;
}ngx_cached_file_t;	//�൱�ڶ�������еĽڵ�

typedef struct {
	//��������ʡ��... 
	ngx_queue_t expire_queue;	//���еĶ���, ��Ϊ"���ڵĶ���"  (�൱��ͷ�ڵ�)
	//��������ʡ��... 
}ngx_open_file_cache_t;	//�����Ѵ򿪵Ļ����ļ�

int main(void) {
	ngx_open_file_cache_t* cache = new ngx_open_file_cache_t; //����һ������(�����ļ�cache)
	ngx_queue_t* q;	//�������Ϊ�����еĵĽڵ� q

	ngx_queue_init(&cache->expire_queue);

	//1. ģ���ļ�ģ�飬���Ӵ򿪵��ļ��������� 
	for (int i = 0; i < 10; i++) {
		ngx_cached_file_t* e = new ngx_cached_file_t;
		e->fd = i;
		ngx_queue_insert_head(&cache->expire_queue, &e->queue);
	}

	//�������� 
	for (q = cache->expire_queue.next; q != ngx_queue_sentinel(&cache->expire_queue); q = q->next) {
		printf("�����е�Ԫ�أ�%d\n", (ngx_queue_data(q, ngx_cached_file_t, queue))->fd);
	}

	//ģ�⻺����ļ����ڣ�ִ�г��в��� 
	while (!ngx_queue_empty(&cache->expire_queue)) {
		q = ngx_queue_last(&cache->expire_queue);
		ngx_cached_file_t* cached_file = ngx_queue_data(q, ngx_cached_file_t, queue);
		printf("�������е�Ԫ�أ�%d\n", cached_file->fd);
		ngx_queue_remove(q);
		delete(cached_file);
	}

	system("pause");
	return 0;
}