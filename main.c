#include "include/my.h"
#include "include/hashtable.h"
#include "include/linked_list.h"
#include <stdio.h>

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 100000) ;

    for (int i = 0; i < 1000000; i++){
        ht_insert(ht, "Youssef", "Youssef1");
    }
    ht_dump(ht);
    delete_hashtable(ht);
    return 0;
}
