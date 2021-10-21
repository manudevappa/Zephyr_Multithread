/*
 * 
 * Author: Manu Devappa | manudevappsa@gmail.com
 * 
 * Implementation of MultiThread in Zephyr RTOS 
 * 
 */

#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>

/* size of stack area used by each thread */
#define STACKSIZE 1024


/* Thread 1*/
void thread1(void)
{
	while(1){
		// place any other code to run Here
		printk("1\n");
		k_msleep(100);
	}
}

/* Thread 2*/
void thread2(void)
{
	while(1){
		// place any other code to run Here
		printk("2\n");
		k_msleep(200);
	}
}

/* Thread 3*/
void thread3(void)
{
	while (1) {
		// place any other code to run Here
		printk("3\n");
		k_msleep(300);
	}
}


K_THREAD_DEFINE(blink0_id, STACKSIZE, thread1, NULL, NULL, NULL,
		1, 0, 0);
K_THREAD_DEFINE(blink1_id, STACKSIZE, thread2, NULL, NULL, NULL,
		2, 0, 0);
K_THREAD_DEFINE(uart_out_id, STACKSIZE, thread3, NULL, NULL, NULL,
		3, 0, 0);
