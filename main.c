#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tree_work.h"
#include "queue_work.h"

#include "p_error.h"

#define RANDOM_MIN (0)
#define RANDOM_MAX (100)

//#define MANUAL_INPUT

int main() {
    srand(time(NULL));

    TQueue queue = {NULL, NULL};
    TTreeNode *tree = NULL;

    printf("Enter number of elements in Queue: ");

    int n = 0;
    if ( (scanf("%d", &n) != 1) || (n <= 0) ) {
        print_error_exit("Bad N");
    }

    int i = 0, value = 0;
    for (i = 0; i < n; i++) {
#ifdef MANUAL_INPUT
        if (scanf("%d", &value) != 1) {
            print_error_exit("Bad value");
        }
#else
        value = rand() % (RANDOM_MAX - RANDOM_MIN + 1) + RANDOM_MIN;
#endif
        enqueue(&queue, value);
    }

    printf("\n*** Queue:\n");
    print_queue(queue);

    for (i = 0; i < n; ++i) {
        tree_add_number(&tree, dequeue(&queue) );
    }

    printf("\n\n*** Tree: \n");
    tree_print(tree);

    tree_cut(&tree);

    printf("\n\n*** Cutted tree: \n");
    tree_print(tree);

    getchar();
	return 0;
}
