#include <stdio.h>

//定义状态机状态如下
typedef enum {
	sta_origin=0,
	sta_running,
	sta_owencpu,
	sta_sleep_int,
	sta_sleep_unint
}State;

//定义发生事件如下
typedef enum{
	evt_fork=0,
	evt_sched,
	evt_wait,
	evt_wait_unint,
	evt_wake_up,
	evt_wake, 
}EventID;

//当前状态转换信息
typedef struct {
	State curState;//当前状态
	EventID eventId;//事件ID
	State nextState;//下个状态
	action_callback;//回调函数，事件发生后，调用对应的回调函数
}StateTransform ; 


//回调函数定义
void action_callback(void *arg)
{
	StateTransform *statTran = (StateTransform *)arg;

	if(arg[statTran->curState] == arg[statTran->nextState])
	{
		printf("invalid event,state not change\n");
	}else{
		printf("call back state from %s --> %s\n",
		arg[statTran->curState],
		arg[statTran->nextState]);
	}
}

//各个状态迁移表数组
/*origin*/
StateTransform stateTran_0[]={
	{sta_origin,evt_fork,        sta_running,action_callback},
	{sta_origin,evt_sched,       sta_origin,NULL},
	{sta_origin,evt_wait,        sta_origin,NULL},
	{sta_origin,evt_wait_unint,  sta_origin,NULL},
	{sta_origin,evt_wake_up,     sta_origin,NULL},
	{sta_origin,evt_wake,        sta_origin,NULL},
}; 

/*running*/
StateTransform stateTran_1[]={
	{sta_running,evt_fork,        sta_running,NULL},
	{sta_running,evt_sched,       sta_owencpu,action_callback},
	{sta_running,evt_wait,        sta_running,NULL},
	{sta_running,evt_wait_unint,  sta_running,NULL},
	{sta_running,evt_wake_up,     sta_running,NULL},
	{sta_running,evt_wake,        sta_running,NULL},
}; 
/*owencpu*/
StateTransform stateTran_2[]={
	{sta_owencpu,evt_fork,        sta_owencpu,NULL},
	{sta_owencpu,evt_sched,       sta_owencpu,NULL},
	{sta_owencpu,evt_wait,        sta_sleep_int,action_callback},
	{sta_owencpu,evt_wait_unint,  sta_sleep_unint,action_callback},
	{sta_owencpu,evt_wake_up,     sta_owencpu,NULL},
	{sta_owencpu,evt_wake,        sta_owencpu,NULL},
}; 

/*sleep_int*/
StateTransform stateTran_3[]={
	{sta_sleep_int,evt_fork,        sta_sleep_int,NULL},
	{sta_sleep_int,evt_sched,       sta_sleep_int,NULL},
	{sta_sleep_int,evt_wait,        sta_sleep_int,NULL},
	{sta_sleep_int,evt_wait_unint,  sta_sleep_int,NULL},
	{sta_sleep_int,evt_wake_up,     sta_sleep_int,NULL},
	{sta_sleep_int,evt_wake,        sta_running,action_callback},
}; 
/*sleep_unint*/
StateTransform stateTran_4[]={
	{sta_sleep_unint,evt_fork,        sta_sleep_unint,NULL},
	{sta_sleep_unint,evt_sched,       sta_sleep_unint,NULL},
	{sta_sleep_unint,evt_wait,        sta_sleep_unint,NULL},
	{sta_sleep_unint,evt_wait_unint,  sta_sleep_unint,NULL},
	{sta_sleep_unint,evt_wake_up,     sta_running,action_callback},
	{sta_sleep_unint,evt_wake,        sta_sleep_unint,NULL},
}; 

#define STATETRANS(n)  (stateTran_##n)
/*change state & call callback()*/

//根据结构体变量StateTransform，实现状态迁移，并调用对应的回调函数。
void do_action(StateTransform *statTran)
{
	if(NULL == statTran)
	{
		perror("statTran is NULL\n");
		return;
	}
	//状态迁移
	globalState = statTran->nextState;
	if(statTran->action != NULL)
	{//调用回调函数
		statTran->action((void*)statTran);
	}else{
		printf("invalid event,state not change\n");
	}
}

int globalState = 0;
//根据发生的event以及当前的进程state，找到对应的StateTransform 结构体，并调用do_action()
void event_happen(unsigned int event)
{
	switch(globalState)
	{
		case sta_origin:
			do_action(&STATETRANS(0)[event]);
			break;
		case sta_running:
			do_action(&STATETRANS(1)[event]);
			break;
		case sta_owencpu:
			do_action(&STATETRANS(2)[event]); 
			break;
		case sta_sleep_int:
			do_action(&STATETRANS(3)[event]); 
			break;
		case sta_sleep_unint:
			do_action(&STATETRANS(4)[event]); 
			break;
		default:
			printf("state is invalid\n");
			break;
	}
}

/*显示当前状态*/
void *show_stat(void *arg)
{
	int len;
	char buf[64]={0};

	while(1)
	{
		sleep(1);
		printf("cur stat:%s\n",statename[globalState]);
	} 
}

init_machine(void)
{
	printf("======init machine======\n");
}

int main(void)
{
	pid_t pid;
	init_machine();
	
	//创建子线程，子线程主要用于显示当前状态
	pthread_create(&pid, NULL,show_stat, NULL);

	sleep(5);
	event_happen(evt_fork);
	sleep(5);
	event_happen(evt_sched);
	sleep(5);
	event_happen(evt_sched);
	sleep(5);
	event_happen(evt_wait);
	sleep(5);
	event_happen(evt_wake);
 
	return 0;
}













