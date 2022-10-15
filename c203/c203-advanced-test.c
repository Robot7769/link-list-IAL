/**/
/****************************** c203-test.c ************************************
 * Předmět: Algoritmy (IAL) - FIT VUT v Brně
 * Pokročilé testy pro příklad c203.c (Fronta znaků v poli)
 * Vytvořil: Václav Topinka, září 2005
 * Upravil: Bohuslav Křena, říjen 2006
 ******************************************************************************/

#include "c203.h"

#include <stdio.h>
#include <stdlib.h>
                                             /* variables used within testing */
Queue* queue;
int QUEUE_SIZE;
int solved;
extern int error_flag;

/*******************************************************************************
 * The following functions allow us to write shorter testing code.
 * They usually call particular operation, check whether the function
 * has been implemented, and, eventualy, print a result of the function.
 ******************************************************************************/

void queuePrint ( Queue* q ) {
/* Prints a queue with the following index meaning:
 * F = Front
 * B = Back
 * E = queue is Empty (F == B)
 */
	putchar('\n');
                                                   /* Prints a queue content. */
	for ( int i=0; i<QUEUE_SIZE; i++ )
		putchar(q->array[i]);
	putchar('\n');
                                                 /* Prints a queue index(es). */
	for ( int i=0; i<QUEUE_SIZE; i++ ) {
		if ( ( i == q->firstIndex ) || ( i == q->freeIndex ) )
			putchar('^');
		else
			putchar(' ');
	}
	putchar('\n');
                                                 /* Prints index(es) meaning. */
	for ( int i=0; i<QUEUE_SIZE; i++ ) {
		if ( (i == q->firstIndex) && (i==q->freeIndex))
			putchar('E');
		else if ( i == q->firstIndex )
			putchar ('F');
		else if ( i == q->freeIndex )
			putchar ('B');
		else
			putchar (' ');
	}
	putchar('\n');
}

void use_queue_init ( Queue* q ) {
    solved = 1;
	Queue_Init( q );
	if ( ! solved )
		printf("Function Queue_Init has not been implemented.\n");
}

void use_queue_empty ( Queue* q ) {
    solved = 1;
	int i = Queue_IsEmpty( q );
	if ( ! solved )
		printf("Function Queue_IsEmpty has not been implemented.\n");
	else
		printf("Function Queue_IsEmpty returned '%s'.\n", i ? "TRUE" : "FALSE");
}

void use_queue_full ( Queue* q ) {
	solved = 1;
	int i = Queue_IsFull( q );
	if ( ! solved )
		printf("Function Queue_IsFull has not been implemented.\n");
	else
		printf("Fucntion Queue_IsFull returned '%s'.\n", i ? "TRUE" : "FALSE");
}

void use_queue_front ( Queue* q ) {
	solved = 1;
	error_flag = 0;
	char c;
	Queue_Front( q, &c );
	if ( ! solved )
		printf("Function Queue_Front has not been implemented.\n");
	else if ( !error_flag )
		printf("Function Queue_Front returned value '%c'.\n", c );
}

void use_queue_remove ( Queue* q ) {
	solved = 1;
	Queue_Remove( q );
	if ( ! solved )
		printf("Function Queue_Remove has not been implemented.\n");
}

void use_queue_get ( Queue* q ) {
	solved = 1;
	error_flag = 0;
	char c;
	Queue_Dequeue( q, &c );
	if ( ! solved )
		printf("Function Queue_Dequeue has not been implemented.\n");
	else if ( !error_flag )
		printf("Function Queue_Dequeue returned value '%c'.\n", c );
}

void use_queue_up ( Queue* q, char c ) {
    solved = 1;
    Queue_Enqueue( q, c );
    if ( ! solved )
		    printf("Function Queue_Enqueue has not been implemented.\n");
		return;
}

/*******************************************************************************
 * ADVANCED TESTS
 ******************************************************************************/

int main ( /*int argc, char* argv[] */) {

	printf ("**************************************************\n");
	printf ("* C203: Queue implemented using an array         *\n");
	printf ("* Advamced testing script (c203-advanced-test.c) *\n");
	printf ("**************************************************\n");
	printf ("* The explanation:                               *\n");
	printf ("* ~~~~~~~~~~~~~~~~                               *\n");
	printf ("* * - not used yet                               *\n");
	printf ("* F - Front                                      *\n");
	printf ("* B - Back                                       *\n");
	printf ("* E - Empty (F == B)                             *\n");
	printf ("**************************************************\n");

	QUEUE_SIZE = 9;
                                     /* We allocate the memory for the queue. */
    queue = (Queue*)malloc(sizeof(Queue));
    if ( queue == NULL ) {
    	printf ("\nc203-test.c: Error: There is not enough memory for the queue.\n");
        return 1;
    }

	printf ("\n[TEST01] queue initialization\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
    use_queue_init( queue );
	queuePrint( queue );

	printf ("\n[TEST02] We try Queue_IsEmpty and Queue_IsFull over the empty queue.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_empty( queue );
	use_queue_full( queue );

	printf ("\n[TEST03] Queue_Front, Queue_Dequeue, and Queue_Remove should cause handled errors.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_front ( queue );
	use_queue_get ( queue );
	use_queue_remove ( queue );
	queuePrint( queue );
                                     /* Test 04 is additional to basic tests. */
	printf ("\n[TEST04] We check Queue_IsEmpty and Queue_IsFull.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_empty( queue );
	use_queue_full( queue );
	
	printf ("\n[TEST05] We put 'Ciao!' into the queue using Queue_Enqueue.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, 'C' );
	use_queue_up( queue, 'i' );
	use_queue_up( queue, 'a' );
	use_queue_up( queue, 'o' );
	use_queue_up( queue, '!' );
	queuePrint( queue );

	printf ("\n[TEST06] Functions Queue_IsEmpty as well as Queue_IsFull should return FALSE now.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_empty( queue );
	use_queue_full( queue );
	
	printf ("\n[TEST07] Function Queue_Front should always return the same value.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_front( queue );
	use_queue_front( queue );
	queuePrint( queue );
	
	printf ("\n[TEST08] Let's examine the difference between Queue_Remove and Queue_Dequeue.\n" );
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_remove( queue );
	use_queue_get( queue );
	queuePrint( queue );
	
	printf ("\n[TEST09] After three Queue_Dequeue the queue should be empty.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );
                   /* Back index should be at the end of arrayay after test 10. */
	printf ("\n[TEST10] We put 1, 2, and 3 to the queue using QueueUp and check the result.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, '1' );
	use_queue_up( queue, '2' );
	use_queue_up( queue, '3' );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );
	
	printf ("\n[TEST11] After removing three elements using Queue_Dequeue, the queue should be empty.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue);

	printf ("\n[TEST12] Additional Queue_Enqueue should move to freeIndex possition 0.\n" );
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, '4' );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );

	printf ("\n[TEST13] After Queue_Dequeue, the indexes should be the same as after Queue_Init.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_get( queue );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue);

	printf ("\n[TEST14] We use Queue_Enqueue eight times to fill up the queue.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	for ( int i=0; i<8; i++ )
		use_queue_up( queue, 'A'+i );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );

	printf ("\n[TEST15] Addition Queue_Enqueue should cause hadled error.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, 'Z' );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );
                              /* The rest of test is not part of basic tests. */
	printf ("\n[TEST16] Many couples of Queue_Enqueue and Queue_Remove operations.\n" );
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	for ( char c='a'; c<='z'; c++ ) {
		use_queue_remove( queue );
		use_queue_up ( queue, c );
	}
	queuePrint( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	
	printf ("\n[TEST17] We create the queue of the size 2.\n");
	printf ("===========================================\n");
	QUEUE_SIZE = 3;
    use_queue_init( queue );
	queuePrint( queue );

	printf ("\n[TEST18] Let's test all operations which should not change empty queue.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_empty ( queue );
	use_queue_full ( queue );
	use_queue_front ( queue );                                      /* Error. */
	use_queue_get ( queue );                                        /* Error. */
	use_queue_remove ( queue );                                     /* Error. */
	queuePrint ( queue );

	printf ("\n[TEST19] Calling Queue_Enqueue three times should cause error.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up ( queue, '1' );
	use_queue_up ( queue, '2' );
	use_queue_up ( queue, '3' );
	use_queue_empty ( queue );
	use_queue_full ( queue );
	use_queue_front ( queue );
	use_queue_get ( queue );
	queuePrint ( queue );

	printf ("\n[TEST20] Calling Queue_Remove followed by Queue_Dequeue should cause error.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_remove ( queue );
	use_queue_get ( queue );
	use_queue_empty ( queue );
	use_queue_full ( queue );
	use_queue_front ( queue );
	queuePrint ( queue );

	printf ("\n[TEST21] We check the nextIndex function by two Queue_Enqueue and Queue_Dequeue.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up ( queue , '3');
	use_queue_get ( queue );
	use_queue_up ( queue , '4');
	use_queue_get ( queue );
	use_queue_empty ( queue );
	use_queue_full ( queue );
	use_queue_front ( queue );
	queuePrint ( queue );
                                                           /* Dirty trick :-) */
	printf ("\n[TEST22] And finally, we create the queue of size 0.\n");
	printf ("====================================================\n");
    QUEUE_SIZE = 1;
	Queue_Init ( queue );
	queuePrint ( queue );
	use_queue_empty ( queue );
	use_queue_full ( queue );
	use_queue_front ( queue );
	use_queue_get ( queue );
	use_queue_remove ( queue );
	queuePrint( queue );
	
	use_queue_up ( queue, '1' );
	use_queue_empty ( queue );
	use_queue_full ( queue );
	use_queue_front ( queue );
	use_queue_get ( queue );
	use_queue_remove ( queue );
	queuePrint ( queue );

	use_queue_empty ( queue );
	use_queue_full ( queue );
	use_queue_front ( queue );

	printf ("\n******* The end of Advanced Tests (c203-advanced-test.c) *******\n");
	free (queue);
	return 0;
}
/**/