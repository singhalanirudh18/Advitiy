# RTOS Implementation
In this RTOS implementation of mine I have basically three parts osHeader.h, os.c and main.c . To get a basic idea of RTOS you can go [here](https://www.youtube.com/watch?v=_VtuJhivJUw). A breif explaination of these is as follows :-
1. **osHeader.h** :- In this I have created a basic structure of task and os.
2. **os.c** :- In this I have defined all the functions related to RTOS.
3. **main.c** :- In this I have created a basic implementation with two tasks whose task is to blink led. 

## osHeader.h
In this first of all I have made a tasktable which stores various tasks their priorties, ready bit and task id. Here is the code for that :-
```C
struct TaskTable
{
	void (*ptrTask) (void);//address
	int Priority; //pr
	int Ready;//rdy
	int TaskId;//id
}arrTaskTable[3];
```
I have initialized the arrTaskTable to store at most three tasks.
</br>
After this I have initialized various variables which keep count of various things such as Number of tasks, Taskid of the current task and index of the current task in arrTaskTable :-
```C
int iTaskcount;
int iHighPriorityTask;
int iIndexPriority;
```

After Initializing all the required variables I have initialized all the appropiate functions that will be required by os.c and main.c :-
```C
void startOS(void);
void Sched(void);
void createTask(void (*ptrTask)(void), int iPriority, int iTaskId );
void startTask(int iTaskId);
void waitTask();

void Task1(void);
void Task2(void);
```

## os.c
In this I have defined various functions which are required to implement RTOS. these are :-
1. **Scheduler** :- Arguabally the most important function in os.c. This function basically keep tracks of the function with highest priorty which is ready than calls it. Code for this is as follows :-
```C
void Sched()
{
	 int iIndex;

	 //Select task with high priority

	 iHighPriorityTask = 10;

	 for (iIndex = 0; iIndex < iTaskcount ; iIndex++)
	 {
		 if ((arrTaskTable[iIndex].Priority <= iHighPriorityTask) &&
				 (arrTaskTable[iIndex].Ready ==1 ))
		 {
			 iHighPriorityTask = arrTaskTable[iIndex].Priority;
			 iIndexPriority = iIndex;
		 }
	 }

	 //call task with high priority
	 (*arrTaskTable[iIndexPriority].ptrTask)();

 }
 ```
 2. **startOS** :- This functions only calls the scheduler for the first time.
 ```C
 void startOS()
{
	//Call Sched
	Sched();
}
```
3. **createTask** :- This function tasks takes a function, priorty and taskid as input. After this it adds this task to the arrTaskTable and assign the task prioarty and taskid taken as arguments and also increments taskcount. Code is as follows :-
```C
void createTask(void (*ptrTask)(void), int iPriority, int iTaskId )
 {
	 //Save priotiy
	 arrTaskTable[iTaskcount].Priority = iPriority;

	 //Save task address
	 arrTaskTable[iTaskcount].ptrTask = ptrTask;

	 //Save task ID
	 arrTaskTable[iTaskcount].TaskId = iTaskId;

	 //Make the task ready
	 arrTaskTable[iTaskcount].Ready = 1;

	 //Increment iTaskcount
	 iTaskcount ++;

 }
```
4. **waitTask** :- This function basically sets the ready bit of the current function to 0 and then calls the scheduler.
```C
void waitTask()
 {
	 arrTaskTable[iIndexPriority].Ready = 0;

	 //Call Sched
	 Sched();

 }
```
5. **startTask** :- This function basically sets the ready bit of the task corresponding to the taskid provided to 1 and then calls the scheduler.
```C
 void startTask(int TaskId)
 {
	int iIndex;

	for (iIndex = 0; iIndex <iTaskcount; iIndex ++ )
	{
		if (TaskId == arrTaskTable[iIndex].TaskId)
		{
			arrTaskTable[iIndex].Ready = 1;
		}
	}

	 //Call Sched
	 Sched();
 }
 ```

 ## main.c
 In this part I have created two tasks which blink a led. In int main(void) I have initailized the pins , created two tasks assigned them priorty and taskid and called startOS. Code is as follows :-
 ```C
 int main(void)
{
	DDRC = 0xFF; //Makes PORTC as Output
	DDRA = 0xFF;
	DDRB = 0xFF;
	PORTC = 0xFF; 
	createTask(Task1, 1, TaskId_1);
	createTask(Task2, 2, TaskId_2);
	startOS();
	return 0;
}
```
The Task1 is fairly simple in this I blink led once then put this task on wait. And as a result when scheduler is called as Task1 is not ready Task2 is called in this also I blink led once and then call startTask(TaskID_1) which further calls Task1. So end result is that I am alternating between Task1 and Task2. Code is as follows :-
```C
void Task1()
{

	while(1)
	{
		PORTA = 0xFF; //Turns ON All LEDs
		_delay_ms(1000); //1 second delay
		PORTA= 0x00; //Turns OFF All LEDs
		_delay_ms(1000); //1 second delay
		//Stop the task
	
		waitTask();

	}

}

void Task2()
{
	while(1)
	{
		PORTB = 0xFF; //Turns ON All LEDs
		_delay_ms(1000); //1 second delay
		PORTB= 0x00; //Turns OFF All LEDs
		_delay_ms(1000); //1 second delay
		//start the task
		startTask(TaskId_1);
	}
}
```